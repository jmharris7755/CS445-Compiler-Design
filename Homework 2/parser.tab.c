/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

//Justin Harris 
//CS445
//Last Updated: 1-29-22
//parser.y
//This file contains Bison Code
#include "scanType.h" //TokenData type 
#include "syntaxTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>





double vars[26];

extern int yylex();
extern FILE *yyin;
extern int line;    //ERR line number from scanner
extern int numErrors;  // ERR err count
static TreeNode *ast;

#define YYERROR_VERBOSE
void yyerror(const char *msg)
{
    printf("ERROR(%d): %s\n", line, msg);
    numErrors++;
}


#line 107 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUMCONST = 4,                   /* NUMCONST  */
  YYSYMBOL_CHARCONST = 5,                  /* CHARCONST  */
  YYSYMBOL_STRINGCONST = 6,                /* STRINGCONST  */
  YYSYMBOL_BOOLCONST = 7,                  /* BOOLCONST  */
  YYSYMBOL_SPEC = 8,                       /* SPEC  */
  YYSYMBOL_KEYWORD = 9,                    /* KEYWORD  */
  YYSYMBOL_INC = 10,                       /* INC  */
  YYSYMBOL_DEC = 11,                       /* DEC  */
  YYSYMBOL_NEQ = 12,                       /* NEQ  */
  YYSYMBOL_LEQ = 13,                       /* LEQ  */
  YYSYMBOL_GEQ = 14,                       /* GEQ  */
  YYSYMBOL_ASGN = 15,                      /* ASGN  */
  YYSYMBOL_ADDASGN = 16,                   /* ADDASGN  */
  YYSYMBOL_MINUSASGN = 17,                 /* MINUSASGN  */
  YYSYMBOL_MULTASGN = 18,                  /* MULTASGN  */
  YYSYMBOL_DIVASGN = 19,                   /* DIVASGN  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_DIVIDE = 22,                    /* DIVIDE  */
  YYSYMBOL_MULT = 23,                      /* MULT  */
  YYSYMBOL_EQUALS = 24,                    /* EQUALS  */
  YYSYMBOL_PERCENT = 25,                   /* PERCENT  */
  YYSYMBOL_COLON = 26,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 27,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_QMARK = 29,                     /* QMARK  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_THEN = 31,                      /* THEN  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_FOR = 33,                       /* FOR  */
  YYSYMBOL_BREAK = 34,                     /* BREAK  */
  YYSYMBOL_RETURN = 35,                    /* RETURN  */
  YYSYMBOL_START = 36,                     /* START  */
  YYSYMBOL_END = 37,                       /* END  */
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_TO = 39,                        /* TO  */
  YYSYMBOL_DO = 40,                        /* DO  */
  YYSYMBOL_BY = 41,                        /* BY  */
  YYSYMBOL_NOT = 42,                       /* NOT  */
  YYSYMBOL_STATIC = 43,                    /* STATIC  */
  YYSYMBOL_BOOL = 44,                      /* BOOL  */
  YYSYMBOL_CHAR = 45,                      /* CHAR  */
  YYSYMBOL_INT = 46,                       /* INT  */
  YYSYMBOL_LBRACKET = 47,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 48,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 49,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 50,                    /* RPAREN  */
  YYSYMBOL_OR = 51,                        /* OR  */
  YYSYMBOL_AND = 52,                       /* AND  */
  YYSYMBOL_LESSTHAN = 53,                  /* LESSTHAN  */
  YYSYMBOL_GREATERTHAN = 54,               /* GREATERTHAN  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_program = 56,                   /* program  */
  YYSYMBOL_declList = 57,                  /* declList  */
  YYSYMBOL_decl = 58,                      /* decl  */
  YYSYMBOL_varDecl = 59,                   /* varDecl  */
  YYSYMBOL_scopedVarDecl = 60,             /* scopedVarDecl  */
  YYSYMBOL_varDeclList = 61,               /* varDeclList  */
  YYSYMBOL_varDeclInit = 62,               /* varDeclInit  */
  YYSYMBOL_varDeclId = 63,                 /* varDeclId  */
  YYSYMBOL_typeSpec = 64,                  /* typeSpec  */
  YYSYMBOL_funDecl = 65,                   /* funDecl  */
  YYSYMBOL_parms = 66,                     /* parms  */
  YYSYMBOL_parmList = 67,                  /* parmList  */
  YYSYMBOL_parmTypeList = 68,              /* parmTypeList  */
  YYSYMBOL_parmIdList = 69,                /* parmIdList  */
  YYSYMBOL_parmId = 70,                    /* parmId  */
  YYSYMBOL_stmt = 71,                      /* stmt  */
  YYSYMBOL_expStmt = 72,                   /* expStmt  */
  YYSYMBOL_compoundStmt = 73,              /* compoundStmt  */
  YYSYMBOL_localDecls = 74,                /* localDecls  */
  YYSYMBOL_stmtList = 75,                  /* stmtList  */
  YYSYMBOL_selectStmt = 76,                /* selectStmt  */
  YYSYMBOL_iterStmt = 77,                  /* iterStmt  */
  YYSYMBOL_iterRange = 78,                 /* iterRange  */
  YYSYMBOL_returnStmt = 79,                /* returnStmt  */
  YYSYMBOL_breakStmt = 80,                 /* breakStmt  */
  YYSYMBOL_exp = 81,                       /* exp  */
  YYSYMBOL_assignop = 82,                  /* assignop  */
  YYSYMBOL_simpleExp = 83,                 /* simpleExp  */
  YYSYMBOL_andExp = 84,                    /* andExp  */
  YYSYMBOL_unaryRelExp = 85,               /* unaryRelExp  */
  YYSYMBOL_relExp = 86,                    /* relExp  */
  YYSYMBOL_relop = 87,                     /* relop  */
  YYSYMBOL_sumExp = 88,                    /* sumExp  */
  YYSYMBOL_sumop = 89,                     /* sumop  */
  YYSYMBOL_mulExp = 90,                    /* mulExp  */
  YYSYMBOL_mulop = 91,                     /* mulop  */
  YYSYMBOL_unaryExp = 92,                  /* unaryExp  */
  YYSYMBOL_unaryop = 93,                   /* unaryop  */
  YYSYMBOL_factor = 94,                    /* factor  */
  YYSYMBOL_mutable = 95,                   /* mutable  */
  YYSYMBOL_immutable = 96,                 /* immutable  */
  YYSYMBOL_call = 97,                      /* call  */
  YYSYMBOL_args = 98,                      /* args  */
  YYSYMBOL_argList = 99,                   /* argList  */
  YYSYMBOL_constant = 100                  /* constant  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    68,    69,    72,    73,    76,    80,    83,
      87,    88,    91,    92,    95,    96,   102,   103,   104,   107,
     114,   122,   123,   126,   127,   130,   133,   134,   137,   140,
     145,   146,   147,   148,   149,   150,   153,   154,   157,   162,
     163,   166,   167,   171,   175,   181,   186,   194,   198,   204,
     207,   213,   217,   221,   226,   231,   234,   235,   236,   237,
     238,   241,   247,   250,   256,   259,   264,   267,   271,   274,
     278,   282,   286,   290,   294,   299,   303,   306,   310,   315,
     319,   322,   326,   330,   335,   338,   341,   345,   349,   354,
     355,   358,   361,   369,   370,   371,   374,   379,   380,   383,
     384,   387,   391,   396,   401
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMCONST",
  "CHARCONST", "STRINGCONST", "BOOLCONST", "SPEC", "KEYWORD", "INC", "DEC",
  "NEQ", "LEQ", "GEQ", "ASGN", "ADDASGN", "MINUSASGN", "MULTASGN",
  "DIVASGN", "PLUS", "MINUS", "DIVIDE", "MULT", "EQUALS", "PERCENT",
  "COLON", "SEMICOLON", "COMMA", "QMARK", "IF", "THEN", "ELSE", "FOR",
  "BREAK", "RETURN", "START", "END", "WHILE", "TO", "DO", "BY", "NOT",
  "STATIC", "BOOL", "CHAR", "INT", "LBRACKET", "RBRACKET", "LPAREN",
  "RPAREN", "OR", "AND", "LESSTHAN", "GREATERTHAN", "$accept", "program",
  "declList", "decl", "varDecl", "scopedVarDecl", "varDeclList",
  "varDeclInit", "varDeclId", "typeSpec", "funDecl", "parms", "parmList",
  "parmTypeList", "parmIdList", "parmId", "stmt", "expStmt",
  "compoundStmt", "localDecls", "stmtList", "selectStmt", "iterStmt",
  "iterRange", "returnStmt", "breakStmt", "exp", "assignop", "simpleExp",
  "andExp", "unaryRelExp", "relExp", "relop", "sumExp", "sumop", "mulExp",
  "mulop", "unaryExp", "unaryop", "factor", "mutable", "immutable", "call",
  "args", "argList", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -31,   -99,   -99,   -99,    62,     1,   -99,   -99,    68,
     -99,    40,   -99,   -99,    19,     4,   -99,    61,    76,    39,
      67,   -99,    95,    40,   -99,    97,   151,    57,    77,   -99,
      71,    40,    60,    59,    63,   -99,    41,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   151,   151,    72,    69,   -99,   -99,
     164,    42,   -99,   158,   -99,   -99,   -99,   -99,   -99,    81,
      76,   -99,   -99,   -99,   -99,    71,   151,   151,   -99,    80,
      72,   109,   151,   151,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   158,   158,   -99,   -99,   -99,   158,   -99,   -99,
     -99,     8,   -99,    85,   -99,    86,   114,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   151,    69,   -99,    17,    42,
     -99,    40,   -99,    97,     6,   -99,   -99,   151,   -99,    97,
      64,   -99,   151,   134,   112,    53,   -99,   151,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   116,   -99,    70,   -99,   -25,
     133,   -99,   -99,   123,   -23,   -99,   -99,   111,   151,   -99,
     111,   119,   126,   -32,   -99,   111,   111,   151,   -99,   -99,
     -21,   151,    72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    16,    17,    18,     0,     2,     4,     5,     0,
       6,    22,     1,     3,    14,     0,    11,    12,     0,     0,
      21,    24,     0,    22,     7,     0,     0,    28,    25,    27,
       0,     0,     0,     0,    14,    10,    91,   101,   102,   103,
     104,    86,    87,    88,     0,     0,    13,    62,    64,    66,
      68,    76,    80,     0,    85,    89,    90,    94,    95,     0,
       0,    40,    20,    23,    15,     0,     0,    98,    65,     0,
      55,    89,     0,     0,    74,    70,    72,    77,    78,    73,
      69,    71,     0,     0,    82,    81,    83,     0,    84,    29,
      26,    42,    19,     0,   100,     0,    97,    93,    53,    54,
      56,    57,    58,    59,    60,     0,    61,    63,    67,    75,
      79,     0,    39,     0,     0,    92,    96,     0,    52,     0,
       0,    37,     0,     0,     0,     0,    38,     0,    41,    30,
      31,    32,    33,    34,    35,     0,    99,     0,     9,     0,
       0,    51,    49,     0,     0,    36,     8,     0,     0,    50,
       0,    43,     0,     0,    45,     0,     0,     0,    44,    46,
      47,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   146,   -99,   -99,   -98,   142,   -99,     2,
     -99,   136,   -99,   137,   -99,   110,   -78,   -99,   -16,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -42,   -99,   -26,    99,
     -39,   -99,   -99,    87,   -99,    90,   -99,   -37,   -99,   -99,
     -44,   -99,   -99,   -99,   -99,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,   112,    15,    16,    17,    18,
      10,    19,    20,    21,    28,    29,   128,   129,   130,    91,
     114,   131,   132,   152,   133,   134,   135,   105,    70,    47,
      48,    49,    82,    50,    83,    51,    87,    52,    53,    54,
      55,    56,    57,    95,    96,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    71,     9,    69,     1,    68,   147,   157,     9,    36,
      37,    38,    39,    40,    62,   120,    88,   150,    11,    72,
     161,   137,    71,    71,    93,    94,    72,    41,    72,    42,
      72,    24,    25,   121,   107,    43,   122,    77,    78,   123,
     124,   125,    61,   126,   127,     2,     3,     4,    44,    92,
     110,   111,     2,     3,     4,    45,    36,    37,    38,    39,
      40,    71,    12,   118,    84,    85,    22,    86,    23,   151,
      71,    14,   154,    71,    41,   136,    42,   158,   159,    27,
     142,    71,    43,   143,     2,     3,     4,    26,    66,    30,
      67,   138,    25,   113,    31,    44,   139,   146,    25,    32,
      34,   144,    45,    71,    59,    60,    71,    61,    64,    65,
      22,    71,    71,   119,    36,    37,    38,    39,    40,    98,
      99,    73,   153,    72,   100,   101,   102,   103,   104,    89,
      97,   160,    41,   115,    42,   162,   116,   140,   121,   141,
      43,   122,   117,   145,   123,   124,   125,    61,   148,   127,
     149,   155,    13,    44,    36,    37,    38,    39,    40,    33,
      45,    36,    37,    38,    39,    40,   156,    35,    63,   108,
      90,   106,    41,   109,    42,     0,    74,    75,    76,    41,
      43,    42,     0,     0,    77,    78,     0,    43,    79,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81
};

static const yytype_int16 yycheck[] =
{
      26,    45,     0,    45,     3,    44,    31,    39,     6,     3,
       4,     5,     6,     7,    30,   113,    53,    40,    49,    51,
      41,   119,    66,    67,    66,    67,    51,    21,    51,    23,
      51,    27,    28,    27,    73,    29,    30,    20,    21,    33,
      34,    35,    36,    37,    38,    44,    45,    46,    42,    65,
      87,    43,    44,    45,    46,    49,     3,     4,     5,     6,
       7,   105,     0,   105,    22,    23,    47,    25,    49,   147,
     114,     3,   150,   117,    21,   117,    23,   155,   156,     3,
      27,   125,    29,   125,    44,    45,    46,    26,    47,    50,
      49,    27,    28,    91,    27,    42,   122,    27,    28,     4,
       3,   127,    49,   147,    47,    28,   150,    36,    48,    50,
      47,   155,   156,   111,     3,     4,     5,     6,     7,    10,
      11,    52,   148,    51,    15,    16,    17,    18,    19,    48,
      50,   157,    21,    48,    23,   161,    50,     3,    27,    27,
      29,    30,    28,    27,    33,    34,    35,    36,    15,    38,
      27,    32,     6,    42,     3,     4,     5,     6,     7,    23,
      49,     3,     4,     5,     6,     7,    40,    25,    31,    82,
      60,    72,    21,    83,    23,    -1,    12,    13,    14,    21,
      29,    23,    -1,    -1,    20,    21,    -1,    29,    24,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    44,    45,    46,    56,    57,    58,    59,    64,
      65,    49,     0,    58,     3,    61,    62,    63,    64,    66,
      67,    68,    47,    49,    27,    28,    26,     3,    69,    70,
      50,    27,     4,    66,     3,    62,     3,     4,     5,     6,
       7,    21,    23,    29,    42,    49,    83,    84,    85,    86,
      88,    90,    92,    93,    94,    95,    96,    97,   100,    47,
      28,    36,    73,    68,    48,    50,    47,    49,    85,    81,
      83,    95,    51,    52,    12,    13,    14,    20,    21,    24,
      53,    54,    87,    89,    22,    23,    25,    91,    92,    48,
      70,    74,    73,    81,    81,    98,    99,    50,    10,    11,
      15,    16,    17,    18,    19,    82,    84,    85,    88,    90,
      92,    43,    60,    64,    75,    48,    50,    28,    81,    64,
      61,    27,    30,    33,    34,    35,    37,    38,    71,    72,
      73,    76,    77,    79,    80,    81,    81,    61,    27,    83,
       3,    27,    27,    81,    83,    27,    27,    31,    15,    27,
      40,    71,    78,    83,    71,    32,    40,    39,    71,    71,
      83,    41,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    81,    81,    81,    81,    82,    82,    82,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    87,    87,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    91,    92,    92,    93,    93,    93,    94,
      94,    95,    95,    96,    96,    96,    97,    98,    98,    99,
      99,   100,   100,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     3,
       3,     1,     1,     3,     1,     4,     1,     1,     1,     6,
       5,     1,     0,     3,     1,     2,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     4,     2,
       0,     2,     0,     4,     6,     4,     6,     3,     5,     2,
       3,     2,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     1,     4,     1,     0,     3,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declList  */
