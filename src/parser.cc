// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.h"


// Unqualified %code blocks.
#line 31 "src/parser/parser.yy"

#include "parser_driver.h"

#line 50 "src/parser.cc"


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
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
#line 123 "src/parser.cc"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



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

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_tok_number: // tok_number
      case symbol_kind::S_tok_i128: // tok_i128
      case symbol_kind::S_tok_i64: // tok_i64
      case symbol_kind::S_tok_i32: // tok_i32
      case symbol_kind::S_tok_i16: // tok_i16
      case symbol_kind::S_tok_f128: // tok_f128
      case symbol_kind::S_tok_f64: // tok_f64
      case symbol_kind::S_tok_f32: // tok_f32
      case symbol_kind::S_tok_f16: // tok_f16
      case symbol_kind::S_basic_type: // basic_type
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tok_identifier: // tok_identifier
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< unique_ptr<ExprAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.YY_MOVE_OR_COPY< unique_ptr<FunctionCallAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_type: // function_type
        value.YY_MOVE_OR_COPY< unique_ptr<FunctionTypeAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module: // module
        value.YY_MOVE_OR_COPY< unique_ptr<ModuleAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.YY_MOVE_OR_COPY< unique_ptr<StmtAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_term: // term
        value.YY_MOVE_OR_COPY< unique_ptr<TermAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< unique_ptr<TypeAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_dec: // variable_dec
        value.YY_MOVE_OR_COPY< unique_ptr<VarDecAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_def: // variable_def
        value.YY_MOVE_OR_COPY< unique_ptr<VarDefAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.YY_MOVE_OR_COPY< vector<unique_ptr<ExprAST>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.YY_MOVE_OR_COPY< vector<unique_ptr<StmtAST>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_decs: // variable_decs
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
    switch (that.kind ())
    {
      case symbol_kind::S_tok_number: // tok_number
      case symbol_kind::S_tok_i128: // tok_i128
      case symbol_kind::S_tok_i64: // tok_i64
      case symbol_kind::S_tok_i32: // tok_i32
      case symbol_kind::S_tok_i16: // tok_i16
      case symbol_kind::S_tok_f128: // tok_f128
      case symbol_kind::S_tok_f64: // tok_f64
      case symbol_kind::S_tok_f32: // tok_f32
      case symbol_kind::S_tok_f16: // tok_f16
      case symbol_kind::S_basic_type: // basic_type
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tok_identifier: // tok_identifier
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< unique_ptr<ExprAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< unique_ptr<FunctionCallAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_type: // function_type
        value.move< unique_ptr<FunctionTypeAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module: // module
        value.move< unique_ptr<ModuleAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< unique_ptr<StmtAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_term: // term
        value.move< unique_ptr<TermAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.move< unique_ptr<TypeAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_dec: // variable_dec
        value.move< unique_ptr<VarDecAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_def: // variable_def
        value.move< unique_ptr<VarDefAST> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.move< vector<unique_ptr<ExprAST>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< vector<unique_ptr<StmtAST>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_decs: // variable_decs
        value.move< vector<unique_ptr<VarDecAST>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_tok_number: // tok_number
      case symbol_kind::S_tok_i128: // tok_i128
      case symbol_kind::S_tok_i64: // tok_i64
      case symbol_kind::S_tok_i32: // tok_i32
      case symbol_kind::S_tok_i16: // tok_i16
      case symbol_kind::S_tok_f128: // tok_f128
      case symbol_kind::S_tok_f64: // tok_f64
      case symbol_kind::S_tok_f32: // tok_f32
      case symbol_kind::S_tok_f16: // tok_f16
      case symbol_kind::S_basic_type: // basic_type
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_tok_identifier: // tok_identifier
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.copy< unique_ptr<ExprAST> > (that.value);
        break;

      case symbol_kind::S_function_call: // function_call
        value.copy< unique_ptr<FunctionCallAST> > (that.value);
        break;

      case symbol_kind::S_function_type: // function_type
        value.copy< unique_ptr<FunctionTypeAST> > (that.value);
        break;

      case symbol_kind::S_module: // module
        value.copy< unique_ptr<ModuleAST> > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< unique_ptr<StmtAST> > (that.value);
        break;

      case symbol_kind::S_term: // term
        value.copy< unique_ptr<TermAST> > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.copy< unique_ptr<TypeAST> > (that.value);
        break;

      case symbol_kind::S_variable_dec: // variable_dec
        value.copy< unique_ptr<VarDecAST> > (that.value);
        break;

      case symbol_kind::S_variable_def: // variable_def
        value.copy< unique_ptr<VarDefAST> > (that.value);
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.copy< vector<unique_ptr<ExprAST>> > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
        value.copy< vector<unique_ptr<StmtAST>> > (that.value);
        break;

      case symbol_kind::S_variable_decs: // variable_decs
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
    switch (that.kind ())
    {
      case symbol_kind::S_tok_number: // tok_number
      case symbol_kind::S_tok_i128: // tok_i128
      case symbol_kind::S_tok_i64: // tok_i64
      case symbol_kind::S_tok_i32: // tok_i32
      case symbol_kind::S_tok_i16: // tok_i16
      case symbol_kind::S_tok_f128: // tok_f128
      case symbol_kind::S_tok_f64: // tok_f64
      case symbol_kind::S_tok_f32: // tok_f32
      case symbol_kind::S_tok_f16: // tok_f16
      case symbol_kind::S_basic_type: // basic_type
        value.move< int > (that.value);
        break;

      case symbol_kind::S_tok_identifier: // tok_identifier
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.move< unique_ptr<ExprAST> > (that.value);
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< unique_ptr<FunctionCallAST> > (that.value);
        break;

      case symbol_kind::S_function_type: // function_type
        value.move< unique_ptr<FunctionTypeAST> > (that.value);
        break;

      case symbol_kind::S_module: // module
        value.move< unique_ptr<ModuleAST> > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< unique_ptr<StmtAST> > (that.value);
        break;

      case symbol_kind::S_term: // term
        value.move< unique_ptr<TermAST> > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.move< unique_ptr<TypeAST> > (that.value);
        break;

      case symbol_kind::S_variable_dec: // variable_dec
        value.move< unique_ptr<VarDecAST> > (that.value);
        break;

      case symbol_kind::S_variable_def: // variable_def
        value.move< unique_ptr<VarDefAST> > (that.value);
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.move< vector<unique_ptr<ExprAST>> > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< vector<unique_ptr<StmtAST>> > (that.value);
        break;

      case symbol_kind::S_variable_decs: // variable_decs
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
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
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
  parser::yypop_ (int n) YY_NOEXCEPT
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
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
      case symbol_kind::S_tok_number: // tok_number
      case symbol_kind::S_tok_i128: // tok_i128
      case symbol_kind::S_tok_i64: // tok_i64
      case symbol_kind::S_tok_i32: // tok_i32
      case symbol_kind::S_tok_i16: // tok_i16
      case symbol_kind::S_tok_f128: // tok_f128
      case symbol_kind::S_tok_f64: // tok_f64
      case symbol_kind::S_tok_f32: // tok_f32
      case symbol_kind::S_tok_f16: // tok_f16
      case symbol_kind::S_basic_type: // basic_type
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_tok_identifier: // tok_identifier
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< unique_ptr<ExprAST> > ();
        break;

      case symbol_kind::S_function_call: // function_call
        yylhs.value.emplace< unique_ptr<FunctionCallAST> > ();
        break;

      case symbol_kind::S_function_type: // function_type
        yylhs.value.emplace< unique_ptr<FunctionTypeAST> > ();
        break;

      case symbol_kind::S_module: // module
        yylhs.value.emplace< unique_ptr<ModuleAST> > ();
        break;

      case symbol_kind::S_stmt: // stmt
        yylhs.value.emplace< unique_ptr<StmtAST> > ();
        break;

      case symbol_kind::S_term: // term
        yylhs.value.emplace< unique_ptr<TermAST> > ();
        break;

      case symbol_kind::S_type: // type
        yylhs.value.emplace< unique_ptr<TypeAST> > ();
        break;

      case symbol_kind::S_variable_dec: // variable_dec
        yylhs.value.emplace< unique_ptr<VarDecAST> > ();
        break;

      case symbol_kind::S_variable_def: // variable_def
        yylhs.value.emplace< unique_ptr<VarDefAST> > ();
        break;

      case symbol_kind::S_arg_list: // arg_list
        yylhs.value.emplace< vector<unique_ptr<ExprAST>> > ();
        break;

      case symbol_kind::S_stmts: // stmts
        yylhs.value.emplace< vector<unique_ptr<StmtAST>> > ();
        break;

      case symbol_kind::S_variable_decs: // variable_decs
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
  case 2: // module: stmts
#line 72 "src/parser/parser.yy"
                {yylhs.value.as < unique_ptr<ModuleAST> > () = make_unique<ModuleAST>("test", move(yystack_[0].value.as < vector<unique_ptr<StmtAST>> > ()));}
#line 830 "src/parser.cc"
    break;

  case 3: // stmts: stmt
#line 75 "src/parser/parser.yy"
               {
			yylhs.value.as < vector<unique_ptr<StmtAST>> > () = vector<unique_ptr<StmtAST>>();
			yylhs.value.as < vector<unique_ptr<StmtAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<StmtAST> > ()));
		}
