// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Enum.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Enum_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Enum_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Enum_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Enum_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Enum_2eproto;
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

enum PlayerType : int {
  PLAYER_TYPE_NONE = 0,
  PLAYER_TYPE_KNIGHT = 1,
  PLAYER_TYPE_MAGE = 2,
  PLAYER_TYPE_ARCHER = 3,
  PlayerType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  PlayerType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool PlayerType_IsValid(int value);
constexpr PlayerType PlayerType_MIN = PLAYER_TYPE_NONE;
constexpr PlayerType PlayerType_MAX = PLAYER_TYPE_ARCHER;
constexpr int PlayerType_ARRAYSIZE = PlayerType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PlayerType_descriptor();
template<typename T>
inline const std::string& PlayerType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PlayerType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PlayerType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PlayerType_descriptor(), enum_t_value);
}
inline bool PlayerType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PlayerType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PlayerType>(
    PlayerType_descriptor(), name, value);
}
enum PacketId : int {
  PKT_NONE = 0,
  PKT_C_ENTER_GAME = 1,
  PKT_S_ENTER_GAME = 2,
  PKT_C_LEAVE_GAME = 3,
  PKT_S_LEAVE_GAME = 4,
  PKT_S_SPAWN = 5,
  PKT_S_DESPAWN = 6,
  PKT_C_MOVE = 7,
  PKT_S_MOVE = 8,
  PKT_C_CHAT = 9,
  PKT_S_CHAT = 10,
  PacketId_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  PacketId_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool PacketId_IsValid(int value);
constexpr PacketId PacketId_MIN = PKT_NONE;
constexpr PacketId PacketId_MAX = PKT_S_CHAT;
constexpr int PacketId_ARRAYSIZE = PacketId_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PacketId_descriptor();
template<typename T>
inline const std::string& PacketId_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PacketId>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PacketId_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PacketId_descriptor(), enum_t_value);
}
inline bool PacketId_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PacketId* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PacketId>(
    PacketId_descriptor(), name, value);
}
enum CreatureState : int {
  IDLE = 0,
  MOVING = 1,
  ATTACK = 2,
  DEAD = 3,
  CreatureState_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  CreatureState_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool CreatureState_IsValid(int value);
constexpr CreatureState CreatureState_MIN = IDLE;
constexpr CreatureState CreatureState_MAX = DEAD;
constexpr int CreatureState_ARRAYSIZE = CreatureState_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CreatureState_descriptor();
template<typename T>
inline const std::string& CreatureState_Name(T enum_t_value) {
  static_assert(::std::is_same<T, CreatureState>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function CreatureState_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    CreatureState_descriptor(), enum_t_value);
}
inline bool CreatureState_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, CreatureState* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<CreatureState>(
    CreatureState_descriptor(), name, value);
}
enum MoveDir : int {
  NONE = 0,
  UP = 1,
  DOWN = 2,
  LEFT = 3,
  RIGHT = 4,
  MoveDir_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  MoveDir_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool MoveDir_IsValid(int value);
constexpr MoveDir MoveDir_MIN = NONE;
constexpr MoveDir MoveDir_MAX = RIGHT;
constexpr int MoveDir_ARRAYSIZE = MoveDir_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MoveDir_descriptor();
template<typename T>
inline const std::string& MoveDir_Name(T enum_t_value) {
  static_assert(::std::is_same<T, MoveDir>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function MoveDir_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    MoveDir_descriptor(), enum_t_value);
}
inline bool MoveDir_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, MoveDir* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<MoveDir>(
    MoveDir_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Protocol::PlayerType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::PlayerType>() {
  return ::Protocol::PlayerType_descriptor();
}
template <> struct is_proto_enum< ::Protocol::PacketId> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::PacketId>() {
  return ::Protocol::PacketId_descriptor();
}
template <> struct is_proto_enum< ::Protocol::CreatureState> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::CreatureState>() {
  return ::Protocol::CreatureState_descriptor();
}
template <> struct is_proto_enum< ::Protocol::MoveDir> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::MoveDir>() {
  return ::Protocol::MoveDir_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Enum_2eproto