#line 65 "parser.y"
                                                                                { ast = (yyvsp[0].tree) ;}
#line 1339 "parser.tab.c"
    break;

  case 3: /* declList: declList decl  */
#line 68 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1345 "parser.tab.c"
    break;

  case 4: /* declList: decl  */
#line 69 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1351 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 72 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1357 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 73 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1363 "parser.tab.c"
    break;

  case 7: /* varDecl: typeSpec varDeclList SEMICOLON  */
#line 76 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); 
                                                                                  convertSiblingType((yyval.tree), (yyvsp[-2].type)); }
#line 1370 "parser.tab.c"
    break;

  case 8: /* scopedVarDecl: STATIC typeSpec varDeclList SEMICOLON  */
#line 80 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); (yyval.tree)->isStatic = true; 
                                                                                  convertSiblingType((yyval.tree), (yyvsp[-2].type));}
#line 1377 "parser.tab.c"
    break;

  case 9: /* scopedVarDecl: typeSpec varDeclList SEMICOLON  */
#line 83 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); 
                                                                                  convertSiblingType((yyval.tree), (yyvsp[-2].type)); }
#line 1384 "parser.tab.c"
    break;

  case 10: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 87 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1390 "parser.tab.c"
    break;

  case 11: /* varDeclList: varDeclInit  */