#line 839 "src/parser.cc"
    break;

  case 4: // stmts: stmts stmt
#line 79 "src/parser/parser.yy"
                             {
			yystack_[1].value.as < vector<unique_ptr<StmtAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<StmtAST> > ()));
			yylhs.value.as < vector<unique_ptr<StmtAST>> > () = move(yystack_[1].value.as < vector<unique_ptr<StmtAST>> > ());
		}
#line 848 "src/parser.cc"
    break;

  case 5: // stmt: expr
#line 85 "src/parser/parser.yy"
               { yylhs.value.as < unique_ptr<StmtAST> > () = make_unique<StmtAST>(move(yystack_[0].value.as < unique_ptr<ExprAST> > ()), nullptr, nullptr); }
#line 854 "src/parser.cc"
    break;

  case 6: // stmt: variable_dec ";"
#line 86 "src/parser/parser.yy"
                                                { yylhs.value.as < unique_ptr<StmtAST> > () = make_unique<StmtAST>(nullptr, move(yystack_[1].value.as < unique_ptr<VarDecAST> > ()), nullptr); }
#line 860 "src/parser.cc"
    break;

  case 7: // stmt: variable_def ";"
#line 87 "src/parser/parser.yy"
                                                { yylhs.value.as < unique_ptr<StmtAST> > () = make_unique<StmtAST>(nullptr, nullptr, move(yystack_[1].value.as < unique_ptr<VarDefAST> > ())); }
