// MIT License
//
// Copyright (c) 2024 Gui Yang 
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <sqlite3.h>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>
#include "proto_def/position.pb.h"
#include "proto_def/index.pb.h"
#include "table/table.h"
class TestTable {
public:
  sqlite3 *getDB() {
    if (!db_) {
      sqlite3_open(R"(/Users/ygui/CLionProjects/playground/data/test.db)", &db_);
      auto sql = "CREATE TABLE Position("
                 "Key   Blob    PRIMARY KEY NOT NULL,"
                 "Value   Blob );";

      auto callback = [](void *NotUsed, int argc, char **argv, char **azColName) {
        int i;
        for (i = 0; i < argc; i++) {
          printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
      };
      /* Execute SQL statement */
      char *zErrMsg = 0;
      int rc = sqlite3_exec(db_, sql, callback, nullptr, &zErrMsg);
      if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
      } else {
        fprintf(stdout, "Table created successfully\n");
      }
    }
    return db_;
  }

  static int readBlob(
      sqlite3 *db, /* Database containing blobs table */
      char *zKey, /* Null-terminated key to retrieve blob for */
      char **pzBlob, /* Set *pzBlob to point to the retrieved blob */
      int *pnBlob /* Set *pnBlob to the size of the retrieved blob */
  ) {
    const char *zSql = "SELECT Data FROM Position WHERE Name = ?";
    sqlite3_stmt *pStmt;
    int rc;

    /* In case there is no table entry for key zKey or an error occurs,
    ** set *pzBlob and *pnBlob to 0 now.
    */
    *pzBlob = 0;
    *pnBlob = 0;

    do {
      /* Compile the SELECT statement into a virtual machine. */
      rc = sqlite3_prepare(db, zSql, -1, &pStmt, nullptr);
      if (rc != SQLITE_OK) {
        return rc;
      }

      /* Bind the key to the SQL variable. */
      sqlite3_bind_text(pStmt, 1, zKey, -1, SQLITE_STATIC);

      /* Run the virtual machine. We can tell by the SQL statement that
      ** at most 1 row will be returned. So call sqlite3_step() once
      ** only. Normally, we would keep calling sqlite3_step until it
      ** returned something other than SQLITE_ROW.
      */
      rc = sqlite3_step(pStmt);
      if (rc == SQLITE_ROW) {
        /* The pointer returned by sqlite3_column_blob() points to memory
        ** that is owned by the statement handle (pStmt). It is only good
        ** until the next call to an sqlite3_XXX() function (e.g. the
        ** sqlite3_finalize() below) that involves the statement handle.
        ** So we need to make a copy of the blob into memory obtained from
        ** malloc() to return to the caller.
        */
        *pnBlob = sqlite3_column_bytes(pStmt, 0);
        *pzBlob = (char *) malloc(*pnBlob);
        memcpy(*pzBlob, sqlite3_column_blob(pStmt, 0), *pnBlob);
      }

      /* Finalize the statement (this releases resources allocated by
      ** sqlite3_prepare() ).
      */
      rc = sqlite3_finalize(pStmt);

      /* If sqlite3_finalize() returned SQLITE_SCHEMA, then try to execute
      ** the statement all over again.
      */
    } while (rc == SQLITE_SCHEMA);

    return rc;
  }

  int writeBlob(
      const char *zKey, /* Null-terminated key string */
      const char *zBlob, /* Pointer to blob of data */
      int nBlob /* Length of data pointed to by zBlob */
  ) {
    const char *zSql = "INSERT INTO Position(Key, Value) VALUES(?, ?)";
    sqlite3_stmt *pStmt;
    int rc;

    do {
      /* Compile the INSERT statement into a virtual machine. */
      rc = sqlite3_prepare(db_, zSql, -1, &pStmt, nullptr);
      if (rc != SQLITE_OK) {
        return rc;
      }

      /* Bind the key and value data for the new table entry to SQL variables
      ** (the ? characters in the sql statement) in the compiled INSERT
      ** statement.
      **
      ** NOTE: variables are numbered from left to right from 1 upwards.
      ** Passing 0 as the second parameter of an sqlite3_bind_XXX() function
      ** is an error.
      */
      sqlite3_bind_text(pStmt, 1, zKey, -1, SQLITE_STATIC);
      sqlite3_bind_blob(pStmt, 2, zBlob, nBlob, SQLITE_STATIC);

      /* Call sqlite3_step() to run the virtual machine. Since the SQL being
      ** executed is not a SELECT statement, we assume no data will be returned.
      */
      rc = sqlite3_step(pStmt);
      assert(rc != SQLITE_ROW);

      /* Finalize the virtual machine. This releases all memory and other
      ** resources allocated by the sqlite3_prepare() call above.
      */
      rc = sqlite3_finalize(pStmt);

      /* If sqlite3_finalize() returned SQLITE_SCHEMA, then try to execute
      ** the statement again.
      */
    } while (rc == SQLITE_SCHEMA);

    return rc;
  }

protected:
  sqlite3 *db_{nullptr};
};

int main() {
  TestTable t;
  auto *db = t.getDB();

  playground::Position pa;
  pa.set_account_id("John");
  pa.set_contract_id(600000);
  pa.set_today_long(1000);

  playground::PositionHashIndex idx;
  idx.set_account_id("John");
  idx.set_contract_id(600000);

  auto value = pa.SerializeAsString();
  auto start = std::chrono::high_resolution_clock::now();
  for(int i=0;i<100000;++i) {
    t.writeBlob(idx.SerializeAsString().c_str(), value.c_str(), value.size());
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "cost: " << std::chrono::duration<double, std::milli>(end - start).count() / 1000000.<< " ms" << std::endl;
}
