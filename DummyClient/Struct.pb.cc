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
namespace Protocol {
constexpr Pos::Pos(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : x_(0)
  , y_(0){}
struct PosDefaultTypeInternal {
  constexpr PosDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PosDefaultTypeInternal() {}
  union {
    Pos _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PosDefaultTypeInternal _Pos_default_instance_;
constexpr Actor::Actor(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , position_(nullptr)
  , id_(uint64_t{0u})
  , type_(0)

  , playertype_(0)

  , blocktype_(0)
{}
struct ActorDefaultTypeInternal {
  constexpr ActorDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ActorDefaultTypeInternal() {}
  union {
    Actor _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ActorDefaultTypeInternal _Actor_default_instance_;
constexpr Player::Player(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : actor_(nullptr)
  , playertype_(0)
{}
struct PlayerDefaultTypeInternal {
  constexpr PlayerDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PlayerDefaultTypeInternal() {}
  union {
    Player _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PlayerDefaultTypeInternal _Player_default_instance_;
}  // namespace Protocol
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Struct_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Struct_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Struct_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Struct_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::Pos, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Protocol::Pos, x_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Pos, y_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Actor, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Actor, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Protocol::Actor, id_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Actor, name_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Actor, type_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Actor, position_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Actor, playertype_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Actor, blocktype_),
  ~0u,
  ~0u,
  ~0u,
  ~0u,
  0,
  1,
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::Player, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Protocol::Player, actor_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Player, playertype_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Protocol::Pos)},
  { 7, 18, sizeof(::Protocol::Actor)},
  { 24, -1, sizeof(::Protocol::Player)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_Pos_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_Actor_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_Player_default_instance_),
};

const char descriptor_table_protodef_Struct_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014Struct.proto\022\010Protocol\032\nEnum.proto\"\033\n\003"
  "Pos\022\t\n\001x\030\001 \001(\002\022\t\n\001y\030\002 \001(\002\"\336\001\n\005Actor\022\n\n\002i"
  "d\030\001 \001(\004\022\014\n\004name\030\002 \001(\t\022!\n\004type\030\003 \001(\0162\023.Pr"
  "otocol.ActorType\022\037\n\010position\030\004 \001(\0132\r.Pro"
  "tocol.Pos\022-\n\nplayerType\030\005 \001(\0162\024.Protocol"
  ".PlayerTypeH\000\210\001\001\022+\n\tblockType\030\006 \001(\0162\023.Pr"
  "otocol.BlockTypeH\001\210\001\001B\r\n\013_playerTypeB\014\n\n"
  "_blockType\"R\n\006Player\022\036\n\005actor\030\001 \001(\0132\017.Pr"
  "otocol.Actor\022(\n\nplayerType\030\002 \001(\0162\024.Proto"
  "col.PlayerTypeb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_Struct_2eproto_deps[1] = {
  &::descriptor_table_Enum_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Struct_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Struct_2eproto = {
  false, false, 382, descriptor_table_protodef_Struct_2eproto, "Struct.proto", 
  &descriptor_table_Struct_2eproto_once, descriptor_table_Struct_2eproto_deps, 1, 3,
  schemas, file_default_instances, TableStruct_Struct_2eproto::offsets,
  file_level_metadata_Struct_2eproto, file_level_enum_descriptors_Struct_2eproto, file_level_service_descriptors_Struct_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Struct_2eproto_getter() {
  return &descriptor_table_Struct_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Struct_2eproto(&descriptor_table_Struct_2eproto);
namespace Protocol {

// ===================================================================

class Pos::_Internal {
 public:
};

Pos::Pos(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Protocol.Pos)
}
Pos::Pos(const Pos& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&x_, &from.x_,
    static_cast<size_t>(reinterpret_cast<char*>(&y_) -
    reinterpret_cast<char*>(&x_)) + sizeof(y_));
  // @@protoc_insertion_point(copy_constructor:Protocol.Pos)
}

void Pos::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&x_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&y_) -
    reinterpret_cast<char*>(&x_)) + sizeof(y_));
}

Pos::~Pos() {
  // @@protoc_insertion_point(destructor:Protocol.Pos)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Pos::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Pos::ArenaDtor(void* object) {
  Pos* _this = reinterpret_cast< Pos* >(object);
  (void)_this;
}
void Pos::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Pos::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Pos::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.Pos)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&y_) -
      reinterpret_cast<char*>(&x_)) + sizeof(y_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Pos::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // float x = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 13)) {
          x_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float y = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          y_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Pos::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.Pos)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // float x = 1;
  if (!(this->x() <= 0 && this->x() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1, this->_internal_x(), target);
  }

  // float y = 2;
  if (!(this->y() <= 0 && this->y() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_y(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.Pos)
  return target;
}

size_t Pos::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.Pos)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // float x = 1;
  if (!(this->x() <= 0 && this->x() >= 0)) {
    total_size += 1 + 4;
  }

  // float y = 2;
  if (!(this->y() <= 0 && this->y() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Pos::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Protocol.Pos)
  GOOGLE_DCHECK_NE(&from, this);
  const Pos* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Pos>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Protocol.Pos)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Protocol.Pos)
    MergeFrom(*source);
  }
}