#line 866 "src/parser.cc"
    break;

  case 8: // variable_def: variable_dec "=" expr ";"
#line 90 "src/parser/parser.yy"
                                                        {
					yylhs.value.as < unique_ptr<VarDefAST> > () = make_unique<VarDefAST>(move(yystack_[3].value.as < unique_ptr<VarDecAST> > ()), move(yystack_[1].value.as < unique_ptr<ExprAST> > ()), vector<unique_ptr<StmtAST>>());
				}
#line 874 "src/parser.cc"
    break;

  case 9: // variable_def: variable_dec "=" "{" stmts "}"
#line 94 "src/parser/parser.yy"
                                                                                  {
					yylhs.value.as < unique_ptr<VarDefAST> > () = make_unique<VarDefAST>(move(yystack_[4].value.as < unique_ptr<VarDecAST> > ()), unique_ptr<ExprAST>(nullptr), move(yystack_[1].value.as < vector<unique_ptr<StmtAST>> > ()));
				}
#line 882 "src/parser.cc"
    break;

  case 10: // variable_dec: tok_identifier ":" type
#line 99 "src/parser/parser.yy"
                                                {yylhs.value.as < unique_ptr<VarDecAST> > () = make_unique<VarDecAST>(yystack_[2].value.as < std::string > (), move(yystack_[0].value.as < unique_ptr<TypeAST> > ()));}
#line 888 "src/parser.cc"
    break;

  case 11: // variable_decs: variable_dec
#line 102 "src/parser/parser.yy"
                               {
					yylhs.value.as < vector<unique_ptr<VarDecAST>> > () = vector<unique_ptr<VarDecAST>>();
					yylhs.value.as < vector<unique_ptr<VarDecAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<VarDecAST> > ()));
				}
#line 897 "src/parser.cc"
    break;

  case 12: // variable_decs: variable_decs "," variable_dec
#line 106 "src/parser/parser.yy"
                                                                       {
					yystack_[2].value.as < vector<unique_ptr<VarDecAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<VarDecAST> > ()));
				}
#line 905 "src/parser.cc"
    break;

  case 13: // type: basic_type
#line 111 "src/parser/parser.yy"
                        { yylhs.value.as < unique_ptr<TypeAST> > () = make_unique<TypeAST>(yystack_[0].value.as < int > (), unique_ptr<FunctionTypeAST>(nullptr)); }
#line 911 "src/parser.cc"
    break;

  case 14: // type: function_type
#line 112 "src/parser/parser.yy"
                                { yylhs.value.as < unique_ptr<TypeAST> > () = make_unique<TypeAST>(0, move(yystack_[0].value.as < unique_ptr<FunctionTypeAST> > ())); }
#line 917 "src/parser.cc"
    break;

  case 15: // basic_type: tok_i16
