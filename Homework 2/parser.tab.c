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


#line 102 "parser.tab.c"

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
  YYSYMBOL_STOP = 37,                      /* STOP  */
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
  YYSYMBOL_matchedif = 76,                 /* matchedif  */
  YYSYMBOL_unmatchedif = 77,               /* unmatchedif  */
  YYSYMBOL_endStmt = 78,                   /* endStmt  */
  YYSYMBOL_iterRange = 79,                 /* iterRange  */
  YYSYMBOL_returnStmt = 80,                /* returnStmt  */
  YYSYMBOL_breakStmt = 81,                 /* breakStmt  */
  YYSYMBOL_exp = 82,                       /* exp  */
  YYSYMBOL_assignop = 83,                  /* assignop  */
  YYSYMBOL_simpleExp = 84,                 /* simpleExp  */
  YYSYMBOL_andExp = 85,                    /* andExp  */
  YYSYMBOL_unaryRelExp = 86,               /* unaryRelExp  */
  YYSYMBOL_relExp = 87,                    /* relExp  */
  YYSYMBOL_relop = 88,                     /* relop  */
  YYSYMBOL_sumExp = 89,                    /* sumExp  */
  YYSYMBOL_sumop = 90,                     /* sumop  */
  YYSYMBOL_mulExp = 91,                    /* mulExp  */
  YYSYMBOL_mulop = 92,                     /* mulop  */
  YYSYMBOL_unaryExp = 93,                  /* unaryExp  */
  YYSYMBOL_unaryop = 94,                   /* unaryop  */
  YYSYMBOL_factor = 95,                    /* factor  */
  YYSYMBOL_mutable = 96,                   /* mutable  */
  YYSYMBOL_immutable = 97,                 /* immutable  */
  YYSYMBOL_call = 98,                      /* call  */
  YYSYMBOL_args = 99,                      /* args  */
  YYSYMBOL_argList = 100,                  /* argList  */
  YYSYMBOL_constant = 101                  /* constant  */
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
#define YYLAST   206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

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
       0,    60,    60,    63,    64,    67,    68,    71,    75,    78,
      82,    83,    86,    87,    90,    91,    97,    98,    99,   102,
     109,   117,   118,   121,   122,   125,   128,   129,   132,   135,
     140,   141,   144,   145,   148,   153,   154,   157,   158,   162,
     163,   168,   173,   181,   186,   191,   198,   203,   204,   205,
     206,   209,   213,   219,   222,   228,   232,   236,   241,   246,
     249,   250,   251,   252,   253,   256,   262,   265,   271,   274,
     279,   282,   286,   289,   293,   297,   301,   305,   309,   314,
     318,   321,   325,   330,   334,   337,   341,   345,   350,   353,
     356,   360,   364,   369,   370,   373,   376,   384,   385,   386,
     389,   394,   395,   398,   399,   402,   406,   411,   416
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
  "BREAK", "RETURN", "START", "STOP", "WHILE", "TO", "DO", "BY", "NOT",
  "STATIC", "BOOL", "CHAR", "INT", "LBRACKET", "RBRACKET", "LPAREN",
  "RPAREN", "OR", "AND", "LESSTHAN", "GREATERTHAN", "$accept", "program",
  "declList", "decl", "varDecl", "scopedVarDecl", "varDeclList",
  "varDeclInit", "varDeclId", "typeSpec", "funDecl", "parms", "parmList",
  "parmTypeList", "parmIdList", "parmId", "stmt", "expStmt",
  "compoundStmt", "localDecls", "stmtList", "matchedif", "unmatchedif",
  "endStmt", "iterRange", "returnStmt", "breakStmt", "exp", "assignop",
  "simpleExp", "andExp", "unaryRelExp", "relExp", "relop", "sumExp",
  "sumop", "mulExp", "mulop", "unaryExp", "unaryop", "factor", "mutable",
  "immutable", "call", "args", "argList", "constant", YY_NULLPTR
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
       1,   -31,   -99,   -99,   -99,    62,     1,   -99,   -99,    66,
     -99,    54,   -99,   -99,    59,     4,   -99,    40,    69,    27,
      67,   -99,    86,    54,   -99,    94,    82,    75,    81,   -99,
      80,    54,    84,    79,    83,   -99,    63,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,    82,    82,    85,    87,   -99,   -99,
     152,    42,   -99,   154,   -99,   -99,   -99,   -99,   -99,    90,
      69,   -99,   -99,   -99,   -99,    80,    82,    82,   -99,    92,
      85,   169,    82,    82,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   154,   154,   -99,   -99,   -99,   154,   -99,   -99,
     -99,     8,   -99,    97,   -99,    96,   105,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,    82,    87,   -99,    17,    42,
     -99,    54,   -99,    94,     6,   -99,   -99,    82,   -99,    94,
      98,   -99,    82,   148,   126,    53,   -99,    82,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   127,   -99,   100,   -99,
     -25,   140,   -99,   -99,   135,   -23,   -99,   -99,   114,    82,
     -99,   114,   -99,   136,   129,   -32,   -99,   -99,   114,   114,
      82,   -99,   -99,   -99,   -99,   -21,    82,    85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    16,    17,    18,     0,     2,     4,     5,     0,
       6,    22,     1,     3,    14,     0,    11,    12,     0,     0,
      21,    24,     0,    22,     7,     0,     0,    28,    25,    27,
       0,     0,     0,     0,    14,    10,    95,   105,   106,   107,
     108,    90,    91,    92,     0,     0,    13,    66,    68,    70,
      72,    80,    84,     0,    89,    93,    94,    98,    99,     0,
       0,    36,    20,    23,    15,     0,     0,   102,    69,     0,
      59,    93,     0,     0,    78,    74,    76,    81,    82,    77,
      73,    75,     0,     0,    86,    85,    87,     0,    88,    29,
      26,    38,    19,     0,   104,     0,   101,    97,    57,    58,
      60,    61,    62,    63,    64,     0,    65,    67,    71,    79,
      83,     0,    35,     0,     0,    96,   100,     0,    56,     0,
       0,    33,     0,     0,     0,     0,    34,     0,    37,    47,
      48,    30,    31,    39,    49,    50,     0,   103,     0,     9,
       0,     0,    55,    53,     0,     0,    32,     8,     0,     0,
      54,     0,    46,    30,     0,     0,    41,    44,     0,     0,
       0,    40,    43,    42,    45,    51,     0,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   161,   -99,   -99,   -98,   145,   -99,     2,
     -99,   151,   -99,   147,   -99,   111,    33,   -99,   -16,   -99,
     -99,   -80,   -67,   -99,   -99,   -99,   -99,   -42,   -99,   -26,
     110,   -39,   -99,   -99,   107,   -99,   108,   -99,   -37,   -99,
     -99,   -44,   -99,   -99,   -99,   -99,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,   112,    15,    16,    17,    18,
      10,    19,    20,    21,    28,    29,   128,   129,   130,    91,
     114,   131,   132,   133,   154,   134,   135,   136,   105,    70,
      47,    48,    49,    82,    50,    83,    51,    87,    52,    53,
      54,    55,    56,    57,    95,    96,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    71,     9,    69,     1,    68,   148,   160,     9,    36,
      37,    38,    39,    40,    62,   120,    88,   151,    11,    72,
     166,   138,    71,    71,    93,    94,    72,    41,    72,    42,
      72,    24,    25,   121,   107,    43,   122,    77,    78,   123,
     124,   125,    61,   126,   127,     2,     3,     4,    44,    92,
     110,   111,     2,     3,     4,    45,    36,    37,    38,    39,
      40,    71,    12,   118,    84,    85,    26,    86,   153,    14,
      71,   156,    27,    71,    41,   137,    42,    30,   161,   163,
     143,    71,    43,   144,   157,    36,    37,    38,    39,    40,
      32,   162,   164,   113,    31,    44,   140,    34,     2,     3,
       4,   145,    45,    41,    71,    42,    22,    71,    23,    60,
      66,    43,    67,   119,    71,    71,    61,    36,    37,    38,
      39,    40,    59,   155,    44,   139,    25,   147,    25,    65,
      22,    45,    64,   117,   165,    41,    72,    42,    89,    73,
     167,   121,    97,    43,   122,   115,   116,   123,   124,   125,
      61,   141,   127,   142,   146,   149,    44,    36,    37,    38,
      39,    40,   150,    45,    74,    75,    76,    13,   158,   159,
      35,    90,    77,    78,    33,    41,    79,    42,    63,    98,
      99,   152,   106,    43,   100,   101,   102,   103,   104,   108,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,    80,    81
};

