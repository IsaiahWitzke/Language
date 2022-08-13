// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 1 "src/parser/my_parser.yy"

void yyerror(char *s);
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include <memory>

using namespace std;


#line 51 "src/parser/y.tab.cc"


#include "y.tab.h"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 128 "src/parser/y.tab.cc"


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      case 5: // tok_i128
      case 6: // tok_i64
      case 7: // tok_i32
      case 8: // tok_i16
      case 9: // tok_f128
      case 10: // tok_f64
      case 11: // tok_f32
      case 12: // tok_f16
      case 32: // basic_type
        value.move< Type::BasicType > (std::move (that.value));
        break;

      case 4: // tok_number
        value.move< int > (std::move (that.value));
        break;

      case 3: // tok_identifier
        value.move< string > (std::move (that.value));
        break;

      case 34: // expr
        value.move< unique_ptr<ExprAST> > (std::move (that.value));
        break;

      case 36: // function_call
        value.move< unique_ptr<FunctionCallAST> > (std::move (that.value));
        break;

      case 33: // function_type
        value.move< unique_ptr<FunctionTypeAST> > (std::move (that.value));
        break;

      case 25: // module
        value.move< unique_ptr<ModuleAST> > (std::move (that.value));
        break;

      case 27: // stmt
        value.move< unique_ptr<StmtAST> > (std::move (that.value));
        break;

      case 35: // term
        value.move< unique_ptr<TermAST> > (std::move (that.value));
        break;

      case 31: // type
        value.move< unique_ptr<TypeAST> > (std::move (that.value));
        break;

      case 29: // variable_dec
        value.move< unique_ptr<VarDecAST> > (std::move (that.value));
        break;

      case 28: // variable_def
        value.move< unique_ptr<VarDefAST> > (std::move (that.value));
        break;

      case 37: // arg_list
        value.move< vector<unique_ptr<ExprAST>> > (std::move (that.value));
        break;

      case 26: // stmts
        value.move< vector<unique_ptr<StmtAST>> > (std::move (that.value));
        break;

      case 30: // variable_decs
        value.move< vector<unique_ptr<VarDecAST>> > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      case 5: // tok_i128
      case 6: // tok_i64
      case 7: // tok_i32
      case 8: // tok_i16
      case 9: // tok_f128
      case 10: // tok_f64
      case 11: // tok_f32
      case 12: // tok_f16
      case 32: // basic_type
        value.copy< Type::BasicType > (YY_MOVE (that.value));
        break;

      case 4: // tok_number
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 3: // tok_identifier
        value.copy< string > (YY_MOVE (that.value));
        break;

      case 34: // expr
        value.copy< unique_ptr<ExprAST> > (YY_MOVE (that.value));
        break;

      case 36: // function_call
        value.copy< unique_ptr<FunctionCallAST> > (YY_MOVE (that.value));
        break;

      case 33: // function_type
        value.copy< unique_ptr<FunctionTypeAST> > (YY_MOVE (that.value));
        break;

      case 25: // module
        value.copy< unique_ptr<ModuleAST> > (YY_MOVE (that.value));
        break;

      case 27: // stmt
        value.copy< unique_ptr<StmtAST> > (YY_MOVE (that.value));
        break;

      case 35: // term
        value.copy< unique_ptr<TermAST> > (YY_MOVE (that.value));
        break;

      case 31: // type
        value.copy< unique_ptr<TypeAST> > (YY_MOVE (that.value));
        break;

      case 29: // variable_dec
        value.copy< unique_ptr<VarDecAST> > (YY_MOVE (that.value));
        break;

      case 28: // variable_def
        value.copy< unique_ptr<VarDefAST> > (YY_MOVE (that.value));
        break;

      case 37: // arg_list
        value.copy< vector<unique_ptr<ExprAST>> > (YY_MOVE (that.value));
        break;

      case 26: // stmts
        value.copy< vector<unique_ptr<StmtAST>> > (YY_MOVE (that.value));
        break;

      case 30: // variable_decs
        value.copy< vector<unique_ptr<VarDecAST>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 5: // tok_i128
      case 6: // tok_i64
      case 7: // tok_i32
      case 8: // tok_i16
      case 9: // tok_f128
      case 10: // tok_f64
      case 11: // tok_f32
      case 12: // tok_f16
      case 32: // basic_type
        value.move< Type::BasicType > (YY_MOVE (s.value));
        break;

      case 4: // tok_number
        value.move< int > (YY_MOVE (s.value));
        break;

      case 3: // tok_identifier
        value.move< string > (YY_MOVE (s.value));
        break;

      case 34: // expr
        value.move< unique_ptr<ExprAST> > (YY_MOVE (s.value));
        break;

      case 36: // function_call
        value.move< unique_ptr<FunctionCallAST> > (YY_MOVE (s.value));
        break;

      case 33: // function_type
        value.move< unique_ptr<FunctionTypeAST> > (YY_MOVE (s.value));
        break;

      case 25: // module
        value.move< unique_ptr<ModuleAST> > (YY_MOVE (s.value));
        break;

      case 27: // stmt
        value.move< unique_ptr<StmtAST> > (YY_MOVE (s.value));
        break;

      case 35: // term
        value.move< unique_ptr<TermAST> > (YY_MOVE (s.value));
        break;

      case 31: // type
        value.move< unique_ptr<TypeAST> > (YY_MOVE (s.value));
        break;

      case 29: // variable_dec
        value.move< unique_ptr<VarDecAST> > (YY_MOVE (s.value));
        break;

      case 28: // variable_def
        value.move< unique_ptr<VarDefAST> > (YY_MOVE (s.value));
        break;

      case 37: // arg_list
        value.move< vector<unique_ptr<ExprAST>> > (YY_MOVE (s.value));
        break;

      case 26: // stmts
        value.move< vector<unique_ptr<StmtAST>> > (YY_MOVE (s.value));
        break;

      case 30: // variable_decs
        value.move< vector<unique_ptr<VarDecAST>> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 5: // tok_i128
      case 6: // tok_i64
      case 7: // tok_i32
      case 8: // tok_i16
      case 9: // tok_f128
      case 10: // tok_f64
      case 11: // tok_f32
      case 12: // tok_f16
      case 32: // basic_type
        value.YY_MOVE_OR_COPY< Type::BasicType > (YY_MOVE (that.value));
        break;

      case 4: // tok_number
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 3: // tok_identifier
        value.YY_MOVE_OR_COPY< string > (YY_MOVE (that.value));
        break;

      case 34: // expr
        value.YY_MOVE_OR_COPY< unique_ptr<ExprAST> > (YY_MOVE (that.value));
        break;

      case 36: // function_call
        value.YY_MOVE_OR_COPY< unique_ptr<FunctionCallAST> > (YY_MOVE (that.value));
        break;

      case 33: // function_type
        value.YY_MOVE_OR_COPY< unique_ptr<FunctionTypeAST> > (YY_MOVE (that.value));
        break;

      case 25: // module
        value.YY_MOVE_OR_COPY< unique_ptr<ModuleAST> > (YY_MOVE (that.value));
        break;

      case 27: // stmt
        value.YY_MOVE_OR_COPY< unique_ptr<StmtAST> > (YY_MOVE (that.value));
        break;

      case 35: // term
        value.YY_MOVE_OR_COPY< unique_ptr<TermAST> > (YY_MOVE (that.value));
        break;

      case 31: // type
        value.YY_MOVE_OR_COPY< unique_ptr<TypeAST> > (YY_MOVE (that.value));
        break;

      case 29: // variable_dec
        value.YY_MOVE_OR_COPY< unique_ptr<VarDecAST> > (YY_MOVE (that.value));
        break;

      case 28: // variable_def
        value.YY_MOVE_OR_COPY< unique_ptr<VarDefAST> > (YY_MOVE (that.value));
        break;

      case 37: // arg_list
        value.YY_MOVE_OR_COPY< vector<unique_ptr<ExprAST>> > (YY_MOVE (that.value));
        break;

      case 26: // stmts
        value.YY_MOVE_OR_COPY< vector<unique_ptr<StmtAST>> > (YY_MOVE (that.value));
        break;

      case 30: // variable_decs
        value.YY_MOVE_OR_COPY< vector<unique_ptr<VarDecAST>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 5: // tok_i128
      case 6: // tok_i64
      case 7: // tok_i32
      case 8: // tok_i16
      case 9: // tok_f128
      case 10: // tok_f64
      case 11: // tok_f32
      case 12: // tok_f16
      case 32: // basic_type
        value.move< Type::BasicType > (YY_MOVE (that.value));
        break;

      case 4: // tok_number
        value.move< int > (YY_MOVE (that.value));
        break;

      case 3: // tok_identifier
        value.move< string > (YY_MOVE (that.value));
        break;

      case 34: // expr
        value.move< unique_ptr<ExprAST> > (YY_MOVE (that.value));
        break;

      case 36: // function_call
        value.move< unique_ptr<FunctionCallAST> > (YY_MOVE (that.value));
        break;

      case 33: // function_type
        value.move< unique_ptr<FunctionTypeAST> > (YY_MOVE (that.value));
        break;

      case 25: // module
        value.move< unique_ptr<ModuleAST> > (YY_MOVE (that.value));
        break;

      case 27: // stmt
        value.move< unique_ptr<StmtAST> > (YY_MOVE (that.value));
        break;

      case 35: // term
        value.move< unique_ptr<TermAST> > (YY_MOVE (that.value));
        break;

      case 31: // type
        value.move< unique_ptr<TypeAST> > (YY_MOVE (that.value));
        break;

      case 29: // variable_dec
        value.move< unique_ptr<VarDecAST> > (YY_MOVE (that.value));
        break;

      case 28: // variable_def
        value.move< unique_ptr<VarDefAST> > (YY_MOVE (that.value));
        break;

      case 37: // arg_list
        value.move< vector<unique_ptr<ExprAST>> > (YY_MOVE (that.value));
        break;

      case 26: // stmts
        value.move< vector<unique_ptr<StmtAST>> > (YY_MOVE (that.value));
        break;

      case 30: // variable_decs
        value.move< vector<unique_ptr<VarDecAST>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 5: // tok_i128
      case 6: // tok_i64
      case 7: // tok_i32
      case 8: // tok_i16
      case 9: // tok_f128
      case 10: // tok_f64
      case 11: // tok_f32
      case 12: // tok_f16
      case 32: // basic_type
        value.copy< Type::BasicType > (that.value);
        break;

      case 4: // tok_number
        value.copy< int > (that.value);
        break;

      case 3: // tok_identifier
        value.copy< string > (that.value);
        break;

      case 34: // expr
        value.copy< unique_ptr<ExprAST> > (that.value);
        break;

      case 36: // function_call
        value.copy< unique_ptr<FunctionCallAST> > (that.value);
        break;

      case 33: // function_type
        value.copy< unique_ptr<FunctionTypeAST> > (that.value);
        break;

      case 25: // module
        value.copy< unique_ptr<ModuleAST> > (that.value);
        break;

      case 27: // stmt
        value.copy< unique_ptr<StmtAST> > (that.value);
        break;

      case 35: // term
        value.copy< unique_ptr<TermAST> > (that.value);
        break;

      case 31: // type
        value.copy< unique_ptr<TypeAST> > (that.value);
        break;

      case 29: // variable_dec
        value.copy< unique_ptr<VarDecAST> > (that.value);
        break;

      case 28: // variable_def
        value.copy< unique_ptr<VarDefAST> > (that.value);
        break;

      case 37: // arg_list
        value.copy< vector<unique_ptr<ExprAST>> > (that.value);
        break;

      case 26: // stmts
        value.copy< vector<unique_ptr<StmtAST>> > (that.value);
        break;

      case 30: // variable_decs
        value.copy< vector<unique_ptr<VarDecAST>> > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 5: // tok_i128
      case 6: // tok_i64
      case 7: // tok_i32
      case 8: // tok_i16
      case 9: // tok_f128
      case 10: // tok_f64
      case 11: // tok_f32
      case 12: // tok_f16
      case 32: // basic_type
        value.move< Type::BasicType > (that.value);
        break;

      case 4: // tok_number
        value.move< int > (that.value);
        break;

      case 3: // tok_identifier
        value.move< string > (that.value);
        break;

      case 34: // expr
        value.move< unique_ptr<ExprAST> > (that.value);
        break;

      case 36: // function_call
        value.move< unique_ptr<FunctionCallAST> > (that.value);
        break;

      case 33: // function_type
        value.move< unique_ptr<FunctionTypeAST> > (that.value);
        break;

      case 25: // module
        value.move< unique_ptr<ModuleAST> > (that.value);
        break;

      case 27: // stmt
        value.move< unique_ptr<StmtAST> > (that.value);
        break;

      case 35: // term
        value.move< unique_ptr<TermAST> > (that.value);
        break;

      case 31: // type
        value.move< unique_ptr<TypeAST> > (that.value);
        break;

      case 29: // variable_dec
        value.move< unique_ptr<VarDecAST> > (that.value);
        break;

      case 28: // variable_def
        value.move< unique_ptr<VarDefAST> > (that.value);
        break;

      case 37: // arg_list
        value.move< vector<unique_ptr<ExprAST>> > (that.value);
        break;

      case 26: // stmts
        value.move< vector<unique_ptr<StmtAST>> > (that.value);
        break;

      case 30: // variable_decs
        value.move< vector<unique_ptr<VarDecAST>> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 5: // tok_i128
      case 6: // tok_i64
      case 7: // tok_i32
      case 8: // tok_i16
      case 9: // tok_f128
      case 10: // tok_f64
      case 11: // tok_f32
      case 12: // tok_f16
      case 32: // basic_type
        yylhs.value.emplace< Type::BasicType > ();
        break;

      case 4: // tok_number
        yylhs.value.emplace< int > ();
        break;

      case 3: // tok_identifier
        yylhs.value.emplace< string > ();
        break;

      case 34: // expr
        yylhs.value.emplace< unique_ptr<ExprAST> > ();
        break;

      case 36: // function_call
        yylhs.value.emplace< unique_ptr<FunctionCallAST> > ();
        break;

      case 33: // function_type
        yylhs.value.emplace< unique_ptr<FunctionTypeAST> > ();
        break;

      case 25: // module
        yylhs.value.emplace< unique_ptr<ModuleAST> > ();
        break;

      case 27: // stmt
        yylhs.value.emplace< unique_ptr<StmtAST> > ();
        break;

      case 35: // term
        yylhs.value.emplace< unique_ptr<TermAST> > ();
        break;

      case 31: // type
        yylhs.value.emplace< unique_ptr<TypeAST> > ();
        break;

      case 29: // variable_dec
        yylhs.value.emplace< unique_ptr<VarDecAST> > ();
        break;

      case 28: // variable_def
        yylhs.value.emplace< unique_ptr<VarDefAST> > ();
        break;

      case 37: // arg_list
        yylhs.value.emplace< vector<unique_ptr<ExprAST>> > ();
        break;

      case 26: // stmts
        yylhs.value.emplace< vector<unique_ptr<StmtAST>> > ();
        break;

      case 30: // variable_decs
        yylhs.value.emplace< vector<unique_ptr<VarDecAST>> > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 41 "src/parser/my_parser.yy"
                {yylhs.value.as < unique_ptr<ModuleAST> > () = make_unique<ModuleAST>("test", move(yystack_[0].value.as < vector<unique_ptr<StmtAST>> > ()))}