#line 116 "src/parser/parser.yy"
             { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 923 "src/parser.cc"
    break;

  case 16: // basic_type: tok_i32
#line 116 "src/parser/parser.yy"
                       { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 929 "src/parser.cc"
    break;

  case 17: // basic_type: tok_i64
#line 116 "src/parser/parser.yy"
                                 { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 935 "src/parser.cc"
    break;

  case 18: // basic_type: tok_i128
#line 116 "src/parser/parser.yy"
                                           { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 941 "src/parser.cc"
    break;

  case 19: // basic_type: tok_f16
#line 116 "src/parser/parser.yy"
                                                      { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 947 "src/parser.cc"
    break;

  case 20: // basic_type: tok_f32
#line 116 "src/parser/parser.yy"
                                                                { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 953 "src/parser.cc"
    break;

  case 21: // basic_type: tok_f64
#line 116 "src/parser/parser.yy"
                                                                          { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 959 "src/parser.cc"
    break;

  case 22: // basic_type: tok_f128
#line 116 "src/parser/parser.yy"
                                                                                    { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 965 "src/parser.cc"
    break;

  case 23: // function_type: "(" variable_decs ")" "->" type
#line 119 "src/parser/parser.yy"
                                                                     {
					yylhs.value.as < unique_ptr<FunctionTypeAST> > () = make_unique<FunctionTypeAST>(move(yystack_[3].value.as < vector<unique_ptr<VarDecAST>> > ()), move(yystack_[0].value.as < unique_ptr<TypeAST> > ()));
				}
#line 973 "src/parser.cc"
    break;

  case 24: // expr: term
#line 124 "src/parser/parser.yy"
               {
			yylhs.value.as < unique_ptr<ExprAST> > () = make_unique<ExprAST>(move(yystack_[0].value.as < unique_ptr<TermAST> > ()), nullptr, 0, nullptr);
		}
#line 981 "src/parser.cc"
    break;

  case 25: // expr: expr "+" term
#line 127 "src/parser/parser.yy"
                                     {
			yylhs.value.as < unique_ptr<ExprAST> > () = make_unique<ExprAST>(nullptr, move(yystack_[2].value.as < unique_ptr<ExprAST> > ()), '+', move(yystack_[0].value.as < unique_ptr<TermAST> > ()));
		}
#line 989 "src/parser.cc"
    break;

  case 26: // expr: expr "-" term
#line 130 "src/parser/parser.yy"
                                      {
			yylhs.value.as < unique_ptr<ExprAST> > () = make_unique<ExprAST>(nullptr, move(yystack_[2].value.as < unique_ptr<ExprAST> > ()), '-', move(yystack_[0].value.as < unique_ptr<TermAST> > ()));
		}
#line 997 "src/parser.cc"
    break;

  case 27: // expr: "(" expr ")"
#line 133 "src/parser/parser.yy"
                                             { yylhs.value.as < unique_ptr<ExprAST> > () = move(yystack_[1].value.as < unique_ptr<ExprAST> > ()); }
#line 1003 "src/parser.cc"
    break;

  case 28: // term: tok_number
#line 136 "src/parser/parser.yy"
                                { yylhs.value.as < unique_ptr<TermAST> > () = make_unique<TermAST>(yystack_[0].value.as < int > (), nullptr, unique_ptr<FunctionCallAST>(nullptr)); }
#line 1009 "src/parser.cc"
    break;

  case 29: // term: tok_identifier
#line 137 "src/parser/parser.yy"
                                        { yylhs.value.as < unique_ptr<TermAST> > () = make_unique<TermAST>(0, yystack_[0].value.as < std::string > (), unique_ptr<FunctionCallAST>(nullptr)); }
#line 1015 "src/parser.cc"
    break;

  case 30: // term: function_call
#line 138 "src/parser/parser.yy"
                                        { yylhs.value.as < unique_ptr<TermAST> > () = make_unique<TermAST>(0, nullptr, move(yystack_[0].value.as < unique_ptr<FunctionCallAST> > ())); }
#line 1021 "src/parser.cc"
    break;

  case 31: // function_call: expr "(" arg_list ")"
#line 142 "src/parser/parser.yy"
                                                        {
					yylhs.value.as < unique_ptr<FunctionCallAST> > () = make_unique<FunctionCallAST>(move(yystack_[3].value.as < unique_ptr<ExprAST> > ()), move(yystack_[1].value.as < vector<unique_ptr<ExprAST>> > ()));
				}
#line 1029 "src/parser.cc"
    break;

  case 32: // arg_list: expr
#line 146 "src/parser/parser.yy"
                       {
				yylhs.value.as < vector<unique_ptr<ExprAST>> > () = vector<unique_ptr<ExprAST>>();
				yylhs.value.as < vector<unique_ptr<ExprAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<ExprAST> > ()));
			}
#line 1038 "src/parser.cc"
    break;

  case 33: // arg_list: arg_list "," expr
#line 150 "src/parser/parser.yy"
                                                 {
				yystack_[2].value.as < vector<unique_ptr<ExprAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<ExprAST> > ()));
				yylhs.value.as < vector<unique_ptr<ExprAST>> > () = move(yystack_[2].value.as < vector<unique_ptr<ExprAST>> > ());
			}
#line 1047 "src/parser.cc"
    break;


#line 1051 "src/parser.cc"

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
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;


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
    YY_STACK_PRINT ();
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

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -30;

  const signed char parser::yytable_ninf_ = -25;

  const signed char
  parser::yypact_[] =
  {
       0,   -14,   -30,    24,    14,     0,   -30,    17,    -8,    44,
     -30,   -30,    25,   -30,    40,   -30,   -30,   -30,     8,   -30,
      24,    24,    24,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,    18,   -30,   -30,   -30,   -30,     0,    29,    44,    47,
      47,    44,    30,   -14,   -30,    31,     4,   -30,   -30,    24,
       2,    18,   -30,    44,    25,   -30,   -30
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    29,    28,     0,     0,     2,     3,     0,     0,     5,
      24,    30,     0,    29,     0,     1,     4,     7,     0,     6,
       0,     0,     0,    18,    17,    16,    15,    22,    21,    20,
      19,     0,    10,    13,    14,    27,     0,     0,     0,    26,
      25,    32,     0,     0,    11,     0,     0,     8,    31,     0,
       0,     0,     9,    33,     0,    12,    23
  };

  const signed char
  parser::yypgoto_[] =
  {
     -30,   -30,    -7,    -4,   -30,   -29,   -30,   -15,   -30,   -30,
      -3,   -11,   -30,   -30
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     4,     5,     6,     7,     8,    45,    32,    33,    34,
       9,    10,    11,    42
  };

  const signed char
  parser::yytable_[] =
  {
      14,    16,    44,     1,     2,    18,    12,     1,     2,    39,
      40,    13,     2,    19,    15,    37,     3,    38,    38,    41,
       3,    43,    55,    52,     3,    54,    36,    13,     2,    46,
      23,    24,    25,    26,    27,    28,    29,    30,    17,    56,
       3,    31,    16,    20,    21,    22,    53,    48,    50,     0,
      47,     0,    49,    51,    20,    21,    22,    35,    20,    21,
      22,   -24,   -24,   -24
  };

  const signed char
  parser::yycheck_[] =
  {
       3,     5,    31,     3,     4,    13,    20,     3,     4,    20,
      21,     3,     4,    21,     0,    18,    16,    20,    21,    22,
      16,     3,    51,    19,    16,    23,    18,     3,     4,    36,
       5,     6,     7,     8,     9,    10,    11,    12,    21,    54,
      16,    16,    46,    14,    15,    16,    49,    17,    17,    -1,
      21,    -1,    22,    22,    14,    15,    16,    17,    14,    15,
      16,    14,    15,    16
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,    16,    25,    26,    27,    28,    29,    34,
      35,    36,    20,     3,    34,     0,    27,    21,    13,    21,
      14,    15,    16,     5,     6,     7,     8,     9,    10,    11,
      12,    16,    31,    32,    33,    17,    18,    34,    34,    35,
      35,    34,    37,     3,    29,    30,    26,    21,    17,    22,
      17,    22,    19,    34,    23,    29,    31
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
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "tok_identifier",
  "tok_number", "tok_i128", "tok_i64", "tok_i32", "tok_i16", "tok_f128",
  "tok_f64", "tok_f32", "tok_f16", "\"=\"", "\"-\"", "\"+\"", "\"(\"",
  "\")\"", "\"{\"", "\"}\"", "\":\"", "\";\"", "\",\"", "\"->\"",
  "$accept", "module", "stmts", "stmt", "variable_def", "variable_dec",
  "variable_decs", "type", "basic_type", "function_type", "expr", "term",
  "function_call", "arg_list", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    72,    72,    75,    79,    85,    86,    87,    90,    94,
      99,   102,   106,   111,   112,   116,   116,   116,   116,   116,
     116,   116,   116,   119,   124,   127,   130,   133,   136,   137,
     138,   142,   146,   150
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
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


} // yy
#line 1390 "src/parser.cc"

#line 155 "src/parser/parser.yy"


void yy::parser::error (const std::string& m) {
	std::cerr << m << '\n';
}
