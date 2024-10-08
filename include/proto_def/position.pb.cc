// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: position.proto

#include "position.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace playground {

inline constexpr Position::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        account_id_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        contract_id_{::int64_t{0}},
        today_long_{0},
        today_short_{0},
        yesterday_long_{0},
        yesterday_short_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Position::Position(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct PositionDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PositionDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~PositionDefaultTypeInternal() {}
  union {
    Position _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PositionDefaultTypeInternal _Position_default_instance_;

inline constexpr Portfolio::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        positions_{},
        name_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()) {}

template <typename>
PROTOBUF_CONSTEXPR Portfolio::Portfolio(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct PortfolioDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PortfolioDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~PortfolioDefaultTypeInternal() {}
  union {
    Portfolio _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PortfolioDefaultTypeInternal _Portfolio_default_instance_;
}  // namespace playground
static ::_pb::Metadata file_level_metadata_position_2eproto[2];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_position_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_position_2eproto = nullptr;
const ::uint32_t TableStruct_position_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::playground::Position, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::playground::Position, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::playground::Position, _impl_.contract_id_),
    PROTOBUF_FIELD_OFFSET(::playground::Position, _impl_.account_id_),
    PROTOBUF_FIELD_OFFSET(::playground::Position, _impl_.today_long_),
    PROTOBUF_FIELD_OFFSET(::playground::Position, _impl_.today_short_),
    PROTOBUF_FIELD_OFFSET(::playground::Position, _impl_.yesterday_long_),
    PROTOBUF_FIELD_OFFSET(::playground::Position, _impl_.yesterday_short_),
    1,
    0,
    2,
    3,
    4,
    5,
    PROTOBUF_FIELD_OFFSET(::playground::Portfolio, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::playground::Portfolio, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::playground::Portfolio, _impl_.name_),
    PROTOBUF_FIELD_OFFSET(::playground::Portfolio, _impl_.positions_),
    0,
    ~0u,
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, 14, -1, sizeof(::playground::Position)},
        {20, 30, -1, sizeof(::playground::Portfolio)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::playground::_Position_default_instance_._instance,
    &::playground::_Portfolio_default_instance_._instance,
};
const char descriptor_table_protodef_position_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\016position.proto\022\nplayground\"\215\001\n\010Positio"
    "n\022\023\n\013contract_id\030\001 \001(\003\022\022\n\naccount_id\030\002 \001"
    "(\t\022\022\n\ntoday_long\030\003 \001(\005\022\023\n\013today_short\030\004 "
    "\001(\005\022\026\n\016yesterday_long\030\005 \001(\005\022\027\n\017yesterday"
    "_short\030\006 \001(\005\"B\n\tPortfolio\022\014\n\004name\030\001 \001(\t\022"
    "\'\n\tpositions\030\002 \003(\0132\024.playground.Position"
};
static ::absl::once_flag descriptor_table_position_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_position_2eproto = {
    false,
    false,
    240,
    descriptor_table_protodef_position_2eproto,
    "position.proto",
    &descriptor_table_position_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_position_2eproto::offsets,
    file_level_metadata_position_2eproto,
    file_level_enum_descriptors_position_2eproto,
    file_level_service_descriptors_position_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_position_2eproto_getter() {
  return &descriptor_table_position_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_position_2eproto(&descriptor_table_position_2eproto);
namespace playground {
// ===================================================================

class Position::_Internal {
 public:
  using HasBits = decltype(std::declval<Position>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(Position, _impl_._has_bits_);
  static void set_has_contract_id(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_account_id(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_today_long(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_today_short(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_yesterday_long(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_yesterday_short(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
};

Position::Position(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:playground.Position)
}
inline PROTOBUF_NDEBUG_INLINE Position::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        account_id_(arena, from.account_id_) {}

Position::Position(
    ::google::protobuf::Arena* arena,
    const Position& from)
    : ::google::protobuf::Message(arena) {
  Position* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, contract_id_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, contract_id_),
           offsetof(Impl_, yesterday_short_) -
               offsetof(Impl_, contract_id_) +
               sizeof(Impl_::yesterday_short_));

  // @@protoc_insertion_point(copy_constructor:playground.Position)
}
inline PROTOBUF_NDEBUG_INLINE Position::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        account_id_(arena) {}

inline void Position::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, contract_id_),
           0,
           offsetof(Impl_, yesterday_short_) -
               offsetof(Impl_, contract_id_) +
               sizeof(Impl_::yesterday_short_));
}
Position::~Position() {
  // @@protoc_insertion_point(destructor:playground.Position)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Position::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.account_id_.Destroy();
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void Position::Clear() {
// @@protoc_insertion_point(message_clear_start:playground.Position)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.account_id_.ClearNonDefaultToEmpty();
  }
  if (cached_has_bits & 0x0000003eu) {
    ::memset(&_impl_.contract_id_, 0, static_cast<::size_t>(
        reinterpret_cast<char*>(&_impl_.yesterday_short_) -
        reinterpret_cast<char*>(&_impl_.contract_id_)) + sizeof(_impl_.yesterday_short_));
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Position::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 6, 0, 38, 2> Position::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Position, _impl_._has_bits_),
    0, // no _extensions_
    6, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967232,  // skipmap
    offsetof(decltype(_table_), field_entries),
    6,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Position_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // optional int64 contract_id = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(Position, _impl_.contract_id_), 1>(),
     {8, 1, 0, PROTOBUF_FIELD_OFFSET(Position, _impl_.contract_id_)}},
    // optional string account_id = 2;
    {::_pbi::TcParser::FastSS1,
     {18, 0, 0, PROTOBUF_FIELD_OFFSET(Position, _impl_.account_id_)}},
    // optional int32 today_long = 3;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Position, _impl_.today_long_), 2>(),
     {24, 2, 0, PROTOBUF_FIELD_OFFSET(Position, _impl_.today_long_)}},
    // optional int32 today_short = 4;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Position, _impl_.today_short_), 3>(),
     {32, 3, 0, PROTOBUF_FIELD_OFFSET(Position, _impl_.today_short_)}},
    // optional int32 yesterday_long = 5;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Position, _impl_.yesterday_long_), 4>(),
     {40, 4, 0, PROTOBUF_FIELD_OFFSET(Position, _impl_.yesterday_long_)}},
    // optional int32 yesterday_short = 6;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Position, _impl_.yesterday_short_), 5>(),
     {48, 5, 0, PROTOBUF_FIELD_OFFSET(Position, _impl_.yesterday_short_)}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // optional int64 contract_id = 1;
    {PROTOBUF_FIELD_OFFSET(Position, _impl_.contract_id_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt64)},
    // optional string account_id = 2;
    {PROTOBUF_FIELD_OFFSET(Position, _impl_.account_id_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // optional int32 today_long = 3;
    {PROTOBUF_FIELD_OFFSET(Position, _impl_.today_long_), _Internal::kHasBitsOffset + 2, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 today_short = 4;
    {PROTOBUF_FIELD_OFFSET(Position, _impl_.today_short_), _Internal::kHasBitsOffset + 3, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 yesterday_long = 5;
    {PROTOBUF_FIELD_OFFSET(Position, _impl_.yesterday_long_), _Internal::kHasBitsOffset + 4, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 yesterday_short = 6;
    {PROTOBUF_FIELD_OFFSET(Position, _impl_.yesterday_short_), _Internal::kHasBitsOffset + 5, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
  }},
  // no aux_entries
  {{
    "\23\0\12\0\0\0\0\0"
    "playground.Position"
    "account_id"
  }},
};

::uint8_t* Position::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:playground.Position)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional int64 contract_id = 1;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt64ToArrayWithField<1>(
            stream, this->_internal_contract_id(), target);
  }

  // optional string account_id = 2;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_account_id();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "playground.Position.account_id");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  // optional int32 today_long = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<3>(
            stream, this->_internal_today_long(), target);
  }

  // optional int32 today_short = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<4>(
            stream, this->_internal_today_short(), target);
  }

  // optional int32 yesterday_long = 5;
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<5>(
            stream, this->_internal_yesterday_long(), target);
  }

  // optional int32 yesterday_short = 6;
  if (cached_has_bits & 0x00000020u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<6>(
            stream, this->_internal_yesterday_short(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:playground.Position)
  return target;
}

::size_t Position::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:playground.Position)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    // optional string account_id = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_account_id());
    }

    // optional int64 contract_id = 1;
    if (cached_has_bits & 0x00000002u) {
      total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
          this->_internal_contract_id());
    }

    // optional int32 today_long = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_today_long());
    }

    // optional int32 today_short = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_today_short());
    }

    // optional int32 yesterday_long = 5;
    if (cached_has_bits & 0x00000010u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_yesterday_long());
    }

    // optional int32 yesterday_short = 6;
    if (cached_has_bits & 0x00000020u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_yesterday_short());
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData Position::_class_data_ = {
    Position::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* Position::GetClassData() const {
  return &_class_data_;
}

void Position::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<Position*>(&to_msg);
  auto& from = static_cast<const Position&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:playground.Position)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_account_id(from._internal_account_id());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_impl_.contract_id_ = from._impl_.contract_id_;
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_impl_.today_long_ = from._impl_.today_long_;
    }
    if (cached_has_bits & 0x00000008u) {
      _this->_impl_.today_short_ = from._impl_.today_short_;
    }
    if (cached_has_bits & 0x00000010u) {
      _this->_impl_.yesterday_long_ = from._impl_.yesterday_long_;
    }
    if (cached_has_bits & 0x00000020u) {
      _this->_impl_.yesterday_short_ = from._impl_.yesterday_short_;
    }
    _this->_impl_._has_bits_[0] |= cached_has_bits;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Position::CopyFrom(const Position& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:playground.Position)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Position::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* Position::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void Position::InternalSwap(Position* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.account_id_, &other->_impl_.account_id_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Position, _impl_.yesterday_short_)
      + sizeof(Position::_impl_.yesterday_short_)
      - PROTOBUF_FIELD_OFFSET(Position, _impl_.contract_id_)>(
          reinterpret_cast<char*>(&_impl_.contract_id_),
          reinterpret_cast<char*>(&other->_impl_.contract_id_));
}

