//
// Created by ygui on 2024/9/29.
//

#ifndef SQLITE_H
#define SQLITE_H
#include <sqlite3.h>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>

namespace data {
class SqliteTable {
public:
  explicit SqliteTable(const char *name) {
    getDB();
  }
  sqlite3 *getDB() {
    sqlite3_open(R"(/Users/ygui/CLionProjects/playground/data/test.db)", &db_);
    if (!db_) {
      auto sql = "CREATE TABLE Position("
                 "Key   INTEGER    PRIMARY KEY NOT NULL,"
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

  int readBlob(
      int zKey, /* Null-terminated key to retrieve blob for */
      char **pzBlob, /* Set *pzBlob to point to the retrieved blob */
      int *pnBlob /* Set *pnBlob to the size of the retrieved blob */
  ) {
    const char *zSql = "SELECT Value FROM Position WHERE Key = ?";
    sqlite3_stmt *pStmt;
    int rc;

    /* In case there is no table entry for key zKey or an error occurs,
    ** set *pzBlob and *pnBlob to 0 now.
    */
    *pzBlob = 0;
    *pnBlob = 0;

    do {
      /* Compile the SELECT statement into a virtual machine. */
      rc = sqlite3_prepare(db_, zSql, -1, &pStmt, nullptr);
      if (rc != SQLITE_OK) {
        return rc;
      }

      /* Bind the key to the SQL variable. */
      sqlite3_bind_int(pStmt, 1, zKey);

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
      int key, /* Null-terminated key string */
      const char *zBlob, /* Pointer to blob of data */
      int nBlob /* Length of data pointed to by zBlob */
  ) {
    const char *zSql = "INSERT INTO Position(Key, Value) VALUES(?, ?)";
    int rc;

    sqlite3_stmt *pStmt_;
    do {
      rc = sqlite3_prepare(db_, zSql, -1, &pStmt_, nullptr);
      if (rc != SQLITE_OK) {
        return rc;
      }

      sqlite3_bind_int(pStmt_, 1, key);
      sqlite3_bind_blob(pStmt_, 2, zBlob, nBlob, SQLITE_STATIC);
      rc = sqlite3_step(pStmt_);
      assert(rc != SQLITE_ROW);
      rc = sqlite3_finalize(pStmt_);
    } while (rc == SQLITE_SCHEMA);

    return rc;
  }

protected:
  sqlite3 *db_{nullptr};

};
}
#endif //SQLITE_H
