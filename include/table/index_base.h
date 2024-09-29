//
// Created by ygui on 2024/9/27.
//

#ifndef INDEX_BASE_H
#define INDEX_BASE_H
#include <google/protobuf/descriptor.h>
#include "index_base.h"

namespace data {
struct PBHash {
  size_t operator()(const google::protobuf::MessageLite &a) const {
    return std::hash<std::string>{}(a.SerializeAsString());
  }
};

struct PBEquals {
  bool operator()(const google::protobuf::MessageLite &msg_a, const google::protobuf::MessageLite &msg_b) const {
    return msg_a.GetTypeName() == msg_b.GetTypeName() &&
           msg_a.SerializeAsString() == msg_b.SerializeAsString();
  }
};


template<class RowPBType, class IndexPBType>
class HashIndexBase {
public:
  using row_pb_t = RowPBType;
  using index_pb_t = IndexPBType;

  explicit HashIndexBase(const row_pb_t &row_v) {
    for (int i = 0; i < index_desc_->field_count(); ++i) {
      auto *dst_field = index_desc_->field(i);
      auto *src_field = row_desc_->FindFieldByName(dst_field->name());
      switch (dst_field->type()) {
        // TODO: 完善类型处理，编译期检查类型
        case google::protobuf::FieldDescriptor::TYPE_INT64: {
          auto str = row_refl_->GetInt64(row_v, src_field);
          index_refl_->SetInt64(&index_value_, dst_field, str);
          break;
        }
        case google::protobuf::FieldDescriptor::TYPE_STRING: {
          auto str = row_refl_->GetString(row_v, src_field);
          index_refl_->SetString(&index_value_, dst_field, str);
          break;
        }
        default: ;
      }
    }
  }

  index_pb_t &get() {
    return index_value_;
  }

  bool operator==(const HashIndexBase &other) const {
    return (index_value_.GetTypeName() == other.index_value_.GetTypeName()) &&
           (index_value_.SerializeAsString() == other.index_value_.SerializeAsString());
  }

  auto DebugString() const {
    return index_value_.DebugString();
  }

protected:
  static const google::protobuf::Descriptor *row_desc_;
  static const google::protobuf::Descriptor *index_desc_;
  static const google::protobuf::Reflection *row_refl_;
  static const google::protobuf::Reflection *index_refl_;
  index_pb_t index_value_;
};

template<class PBType, class IndexType>
const google::protobuf::Descriptor *HashIndexBase<PBType, IndexType>::row_desc_ = PBType::descriptor();

template<class PBType, class IndexType>
const google::protobuf::Descriptor *HashIndexBase<PBType, IndexType>::index_desc_ = IndexType::GetDescriptor();

template<class PBType, class IndexType>
const google::protobuf::Reflection *HashIndexBase<PBType, IndexType>::row_refl_ = PBType::GetReflection();

template<class PBType, class IndexType>
const google::protobuf::Reflection *HashIndexBase<PBType, IndexType>::index_refl_ = IndexType::GetReflection();
}

#endif //INDEX_BASE_H

