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
#line 30 "src/parser/parser.yy"

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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


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
#line 142 "src/parser.cc"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
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
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_tok_inum: // tok_inum
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
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_tok_inum: // tok_inum
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
      case symbol_kind::S_tok_inum: // tok_inum
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

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_tok_inum: // tok_inum
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

    location = that.location;
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
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
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

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

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
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
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
      case symbol_kind::S_tok_inum: // tok_inum
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


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
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
#line 83 "src/parser/parser.yy"
                {
			yylhs.value.as < unique_ptr<ModuleAST> > () = make_unique<ModuleAST>("test", move(yystack_[0].value.as < vector<unique_ptr<StmtAST>> > ()));
			drv.result = move(yylhs.value.as < unique_ptr<ModuleAST> > ());
		}
#line 830 "src/parser.cc"
    break;

  case 3: // stmts: %empty
#line 89 "src/parser/parser.yy"
                 {
			yylhs.value.as < vector<unique_ptr<StmtAST>> > () = vector<unique_ptr<StmtAST>>();
		}
#line 838 "src/parser.cc"
    break;

  case 4: // stmts: stmts stmt
#line 92 "src/parser/parser.yy"
                             {
			yystack_[1].value.as < vector<unique_ptr<StmtAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<StmtAST> > ()));
			yylhs.value.as < vector<unique_ptr<StmtAST>> > () = move(yystack_[1].value.as < vector<unique_ptr<StmtAST>> > ());
		}
#line 847 "src/parser.cc"
    break;

  case 5: // stmt: expr ";"
#line 98 "src/parser/parser.yy"
                                        { yylhs.value.as < unique_ptr<StmtAST> > () = make_unique<ExprStmtAST>(move(yystack_[1].value.as < unique_ptr<ExprAST> > ())); }
#line 853 "src/parser.cc"
    break;

  case 6: // stmt: variable_dec
#line 99 "src/parser/parser.yy"
                                        { yylhs.value.as < unique_ptr<StmtAST> > () = make_unique<VarDecStmtAST>(move(yystack_[0].value.as < unique_ptr<VarDecAST> > ())); }
#line 859 "src/parser.cc"
    break;

  case 7: // stmt: variable_def
#line 100 "src/parser/parser.yy"
                                        { yylhs.value.as < unique_ptr<StmtAST> > () = make_unique<VarDefStmtAST>(move(yystack_[0].value.as < unique_ptr<VarDefAST> > ())); }
#line 865 "src/parser.cc"
    break;

  case 8: // stmt: "return" expr ";"
#line 101 "src/parser/parser.yy"
                                        { yylhs.value.as < unique_ptr<StmtAST> > () = make_unique<ReturnStmtAST>(move(yystack_[1].value.as < unique_ptr<ExprAST> > ())); }
#line 871 "src/parser.cc"
    break;

  case 9: // variable_def: variable_dec "=" expr ";"
#line 104 "src/parser/parser.yy"
                                            {
					yylhs.value.as < unique_ptr<VarDefAST> > () = make_unique<VarDefAST>(move(yystack_[3].value.as < unique_ptr<VarDecAST> > ()), move(yystack_[1].value.as < unique_ptr<ExprAST> > ()), vector<unique_ptr<StmtAST>>());
				}
#line 879 "src/parser.cc"
    break;

  case 10: // variable_def: variable_dec "=" "{" stmts "}"
#line 108 "src/parser/parser.yy"
                                                                 {
					yylhs.value.as < unique_ptr<VarDefAST> > () = make_unique<VarDefAST>(move(yystack_[4].value.as < unique_ptr<VarDecAST> > ()), unique_ptr<ExprAST>(nullptr), move(yystack_[1].value.as < vector<unique_ptr<StmtAST>> > ()));
				}
#line 887 "src/parser.cc"
    break;

  case 11: // variable_dec: tok_identifier ":" type
#line 113 "src/parser/parser.yy"
                                                {yylhs.value.as < unique_ptr<VarDecAST> > () = make_unique<VarDecAST>(yystack_[2].value.as < std::string > (), move(yystack_[0].value.as < unique_ptr<TypeAST> > ()));}
#line 893 "src/parser.cc"
    break;

  case 12: // variable_decs: %empty
#line 116 "src/parser/parser.yy"
                         {
					yylhs.value.as < vector<unique_ptr<VarDecAST>> > () = vector<unique_ptr<VarDecAST>>();
				}
#line 901 "src/parser.cc"
    break;

  case 13: // variable_decs: variable_dec
