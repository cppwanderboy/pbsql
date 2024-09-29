#include <iostream>
#include "proto_def/position.pb.h"
#include "proto_def/index.pb.h"
#include "table/table.h"

int main(int argc, char *argv[]) {
  // load pb database
  playground::Position pa;
  pa.set_account_id("John");
  pa.set_contract_id(600000);
  pa.set_today_long(1000);
  playground::Position pb;
  pb.set_contract_id(600004);
  pb.set_account_id("Snow");
  pb.set_today_long(5000);

  data::TablePosition t;
  t.insert(pa);
  t.insert(pb);

  // query hist using pb
  playground::Position q1;
  q1.set_account_id("John");
  q1.set_contract_id(600000);
  std::cerr << "== Index =======================" << std::endl;
  std::cerr << q1.DebugString() << std::endl;
  t.replace_query(q1);
  std::cerr << "== Query Result =======================" << std::endl;
  std::cerr << q1.DebugString() << std::endl;

  // change and commit & no commit
  q1.set_today_long(3000);
  t.update(q1);
  q1.set_today_long(4000);

  playground::Position q2;
  q2.set_account_id("John");
  q2.set_contract_id(600000);
  t.replace_query(q2);
  std::cerr << "== Commit Result =======================" << std::endl;
  std::cerr << q2.DebugString() << std::endl;
  std::cerr << "== Uncommit Result =======================" << std::endl;
  std::cerr << q1.DebugString() << std::endl;
}