#line 1134 "src/parser/y.tab.cc"
    break;

  case 3:
#line 44 "src/parser/my_parser.yy"
               {
			yylhs.value.as < vector<unique_ptr<StmtAST>> > () = vector<uniqe_ptr<StmtAST>>(move(yystack_[0].value.as < unique_ptr<StmtAST> > ()));
		}
#line 1142 "src/parser/y.tab.cc"
    break;

  case 4:
#line 47 "src/parser/my_parser.yy"
                             {
			yystack_[1].value.as < vector<unique_ptr<StmtAST>> > ()->push_back(move(yystack_[0].value.as < unique_ptr<StmtAST> > ()));
			yylhs.value.as < vector<unique_ptr<StmtAST>> > () = yystack_[1].value.as < vector<unique_ptr<StmtAST>> > ()
		}
#line 1151 "src/parser/y.tab.cc"
    break;

  case 5:
#line 53 "src/parser/my_parser.yy"
               { yylhs.value.as < unique_ptr<StmtAST> > () = make_unique<StmtAST>(move(yystack_[0].value.as < unique_ptr<ExprAST> > ()), nullptr, nullptr); }
#line 1157 "src/parser/y.tab.cc"
    break;

  case 6:
#line 54 "src/parser/my_parser.yy"
                                        { yylhs.value.as < unique_ptr<StmtAST> > () = make_unique<StmtAST>(nullptr, move(yystack_[1].value.as < unique_ptr<VarDecAST> > ()), nullptr); }
