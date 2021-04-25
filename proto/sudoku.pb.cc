// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sudoku.proto

#include "sudoku.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace sudoku {
class SudokuDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Sudoku>
      _instance;
} _Sudoku_default_instance_;
}  // namespace sudoku
namespace protobuf_sudoku_2eproto {
static void InitDefaultsSudoku() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::sudoku::_Sudoku_default_instance_;
    new (ptr) ::sudoku::Sudoku();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::sudoku::Sudoku::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Sudoku =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsSudoku}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Sudoku.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::sudoku::Sudoku, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::sudoku::Sudoku, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::sudoku::Sudoku, nbempty_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::sudoku::Sudoku, values_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::sudoku::Sudoku, score_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::sudoku::Sudoku, level_),
  0,
  ~0u,
  1,
  2,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(::sudoku::Sudoku)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::sudoku::_Sudoku_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "sudoku.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\014sudoku.proto\022\006sudoku\"G\n\006Sudoku\022\017\n\007nbEm"
      "pty\030\001 \002(\005\022\016\n\006values\030\002 \003(\005\022\r\n\005score\030\003 \002(\005"
      "\022\r\n\005level\030\004 \002(\005"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 95);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "sudoku.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_sudoku_2eproto
namespace sudoku {

// ===================================================================

void Sudoku::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Sudoku::kNbEmptyFieldNumber;
const int Sudoku::kValuesFieldNumber;
const int Sudoku::kScoreFieldNumber;
const int Sudoku::kLevelFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Sudoku::Sudoku()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_sudoku_2eproto::scc_info_Sudoku.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:sudoku.Sudoku)
}
Sudoku::Sudoku(const Sudoku& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      values_(from.values_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&nbempty_, &from.nbempty_,
    static_cast<size_t>(reinterpret_cast<char*>(&level_) -
    reinterpret_cast<char*>(&nbempty_)) + sizeof(level_));
  // @@protoc_insertion_point(copy_constructor:sudoku.Sudoku)
}

void Sudoku::SharedCtor() {
  ::memset(&nbempty_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&level_) -
      reinterpret_cast<char*>(&nbempty_)) + sizeof(level_));
}

Sudoku::~Sudoku() {
  // @@protoc_insertion_point(destructor:sudoku.Sudoku)
  SharedDtor();
}

void Sudoku::SharedDtor() {
}

void Sudoku::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Sudoku::descriptor() {
  ::protobuf_sudoku_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_sudoku_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Sudoku& Sudoku::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_sudoku_2eproto::scc_info_Sudoku.base);
  return *internal_default_instance();
}


void Sudoku::Clear() {
// @@protoc_insertion_point(message_clear_start:sudoku.Sudoku)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  values_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 7u) {
    ::memset(&nbempty_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&level_) -
        reinterpret_cast<char*>(&nbempty_)) + sizeof(level_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool Sudoku::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:sudoku.Sudoku)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 nbEmpty = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_nbempty();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &nbempty_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated int32 values = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 16u, input, this->mutable_values())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_values())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int32 score = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_score();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &score_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int32 level = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          set_has_level();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &level_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:sudoku.Sudoku)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:sudoku.Sudoku)
  return false;
#undef DO_
}

void Sudoku::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:sudoku.Sudoku)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 nbEmpty = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->nbempty(), output);
  }

  // repeated int32 values = 2;
  for (int i = 0, n = this->values_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      2, this->values(i), output);
  }

  // required int32 score = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->score(), output);
  }

  // required int32 level = 4;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->level(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:sudoku.Sudoku)
}

::google::protobuf::uint8* Sudoku::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:sudoku.Sudoku)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 nbEmpty = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->nbempty(), target);
  }

  // repeated int32 values = 2;
  target = ::google::protobuf::internal::WireFormatLite::
    WriteInt32ToArray(2, this->values_, target);

  // required int32 score = 3;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->score(), target);
  }

  // required int32 level = 4;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->level(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:sudoku.Sudoku)
  return target;
}

size_t Sudoku::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:sudoku.Sudoku)
  size_t total_size = 0;

  if (has_nbempty()) {
    // required int32 nbEmpty = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->nbempty());
  }

  if (has_score()) {
    // required int32 score = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->score());
  }

  if (has_level()) {
    // required int32 level = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->level());
  }

  return total_size;
}
size_t Sudoku::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:sudoku.Sudoku)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required int32 nbEmpty = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->nbempty());

    // required int32 score = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->score());

    // required int32 level = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->level());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  // repeated int32 values = 2;
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      Int32Size(this->values_);
    total_size += 1 *
                  ::google::protobuf::internal::FromIntSize(this->values_size());
    total_size += data_size;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Sudoku::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:sudoku.Sudoku)
  GOOGLE_DCHECK_NE(&from, this);
  const Sudoku* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Sudoku>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:sudoku.Sudoku)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:sudoku.Sudoku)
    MergeFrom(*source);
  }
}

void Sudoku::MergeFrom(const Sudoku& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:sudoku.Sudoku)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  values_.MergeFrom(from.values_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      nbempty_ = from.nbempty_;
    }
    if (cached_has_bits & 0x00000002u) {
      score_ = from.score_;
    }
    if (cached_has_bits & 0x00000004u) {
      level_ = from.level_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Sudoku::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:sudoku.Sudoku)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Sudoku::CopyFrom(const Sudoku& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:sudoku.Sudoku)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Sudoku::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  return true;
}

void Sudoku::Swap(Sudoku* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Sudoku::InternalSwap(Sudoku* other) {
  using std::swap;
  values_.InternalSwap(&other->values_);
  swap(nbempty_, other->nbempty_);
  swap(score_, other->score_);
  swap(level_, other->level_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Sudoku::GetMetadata() const {
  protobuf_sudoku_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_sudoku_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace sudoku
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::sudoku::Sudoku* Arena::CreateMaybeMessage< ::sudoku::Sudoku >(Arena* arena) {
  return Arena::CreateInternal< ::sudoku::Sudoku >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