#line 88 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1396 "parser.tab.c"
    break;

  case 12: /* varDeclInit: varDeclId  */
#line 91 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1402 "parser.tab.c"
    break;

  case 13: /* varDeclInit: varDeclId COLON simpleExp  */
#line 92 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-2].tree); (yyval.tree)->child[0] = (yyvsp[0].tree); }
#line 1408 "parser.tab.c"
    break;

  case 14: /* varDeclId: ID  */
#line 95 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(VarK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput; }
#line 1414 "parser.tab.c"
    break;

  case 15: /* varDeclId: ID LBRACKET NUMCONST RBRACKET  */
#line 96 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(VarK, (yyvsp[-3].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->isArray = true;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[-3].tokenData); (yyval.tree)->expType = UndefinedType; }
#line 1423 "parser.tab.c"
    break;

  case 16: /* typeSpec: BOOL  */
#line 102 "parser.y"
                                                                                { (yyval.type) = Boolean; }
#line 1429 "parser.tab.c"
    break;

  case 17: /* typeSpec: CHAR  */
#line 103 "parser.y"
                                                                                { (yyval.type) = Char; }
#line 1435 "parser.tab.c"
    break;

  case 18: /* typeSpec: INT  */
#line 104 "parser.y"
                                                                                { (yyval.type) = Integer; }