void Pos::MergeFrom(const Pos& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.Pos)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from.x() <= 0 && from.x() >= 0)) {
    _internal_set_x(from._internal_x());
  }
  if (!(from.y() <= 0 && from.y() >= 0)) {
    _internal_set_y(from._internal_y());
  }
}

void Pos::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Protocol.Pos)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Pos::CopyFrom(const Pos& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.Pos)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Pos::IsInitialized() const {
  return true;
}

void Pos::InternalSwap(Pos* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Pos, y_)
      + sizeof(Pos::y_)
      - PROTOBUF_FIELD_OFFSET(Pos, x_)>(
          reinterpret_cast<char*>(&x_),
          reinterpret_cast<char*>(&other->x_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Pos::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Struct_2eproto_getter, &descriptor_table_Struct_2eproto_once,
      file_level_metadata_Struct_2eproto[0]);
}

// ===================================================================

class Actor::_Internal {
 public:
  using HasBits = decltype(std::declval<Actor>()._has_bits_);
  static const ::Protocol::Pos& position(const Actor* msg);
  static void set_has_playertype(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_blocktype(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

const ::Protocol::Pos&
Actor::_Internal::position(const Actor* msg) {
  return *msg->position_;
}
Actor::Actor(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Protocol.Actor)
}
Actor::Actor(const Actor& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArenaForAllocation());
  }
  if (from._internal_has_position()) {
    position_ = new ::Protocol::Pos(*from.position_);
  } else {
    position_ = nullptr;
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&blocktype_) -
    reinterpret_cast<char*>(&id_)) + sizeof(blocktype_));
  // @@protoc_insertion_point(copy_constructor:Protocol.Actor)
}

void Actor::SharedCtor() {
name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&position_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&blocktype_) -
    reinterpret_cast<char*>(&position_)) + sizeof(blocktype_));
}

Actor::~Actor() {
  // @@protoc_insertion_point(destructor:Protocol.Actor)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Actor::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete position_;
}

void Actor::ArenaDtor(void* object) {
  Actor* _this = reinterpret_cast< Actor* >(object);
  (void)_this;
}
void Actor::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Actor::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Actor::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.Actor)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && position_ != nullptr) {
    delete position_;
  }
  position_ = nullptr;
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&type_) -
      reinterpret_cast<char*>(&id_)) + sizeof(type_));
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    ::memset(&playertype_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&blocktype_) -
        reinterpret_cast<char*>(&playertype_)) + sizeof(blocktype_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Actor::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint64 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Protocol.Actor.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .Protocol.ActorType type = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_type(static_cast<::Protocol::ActorType>(val));
        } else goto handle_unusual;
        continue;
      // .Protocol.Pos position = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_position(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .Protocol.PlayerType playerType = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_playertype(static_cast<::Protocol::PlayerType>(val));
        } else goto handle_unusual;
        continue;
      // optional .Protocol.BlockType blockType = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_blocktype(static_cast<::Protocol::BlockType>(val));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Actor::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.Actor)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 id = 1;
  if (this->id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(1, this->_internal_id(), target);
  }

  // string name = 2;
  if (!this->name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.Actor.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  // .Protocol.ActorType type = 3;
  if (this->type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      3, this->_internal_type(), target);
  }

  // .Protocol.Pos position = 4;
  if (this->has_position()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        4, _Internal::position(this), target, stream);
  }

  // optional .Protocol.PlayerType playerType = 5;
  if (_internal_has_playertype()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      5, this->_internal_playertype(), target);
  }

  // optional .Protocol.BlockType blockType = 6;
  if (_internal_has_blocktype()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      6, this->_internal_blocktype(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.Actor)
  return target;
}

size_t Actor::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.Actor)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 2;
  if (!this->name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // .Protocol.Pos position = 4;
  if (this->has_position()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *position_);
  }

  // uint64 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_id());
  }

  // .Protocol.ActorType type = 3;
  if (this->type() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_type());
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional .Protocol.PlayerType playerType = 5;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_playertype());
    }

    // optional .Protocol.BlockType blockType = 6;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_blocktype());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Actor::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Protocol.Actor)
  GOOGLE_DCHECK_NE(&from, this);
  const Actor* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Actor>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Protocol.Actor)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Protocol.Actor)
    MergeFrom(*source);
  }
}

