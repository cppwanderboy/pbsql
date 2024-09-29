//
// Created by ygui on 2024/8/30.
//

#ifndef TABLE_BASE_H
#define TABLE_BASE_H
#include <sqlite3.h>
#include <string_view>

#include "index_base.h"
#include "sqlite_base.h"

namespace data {
enum ETableAction {
  INSERT = 0,
  DELETE,
  UPDATE,
};

template<class RowPBType, class IndexPBTyep>
class TableBase {
public:
  using row_pb_t = RowPBType;
  using index_t = HashIndexBase<row_pb_t, IndexPBTyep>;
  using index_pb_t = IndexPBTyep;
  std::string_view db_path = R"(C:\Users\ygui\CLionProjects\playground\data\test.db)";

  TableBase() {
    mem_.reserve(4096);
    char *buffer = new char[4096];
    int used{0};
    sqlite_.readBlob(0, &buffer, &used);
    row_pb_t p1,p2;
    p1.ParseFromArray(buffer, used);
    std::cout << p1.DebugString() << std::endl;
    sqlite_.readBlob(1, &buffer, &used);
    p2.ParseFromArray(buffer, used);
    std::cout << p2.DebugString() << std::endl;
  }

  void insert(row_pb_t &pb_value) {
    mem_.push_back(pb_value);
    sync_db(INSERT, nullptr, &mem_.back());
    index_t idx_value(mem_.back());
    index_[idx_value.get()] = &mem_.back();
  }

  row_pb_t query(index_t &idx) {
    return *index_[idx.get()];
  }

  bool replace_query(row_pb_t &row_pb_v) {
    index_t idx(row_pb_v);
    auto *p = index_[idx.get()];
    row_pb_v.CopyFrom(*p);
    return true;
  }

  void update(row_pb_t &pb_value) {
    index_t idx(pb_value);
    index_[idx.get()]->CopyFrom(pb_value);
  }

protected:
  bool sync_db(ETableAction action, const row_pb_t *old_v, const row_pb_t *new_v) {
    switch (action) {
    case INSERT: {
      sqlite_.writeBlob(count_++, new_v->SerializeAsString().data(), new_v->ByteSizeLong());
      break;
    }
    case DELETE: {
      break;
    }
    case UPDATE: {
      break;
    }
    }
    return true;
  }

protected:
  int count_{0};
  SqliteTable sqlite_{"Position"};
  std::vector<row_pb_t> mem_;
  std::unordered_map<index_pb_t, row_pb_t *, data::PBHash, PBEquals> index_;
};
}
#endif //TABLE_BASE_H
