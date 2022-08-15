// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file src/include/parser.h
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_SRC_INCLUDE_PARSER_H_INCLUDED
# define YY_YY_SRC_INCLUDE_PARSER_H_INCLUDED
// "%code requires" blocks.
#line 10 "src/parser/parser.yy"

#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <string>
#include "ast.h"	// our parse tree classes

class driver;
using namespace std;

#line 60 "src/include/parser.h"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 200 "src/include/parser.h"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // tok_inum
      char dummy1[sizeof (int)];

      // tok_identifier
      char dummy2[sizeof (std::string)];

      // expr
      char dummy3[sizeof (unique_ptr<ExprAST>)];

      // function_call
      char dummy4[sizeof (unique_ptr<FunctionCallAST>)];

      // function_type
      char dummy5[sizeof (unique_ptr<FunctionTypeAST>)];

      // module
      char dummy6[sizeof (unique_ptr<ModuleAST>)];

      // stmt
      char dummy7[sizeof (unique_ptr<StmtAST>)];

      // term
      char dummy8[sizeof (unique_ptr<TermAST>)];

      // type
      char dummy9[sizeof (unique_ptr<TypeAST>)];

      // variable_dec
      char dummy10[sizeof (unique_ptr<VarDecAST>)];

      // variable_def
      char dummy11[sizeof (unique_ptr<VarDefAST>)];

      // arg_list
      char dummy12[sizeof (vector<unique_ptr<ExprAST>>)];

      // stmts
      char dummy13[sizeof (vector<unique_ptr<StmtAST>>)];

      // variable_decs
      char dummy14[sizeof (vector<unique_ptr<VarDecAST>>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 1,                   // error
    YYUNDEF = 2,                   // "invalid token"
    tok_identifier = 3,            // tok_identifier
    tok_inum = 4,                  // tok_inum
    tok_eq = 5,                    // "="
    tok_minus = 6,                 // "-"
    tok_plus = 7,                  // "+"
    tok_lparen = 8,                // "("
    tok_rparen = 9,                // ")"
    tok_lcurly = 10,               // "{"
    tok_rcurly = 11,               // "}"
    tok_colon = 12,                // ":"
    tok_semi_colon = 13,           // ";"
    tok_coma = 14,                 // ","
    tok_arrow = 15,                // "->"
    tok_i128 = 16,                 // "i128"
    tok_i64 = 17,                  // "i64"
    tok_i32 = 18,                  // "i32"
    tok_i16 = 19,                  // "i16"
    tok_f128 = 20,                 // "f128"
    tok_f64 = 21,                  // "f64"
    tok_f32 = 22,                  // "f32"
    tok_f16 = 23                   // "f16"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 24, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_tok_identifier = 3,                    // tok_identifier
        S_tok_inum = 4,                          // tok_inum
        S_tok_eq = 5,                            // "="
        S_tok_minus = 6,                         // "-"
        S_tok_plus = 7,                          // "+"
        S_tok_lparen = 8,                        // "("
        S_tok_rparen = 9,                        // ")"
        S_tok_lcurly = 10,                       // "{"
        S_tok_rcurly = 11,                       // "}"
        S_tok_colon = 12,                        // ":"
        S_tok_semi_colon = 13,                   // ";"
        S_tok_coma = 14,                         // ","
        S_tok_arrow = 15,                        // "->"
        S_tok_i128 = 16,                         // "i128"
        S_tok_i64 = 17,                          // "i64"
        S_tok_i32 = 18,                          // "i32"
        S_tok_i16 = 19,                          // "i16"
        S_tok_f128 = 20,                         // "f128"
        S_tok_f64 = 21,                          // "f64"
        S_tok_f32 = 22,                          // "f32"
        S_tok_f16 = 23,                          // "f16"
        S_YYACCEPT = 24,                         // $accept
        S_module = 25,                           // module
        S_stmts = 26,                            // stmts
        S_stmt = 27,                             // stmt
        S_variable_def = 28,                     // variable_def
        S_variable_dec = 29,                     // variable_dec
        S_variable_decs = 30,                    // variable_decs
        S_type = 31,                             // type
        S_basic_type = 32,                       // basic_type
        S_function_type = 33,                    // function_type
        S_expr = 34,                             // expr
        S_term = 35,                             // term
        S_function_call = 36,                    // function_call
        S_arg_list = 37                          // arg_list
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_tok_inum: // tok_inum
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_tok_identifier: // tok_identifier
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< unique_ptr<ExprAST> > (std::move (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< unique_ptr<FunctionCallAST> > (std::move (that.value));
        break;

      case symbol_kind::S_function_type: // function_type
        value.move< unique_ptr<FunctionTypeAST> > (std::move (that.value));
        break;

      case symbol_kind::S_module: // module
        value.move< unique_ptr<ModuleAST> > (std::move (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< unique_ptr<StmtAST> > (std::move (that.value));
        break;

      case symbol_kind::S_term: // term
        value.move< unique_ptr<TermAST> > (std::move (that.value));
        break;

      case symbol_kind::S_type: // type
        value.move< unique_ptr<TypeAST> > (std::move (that.value));
        break;

      case symbol_kind::S_variable_dec: // variable_dec
        value.move< unique_ptr<VarDecAST> > (std::move (that.value));
        break;

      case symbol_kind::S_variable_def: // variable_def
        value.move< unique_ptr<VarDefAST> > (std::move (that.value));
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.move< vector<unique_ptr<ExprAST>> > (std::move (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< vector<unique_ptr<StmtAST>> > (std::move (that.value));
        break;

      case symbol_kind::S_variable_decs: // variable_decs
        value.move< vector<unique_ptr<VarDecAST>> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unique_ptr<ExprAST>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unique_ptr<ExprAST>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unique_ptr<FunctionCallAST>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unique_ptr<FunctionCallAST>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unique_ptr<FunctionTypeAST>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unique_ptr<FunctionTypeAST>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unique_ptr<ModuleAST>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unique_ptr<ModuleAST>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unique_ptr<StmtAST>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unique_ptr<StmtAST>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unique_ptr<TermAST>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unique_ptr<TermAST>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unique_ptr<TypeAST>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unique_ptr<TypeAST>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unique_ptr<VarDecAST>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unique_ptr<VarDecAST>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unique_ptr<VarDefAST>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unique_ptr<VarDefAST>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, vector<unique_ptr<ExprAST>>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const vector<unique_ptr<ExprAST>>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, vector<unique_ptr<StmtAST>>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const vector<unique_ptr<StmtAST>>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, vector<unique_ptr<VarDecAST>>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const vector<unique_ptr<VarDecAST>>& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_tok_inum: // tok_inum
        value.template destroy< int > ();
        break;

      case symbol_kind::S_tok_identifier: // tok_identifier
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_expr: // expr
        value.template destroy< unique_ptr<ExprAST> > ();
        break;

      case symbol_kind::S_function_call: // function_call
        value.template destroy< unique_ptr<FunctionCallAST> > ();
        break;

      case symbol_kind::S_function_type: // function_type
        value.template destroy< unique_ptr<FunctionTypeAST> > ();
        break;

      case symbol_kind::S_module: // module
        value.template destroy< unique_ptr<ModuleAST> > ();
        break;

      case symbol_kind::S_stmt: // stmt
        value.template destroy< unique_ptr<StmtAST> > ();
        break;

      case symbol_kind::S_term: // term
        value.template destroy< unique_ptr<TermAST> > ();
        break;

      case symbol_kind::S_type: // type
        value.template destroy< unique_ptr<TypeAST> > ();
        break;

      case symbol_kind::S_variable_dec: // variable_dec
        value.template destroy< unique_ptr<VarDecAST> > ();
        break;

      case symbol_kind::S_variable_def: // variable_def
        value.template destroy< unique_ptr<VarDefAST> > ();
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.template destroy< vector<unique_ptr<ExprAST>> > ();
        break;

      case symbol_kind::S_stmts: // stmts
        value.template destroy< vector<unique_ptr<StmtAST>> > ();
        break;

      case symbol_kind::S_variable_decs: // variable_decs
        value.template destroy< vector<unique_ptr<VarDecAST>> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::YYUNDEF)
                   || (token::tok_eq <= tok && tok <= token::tok_f16));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const int& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::tok_inum);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::tok_identifier);
#endif
      }
    };

    /// Build a parser object.
    parser (driver& drv_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_identifier (std::string v)
      {
        return symbol_type (token::tok_identifier, std::move (v));
      }
#else
      static
      symbol_type
      make_tok_identifier (const std::string& v)
      {
        return symbol_type (token::tok_identifier, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_inum (int v)
      {
        return symbol_type (token::tok_inum, std::move (v));
      }
#else
      static
      symbol_type
      make_tok_inum (const int& v)
      {
        return symbol_type (token::tok_inum, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_eq ()
      {
        return symbol_type (token::tok_eq);
      }
#else
      static
      symbol_type
      make_tok_eq ()
      {
        return symbol_type (token::tok_eq);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_minus ()
      {
        return symbol_type (token::tok_minus);
      }
#else
      static
      symbol_type
      make_tok_minus ()
      {
        return symbol_type (token::tok_minus);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_plus ()
      {
        return symbol_type (token::tok_plus);
      }
#else
      static
      symbol_type
      make_tok_plus ()
      {
        return symbol_type (token::tok_plus);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_lparen ()
      {
        return symbol_type (token::tok_lparen);
      }
#else
      static
      symbol_type
      make_tok_lparen ()
      {
        return symbol_type (token::tok_lparen);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_rparen ()
      {
        return symbol_type (token::tok_rparen);
      }
#else
      static
      symbol_type
      make_tok_rparen ()
      {
        return symbol_type (token::tok_rparen);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_lcurly ()
      {
        return symbol_type (token::tok_lcurly);
      }
#else
      static
      symbol_type
      make_tok_lcurly ()
      {
        return symbol_type (token::tok_lcurly);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_rcurly ()
      {
        return symbol_type (token::tok_rcurly);
      }
#else
      static
      symbol_type
      make_tok_rcurly ()
      {
        return symbol_type (token::tok_rcurly);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_colon ()
      {
        return symbol_type (token::tok_colon);
      }
#else
      static
      symbol_type
      make_tok_colon ()
      {
        return symbol_type (token::tok_colon);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_semi_colon ()
      {
        return symbol_type (token::tok_semi_colon);
      }
#else
      static
      symbol_type
      make_tok_semi_colon ()
      {
        return symbol_type (token::tok_semi_colon);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_coma ()
      {
        return symbol_type (token::tok_coma);
      }
#else
      static
      symbol_type
      make_tok_coma ()
      {
        return symbol_type (token::tok_coma);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_arrow ()
      {
        return symbol_type (token::tok_arrow);
      }
#else
      static
      symbol_type
      make_tok_arrow ()
      {
        return symbol_type (token::tok_arrow);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_i128 ()
      {
        return symbol_type (token::tok_i128);
      }
#else
      static
      symbol_type
      make_tok_i128 ()
      {
        return symbol_type (token::tok_i128);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_i64 ()
      {
        return symbol_type (token::tok_i64);
      }
#else
      static
      symbol_type
      make_tok_i64 ()
      {
        return symbol_type (token::tok_i64);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_i32 ()
      {
        return symbol_type (token::tok_i32);
      }
#else
      static
      symbol_type
      make_tok_i32 ()
      {
        return symbol_type (token::tok_i32);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_i16 ()
      {
        return symbol_type (token::tok_i16);
      }
#else
      static
      symbol_type
      make_tok_i16 ()
      {
        return symbol_type (token::tok_i16);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_f128 ()
      {
        return symbol_type (token::tok_f128);
      }
#else
      static
      symbol_type
      make_tok_f128 ()
      {
        return symbol_type (token::tok_f128);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_f64 ()
      {
        return symbol_type (token::tok_f64);
      }
#else
      static
      symbol_type
      make_tok_f64 ()
      {
        return symbol_type (token::tok_f64);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_f32 ()
      {
        return symbol_type (token::tok_f32);
      }
#else
      static
      symbol_type
      make_tok_f32 ()
      {
        return symbol_type (token::tok_f32);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tok_f16 ()
      {
        return symbol_type (token::tok_f16);
      }
#else
      static
      symbol_type
      make_tok_f16 ()
      {
        return symbol_type (token::tok_f16);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 53,     ///< Last index in yytable_.
      yynnts_ = 14,  ///< Number of nonterminal symbols.
      yyfinal_ = 15 ///< Termination state number.
    };


    // User arguments.
    driver& drv;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_tok_inum: // tok_inum
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tok_identifier: // tok_identifier
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.copy< unique_ptr<ExprAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.copy< unique_ptr<FunctionCallAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_type: // function_type
        value.copy< unique_ptr<FunctionTypeAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module: // module
        value.copy< unique_ptr<ModuleAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< unique_ptr<StmtAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_term: // term
        value.copy< unique_ptr<TermAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.copy< unique_ptr<TypeAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_dec: // variable_dec
        value.copy< unique_ptr<VarDecAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_def: // variable_def
        value.copy< unique_ptr<VarDefAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.copy< vector<unique_ptr<ExprAST>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.copy< vector<unique_ptr<StmtAST>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_decs: // variable_decs
        value.copy< vector<unique_ptr<VarDecAST>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_tok_inum: // tok_inum
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tok_identifier: // tok_identifier
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< unique_ptr<ExprAST> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< unique_ptr<FunctionCallAST> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_function_type: // function_type
        value.move< unique_ptr<FunctionTypeAST> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_module: // module
        value.move< unique_ptr<ModuleAST> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< unique_ptr<StmtAST> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_term: // term
        value.move< unique_ptr<TermAST> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type: // type
        value.move< unique_ptr<TypeAST> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_variable_dec: // variable_dec
        value.move< unique_ptr<VarDecAST> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_variable_def: // variable_def
        value.move< unique_ptr<VarDefAST> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.move< vector<unique_ptr<ExprAST>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< vector<unique_ptr<StmtAST>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_variable_decs: // variable_decs
        value.move< vector<unique_ptr<VarDecAST>> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 2016 "src/include/parser.h"




#endif // !YY_YY_SRC_INCLUDE_PARSER_H_INCLUDED