#line 1441 "parser.tab.c"
    break;

  case 19: /* funDecl: typeSpec ID LPAREN parms RPAREN compoundStmt  */
#line 107 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-4].tokenData)->tokenStrInput);
                                                                                  (yyval.tree)->expType = (yyvsp[-5].type);
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[-4].tokenData);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1452 "parser.tab.c"
    break;

  case 20: /* funDecl: ID LPAREN parms RPAREN compoundStmt  */
#line 114 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-4].tokenData)->tokenStrInput);
                                                                                  //$$->expType = $1;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[-4].tokenData);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1463 "parser.tab.c"
    break;

  case 21: /* parms: parmList  */
#line 122 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ; }
#line 1469 "parser.tab.c"
    break;

  case 22: /* parms: %empty  */
#line 123 "parser.y"
                                                                                { (yyval.tree) = NULL ; }
#line 1475 "parser.tab.c"
    break;

  case 23: /* parmList: parmList SEMICOLON parmTypeList  */
#line 126 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1481 "parser.tab.c"
    break;

  case 24: /* parmList: parmTypeList  */
#line 127 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ; }
#line 1487 "parser.tab.c"
    break;

  case 25: /* parmTypeList: typeSpec parmIdList  */
#line 130 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); convertSiblingType((yyval.tree), (yyvsp[-1].type)); }
#line 1493 "parser.tab.c"
    break;

  case 26: /* parmIdList: parmIdList COMMA parmId  */