static const yytype_int16 yycheck[] =
{
      26,    45,     0,    45,     3,    44,    31,    39,     6,     3,
       4,     5,     6,     7,    30,   113,    53,    40,    49,    51,
      41,   119,    66,    67,    66,    67,    51,    21,    51,    23,
      51,    27,    28,    27,    73,    29,    30,    20,    21,    33,
      34,    35,    36,    37,    38,    44,    45,    46,    42,    65,
      87,    43,    44,    45,    46,    49,     3,     4,     5,     6,
       7,   105,     0,   105,    22,    23,    26,    25,   148,     3,
     114,   151,     3,   117,    21,   117,    23,    50,   158,   159,
      27,   125,    29,   125,   151,     3,     4,     5,     6,     7,
       4,   158,   159,    91,    27,    42,   122,     3,    44,    45,
      46,   127,    49,    21,   148,    23,    47,   151,    49,    28,
      47,    29,    49,   111,   158,   159,    36,     3,     4,     5,
       6,     7,    47,   149,    42,    27,    28,    27,    28,    50,
      47,    49,    48,    28,   160,    21,    51,    23,    48,    52,
     166,    27,    50,    29,    30,    48,    50,    33,    34,    35,
      36,     3,    38,    27,    27,    15,    42,     3,     4,     5,
       6,     7,    27,    49,    12,    13,    14,     6,    32,    40,
      25,    60,    20,    21,    23,    21,    24,    23,    31,    10,
      11,   148,    72,    29,    15,    16,    17,    18,    19,    82,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    44,    45,    46,    56,    57,    58,    59,    64,
      65,    49,     0,    58,     3,    61,    62,    63,    64,    66,
      67,    68,    47,    49,    27,    28,    26,     3,    69,    70,
      50,    27,     4,    66,     3,    62,     3,     4,     5,     6,
       7,    21,    23,    29,    42,    49,    84,    85,    86,    87,
      89,    91,    93,    94,    95,    96,    97,    98,   101,    47,
      28,    36,    73,    68,    48,    50,    47,    49,    86,    82,
      84,    96,    51,    52,    12,    13,    14,    20,    21,    24,
      53,    54,    88,    90,    22,    23,    25,    92,    93,    48,
      70,    74,    73,    82,    82,    99,   100,    50,    10,    11,
      15,    16,    17,    18,    19,    83,    85,    86,    89,    91,
      93,    43,    60,    64,    75,    48,    50,    28,    82,    64,
      61,    27,    30,    33,    34,    35,    37,    38,    71,    72,
      73,    76,    77,    78,    80,    81,    82,    82,    61,    27,
      84,     3,    27,    27,    82,    84,    27,    27,    31,    15,
      27,    40,    71,    76,    79,    84,    76,    77,    32,    40,
      39,    76,    77,    76,    77,    84,    41,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    77,    77,    77,    77,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    82,    82,    82,    82,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    88,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    92,    93,    93,
      94,    94,    94,    95,    95,    96,    96,    97,    97,    97,
      98,    99,    99,   100,   100,   101,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     3,
       3,     1,     1,     3,     1,     4,     1,     1,     1,     6,
       5,     1,     0,     3,     1,     2,     3,     1,     1,     3,
       1,     1,     2,     1,     4,     2,     0,     2,     0,     1,
       6,     4,     6,     6,     4,     6,     4,     1,     1,     1,
       1,     3,     5,     2,     3,     2,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     1,     1,
       4,     1,     0,     3,     1,     1,     1,     1,     1
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
#line 60 "parser.y"
                                                                                { ast = (yyvsp[0].tree) ;}
#line 1333 "parser.tab.c"
    break;

  case 3: /* declList: declList decl  */
#line 63 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1339 "parser.tab.c"
    break;

  case 4: /* declList: decl  */
#line 64 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1345 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 67 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1351 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 68 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1357 "parser.tab.c"
    break;

  case 7: /* varDecl: typeSpec varDeclList SEMICOLON  */
#line 71 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); 
                                                                                  convertSiblingType((yyval.tree), (yyvsp[-2].type)); }