#line 1163 "src/parser/y.tab.cc"
    break;

  case 7:
#line 55 "src/parser/my_parser.yy"
                                        { yylhs.value.as < unique_ptr<StmtAST> > () = make_unique<StmtAST>(nullptr, nullptr, move(yystack_[1].value.as < unique_ptr<VarDefAST> > ())); }
#line 1169 "src/parser/y.tab.cc"
    break;

  case 8:
#line 58 "src/parser/my_parser.yy"
                                                {
					yylhs.value.as < unique_ptr<VarDefAST> > () = make_unique<VarDefAST>(move(yystack_[3].value.as < unique_ptr<VarDecAST> > ()), move(yystack_[1].value.as < unique_ptr<ExprAST> > ()), nullptr);
				}
#line 1177 "src/parser/y.tab.cc"
    break;

  case 9:
#line 62 "src/parser/my_parser.yy"
                                                                 {
					yylhs.value.as < unique_ptr<VarDefAST> > () = make_unique<VarDefAST>(move(yystack_[4].value.as < unique_ptr<VarDecAST> > ()), nullptr, move(yystack_[1].value.as < vector<unique_ptr<StmtAST>> > ()));
				}
#line 1185 "src/parser/y.tab.cc"
    break;

  case 10:
#line 67 "src/parser/my_parser.yy"
                                                {yylhs.value.as < unique_ptr<VarDecAST> > () = make_unique<VarDecAST>(yystack_[2].value.as < string > (), move(yystack_[0].value.as < unique_ptr<TypeAST> > ()));}