#line 133 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1499 "parser.tab.c"
    break;

  case 27: /* parmIdList: parmId  */
#line 134 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1505 "parser.tab.c"
    break;

  case 28: /* parmId: ID  */
#line 137 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(ParamK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[0].tokenData)->tokenStrInput); }
#line 1512 "parser.tab.c"
    break;

  case 29: /* parmId: ID LBRACKET RBRACKET  */
#line 140 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(ParamK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-2].tokenData)->tokenStrInput); 
                                                                                  (yyval.tree)->isArray = true;}
#line 1520 "parser.tab.c"
    break;

  case 30: /* stmt: expStmt  */
#line 145 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1526 "parser.tab.c"
    break;

  case 31: /* stmt: compoundStmt  */
#line 146 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1532 "parser.tab.c"
    break;

  case 32: /* stmt: selectStmt  */
#line 147 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1538 "parser.tab.c"
    break;

  case 33: /* stmt: iterStmt  */
#line 148 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1544 "parser.tab.c"
    break;

  case 34: /* stmt: returnStmt  */
#line 149 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1550 "parser.tab.c"
    break;

  case 35: /* stmt: breakStmt  */
#line 150 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1556 "parser.tab.c"
    break;

  case 36: /* expStmt: exp SEMICOLON  */
#line 153 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); }
#line 1562 "parser.tab.c"
    break;

  case 37: /* expStmt: SEMICOLON  */