#line 1364 "parser.tab.c"
    break;

  case 8: /* scopedVarDecl: STATIC typeSpec varDeclList SEMICOLON  */
#line 75 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); (yyval.tree)->isStatic = true; 
                                                                                  convertSiblingType((yyval.tree), (yyvsp[-2].type));}
#line 1371 "parser.tab.c"
    break;

  case 9: /* scopedVarDecl: typeSpec varDeclList SEMICOLON  */
#line 78 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); 
                                                                                  convertSiblingType((yyval.tree), (yyvsp[-2].type)); }
#line 1378 "parser.tab.c"
    break;

  case 10: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 82 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1384 "parser.tab.c"
    break;

  case 11: /* varDeclList: varDeclInit  */
#line 83 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1390 "parser.tab.c"
    break;

  case 12: /* varDeclInit: varDeclId  */
#line 86 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1396 "parser.tab.c"
    break;

  case 13: /* varDeclInit: varDeclId COLON simpleExp  */
#line 87 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-2].tree); (yyval.tree)->child[0] = (yyvsp[0].tree); }
#line 1402 "parser.tab.c"
    break;

  case 14: /* varDeclId: ID  */
#line 90 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(VarK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput; }
#line 1408 "parser.tab.c"
    break;

  case 15: /* varDeclId: ID LBRACKET NUMCONST RBRACKET  */