#line 1191 "src/parser/y.tab.cc"
    break;

  case 11:
#line 70 "src/parser/my_parser.yy"
                               {
					yylhs.value.as < vector<unique_ptr<VarDecAST>> > () = make_unique<vector<uniqe_ptr<VarDecAST>>>(move(yystack_[0].value.as < unique_ptr<VarDecAST> > ()));
				}
#line 1199 "src/parser/y.tab.cc"
    break;

  case 12:
#line 73 "src/parser/my_parser.yy"
                                                                  {
					yystack_[2].value.as < vector<unique_ptr<VarDecAST>> > ()->push_back(move(yystack_[0].value.as < unique_ptr<VarDecAST> > ()));
					yylhs.value.as < vector<unique_ptr<VarDecAST>> > () = yystack_[0].value.as < unique_ptr<VarDecAST> > ();
				}
#line 1208 "src/parser/y.tab.cc"
    break;

  case 13:
#line 79 "src/parser/my_parser.yy"
                        { yylhs.value.as < unique_ptr<TypeAST> > () = make_unique<TypeAST>(yystack_[0].value.as < Type::BasicType > (), nullptr); }
#line 1214 "src/parser/y.tab.cc"
    break;

  case 14:
#line 80 "src/parser/my_parser.yy"
                                { yylhs.value.as < unique_ptr<TypeAST> > () = make_unique<TypeAST>(nullptr, move(yystack_[0].value.as < unique_ptr<FunctionTypeAST> > ())); }