#line 154 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1568 "parser.tab.c"
    break;

  case 38: /* compoundStmt: START localDecls stmtList END  */
#line 157 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(CompoundK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-1].tree); }
#line 1576 "parser.tab.c"
    break;

  case 39: /* localDecls: localDecls scopedVarDecl  */
#line 162 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1582 "parser.tab.c"
    break;

  case 40: /* localDecls: %empty  */
#line 163 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1588 "parser.tab.c"
    break;

  case 41: /* stmtList: stmtList stmt  */
#line 166 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1594 "parser.tab.c"
    break;

  case 42: /* stmtList: %empty  */
#line 167 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1600 "parser.tab.c"
    break;

  case 43: /* selectStmt: IF simpleExp THEN stmt  */
#line 171 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1608 "parser.tab.c"
    break;

  case 44: /* selectStmt: IF simpleExp THEN stmt ELSE stmt  */
#line 175 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1617 "parser.tab.c"
    break;

  case 45: /* iterStmt: WHILE simpleExp DO stmt  */
#line 181 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1626 "parser.tab.c"
    break;

  case 46: /* iterStmt: FOR ID ASGN iterRange DO stmt  */
#line 186 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = newDeclNode(VarK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->child[0]->expType = Integer;
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree); }
#line 1637 "parser.tab.c"
    break;

  case 47: /* iterRange: simpleExp TO simpleExp  */
#line 194 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(RangeK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1645 "parser.tab.c"
    break;

  case 48: /* iterRange: simpleExp TO simpleExp BY simpleExp  */
#line 198 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(RangeK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1654 "parser.tab.c"
    break;

  case 49: /* returnStmt: RETURN SEMICOLON  */