#line 91 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(VarK, (yyvsp[-3].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->isArray = true;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[-3].tokenData); (yyval.tree)->expType = UndefinedType; }
#line 1417 "parser.tab.c"
    break;

  case 16: /* typeSpec: BOOL  */
#line 97 "parser.y"
                                                                                { (yyval.type) = Boolean; }
#line 1423 "parser.tab.c"
    break;

  case 17: /* typeSpec: CHAR  */
#line 98 "parser.y"
                                                                                { (yyval.type) = Char; }
#line 1429 "parser.tab.c"
    break;

  case 18: /* typeSpec: INT  */
#line 99 "parser.y"
                                                                                { (yyval.type) = Integer; }
#line 1435 "parser.tab.c"
    break;

  case 19: /* funDecl: typeSpec ID LPAREN parms RPAREN compoundStmt  */
#line 102 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-4].tokenData)->tokenStrInput);
                                                                                  (yyval.tree)->expType = (yyvsp[-5].type);
                                                                                  //$$->thisTokenData = $2;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1446 "parser.tab.c"
    break;

  case 20: /* funDecl: ID LPAREN parms RPAREN compoundStmt  */
#line 109 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-4].tokenData)->tokenStrInput);
                                                                                  //$$->expType = $1;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[-4].tokenData);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1457 "parser.tab.c"
    break;

  case 21: /* parms: parmList  */
#line 117 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ; }
#line 1463 "parser.tab.c"
    break;

  case 22: /* parms: %empty  */
