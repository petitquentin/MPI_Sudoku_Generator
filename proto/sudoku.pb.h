// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sudoku.proto

#ifndef PROTOBUF_INCLUDED_sudoku_2eproto
#define PROTOBUF_INCLUDED_sudoku_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_sudoku_2eproto 

namespace protobuf_sudoku_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_sudoku_2eproto
namespace sudoku {
class Sudoku;
class SudokuDefaultTypeInternal;
extern SudokuDefaultTypeInternal _Sudoku_default_instance_;
}  // namespace sudoku
namespace google {
namespace protobuf {
template<> ::sudoku::Sudoku* Arena::CreateMaybeMessage<::sudoku::Sudoku>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace sudoku {

// ===================================================================

class Sudoku : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sudoku.Sudoku) */ {
 public:
  Sudoku();
  virtual ~Sudoku();

  Sudoku(const Sudoku& from);

  inline Sudoku& operator=(const Sudoku& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Sudoku(Sudoku&& from) noexcept
    : Sudoku() {
    *this = ::std::move(from);
  }

  inline Sudoku& operator=(Sudoku&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Sudoku& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Sudoku* internal_default_instance() {
    return reinterpret_cast<const Sudoku*>(
               &_Sudoku_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Sudoku* other);
  friend void swap(Sudoku& a, Sudoku& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Sudoku* New() const final {
    return CreateMaybeMessage<Sudoku>(NULL);
  }

  Sudoku* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Sudoku>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Sudoku& from);
  void MergeFrom(const Sudoku& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Sudoku* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated int32 values = 2;
  int values_size() const;
  void clear_values();
  static const int kValuesFieldNumber = 2;
  ::google::protobuf::int32 values(int index) const;
  void set_values(int index, ::google::protobuf::int32 value);
  void add_values(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      values() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_values();

  // required int32 nbEmpty = 1;
  bool has_nbempty() const;
  void clear_nbempty();
  static const int kNbEmptyFieldNumber = 1;
  ::google::protobuf::int32 nbempty() const;
  void set_nbempty(::google::protobuf::int32 value);

  // required int32 score = 3;
  bool has_score() const;
  void clear_score();
  static const int kScoreFieldNumber = 3;
  ::google::protobuf::int32 score() const;
  void set_score(::google::protobuf::int32 value);

  // required int32 level = 4;
  bool has_level() const;
  void clear_level();
  static const int kLevelFieldNumber = 4;
  ::google::protobuf::int32 level() const;
  void set_level(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:sudoku.Sudoku)
 private:
  void set_has_nbempty();
  void clear_has_nbempty();
  void set_has_score();
  void clear_has_score();
  void set_has_level();
  void clear_has_level();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > values_;
  ::google::protobuf::int32 nbempty_;
  ::google::protobuf::int32 score_;
  ::google::protobuf::int32 level_;
  friend struct ::protobuf_sudoku_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Sudoku

// required int32 nbEmpty = 1;
inline bool Sudoku::has_nbempty() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Sudoku::set_has_nbempty() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Sudoku::clear_has_nbempty() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Sudoku::clear_nbempty() {
  nbempty_ = 0;
  clear_has_nbempty();
}
inline ::google::protobuf::int32 Sudoku::nbempty() const {
  // @@protoc_insertion_point(field_get:sudoku.Sudoku.nbEmpty)
  return nbempty_;
}
inline void Sudoku::set_nbempty(::google::protobuf::int32 value) {
  set_has_nbempty();
  nbempty_ = value;
  // @@protoc_insertion_point(field_set:sudoku.Sudoku.nbEmpty)
}

// repeated int32 values = 2;
inline int Sudoku::values_size() const {
  return values_.size();
}
inline void Sudoku::clear_values() {
  values_.Clear();
}
inline ::google::protobuf::int32 Sudoku::values(int index) const {
  // @@protoc_insertion_point(field_get:sudoku.Sudoku.values)
  return values_.Get(index);
}
inline void Sudoku::set_values(int index, ::google::protobuf::int32 value) {
  values_.Set(index, value);
  // @@protoc_insertion_point(field_set:sudoku.Sudoku.values)
}
inline void Sudoku::add_values(::google::protobuf::int32 value) {
  values_.Add(value);
  // @@protoc_insertion_point(field_add:sudoku.Sudoku.values)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
Sudoku::values() const {
  // @@protoc_insertion_point(field_list:sudoku.Sudoku.values)
  return values_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
Sudoku::mutable_values() {
  // @@protoc_insertion_point(field_mutable_list:sudoku.Sudoku.values)
  return &values_;
}

// required int32 score = 3;
inline bool Sudoku::has_score() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Sudoku::set_has_score() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Sudoku::clear_has_score() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Sudoku::clear_score() {
  score_ = 0;
  clear_has_score();
}
inline ::google::protobuf::int32 Sudoku::score() const {
  // @@protoc_insertion_point(field_get:sudoku.Sudoku.score)
  return score_;
}
inline void Sudoku::set_score(::google::protobuf::int32 value) {
  set_has_score();
  score_ = value;
  // @@protoc_insertion_point(field_set:sudoku.Sudoku.score)
}

// required int32 level = 4;
inline bool Sudoku::has_level() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Sudoku::set_has_level() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Sudoku::clear_has_level() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Sudoku::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 Sudoku::level() const {
  // @@protoc_insertion_point(field_get:sudoku.Sudoku.level)
  return level_;
}
inline void Sudoku::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
  // @@protoc_insertion_point(field_set:sudoku.Sudoku.level)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace sudoku

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_sudoku_2eproto