#line 119 "src/parser/parser.yy"
                                               {
					yylhs.value.as < vector<unique_ptr<VarDecAST>> > () = vector<unique_ptr<VarDecAST>>();
					yylhs.value.as < vector<unique_ptr<VarDecAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<VarDecAST> > ()));
				}
#line 910 "src/parser.cc"
    break;

  case 14: // variable_decs: variable_decs "," variable_dec
#line 123 "src/parser/parser.yy"
                                                                       {
					yystack_[2].value.as < vector<unique_ptr<VarDecAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<VarDecAST> > ()));
				}
#line 918 "src/parser.cc"
    break;

  case 15: // type: basic_type
#line 128 "src/parser/parser.yy"
                        { yylhs.value.as < unique_ptr<TypeAST> > () = make_unique<TypeAST>(yy::parser::token::tok_i64, unique_ptr<FunctionTypeAST>(nullptr)); }
#line 924 "src/parser.cc"
    break;

  case 16: // type: function_type
#line 129 "src/parser/parser.yy"
                                { yylhs.value.as < unique_ptr<TypeAST> > () = make_unique<TypeAST>(0, move(yystack_[0].value.as < unique_ptr<FunctionTypeAST> > ())); }
#line 930 "src/parser.cc"
    break;

  case 25: // function_type: "(" variable_decs ")" "->" type
#line 136 "src/parser/parser.yy"
                                                  {
					yylhs.value.as < unique_ptr<FunctionTypeAST> > () = make_unique<FunctionTypeAST>(move(yystack_[3].value.as < vector<unique_ptr<VarDecAST>> > ()), move(yystack_[0].value.as < unique_ptr<TypeAST> > ()));
				}
#line 938 "src/parser.cc"
    break;

  case 26: // expr: term
#line 141 "src/parser/parser.yy"
                                { yylhs.value.as < unique_ptr<ExprAST> > () = make_unique<ExprAST>(move(yystack_[0].value.as < unique_ptr<TermAST> > ()), nullptr, 0, nullptr); }
#line 944 "src/parser.cc"
    break;

  case 27: // expr: expr "+" term
#line 142 "src/parser/parser.yy"
                                { yylhs.value.as < unique_ptr<ExprAST> > () = make_unique<ExprAST>(nullptr, move(yystack_[2].value.as < unique_ptr<ExprAST> > ()), '+', move(yystack_[0].value.as < unique_ptr<TermAST> > ())); }
#line 950 "src/parser.cc"
    break;

  case 28: // term: tok_inum
#line 146 "src/parser/parser.yy"
                                        { yylhs.value.as < unique_ptr<TermAST> > () = make_unique<TermAST>(yystack_[0].value.as < int > (), "", unique_ptr<FunctionCallAST>(nullptr), unique_ptr<ExprAST>(nullptr)); }
#line 956 "src/parser.cc"
    break;

  case 29: // term: "(" expr ")"
#line 147 "src/parser/parser.yy"
                                        { yylhs.value.as < unique_ptr<TermAST> > () = make_unique<TermAST>(0, "", unique_ptr<FunctionCallAST>(nullptr), move(yystack_[1].value.as < unique_ptr<ExprAST> > ())); }
#line 962 "src/parser.cc"
    break;

  case 30: // term: tok_identifier
#line 148 "src/parser/parser.yy"
                                        { yylhs.value.as < unique_ptr<TermAST> > () = make_unique<TermAST>(0, yystack_[0].value.as < std::string > (), unique_ptr<FunctionCallAST>(nullptr), unique_ptr<ExprAST>(nullptr)); }
#line 968 "src/parser.cc"
    break;

  case 31: // term: function_call
#line 149 "src/parser/parser.yy"
                                        { yylhs.value.as < unique_ptr<TermAST> > () = make_unique<TermAST>(0, nullptr, move(yystack_[0].value.as < unique_ptr<FunctionCallAST> > ()), unique_ptr<ExprAST>(nullptr)); }
#line 974 "src/parser.cc"
    break;

  case 32: // function_call: term "(" arg_list ")"
#line 153 "src/parser/parser.yy"
                                        {
					yylhs.value.as < unique_ptr<FunctionCallAST> > () = make_unique<FunctionCallAST>(move(yystack_[3].value.as < unique_ptr<TermAST> > ()), move(yystack_[1].value.as < vector<unique_ptr<ExprAST>> > ()));
				}
#line 982 "src/parser.cc"
    break;

  case 33: // arg_list: expr
#line 157 "src/parser/parser.yy"
                       {
				yylhs.value.as < vector<unique_ptr<ExprAST>> > () = vector<unique_ptr<ExprAST>>();
				yylhs.value.as < vector<unique_ptr<ExprAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<ExprAST> > ()));
			}