#line 118 "parser.y"
                                                                                { (yyval.tree) = NULL ; }
#line 1469 "parser.tab.c"
    break;

  case 23: /* parmList: parmList SEMICOLON parmTypeList  */
#line 121 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1475 "parser.tab.c"
    break;

  case 24: /* parmList: parmTypeList  */
#line 122 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ; }
#line 1481 "parser.tab.c"
    break;

  case 25: /* parmTypeList: typeSpec parmIdList  */
#line 125 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); convertSiblingType((yyval.tree), (yyvsp[-1].type)); }
#line 1487 "parser.tab.c"
    break;

  case 26: /* parmIdList: parmIdList COMMA parmId  */
#line 128 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1493 "parser.tab.c"
    break;

  case 27: /* parmIdList: parmId  */
#line 129 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1499 "parser.tab.c"
    break;

  case 28: /* parmId: ID  */
#line 132 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(ParamK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[0].tokenData)->tokenStrInput); }
#line 1506 "parser.tab.c"
    break;

  case 29: /* parmId: ID LBRACKET RBRACKET  */
#line 135 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(ParamK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-2].tokenData)->tokenStrInput); 
                                                                                  (yyval.tree)->isArray = true;}
#line 1514 "parser.tab.c"
    break;

  case 30: /* stmt: matchedif  */
#line 140 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1520 "parser.tab.c"
    break;

  case 31: /* stmt: unmatchedif  */
#line 141 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1526 "parser.tab.c"
    break;

  case 32: /* expStmt: exp SEMICOLON  */
#line 144 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); }
#line 1532 "parser.tab.c"
    break;

  case 33: /* expStmt: SEMICOLON  */
#line 145 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1538 "parser.tab.c"
    break;

  case 34: /* compoundStmt: START localDecls stmtList STOP  */
#line 148 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(CompoundK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-1].tree); }
#line 1546 "parser.tab.c"
    break;

  case 35: /* localDecls: localDecls scopedVarDecl  */
#line 153 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1552 "parser.tab.c"
    break;

  case 36: /* localDecls: %empty  */
#line 154 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1558 "parser.tab.c"
    break;

  case 37: /* stmtList: stmtList stmt  */
#line 157 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1564 "parser.tab.c"
    break;

  case 38: /* stmtList: %empty  */
#line 158 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1570 "parser.tab.c"
    break;

  case 39: /* matchedif: endStmt  */
#line 162 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1576 "parser.tab.c"
    break;

  case 40: /* matchedif: IF simpleExp THEN matchedif ELSE matchedif  */
#line 163 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1585 "parser.tab.c"
    break;

  case 41: /* matchedif: WHILE simpleExp DO matchedif  */
#line 168 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1594 "parser.tab.c"
    break;

  case 42: /* matchedif: FOR ID ASGN iterRange DO matchedif  */
#line 173 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = newDeclNode(VarK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->child[0]->expType = Integer;
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1605 "parser.tab.c"
    break;

  case 43: /* unmatchedif: IF simpleExp THEN matchedif ELSE unmatchedif  */
#line 181 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1614 "parser.tab.c"
    break;

  case 44: /* unmatchedif: WHILE simpleExp DO unmatchedif  */
#line 186 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1623 "parser.tab.c"
    break;

  case 45: /* unmatchedif: FOR ID ASGN iterRange DO unmatchedif  */
#line 191 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = newDeclNode(VarK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->child[0]->expType = Integer;
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1634 "parser.tab.c"
    break;

  case 46: /* unmatchedif: IF simpleExp THEN stmt  */
#line 198 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1642 "parser.tab.c"
    break;

  case 47: /* endStmt: expStmt  */
#line 203 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1648 "parser.tab.c"
    break;

  case 48: /* endStmt: compoundStmt  */
#line 204 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1654 "parser.tab.c"
    break;

  case 49: /* endStmt: returnStmt  */