::google::protobuf::Metadata Position::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_position_2eproto_getter, &descriptor_table_position_2eproto_once,
      file_level_metadata_position_2eproto[0]);
}
// ===================================================================

class Portfolio::_Internal {
 public:
  using HasBits = decltype(std::declval<Portfolio>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(Portfolio, _impl_._has_bits_);
  static void set_has_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

Portfolio::Portfolio(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:playground.Portfolio)
}
inline PROTOBUF_NDEBUG_INLINE Portfolio::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        positions_{visibility, arena, from.positions_},
        name_(arena, from.name_) {}

Portfolio::Portfolio(
    ::google::protobuf::Arena* arena,
    const Portfolio& from)
    : ::google::protobuf::Message(arena) {
  Portfolio* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);

  // @@protoc_insertion_point(copy_constructor:playground.Portfolio)
}
inline PROTOBUF_NDEBUG_INLINE Portfolio::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        positions_{visibility, arena},
        name_(arena) {}

inline void Portfolio::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Portfolio::~Portfolio() {
  // @@protoc_insertion_point(destructor:playground.Portfolio)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Portfolio::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.name_.Destroy();
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void Portfolio::Clear() {
// @@protoc_insertion_point(message_clear_start:playground.Portfolio)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.positions_.Clear();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.name_.ClearNonDefaultToEmpty();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Portfolio::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 1, 33, 2> Portfolio::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Portfolio, _impl_._has_bits_),
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_Portfolio_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // repeated .playground.Position positions = 2;
    {::_pbi::TcParser::FastMtR1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(Portfolio, _impl_.positions_)}},
    // optional string name = 1;
    {::_pbi::TcParser::FastSS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(Portfolio, _impl_.name_)}},
  }}, {{
    65535, 65535
  }}, {{
    // optional string name = 1;
    {PROTOBUF_FIELD_OFFSET(Portfolio, _impl_.name_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // repeated .playground.Position positions = 2;
    {PROTOBUF_FIELD_OFFSET(Portfolio, _impl_.positions_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::playground::Position>()},
  }}, {{
    "\24\4\0\0\0\0\0\0"
    "playground.Portfolio"
    "name"
  }},
};

::uint8_t* Portfolio::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:playground.Portfolio)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional string name = 1;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_name();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "playground.Portfolio.name");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // repeated .playground.Position positions = 2;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_positions_size()); i < n; i++) {
    const auto& repfield = this->_internal_positions().Get(i);
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessage(2, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:playground.Portfolio)
  return target;
}

::size_t Portfolio::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:playground.Portfolio)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .playground.Position positions = 2;
  total_size += 1UL * this->_internal_positions_size();
  for (const auto& msg : this->_internal_positions()) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  // optional string name = 1;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_name());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData Portfolio::_class_data_ = {
    Portfolio::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* Portfolio::GetClassData() const {
  return &_class_data_;
}

void Portfolio::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<Portfolio*>(&to_msg);
  auto& from = static_cast<const Portfolio&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:playground.Portfolio)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_positions()->MergeFrom(
      from._internal_positions());
  if ((from._impl_._has_bits_[0] & 0x00000001u) != 0) {
    _this->_internal_set_name(from._internal_name());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Portfolio::CopyFrom(const Portfolio& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:playground.Portfolio)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Portfolio::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* Portfolio::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void Portfolio::InternalSwap(Portfolio* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.positions_.InternalSwap(&other->_impl_.positions_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.name_, &other->_impl_.name_, arena);
}

::google::protobuf::Metadata Portfolio::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_position_2eproto_getter, &descriptor_table_position_2eproto_once,
      file_level_metadata_position_2eproto[1]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace playground
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
