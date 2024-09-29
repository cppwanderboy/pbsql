//
// Created by ygui on 2024/9/27.
//

#ifndef TABLE_H
#define TABLE_H
#include "table/table_base.h"
#include "proto_def/position.pb.h"
#include "proto_def/index.pb.h"

#define PB_NAMESPACE playground

namespace data {
#define DEFINE_TABLE(Object,Index)                              \
using Table##Object = TableBase<PB_NAMESPACE::Object,PB_NAMESPACE::Index>;\
}

DEFINE_TABLE(Position, PositionHashIndex);
#endif //TABLE_H
