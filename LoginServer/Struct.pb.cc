// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#include "Struct.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace Protocol {
PROTOBUF_CONSTEXPR PlayerInfo::PlayerInfo(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.playerid_)*/0
  , /*decltype(_impl_.posx_)*/0
  , /*decltype(_impl_.posy_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PlayerInfoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PlayerInfoDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PlayerInfoDefaultTypeInternal() {}
  union {
    PlayerInfo _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PlayerInfoDefaultTypeInternal _PlayerInfo_default_instance_;
PROTOBUF_CONSTEXPR PositionInfo::PositionInfo(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.state_)*/0
  , /*decltype(_impl_.movedir_)*/0
  , /*decltype(_impl_.posx_)*/0
  , /*decltype(_impl_.posy_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PositionInfoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PositionInfoDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PositionInfoDefaultTypeInternal() {}
  union {
    PositionInfo _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PositionInfoDefaultTypeInternal _PositionInfo_default_instance_;
}  // namespace Protocol
static ::_pb::Metadata file_level_metadata_Struct_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_Struct_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_Struct_2eproto = nullptr;

const uint32_t TableStruct_Struct_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _impl_.playerid_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _impl_.posx_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PlayerInfo, _impl_.posy_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::PositionInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::PositionInfo, _impl_.state_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PositionInfo, _impl_.movedir_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PositionInfo, _impl_.posx_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PositionInfo, _impl_.posy_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::PlayerInfo)},
  { 10, -1, -1, sizeof(::Protocol::PositionInfo)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::Protocol::_PlayerInfo_default_instance_._instance,
  &::Protocol::_PositionInfo_default_instance_._instance,
};

const char descriptor_table_protodef_Struct_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014Struct.proto\022\010Protocol\032\nEnum.proto\"H\n\n"
  "PlayerInfo\022\020\n\010playerId\030\001 \001(\005\022\014\n\004name\030\002 \001"
  "(\t\022\014\n\004posX\030\003 \001(\005\022\014\n\004posY\030\004 \001(\005\"v\n\014Positi"
  "onInfo\022&\n\005state\030\001 \001(\0162\027.Protocol.Creatur"
  "eState\022\"\n\007moveDir\030\002 \001(\0162\021.Protocol.MoveD"
  "ir\022\014\n\004posX\030\003 \001(\005\022\014\n\004posY\030\004 \001(\005b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_Struct_2eproto_deps[1] = {
  &::descriptor_table_Enum_2eproto,
};
static ::_pbi::once_flag descriptor_table_Struct_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_Struct_2eproto = {
    false, false, 238, descriptor_table_protodef_Struct_2eproto,
    "Struct.proto",
    &descriptor_table_Struct_2eproto_once, descriptor_table_Struct_2eproto_deps, 1, 2,
    schemas, file_default_instances, TableStruct_Struct_2eproto::offsets,
    file_level_metadata_Struct_2eproto, file_level_enum_descriptors_Struct_2eproto,
    file_level_service_descriptors_Struct_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_Struct_2eproto_getter() {
  return &descriptor_table_Struct_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_Struct_2eproto(&descriptor_table_Struct_2eproto);
namespace Protocol {

// ===================================================================

class PlayerInfo::_Internal {
 public:
};

PlayerInfo::PlayerInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Protocol.PlayerInfo)
}
PlayerInfo::PlayerInfo(const PlayerInfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  PlayerInfo* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , decltype(_impl_.playerid_){}
    , decltype(_impl_.posx_){}
    , decltype(_impl_.posy_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.playerid_, &from._impl_.playerid_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.posy_) -
    reinterpret_cast<char*>(&_impl_.playerid_)) + sizeof(_impl_.posy_));
  // @@protoc_insertion_point(copy_constructor:Protocol.PlayerInfo)
}

inline void PlayerInfo::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , decltype(_impl_.playerid_){0}
    , decltype(_impl_.posx_){0}
    , decltype(_impl_.posy_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

PlayerInfo::~PlayerInfo() {
  // @@protoc_insertion_point(destructor:Protocol.PlayerInfo)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void PlayerInfo::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.name_.Destroy();
}

void PlayerInfo::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void PlayerInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.PlayerInfo)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.ClearToEmpty();
  ::memset(&_impl_.playerid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.posy_) -
      reinterpret_cast<char*>(&_impl_.playerid_)) + sizeof(_impl_.posy_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PlayerInfo::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 playerId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.playerid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Protocol.PlayerInfo.name"));
        } else
          goto handle_unusual;
        continue;
      // int32 posX = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.posx_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 posY = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _impl_.posy_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* PlayerInfo::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.PlayerInfo)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 playerId = 1;
  if (this->_internal_playerid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_playerid(), target);
  }

  // string name = 2;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.PlayerInfo.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  // int32 posX = 3;
  if (this->_internal_posx() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_posx(), target);
  }

  // int32 posY = 4;
  if (this->_internal_posy() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(4, this->_internal_posy(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.PlayerInfo)
  return target;
}

size_t PlayerInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.PlayerInfo)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 2;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // int32 playerId = 1;
  if (this->_internal_playerid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_playerid());
  }

  // int32 posX = 3;
  if (this->_internal_posx() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_posx());
  }

  // int32 posY = 4;
  if (this->_internal_posy() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_posy());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData PlayerInfo::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    PlayerInfo::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*PlayerInfo::GetClassData() const { return &_class_data_; }


void PlayerInfo::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<PlayerInfo*>(&to_msg);
  auto& from = static_cast<const PlayerInfo&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Protocol.PlayerInfo)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  if (from._internal_playerid() != 0) {
    _this->_internal_set_playerid(from._internal_playerid());
  }
  if (from._internal_posx() != 0) {
    _this->_internal_set_posx(from._internal_posx());
  }
  if (from._internal_posy() != 0) {
    _this->_internal_set_posy(from._internal_posy());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void PlayerInfo::CopyFrom(const PlayerInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.PlayerInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PlayerInfo::IsInitialized() const {
  return true;
}

void PlayerInfo::InternalSwap(PlayerInfo* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.posy_)
      + sizeof(PlayerInfo::_impl_.posy_)
      - PROTOBUF_FIELD_OFFSET(PlayerInfo, _impl_.playerid_)>(
          reinterpret_cast<char*>(&_impl_.playerid_),
          reinterpret_cast<char*>(&other->_impl_.playerid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata PlayerInfo::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Struct_2eproto_getter, &descriptor_table_Struct_2eproto_once,
      file_level_metadata_Struct_2eproto[0]);
}

// ===================================================================

class PositionInfo::_Internal {
 public:
};

PositionInfo::PositionInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Protocol.PositionInfo)
}
PositionInfo::PositionInfo(const PositionInfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  PositionInfo* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.state_){}
    , decltype(_impl_.movedir_){}
    , decltype(_impl_.posx_){}
    , decltype(_impl_.posy_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.state_, &from._impl_.state_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.posy_) -
    reinterpret_cast<char*>(&_impl_.state_)) + sizeof(_impl_.posy_));
  // @@protoc_insertion_point(copy_constructor:Protocol.PositionInfo)
}

inline void PositionInfo::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.state_){0}
    , decltype(_impl_.movedir_){0}
    , decltype(_impl_.posx_){0}
    , decltype(_impl_.posy_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

PositionInfo::~PositionInfo() {
  // @@protoc_insertion_point(destructor:Protocol.PositionInfo)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void PositionInfo::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void PositionInfo::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void PositionInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.PositionInfo)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.state_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.posy_) -
      reinterpret_cast<char*>(&_impl_.state_)) + sizeof(_impl_.posy_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PositionInfo::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .Protocol.CreatureState state = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_state(static_cast<::Protocol::CreatureState>(val));
        } else
          goto handle_unusual;
        continue;
      // .Protocol.MoveDir moveDir = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_movedir(static_cast<::Protocol::MoveDir>(val));
        } else
          goto handle_unusual;
        continue;
      // int32 posX = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.posx_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 posY = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _impl_.posy_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* PositionInfo::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.PositionInfo)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .Protocol.CreatureState state = 1;
  if (this->_internal_state() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      1, this->_internal_state(), target);
  }

  // .Protocol.MoveDir moveDir = 2;
  if (this->_internal_movedir() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      2, this->_internal_movedir(), target);
  }

  // int32 posX = 3;
  if (this->_internal_posx() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_posx(), target);
  }

  // int32 posY = 4;
  if (this->_internal_posy() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(4, this->_internal_posy(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.PositionInfo)
  return target;
}

size_t PositionInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.PositionInfo)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .Protocol.CreatureState state = 1;
  if (this->_internal_state() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_state());
  }

  // .Protocol.MoveDir moveDir = 2;
  if (this->_internal_movedir() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_movedir());
  }

  // int32 posX = 3;
  if (this->_internal_posx() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_posx());
  }

  // int32 posY = 4;
  if (this->_internal_posy() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_posy());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData PositionInfo::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    PositionInfo::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*PositionInfo::GetClassData() const { return &_class_data_; }


void PositionInfo::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<PositionInfo*>(&to_msg);
  auto& from = static_cast<const PositionInfo&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Protocol.PositionInfo)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_state() != 0) {
    _this->_internal_set_state(from._internal_state());
  }
  if (from._internal_movedir() != 0) {
    _this->_internal_set_movedir(from._internal_movedir());
  }
  if (from._internal_posx() != 0) {
    _this->_internal_set_posx(from._internal_posx());
  }
  if (from._internal_posy() != 0) {
    _this->_internal_set_posy(from._internal_posy());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void PositionInfo::CopyFrom(const PositionInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.PositionInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PositionInfo::IsInitialized() const {
  return true;
}

void PositionInfo::InternalSwap(PositionInfo* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(PositionInfo, _impl_.posy_)
      + sizeof(PositionInfo::_impl_.posy_)
      - PROTOBUF_FIELD_OFFSET(PositionInfo, _impl_.state_)>(
          reinterpret_cast<char*>(&_impl_.state_),
          reinterpret_cast<char*>(&other->_impl_.state_));
}

::PROTOBUF_NAMESPACE_ID::Metadata PositionInfo::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Struct_2eproto_getter, &descriptor_table_Struct_2eproto_once,
      file_level_metadata_Struct_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::PlayerInfo*
Arena::CreateMaybeMessage< ::Protocol::PlayerInfo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::PlayerInfo >(arena);
}
template<> PROTOBUF_NOINLINE ::Protocol::PositionInfo*
Arena::CreateMaybeMessage< ::Protocol::PositionInfo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::PositionInfo >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>