#line 1220 "src/parser/y.tab.cc"
    break;

  case 15:
#line 84 "src/parser/my_parser.yy"
             { yylhs.value.as < Type::BasicType > () = yystack_[0].value.as < Type::BasicType > (); }
#line 1226 "src/parser/y.tab.cc"
    break;

  case 16:
#line 84 "src/parser/my_parser.yy"
                       { yylhs.value.as < Type::BasicType > () = yystack_[0].value.as < Type::BasicType > (); }
#line 1232 "src/parser/y.tab.cc"
    break;

  case 17:
#line 84 "src/parser/my_parser.yy"
                                 { yylhs.value.as < Type::BasicType > () = yystack_[0].value.as < Type::BasicType > (); }
#line 1238 "src/parser/y.tab.cc"
    break;

  case 18:
#line 84 "src/parser/my_parser.yy"
                                           { yylhs.value.as < Type::BasicType > () = yystack_[0].value.as < Type::BasicType > (); }
#line 1244 "src/parser/y.tab.cc"
    break;

  case 19:
#line 84 "src/parser/my_parser.yy"
                                                      { yylhs.value.as < Type::BasicType > () = yystack_[0].value.as < Type::BasicType > (); }
#line 1250 "src/parser/y.tab.cc"
    break;

  case 20:
#line 84 "src/parser/my_parser.yy"
                                                                { yylhs.value.as < Type::BasicType > () = yystack_[0].value.as < Type::BasicType > (); }
#line 1256 "src/parser/y.tab.cc"
    break;

  case 21:
#line 84 "src/parser/my_parser.yy"
                                                                          { yylhs.value.as < Type::BasicType > () = yystack_[0].value.as < Type::BasicType > (); }