#line 991 "src/parser.cc"
    break;

  case 34: // arg_list: arg_list "," expr
#line 161 "src/parser/parser.yy"
                                            {
				yystack_[2].value.as < vector<unique_ptr<ExprAST>> > ().push_back(move(yystack_[0].value.as < unique_ptr<ExprAST> > ()));
				yylhs.value.as < vector<unique_ptr<ExprAST>> > () = move(yystack_[2].value.as < vector<unique_ptr<ExprAST>> > ());
			}
#line 1000 "src/parser.cc"
    break;


#line 1004 "src/parser.cc"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
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

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
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
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "tok_identifier", "tok_inum",
  "=", "-", "+", "(", ")", "{", "}", ":", ";", ",", "->", "i128", "i64",
  "i32", "i16", "f128", "f64", "f32", "f16", "return", "$accept", "module",
  "stmts", "stmt", "variable_def", "variable_dec", "variable_decs", "type",
  "basic_type", "function_type", "expr", "term", "function_call",
  "arg_list", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -21;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
     -21,     7,     2,   -21,    -3,   -21,    13,    13,   -21,   -21,
      18,    12,    19,   -21,    14,   -21,    42,    31,    10,    13,
     -21,    13,    25,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,    32,    19,    39,
      33,    -3,   -21,    34,     0,   -21,   -21,    13,    35,    25,
     -21,    39,    14,   -21,   -21
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,     2,     1,    30,    28,     0,     0,     4,     7,
       6,     0,    26,    31,     0,    30,     0,     0,     0,     0,
       5,     0,    12,    20,    19,    18,    17,    24,    23,    22,
      21,    11,    15,    16,    29,     8,     3,     0,    27,    33,
       0,     0,    13,     0,     0,     9,    32,     0,     0,     0,
      10,    34,     0,    14,    25
  };

  const signed char
  parser::yypgoto_[] =
  {
     -21,   -21,     4,   -21,   -21,   -20,   -21,     1,   -21,   -21,
      -6,    36,   -21,   -21
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,     2,     8,     9,    10,    43,    31,    32,    33,
      11,    12,    13,    40
  };

  const signed char
  parser::yytable_[] =
  {
      16,    17,    42,     4,     5,     4,     5,     3,     6,    14,
       6,    50,    37,    15,     5,    39,    15,     5,     6,    19,
      36,     6,    22,    18,     7,    20,     7,    21,    41,    53,
      23,    24,    25,    26,    27,    28,    29,    30,    19,    19,
      44,    51,    46,    48,    35,    45,    19,    47,    49,    19,
      52,    34,     0,    54,     0,    38
  };

  const signed char
  parser::yycheck_[] =
  {
       6,     7,    22,     3,     4,     3,     4,     0,     8,    12,
       8,    11,    18,     3,     4,    21,     3,     4,     8,     7,
      10,     8,     8,     5,    24,    13,    24,     8,     3,    49,
      16,    17,    18,    19,    20,    21,    22,    23,     7,     7,
      36,    47,     9,     9,    13,    13,     7,    14,    14,     7,
      15,     9,    -1,    52,    -1,    19
  };

  const signed char
  parser::yystos_[] =
  {
       0,    26,    27,     0,     3,     4,     8,    24,    28,    29,
      30,    35,    36,    37,    12,     3,    35,    35,     5,     7,
      13,     8,     8,    16,    17,    18,    19,    20,    21,    22,
      23,    32,    33,    34,     9,    13,    10,    35,    36,    35,
      38,     3,    30,    31,    27,    13,     9,    14,     9,    14,
      11,    35,    15,    30,    32
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    25,    26,    27,    27,    28,    28,    28,    28,    29,
      29,    30,    31,    31,    31,    32,    32,    33,    33,    33,
      33,    33,    33,    33,    33,    34,    35,    35,    36,    36,
      36,    36,    37,    38,    38
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     2,     1,     1,     3,     4,
       5,     3,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     3,     1,     3,
       1,     1,     4,     1,     3
  };




#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    83,    83,    89,    92,    98,    99,   100,   101,   104,
     108,   113,   116,   119,   123,   128,   129,   133,   133,   133,
     133,   133,   133,   133,   133,   136,   141,   142,   146,   147,
     148,   149,   153,   157,   161
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
#line 1595 "src/parser.cc"

#line 166 "src/parser/parser.yy"


void yy::parser::error (const location_type& l, const std::string& m) {
	std::cerr << l << ": " << m << '\n';
}