#line 204 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;}
#line 1661 "parser.tab.c"
    break;

  case 50: /* returnStmt: RETURN exp SEMICOLON  */
#line 207 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenStrInput; 
                                                                                  (yyval.tree)->expType = (yyvsp[-1].tree)->expType;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree);}
#line 1670 "parser.tab.c"
    break;

  case 51: /* breakStmt: BREAK SEMICOLON  */
#line 213 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(BreakK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput; }
#line 1677 "parser.tab.c"
    break;

  case 52: /* exp: mutable assignop exp  */
#line 217 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1685 "parser.tab.c"
    break;

  case 53: /* exp: mutable INC  */
#line 221 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree); }
#line 1694 "parser.tab.c"
    break;

  case 54: /* exp: mutable DEC  */
#line 226 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree); }
#line 1703 "parser.tab.c"
    break;

  case 55: /* exp: simpleExp  */
#line 231 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1709 "parser.tab.c"
    break;

  case 56: /* assignop: ASGN  */
#line 234 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 1715 "parser.tab.c"
    break;

  case 57: /* assignop: ADDASGN  */
#line 235 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 1721 "parser.tab.c"
    break;

  case 58: /* assignop: MINUSASGN  */
#line 236 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 1727 "parser.tab.c"
    break;

  case 59: /* assignop: MULTASGN  */
#line 237 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 1733 "parser.tab.c"
    break;

  case 60: /* assignop: DIVASGN  */
#line 238 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 1739 "parser.tab.c"
    break;

  case 61: /* simpleExp: simpleExp OR andExp  */
#line 241 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1749 "parser.tab.c"
    break;

  case 62: /* simpleExp: andExp  */
#line 247 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1755 "parser.tab.c"
    break;

  case 63: /* andExp: andExp AND unaryRelExp  */
#line 250 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1765 "parser.tab.c"
    break;

  case 64: /* andExp: unaryRelExp  */
#line 256 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1771 "parser.tab.c"
    break;

  case 65: /* unaryRelExp: NOT unaryRelExp  */
#line 259 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[0].tree);}
#line 1780 "parser.tab.c"
    break;

  case 66: /* unaryRelExp: relExp  */
#line 264 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1786 "parser.tab.c"
    break;

  case 67: /* relExp: sumExp relop sumExp  */
#line 267 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1794 "parser.tab.c"
    break;

  case 68: /* relExp: sumExp  */
#line 271 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ;}
#line 1800 "parser.tab.c"
    break;

  case 69: /* relop: LESSTHAN  */
#line 274 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1808 "parser.tab.c"
    break;

  case 70: /* relop: LEQ  */
#line 278 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1816 "parser.tab.c"
    break;

  case 71: /* relop: GREATERTHAN  */
#line 282 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1824 "parser.tab.c"
    break;

  case 72: /* relop: GEQ  */
#line 286 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1832 "parser.tab.c"
    break;

  case 73: /* relop: EQUALS  */
#line 290 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1840 "parser.tab.c"
    break;

  case 74: /* relop: NEQ  */
#line 294 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1848 "parser.tab.c"
    break;

  case 75: /* sumExp: sumExp sumop mulExp  */
#line 299 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1856 "parser.tab.c"
    break;

  case 76: /* sumExp: mulExp  */
#line 303 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1862 "parser.tab.c"
    break;

  case 77: /* sumop: PLUS  */
#line 306 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1870 "parser.tab.c"
    break;

  case 78: /* sumop: MINUS  */
#line 310 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1878 "parser.tab.c"
    break;

  case 79: /* mulExp: mulExp mulop unaryExp  */
#line 315 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1886 "parser.tab.c"
    break;

  case 80: /* mulExp: unaryExp  */
#line 319 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1892 "parser.tab.c"
    break;

  case 81: /* mulop: MULT  */
#line 322 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1900 "parser.tab.c"
    break;

  case 82: /* mulop: DIVIDE  */
#line 326 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1908 "parser.tab.c"
    break;

  case 83: /* mulop: PERCENT  */