#line 1262 "src/parser/y.tab.cc"
    break;

  case 22:
#line 84 "src/parser/my_parser.yy"
                                                                                    { yylhs.value.as < Type::BasicType > () = yystack_[0].value.as < Type::BasicType > (); }
#line 1268 "src/parser/y.tab.cc"
    break;

  case 23:
#line 87 "src/parser/my_parser.yy"
                                                       {
					yylhs.value.as < unique_ptr<FunctionTypeAST> > () = make_unique<FunctionTypeAST>(move(yystack_[3].value.as < vector<unique_ptr<VarDecAST>> > ()), move(yystack_[0].value.as < unique_ptr<TypeAST> > ()));
				}
#line 1276 "src/parser/y.tab.cc"
    break;

  case 24:
#line 92 "src/parser/my_parser.yy"
               {
			yylhs.value.as < unique_ptr<ExprAST> > () = make_unique<ExprAST>(move(yystack_[0].value.as < unique_ptr<TermAST> > ()), nullptr, nullptr, nullptr);
		}
#line 1284 "src/parser/y.tab.cc"
    break;

  case 25:
#line 95 "src/parser/my_parser.yy"
                                {
			yylhs.value.as < unique_ptr<ExprAST> > () = make_unique<ExprAST>(nullptr, move(yystack_[2].value.as < unique_ptr<ExprAST> > ()), '+', move(yystack_[0].value.as < unique_ptr<TermAST> > ()));
		}
#line 1292 "src/parser/y.tab.cc"
    break;

  case 26:
#line 98 "src/parser/my_parser.yy"
                                {
			yylhs.value.as < unique_ptr<ExprAST> > () = make_unique<ExprAST>(nullptr, move(yystack_[2].value.as < unique_ptr<ExprAST> > ()), '-', move(yystack_[0].value.as < unique_ptr<TermAST> > ()));
		}
#line 1300 "src/parser/y.tab.cc"
    break;

  case 27:
#line 101 "src/parser/my_parser.yy"
                               { yylhs.value.as < unique_ptr<ExprAST> > () = move(yystack_[1].value.as < unique_ptr<ExprAST> > ()); }
#line 1306 "src/parser/y.tab.cc"
    break;

  case 28:
#line 104 "src/parser/my_parser.yy"
                                { yylhs.value.as < unique_ptr<TermAST> > () = make_unique<TermAST>(yystack_[0].value.as < int > (), nullptr, nullptr); }
#line 1312 "src/parser/y.tab.cc"
    break;

  case 29:
#line 105 "src/parser/my_parser.yy"
                                        { yylhs.value.as < unique_ptr<TermAST> > () = make_unique<TermAST>(0, yystack_[0].value.as < string > (), nullptr); }
#line 1318 "src/parser/y.tab.cc"
    break;

  case 30:
#line 106 "src/parser/my_parser.yy"
                                        { yylhs.value.as < unique_ptr<TermAST> > () = make_unique<TermAST>(0, nullptr, move(yystack_[0].value.as < unique_ptr<FunctionCallAST> > ())); }
#line 1324 "src/parser/y.tab.cc"
    break;

  case 31:
#line 110 "src/parser/my_parser.yy"
                                        {
					yylhs.value.as < unique_ptr<FunctionCallAST> > () = make_unique<FunctionCallAST>(move(yystack_[3].value.as < unique_ptr<ExprAST> > ()), move(yystack_[1].value.as < vector<unique_ptr<ExprAST>> > ()));
				}
#line 1332 "src/parser/y.tab.cc"
    break;

  case 32:
#line 114 "src/parser/my_parser.yy"
                       {
				yylhs.value.as < vector<unique_ptr<ExprAST>> > () = vector<uniqe_ptr<ExprAST>>(move(yystack_[0].value.as < unique_ptr<ExprAST> > ()));
			}
#line 1340 "src/parser/y.tab.cc"
    break;

  case 33:
#line 117 "src/parser/my_parser.yy"
                                            {
				yystack_[2].value.as < vector<unique_ptr<ExprAST>> > ()->push_back(move(yystack_[2].value.as < vector<unique_ptr<ExprAST>> > ()));
				yylhs.value.as < vector<unique_ptr<ExprAST>> > () = yystack_[0].value.as < unique_ptr<ExprAST> > ();
			}
#line 1349 "src/parser/y.tab.cc"
    break;