#line 205 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1660 "parser.tab.c"
    break;

  case 50: /* endStmt: breakStmt  */
#line 206 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1666 "parser.tab.c"
    break;

  case 51: /* iterRange: simpleExp TO simpleExp  */
#line 209 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(RangeK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1674 "parser.tab.c"
    break;

  case 52: /* iterRange: simpleExp TO simpleExp BY simpleExp  */
#line 213 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(RangeK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1683 "parser.tab.c"
    break;

  case 53: /* returnStmt: RETURN SEMICOLON  */
#line 219 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;}
#line 1690 "parser.tab.c"
    break;

  case 54: /* returnStmt: RETURN exp SEMICOLON  */
#line 222 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenStrInput; 
                                                                                  (yyval.tree)->expType = (yyvsp[-1].tree)->expType;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree);}
#line 1699 "parser.tab.c"
    break;

  case 55: /* breakStmt: BREAK SEMICOLON  */
#line 228 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(BreakK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput; }
#line 1706 "parser.tab.c"
    break;

  case 56: /* exp: mutable assignop exp  */
#line 232 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1714 "parser.tab.c"
    break;

  case 57: /* exp: mutable INC  */
#line 236 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree); }
#line 1723 "parser.tab.c"
    break;

  case 58: /* exp: mutable DEC  */
#line 241 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree); }
#line 1732 "parser.tab.c"
    break;

  case 59: /* exp: simpleExp  */
#line 246 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1738 "parser.tab.c"
    break;

  case 60: /* assignop: ASGN  */
#line 249 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 1744 "parser.tab.c"
    break;

  case 61: /* assignop: ADDASGN  */
#line 250 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 1750 "parser.tab.c"
    break;

  case 62: /* assignop: MINUSASGN  */
#line 251 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 1756 "parser.tab.c"
    break;

  case 63: /* assignop: MULTASGN  */
#line 252 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 1762 "parser.tab.c"
    break;

  case 64: /* assignop: DIVASGN  */
#line 253 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 1768 "parser.tab.c"
    break;

  case 65: /* simpleExp: simpleExp OR andExp  */
#line 256 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1778 "parser.tab.c"
    break;

  case 66: /* simpleExp: andExp  */
#line 262 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1784 "parser.tab.c"
    break;

  case 67: /* andExp: andExp AND unaryRelExp  */
#line 265 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1794 "parser.tab.c"
    break;

  case 68: /* andExp: unaryRelExp  */
#line 271 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1800 "parser.tab.c"
    break;

  case 69: /* unaryRelExp: NOT unaryRelExp  */
#line 274 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[0].tree);}
#line 1809 "parser.tab.c"
    break;

  case 70: /* unaryRelExp: relExp  */
#line 279 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1815 "parser.tab.c"
    break;

  case 71: /* relExp: sumExp relop sumExp  */
#line 282 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1823 "parser.tab.c"
    break;

  case 72: /* relExp: sumExp  */
#line 286 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ;}
#line 1829 "parser.tab.c"
    break;

  case 73: /* relop: LESSTHAN  */
#line 289 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1837 "parser.tab.c"
    break;

  case 74: /* relop: LEQ  */
#line 293 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1845 "parser.tab.c"
    break;

  case 75: /* relop: GREATERTHAN  */
#line 297 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1853 "parser.tab.c"
    break;

  case 76: /* relop: GEQ  */
#line 301 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1861 "parser.tab.c"
    break;

  case 77: /* relop: EQUALS  */
#line 305 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1869 "parser.tab.c"
    break;

  case 78: /* relop: NEQ  */
#line 309 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 1877 "parser.tab.c"
    break;

  case 79: /* sumExp: sumExp sumop mulExp  */
#line 314 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1885 "parser.tab.c"
    break;

  case 80: /* sumExp: mulExp  */
#line 318 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1891 "parser.tab.c"
    break;

  case 81: /* sumop: PLUS  */