void Actor::MergeFrom(const Actor& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.Actor)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from.name().empty()) {
    _internal_set_name(from._internal_name());
  }
  if (from.has_position()) {
    _internal_mutable_position()->::Protocol::Pos::MergeFrom(from._internal_position());
  }
  if (from.id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.type() != 0) {
    _internal_set_type(from._internal_type());
  }
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      playertype_ = from.playertype_;
    }
    if (cached_has_bits & 0x00000002u) {
      blocktype_ = from.blocktype_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Actor::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Protocol.Actor)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Actor::CopyFrom(const Actor& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.Actor)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Actor::IsInitialized() const {
  return true;
}

void Actor::InternalSwap(Actor* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &name_, GetArenaForAllocation(),
      &other->name_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Actor, blocktype_)
      + sizeof(Actor::blocktype_)
      - PROTOBUF_FIELD_OFFSET(Actor, position_)>(
          reinterpret_cast<char*>(&position_),
          reinterpret_cast<char*>(&other->position_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Actor::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Struct_2eproto_getter, &descriptor_table_Struct_2eproto_once,
      file_level_metadata_Struct_2eproto[1]);
}

// ===================================================================

class Player::_Internal {
 public:
  static const ::Protocol::Actor& actor(const Player* msg);
};

const ::Protocol::Actor&
Player::_Internal::actor(const Player* msg) {
  return *msg->actor_;
}
Player::Player(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Protocol.Player)
}
Player::Player(const Player& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_actor()) {
    actor_ = new ::Protocol::Actor(*from.actor_);
  } else {
    actor_ = nullptr;
  }
  playertype_ = from.playertype_;
  // @@protoc_insertion_point(copy_constructor:Protocol.Player)
}

void Player::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&actor_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&playertype_) -
    reinterpret_cast<char*>(&actor_)) + sizeof(playertype_));
}

Player::~Player() {
  // @@protoc_insertion_point(destructor:Protocol.Player)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Player::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete actor_;
}

void Player::ArenaDtor(void* object) {
  Player* _this = reinterpret_cast< Player* >(object);
  (void)_this;
}
void Player::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Player::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Player::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.Player)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && actor_ != nullptr) {
    delete actor_;
  }
  actor_ = nullptr;
  playertype_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Player::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .Protocol.Actor actor = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_actor(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .Protocol.PlayerType playerType = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_playertype(static_cast<::Protocol::PlayerType>(val));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Player::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.Player)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .Protocol.Actor actor = 1;
  if (this->has_actor()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::actor(this), target, stream);
  }

  // .Protocol.PlayerType playerType = 2;
  if (this->playertype() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      2, this->_internal_playertype(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.Player)
  return target;
}

size_t Player::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.Player)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .Protocol.Actor actor = 1;
  if (this->has_actor()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *actor_);
  }

  // .Protocol.PlayerType playerType = 2;
  if (this->playertype() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_playertype());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Player::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Protocol.Player)
  GOOGLE_DCHECK_NE(&from, this);
  const Player* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Player>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Protocol.Player)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Protocol.Player)
    MergeFrom(*source);
  }
}

void Player::MergeFrom(const Player& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.Player)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_actor()) {
    _internal_mutable_actor()->::Protocol::Actor::MergeFrom(from._internal_actor());
  }
  if (from.playertype() != 0) {
    _internal_set_playertype(from._internal_playertype());
  }
}

void Player::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Protocol.Player)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Player::CopyFrom(const Player& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.Player)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Player::IsInitialized() const {
  return true;
}

void Player::InternalSwap(Player* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Player, playertype_)
      + sizeof(Player::playertype_)
      - PROTOBUF_FIELD_OFFSET(Player, actor_)>(
          reinterpret_cast<char*>(&actor_),
          reinterpret_cast<char*>(&other->actor_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Player::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Struct_2eproto_getter, &descriptor_table_Struct_2eproto_once,
      file_level_metadata_Struct_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::Pos* Arena::CreateMaybeMessage< ::Protocol::Pos >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::Pos >(arena);
}
template<> PROTOBUF_NOINLINE ::Protocol::Actor* Arena::CreateMaybeMessage< ::Protocol::Actor >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::Actor >(arena);
}
template<> PROTOBUF_NOINLINE ::Protocol::Player* Arena::CreateMaybeMessage< ::Protocol::Player >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::Player >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>