#line 1353 "src/parser/y.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -30;

  const signed char parser::yytable_ninf_ = -25;

  const signed char
  parser::yypact_[] =
  {
       2,     7,   -30,     8,    14,     2,   -30,    13,   -11,    34,
     -30,   -30,    24,   -30,    30,   -30,   -30,   -30,   -30,     4,
       8,     8,     8,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,    35,   -30,   -30,   -30,   -30,     2,    26,    34,    -6,
      34,    38,    38,     7,   -30,    18,     6,   -30,     8,   -30,
      35,    28,   -30,    34,   -30,    24,   -30
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    29,    28,     0,     0,     2,     3,     0,     0,     5,
      24,    30,     0,    29,     0,     1,     4,     7,     6,     0,
       0,     0,     0,    18,    17,    16,    15,    22,    21,    20,
      19,     0,    10,    13,    14,    27,     0,     0,    32,     0,
       0,    25,    26,     0,    11,     0,     0,     8,     0,    31,
       0,     0,     9,    33,    12,     0,    23
  };

  const signed char
  parser::yypgoto_[] =
  {
     -30,   -30,    11,    -4,   -30,   -29,   -30,   -12,   -30,   -30,
      -3,    41,   -30,   -30
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,    45,    32,    33,    34,
       9,    10,    11,    39
  };

  const signed char
  parser::yytable_[] =
  {
      14,    16,    44,    18,    19,     1,     2,    13,     2,     1,
       2,    13,     2,    48,    15,    49,    37,    38,    40,    40,
      36,    54,     3,    52,     3,    12,     3,    17,     3,    23,
      24,    25,    26,    27,    28,    29,    30,    50,    43,    51,
      47,    55,    16,    56,    31,    53,    20,    46,    21,    22,
      20,    35,    21,    22,    20,     0,    21,    22,   -24,     0,
     -24,   -24,    41,    42
  };

  const signed char
  parser::yycheck_[] =
  {
       3,     5,    31,    14,    15,     3,     4,     3,     4,     3,
       4,     3,     4,    19,     0,    21,    19,    20,    21,    22,
      16,    50,    20,    17,    20,    18,    20,    14,    20,     5,
       6,     7,     8,     9,    10,    11,    12,    19,     3,    21,
      14,    13,    46,    55,    20,    48,    20,    36,    22,    23,
      20,    21,    22,    23,    20,    -1,    22,    23,    20,    -1,
      22,    23,    21,    22
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,    20,    25,    26,    27,    28,    29,    34,
      35,    36,    18,     3,    34,     0,    27,    14,    14,    15,
      20,    22,    23,     5,     6,     7,     8,     9,    10,    11,
      12,    20,    31,    32,    33,    21,    16,    34,    34,    37,
      34,    35,    35,     3,    29,    30,    26,    14,    19,    21,
      19,    21,    17,    34,    29,    13,    31
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    24,    25,    26,    26,    27,    27,    27,    28,    28,
      29,    30,    30,    31,    31,    32,    32,    32,    32,    32,
      32,    32,    32,    33,    34,    34,    34,    34,    35,    35,
      35,    36,    37,    37
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     2,     2,     4,     5,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     3,     3,     3,     1,     1,
       1,     4,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "tok_identifier", "tok_number",
  "tok_i128", "tok_i64", "tok_i32", "tok_i16", "tok_f128", "tok_f64",
  "tok_f32", "tok_f16", "tok_arrow", "';'", "'='", "'{'", "'}'", "':'",
  "','", "'('", "')'", "'+'", "'-'", "$accept", "module", "stmts", "stmt",
  "variable_def", "variable_dec", "variable_decs", "type", "basic_type",
  "function_type", "expr", "term", "function_call", "arg_list", YY_NULLPTR
  };


  const signed char
  parser::yyrline_[] =
  {
       0,    41,    41,    44,    47,    53,    54,    55,    58,    62,
      67,    70,    73,    79,    80,    84,    84,    84,    84,    84,
      84,    84,    84,    87,    92,    95,    98,   101,   104,   105,
     106,   110,   114,   117
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      20,    21,     2,    22,    19,    23,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    18,    14,
       2,    15,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    16,     2,    17,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13
    };
    const int user_token_number_max_ = 268;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

} // yy
#line 1725 "src/parser/y.tab.cc"

#line 122 "src/parser/my_parser.yy"


void yyerror (char *s) {
	fprintf (stderr, "%s\n", s);
}