#line 330 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1916 "parser.tab.c"
    break;

  case 84: /* unaryExp: unaryop unaryExp  */
#line 335 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[0].tree); }
#line 1923 "parser.tab.c"
    break;

  case 85: /* unaryExp: factor  */
#line 338 "parser.y"
                                                                              { (yyval.tree) = (yyvsp[0].tree); }
#line 1929 "parser.tab.c"
    break;

  case 86: /* unaryop: MINUS  */
#line 341 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1937 "parser.tab.c"
    break;

  case 87: /* unaryop: MULT  */
#line 345 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1945 "parser.tab.c"
    break;

  case 88: /* unaryop: QMARK  */
#line 349 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1953 "parser.tab.c"
    break;

  case 89: /* factor: mutable  */
#line 354 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1959 "parser.tab.c"
    break;

  case 90: /* factor: immutable  */
#line 355 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1965 "parser.tab.c"
    break;

  case 91: /* mutable: ID  */
#line 358 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(ParamK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[0].tokenData)->tokenStrInput); }
#line 1972 "parser.tab.c"
    break;

  case 92: /* mutable: ID LBRACKET exp RBRACKET  */
#line 361 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0] = newExpNode(IdK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0]->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0]->isArray = true;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-1].tree); }
#line 1983 "parser.tab.c"
    break;

  case 93: /* immutable: LPAREN exp RPAREN  */
#line 369 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); }
#line 1989 "parser.tab.c"
    break;

  case 94: /* immutable: call  */
#line 370 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1995 "parser.tab.c"
    break;

  case 95: /* immutable: constant  */
#line 371 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2001 "parser.tab.c"
    break;

  case 96: /* call: ID LPAREN args RPAREN  */
#line 374 "parser.y"
                                                                                { (yyval.tree) = newExpNode(CallK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-3].tokenData)->tokenStrInput);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree);}
#line 2009 "parser.tab.c"
    break;

  case 97: /* args: argList  */
#line 379 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2015 "parser.tab.c"
    break;

  case 98: /* args: %empty  */
#line 380 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2021 "parser.tab.c"
    break;

  case 99: /* argList: argList COMMA exp  */
#line 383 "parser.y"
                                                                                {(yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2027 "parser.tab.c"
    break;

  case 100: /* argList: exp  */
#line 384 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2033 "parser.tab.c"
    break;

  case 101: /* constant: NUMCONST  */
#line 387 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue;
                                                                                  (yyval.tree)->expType = Integer; }
#line 2041 "parser.tab.c"
    break;

  case 102: /* constant: CHARCONST  */
#line 391 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[0].tokenData);
                                                                                  (yyval.tree)->expType = Char; }
#line 2050 "parser.tab.c"
    break;

  case 103: /* constant: STRINGCONST  */
#line 396 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.string = strdup((yyvsp[0].tokenData)->svalue);
                                                                                  (yyval.tree)->isArray = true;
                                                                                  (yyval.tree)->expType = CharInt; }
#line 2059 "parser.tab.c"
    break;

  case 104: /* constant: BOOLCONST  */
#line 401 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean; }
#line 2068 "parser.tab.c"
    break;


#line 2072 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 407 "parser.y"


extern int yydebug;
int main(int argc, char *argv[])
{

    int selOption = 0;
    bool printAST = 0;

    while((selOption = getopt(argc, argv, "dp")) != -1){

        switch(selOption){

            case'c':
                //do nothing
                break;

            case 'd':
                yydebug = 1;
                break;
            
            case 'p':
                printAST = true;
                break;

            default:
                exit(1);
        }
    }


    if(argc >1){
        if((yyin = fopen(argv[argc-1], "r"))) {
            // file open successful
        }
        else {
            //failed to open
            printf("ERROR: failed to open \'%s\'\n", argv[1]);
            exit(1);
        }
    }

    yyparse();

    if(printAST){
        printTree(ast, 0);
    }

    //do the parsing
    //numErrors = 0;

    //printf("Number of errors: %d\n", numErrors);

    return 0;
}