#line 321 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1899 "parser.tab.c"
    break;

  case 82: /* sumop: MINUS  */
#line 325 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1907 "parser.tab.c"
    break;

  case 83: /* mulExp: mulExp mulop unaryExp  */
#line 330 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1915 "parser.tab.c"
    break;

  case 84: /* mulExp: unaryExp  */
#line 334 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1921 "parser.tab.c"
    break;

  case 85: /* mulop: MULT  */
#line 337 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1929 "parser.tab.c"
    break;

  case 86: /* mulop: DIVIDE  */
#line 341 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1937 "parser.tab.c"
    break;

  case 87: /* mulop: PERCENT  */
#line 345 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1945 "parser.tab.c"
    break;

  case 88: /* unaryExp: unaryop unaryExp  */
#line 350 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[0].tree); }
#line 1952 "parser.tab.c"
    break;

  case 89: /* unaryExp: factor  */
#line 353 "parser.y"
                                                                              { (yyval.tree) = (yyvsp[0].tree); }
#line 1958 "parser.tab.c"
    break;

  case 90: /* unaryop: MINUS  */
#line 356 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1966 "parser.tab.c"
    break;

  case 91: /* unaryop: MULT  */
#line 360 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1974 "parser.tab.c"
    break;

  case 92: /* unaryop: QMARK  */
#line 364 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 1982 "parser.tab.c"
    break;

  case 93: /* factor: mutable  */
#line 369 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1988 "parser.tab.c"
    break;

  case 94: /* factor: immutable  */
#line 370 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1994 "parser.tab.c"
    break;

  case 95: /* mutable: ID  */
#line 373 "parser.y"
                                                                                { (yyval.tree) = newExpNode(IdK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[0].tokenData)->tokenStrInput); }
#line 2001 "parser.tab.c"
    break;

  case 96: /* mutable: ID LBRACKET exp RBRACKET  */
#line 376 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0] = newExpNode(IdK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0]->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0]->isArray = true;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-1].tree); }
#line 2012 "parser.tab.c"
    break;

  case 97: /* immutable: LPAREN exp RPAREN  */
#line 384 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); }
#line 2018 "parser.tab.c"
    break;

  case 98: /* immutable: call  */
#line 385 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2024 "parser.tab.c"
    break;

  case 99: /* immutable: constant  */
#line 386 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2030 "parser.tab.c"
    break;

  case 100: /* call: ID LPAREN args RPAREN  */
#line 389 "parser.y"
                                                                                { (yyval.tree) = newExpNode(CallK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-3].tokenData)->tokenStrInput);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree);}
#line 2038 "parser.tab.c"
    break;

  case 101: /* args: argList  */
#line 394 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2044 "parser.tab.c"
    break;

  case 102: /* args: %empty  */
#line 395 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2050 "parser.tab.c"
    break;

  case 103: /* argList: argList COMMA exp  */
#line 398 "parser.y"
                                                                                {(yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2056 "parser.tab.c"
    break;

  case 104: /* argList: exp  */
#line 399 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2062 "parser.tab.c"
    break;

  case 105: /* constant: NUMCONST  */
#line 402 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue;
                                                                                  (yyval.tree)->expType = Integer; }
#line 2070 "parser.tab.c"
    break;

  case 106: /* constant: CHARCONST  */
#line 406 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[0].tokenData);
                                                                                  (yyval.tree)->expType = Char; }
#line 2079 "parser.tab.c"
    break;

  case 107: /* constant: STRINGCONST  */
#line 411 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.string = strdup((yyvsp[0].tokenData)->svalue);
                                                                                  (yyval.tree)->isArray = true;
                                                                                  (yyval.tree)->expType = CharInt; }
#line 2088 "parser.tab.c"
    break;

  case 108: /* constant: BOOLCONST  */
#line 416 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean; }
#line 2097 "parser.tab.c"
    break;


#line 2101 "parser.tab.c"

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

#line 422 "parser.y"


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
