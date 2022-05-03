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
//Last Updated: 4-09-22
//parser.y
//This file contains Bison Code
#include "scanType.h" //TokenData type 
#include "syntaxTree.h"
#include "codeGen.h"
#include "semantic.h"
#include "IOinit.h"
#include "yyerror.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <iostream>
#include <fstream>


extern int yylex();
extern FILE *yyin;
extern int line;    //ERR line number from scanner
extern int numErrors;  // ERR err count
int numWarnings; //warning count
static TreeNode *ast;
bool TYPES = false;
bool printOffset = false;
bool opM;

extern int goffset;

extern SymbolTable symbolTable;

extern FILE *code;
FILE *fp;

#define YYERROR_VERBOSE
/*void yyerror(const char *msg)
{
    printf("ERROR(%d): %s\n", line, msg);
    numErrors++;
}*/


#line 119 "parser.tab.c"

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   724

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

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
       0,    77,    77,    80,    81,    84,    85,    86,    89,    93,
      95,    99,   103,   108,   111,   112,   113,   116,   118,   123,
     127,   128,   133,   134,   138,   139,   140,   143,   151,   158,
     159,   160,   161,   164,   165,   168,   169,   170,   171,   174,
     175,   178,   180,   181,   182,   185,   187,   192,   193,   196,
     197,   198,   202,   208,   209,   212,   213,   217,   218,   223,
     224,   225,   227,   232,   234,   236,   243,   244,   247,   252,
     255,   260,   263,   270,   273,   277,   280,   281,   282,   283,
     286,   290,   295,   296,   298,   301,   304,   310,   314,   318,
     322,   327,   332,   334,   335,   336,   337,   340,   341,   342,
     343,   344,   347,   353,   354,   357,   363,   364,   367,   372,
     373,   376,   380,   382,   385,   389,   393,   397,   401,   405,
     410,   414,   415,   418,   422,   427,   431,   432,   435,   439,
     443,   448,   451,   452,   455,   459,   463,   468,   469,   472,
     475,   483,   484,   485,   486,   489,   493,   496,   497,   500,
     501,   502,   505,   509,   514,   520
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

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-149)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,   212,   -12,  -133,  -133,  -133,    69,   637,  -133,  -133,
      98,  -133,    14,    44,   161,  -133,    24,     3,  -133,  -133,
      40,    77,   232,   284,  -133,   148,  -133,   201,   284,    -9,
     213,    78,   118,  -133,  -133,    50,  -133,   107,   177,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,   293,   324,   108,   120,
    -133,  -133,   208,   160,  -133,    10,  -133,  -133,  -133,  -133,
    -133,  -133,   129,    14,  -133,   108,   153,   149,   175,  -133,
       7,    33,    -9,   167,  -133,   333,    23,   107,  -133,   675,
     173,   108,   688,   364,   373,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,   604,   613,  -133,  -133,  -133,   625,   107,
    -133,  -133,   182,   240,  -133,  -133,  -133,  -133,  -133,   219,
     675,   196,  -133,   222,   235,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,   333,  -133,  -133,  -133,   404,   107,   120,   107,
    -133,   107,   215,   107,   160,   107,  -133,  -133,  -133,  -133,
     258,  -133,  -133,  -133,   413,  -133,   675,  -133,   121,  -133,
     251,   157,   675,  -133,   251,   248,   640,  -133,   444,   263,
     242,   102,  -133,   453,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,   254,   256,  -133,  -133,   -11,    71,  -133,   277,
    -133,   653,  -133,   268,     5,    41,  -133,  -133,   204,   204,
     244,   484,  -133,  -133,   244,   244,   493,   267,   524,   274,
    -133,  -133,   276,    97,   269,   -29,  -133,  -133,  -133,  -133,
      66,    83,   295,    99,    76,   244,   244,   244,   310,   244,
     533,   204,   204,   564,   204,   204,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,   107,    79,   280,   283,   130,
     278,   573,   204,   204,   204,   204,   107,   108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    24,    25,    26,     0,     0,     4,     5,
       0,     6,    16,    20,     0,    15,    17,     0,     1,     3,
      29,    20,     0,     0,    23,     0,     9,     0,     0,    31,
       0,     0,    33,    36,    10,     0,     8,     0,   139,   152,
     153,   154,   155,   134,   135,   136,     0,     0,    19,   103,
     106,   109,   113,   121,   126,     0,   132,   137,   138,   142,
     143,    22,     0,    14,    13,    18,    40,    45,    39,    42,
       0,     0,    30,     0,   146,     0,     0,   110,   108,   144,
       0,    92,   137,     0,     0,   119,   115,   117,   123,   124,
     118,   114,   116,     0,     0,   129,   128,   130,     0,   133,
     131,    21,     0,     0,    32,    54,    28,    37,    35,     0,
       0,     0,   150,     0,   147,    95,    96,    97,    98,    99,
     100,   101,     0,   141,    90,    91,     0,   104,   102,   107,
     105,   112,   111,   122,   120,   127,   125,    46,    43,    41,
      56,    27,   140,   145,     0,    93,    94,    89,     0,    53,
       0,     0,   151,   149,     0,     0,     0,    50,     0,     0,
       0,     0,    52,     0,    55,    76,    77,    47,    48,    57,
      78,    79,     0,     0,    12,    51,    59,     0,    67,     0,
      88,     0,    85,     0,    64,     0,    49,    11,     0,     0,
       0,     0,    87,    86,     0,     0,     0,     0,     0,    75,
      60,    74,    47,     0,     0,     0,    63,    71,    62,    70,
      59,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    69,    58,    68,
      66,    73,    83,    65,    72,    82,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,   312,  -133,  -133,    -7,   290,  -133,     2,
    -133,   285,  -133,   250,  -133,   220,   134,  -133,   -45,  -133,
    -133,  -132,   -62,  -133,   109,  -133,  -133,   -40,   259,   -22,
     260,    -4,  -133,  -133,   253,  -133,   255,  -133,   -43,  -133,
    -133,   -23,  -133,  -133,  -133,  -133,  -133
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,   149,    14,    15,    16,    30,
      11,    31,    32,    33,    68,    69,   164,   165,   166,   140,
     151,   206,   168,   169,   204,   170,   171,   172,   122,    81,
      49,    50,    51,    93,    52,    94,    53,    98,    54,    55,
      56,    82,    58,    59,   113,   114,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    48,    10,    22,    29,    57,    65,    80,   104,    10,
     220,    99,   100,    38,    39,    40,    41,    42,   -38,   167,
     188,   189,    83,    57,   110,   106,    38,    39,    40,    41,
      42,    43,    57,    44,   107,   111,   112,    17,    74,    45,
      23,   -38,    78,   105,    43,   194,    44,     3,     4,     5,
      28,    72,    45,   -34,    74,   136,   199,   200,   202,    47,
      57,    57,    24,   208,   141,    46,    23,    34,   -16,    18,
      57,    57,    47,  -148,     1,    57,     2,     3,     4,     5,
     130,   195,   145,   226,   228,   230,   147,   233,    24,   237,
     238,    25,    83,   208,     3,     4,     5,   221,   189,    20,
     -34,    21,   190,   181,   153,    38,    39,    40,    41,    42,
     226,   228,   230,   233,   222,    74,   225,     3,     4,     5,
     241,   183,    83,    43,    25,    44,    35,    83,    70,   182,
      83,    45,   207,   209,    83,    57,   177,   217,   218,   224,
      57,   185,   150,   155,    46,    71,    74,   173,    74,    61,
     154,    47,    62,   227,   229,   231,    74,   234,   156,    83,
      38,    39,    40,    41,    42,     3,     4,     5,    57,   205,
     244,   218,    84,    57,   211,    57,   214,   101,    43,    74,
      44,   -44,    95,    96,   157,    97,    45,   158,    26,    27,
     159,   160,   161,   105,   162,   163,   102,    57,   236,    46,
      57,   205,    63,   103,    13,   156,    47,    38,    39,    40,
      41,    42,    -7,    12,    66,    13,    67,   109,    57,   247,
      85,    86,    87,   123,    75,    43,    76,    44,    88,    89,
     137,   157,    90,    45,   196,    88,    89,   197,   160,   161,
     105,   138,   198,    67,   142,   156,    46,    38,    39,    40,
      41,    42,    12,    47,    13,   105,    -7,    -7,    -7,    36,
      27,    91,    92,   144,   178,    43,   179,    44,   178,   180,
     212,   157,   143,    45,   158,   174,    27,   159,   160,   161,
     105,   186,   163,   187,    27,    37,    46,    38,    39,    40,
      41,    42,   191,    47,    77,   193,    38,    39,    40,    41,
      42,   148,     3,     4,     5,    43,   215,    44,   216,   219,
     223,   232,   242,    45,    43,   243,    44,    64,   245,    19,
      73,   108,    45,   139,   201,    79,    46,    38,    39,    40,
      41,    42,   240,    47,   110,    46,    38,    39,    40,    41,
      42,   126,    47,   128,     0,    43,   132,    44,     0,   134,
       0,     0,     0,    45,    43,     0,    44,     0,     0,     0,
       0,     0,    45,     0,     0,   127,    46,    38,    39,    40,
      41,    42,     0,    47,   129,    46,    38,    39,    40,    41,
      42,     0,    47,     0,     0,    43,     0,    44,     0,     0,
       0,     0,     0,    45,    43,     0,    44,     0,     0,     0,
       0,     0,    45,     0,     0,   146,    46,    38,    39,    40,
      41,    42,     0,    47,   152,    46,    38,    39,    40,    41,
      42,     0,    47,     0,     0,    43,     0,    44,     0,     0,
       0,     0,     0,    45,    43,     0,    44,     0,     0,     0,
       0,     0,    45,     0,     0,   176,    46,    38,    39,    40,
      41,    42,     0,    47,   184,    46,    38,    39,    40,    41,
      42,     0,    47,     0,     0,    43,     0,    44,     0,     0,
       0,     0,     0,    45,    43,     0,    44,     0,     0,     0,
       0,     0,    45,     0,     0,   203,    46,    38,    39,    40,
      41,    42,     0,    47,   210,    46,    38,    39,    40,    41,
      42,     0,    47,     0,     0,    43,     0,    44,     0,     0,
       0,     0,     0,    45,    43,     0,    44,     0,     0,     0,
       0,     0,    45,     0,     0,   213,    46,    38,    39,    40,
      41,    42,     0,    47,   235,    46,    38,    39,    40,    41,
      42,     0,    47,     0,     0,    43,     0,    44,     0,     0,
       0,     0,     0,    45,    43,     0,    44,     0,     0,     0,
       0,     0,    45,     0,     0,   239,    46,    38,    39,    40,
      41,    42,     0,    47,   246,    46,    38,    39,    40,    41,
      42,     0,    47,     0,     0,    43,     0,    44,     0,     0,
       0,     0,     0,    45,    43,     0,    44,     0,     0,     0,
       0,     0,    45,     0,     0,   131,    46,    38,    39,    40,
      41,    42,     0,    47,   133,    46,    38,    39,    40,    41,
      42,     0,    47,     0,     0,    43,   135,    44,    38,    39,
      40,    41,    42,    45,    43,     0,    44,    -2,     1,     0,
       2,     0,    45,     0,     0,     0,    43,     0,    44,     0,
     115,   116,     0,    47,    45,   117,   118,   119,   120,   121,
       0,     0,    47,   115,   116,     0,     0,   175,   117,   118,
     119,   120,   121,     0,    47,     0,     0,     0,     0,     0,
     192,     3,     4,     5,     0,   115,   116,     0,     0,    74,
     117,   118,   119,   120,   121,     0,     0,     0,   124,   125,
       0,     0,    74,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74
};

static const yytype_int16 yycheck[] =
{
      23,    23,     0,    10,     1,    28,    28,    47,     1,     7,
      39,     1,    55,     3,     4,     5,     6,     7,    27,   151,
      31,    32,    51,    46,     1,    70,     3,     4,     5,     6,
       7,    21,    55,    23,     1,    75,    76,    49,    49,    29,
      26,    50,    46,    36,    21,    40,    23,    44,    45,    46,
      26,     1,    29,    50,    49,    98,   188,   189,   190,    49,
      83,    84,    48,   195,   109,    42,    26,    27,    28,     0,
      93,    94,    49,    50,     1,    98,     3,    44,    45,    46,
      84,    40,   122,   215,   216,   217,   126,   219,    48,   221,
     222,    47,    51,   225,    44,    45,    46,    31,    32,     1,
      50,     3,    31,     1,   144,     3,     4,     5,     6,     7,
     242,   243,   244,   245,    31,    49,    40,    44,    45,    46,
      41,   161,    51,    21,    47,    23,    49,    51,    50,    27,
      51,    29,   194,   195,    51,   158,   158,    40,    41,    40,
     163,   163,   140,   150,    42,    27,    49,   154,    49,     1,
     148,    49,     4,   215,   216,   217,    49,   219,     1,    51,
       3,     4,     5,     6,     7,    44,    45,    46,   191,   191,
      40,    41,    52,   196,   196,   198,   198,    48,    21,    49,
      23,    28,    22,    23,    27,    25,    29,    30,    27,    28,
      33,    34,    35,    36,    37,    38,    47,   220,   220,    42,
     223,   223,     1,    28,     3,     1,    49,     3,     4,     5,
       6,     7,     0,     1,     1,     3,     3,    50,   241,   241,
      12,    13,    14,    50,    47,    21,    49,    23,    20,    21,
      48,    27,    24,    29,    30,    20,    21,    33,    34,    35,
      36,     1,    38,     3,    48,     1,    42,     3,     4,     5,
       6,     7,     1,    49,     3,    36,    44,    45,    46,    27,
      28,    53,    54,    28,     1,    21,     3,    23,     1,    27,
       3,    27,    50,    29,    30,    27,    28,    33,    34,    35,
      36,    27,    38,    27,    28,     1,    42,     3,     4,     5,
       6,     7,    15,    49,     1,    27,     3,     4,     5,     6,
       7,    43,    44,    45,    46,    21,    32,    23,    32,    40,
      15,     1,    32,    29,    21,    32,    23,    27,    40,     7,
      35,    71,    29,   103,   190,     1,    42,     3,     4,     5,
       6,     7,   223,    49,     1,    42,     3,     4,     5,     6,
       7,    82,    49,    83,    -1,    21,    93,    23,    -1,    94,
      -1,    -1,    -1,    29,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,     1,    42,     3,     4,     5,
       6,     7,    -1,    49,     1,    42,     3,     4,     5,     6,
       7,    -1,    49,    -1,    -1,    21,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    29,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,     1,    42,     3,     4,     5,
       6,     7,    -1,    49,     1,    42,     3,     4,     5,     6,
       7,    -1,    49,    -1,    -1,    21,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    29,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,     1,    42,     3,     4,     5,
       6,     7,    -1,    49,     1,    42,     3,     4,     5,     6,
       7,    -1,    49,    -1,    -1,    21,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    29,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,     1,    42,     3,     4,     5,
       6,     7,    -1,    49,     1,    42,     3,     4,     5,     6,
       7,    -1,    49,    -1,    -1,    21,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    29,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,     1,    42,     3,     4,     5,
       6,     7,    -1,    49,     1,    42,     3,     4,     5,     6,
       7,    -1,    49,    -1,    -1,    21,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    29,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,     1,    42,     3,     4,     5,
       6,     7,    -1,    49,     1,    42,     3,     4,     5,     6,
       7,    -1,    49,    -1,    -1,    21,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    29,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,     1,    42,     3,     4,     5,
       6,     7,    -1,    49,     1,    42,     3,     4,     5,     6,
       7,    -1,    49,    -1,    -1,    21,     1,    23,     3,     4,
       5,     6,     7,    29,    21,    -1,    23,     0,     1,    -1,
       3,    -1,    29,    -1,    -1,    -1,    21,    -1,    23,    -1,
      10,    11,    -1,    49,    29,    15,    16,    17,    18,    19,
      -1,    -1,    49,    10,    11,    -1,    -1,    27,    15,    16,
      17,    18,    19,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      27,    44,    45,    46,    -1,    10,    11,    -1,    -1,    49,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    10,    11,
      -1,    -1,    49,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    44,    45,    46,    56,    57,    58,    59,
      64,    65,     1,     3,    61,    62,    63,    49,     0,    58,
       1,     3,    61,    26,    48,    47,    27,    28,    26,     1,
      64,    66,    67,    68,    27,    49,    27,     1,     3,     4,
       5,     6,     7,    21,    23,    29,    42,    49,    84,    85,
      86,    87,    89,    91,    93,    94,    95,    96,    97,    98,
     101,     1,     4,     1,    62,    84,     1,     3,    69,    70,
      50,    27,     1,    66,    49,    47,    49,     1,    86,     1,
      82,    84,    96,    51,    52,    12,    13,    14,    20,    21,
      24,    53,    54,    88,    90,    22,    23,    25,    92,     1,
      93,    48,    47,    28,     1,    36,    73,     1,    68,    50,
       1,    82,    82,    99,   100,    10,    11,    15,    16,    17,
      18,    19,    83,    50,    10,    11,    83,     1,    85,     1,
      86,     1,    89,     1,    91,     1,    93,    48,     1,    70,
      74,    73,    48,    50,    28,    82,     1,    82,    43,    60,
      64,    75,     1,    82,    64,    61,     1,    27,    30,    33,
      34,    35,    37,    38,    71,    72,    73,    76,    77,    78,
      80,    81,    82,    61,    27,    27,     1,    84,     1,     3,
      27,     1,    27,    82,     1,    84,    27,    27,    31,    32,
      31,    15,    27,    27,    40,    40,    30,    33,    38,    76,
      76,    71,    76,     1,    79,    84,    76,    77,    76,    77,
       1,    84,     3,     1,    84,    32,    32,    40,    41,    40,
      39,    31,    31,    15,    40,    40,    76,    77,    76,    77,
      76,    77,     1,    76,    77,     1,    84,    76,    76,     1,
      79,    41,    32,    32,    40,    40,     1,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    80,    80,    80,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    84,    84,    84,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    90,    90,    91,    91,    91,    92,    92,
      92,    93,    93,    93,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    97,    98,    98,    99,    99,   100,
     100,   100,   101,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       3,     4,     3,     3,     3,     1,     1,     1,     3,     3,
       1,     4,     3,     2,     1,     1,     1,     6,     5,     2,
       4,     3,     5,     1,     0,     3,     1,     3,     1,     2,
       2,     3,     1,     3,     1,     1,     3,     1,     1,     2,
       1,     2,     4,     2,     0,     2,     0,     1,     6,     2,
       4,     6,     4,     4,     2,     6,     6,     2,     6,     6,
       4,     4,     6,     6,     4,     4,     1,     1,     1,     1,
       3,     5,     3,     3,     5,     2,     3,     3,     2,     3,
       2,     2,     1,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     3,     1,     3,     3,     1,     3,     2,     1,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     3,     1,     3,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     1,     2,     4,     2,     1,     0,     3,
       1,     3,     1,     1,     1,     1
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
#line 77 "parser.y"
                                                                                { ast = (yyvsp[0].tree) ;}
#line 1493 "parser.tab.c"
    break;

  case 3: /* declList: declList decl  */
#line 80 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1499 "parser.tab.c"
    break;

  case 4: /* declList: decl  */
#line 81 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1505 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 84 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1511 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 85 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1517 "parser.tab.c"
    break;

  case 7: /* decl: error  */
#line 86 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1523 "parser.tab.c"
    break;

  case 8: /* varDecl: typeSpec varDeclList SEMICOLON  */
#line 89 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); 
                                                                                  convertSiblingType((yyval.tree), (yyvsp[-2].type)); 
                                                                                  yyerrok; }
#line 1531 "parser.tab.c"
    break;

  case 9: /* varDecl: error varDeclList SEMICOLON  */
#line 93 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 1538 "parser.tab.c"
    break;

  case 10: /* varDecl: typeSpec error SEMICOLON  */
#line 95 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 1545 "parser.tab.c"
    break;

  case 11: /* scopedVarDecl: STATIC typeSpec varDeclList SEMICOLON  */
#line 99 "parser.y"
                                                                                {(yyval.tree) = (yyvsp[-1].tree); (yyval.tree)->isStatic = true; 
                                                                                  convertSiblingType((yyval.tree), (yyvsp[-2].type)); 
                                                                                  yyerrok; }
#line 1553 "parser.tab.c"
    break;

  case 12: /* scopedVarDecl: typeSpec varDeclList SEMICOLON  */
#line 103 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); 
                                                                                  convertSiblingType((yyval.tree), (yyvsp[-2].type)); 
                                                                                  yyerrok; }
#line 1561 "parser.tab.c"
    break;

  case 13: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 108 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree)); 
                                                                                  yyerrok; }
#line 1568 "parser.tab.c"
    break;

  case 14: /* varDeclList: varDeclList COMMA error  */
#line 111 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1574 "parser.tab.c"
    break;

  case 15: /* varDeclList: varDeclInit  */
#line 112 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1580 "parser.tab.c"
    break;

  case 16: /* varDeclList: error  */
#line 113 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1586 "parser.tab.c"
    break;

  case 17: /* varDeclInit: varDeclId  */
#line 116 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1592 "parser.tab.c"
    break;

  case 18: /* varDeclInit: varDeclId COLON simpleExp  */
#line 118 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-2].tree); 
                                                                                  if((yyvsp[-2].tree) != NULL){
                                                                                      (yyval.tree)->child[0] = (yyvsp[0].tree);
                                                                                    } }
#line 1601 "parser.tab.c"
    break;

  case 19: /* varDeclInit: error COLON simpleExp  */
#line 123 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 1608 "parser.tab.c"
    break;

  case 20: /* varDeclId: ID  */
#line 127 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(VarK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput; }
#line 1614 "parser.tab.c"
    break;

  case 21: /* varDeclId: ID LBRACKET NUMCONST RBRACKET  */
#line 128 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(VarK, (yyvsp[-3].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->isArray = true;
                                                                                  (yyval.tree)->arrLength = (yyvsp[-1].tokenData)->nvalue;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[-3].tokenData); (yyval.tree)->expType = UndefinedType;}
#line 1624 "parser.tab.c"
    break;

  case 22: /* varDeclId: ID LBRACKET error  */
#line 133 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1630 "parser.tab.c"
    break;

  case 23: /* varDeclId: error RBRACKET  */
#line 134 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok;}
#line 1637 "parser.tab.c"
    break;

  case 24: /* typeSpec: BOOL  */
#line 138 "parser.y"
                                                                                { (yyval.type) = Boolean; }
#line 1643 "parser.tab.c"
    break;

  case 25: /* typeSpec: CHAR  */
#line 139 "parser.y"
                                                                                { (yyval.type) = Char; }
#line 1649 "parser.tab.c"
    break;

  case 26: /* typeSpec: INT  */
#line 140 "parser.y"
                                                                                { (yyval.type) = Integer; }
#line 1655 "parser.tab.c"
    break;

  case 27: /* funDecl: typeSpec ID LPAREN parms RPAREN compoundStmt  */
#line 143 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-4].tokenData)->tokenStrInput);
                                                                                  (yyval.tree)->expType = (yyvsp[-5].type);
                                                                                  //$$->thisTokenData = $2;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1666 "parser.tab.c"
    break;

  case 28: /* funDecl: ID LPAREN parms RPAREN compoundStmt  */
#line 151 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-4].tokenData)->tokenStrInput);
                                                                                  //$$->expType = $1;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[-4].tokenData);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1677 "parser.tab.c"
    break;

  case 29: /* funDecl: typeSpec error  */
#line 158 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1683 "parser.tab.c"
    break;

  case 30: /* funDecl: typeSpec ID LPAREN error  */
#line 159 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1689 "parser.tab.c"
    break;

  case 31: /* funDecl: ID LPAREN error  */
#line 160 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1695 "parser.tab.c"
    break;

  case 32: /* funDecl: ID LPAREN parms RPAREN error  */
#line 161 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1701 "parser.tab.c"
    break;

  case 33: /* parms: parmList  */
#line 164 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ; }
#line 1707 "parser.tab.c"
    break;

  case 34: /* parms: %empty  */
#line 165 "parser.y"
                                                                                { (yyval.tree) = NULL ; }
#line 1713 "parser.tab.c"
    break;

  case 35: /* parmList: parmList SEMICOLON parmTypeList  */
#line 168 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1719 "parser.tab.c"
    break;

  case 36: /* parmList: parmTypeList  */
#line 169 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ; }
#line 1725 "parser.tab.c"
    break;

  case 37: /* parmList: parmList SEMICOLON error  */
#line 170 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1731 "parser.tab.c"
    break;

  case 38: /* parmList: error  */
#line 171 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1737 "parser.tab.c"
    break;

  case 39: /* parmTypeList: typeSpec parmIdList  */
#line 174 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); convertSiblingType((yyval.tree), (yyvsp[-1].type)); }
#line 1743 "parser.tab.c"
    break;

  case 40: /* parmTypeList: typeSpec error  */
#line 175 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1749 "parser.tab.c"
    break;

  case 41: /* parmIdList: parmIdList COMMA parmId  */
#line 178 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree)); 
                                                                                  yyerrok; }
#line 1756 "parser.tab.c"
    break;

  case 42: /* parmIdList: parmId  */
#line 180 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1762 "parser.tab.c"
    break;

  case 43: /* parmIdList: parmIdList COMMA error  */
#line 181 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1768 "parser.tab.c"
    break;

  case 44: /* parmIdList: error  */
#line 182 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1774 "parser.tab.c"
    break;

  case 45: /* parmId: ID  */
#line 185 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(ParamK, (yyvsp[0].tokenData));(yyval.tree)->attr.name = strdup((yyvsp[0].tokenData)->tokenStrInput); }
#line 1780 "parser.tab.c"
    break;

  case 46: /* parmId: ID LBRACKET RBRACKET  */
#line 187 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(ParamK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-2].tokenData)->tokenStrInput); 
                                                                                  (yyval.tree)->isArray = true;}
#line 1788 "parser.tab.c"
    break;

  case 47: /* stmt: matchedif  */
#line 192 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1794 "parser.tab.c"
    break;

  case 48: /* stmt: unmatchedif  */
#line 193 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1800 "parser.tab.c"
    break;

  case 49: /* expStmt: exp SEMICOLON  */
#line 196 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); }
#line 1806 "parser.tab.c"
    break;

  case 50: /* expStmt: SEMICOLON  */
#line 197 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1812 "parser.tab.c"
    break;

  case 51: /* expStmt: error SEMICOLON  */
#line 198 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 1819 "parser.tab.c"
    break;

  case 52: /* compoundStmt: START localDecls stmtList STOP  */
#line 202 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(CompoundK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-1].tree); 
                                                                                  yyerrok; }
#line 1828 "parser.tab.c"
    break;

  case 53: /* localDecls: localDecls scopedVarDecl  */
#line 208 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1834 "parser.tab.c"
    break;

  case 54: /* localDecls: %empty  */
#line 209 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1840 "parser.tab.c"
    break;

  case 55: /* stmtList: stmtList stmt  */
#line 212 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1846 "parser.tab.c"
    break;

  case 56: /* stmtList: %empty  */
#line 213 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1852 "parser.tab.c"
    break;

  case 57: /* matchedif: endStmt  */
#line 217 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1858 "parser.tab.c"
    break;

  case 58: /* matchedif: IF simpleExp THEN matchedif ELSE matchedif  */
#line 218 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1867 "parser.tab.c"
    break;

  case 59: /* matchedif: IF error  */
#line 223 "parser.y"
                                                                                 { (yyval.tree) = NULL; }
#line 1873 "parser.tab.c"
    break;

  case 60: /* matchedif: IF error ELSE matchedif  */
#line 224 "parser.y"
                                                                                 { (yyval.tree) = NULL; yyerrok; }
#line 1879 "parser.tab.c"
    break;

  case 61: /* matchedif: IF error THEN matchedif ELSE matchedif  */
#line 225 "parser.y"
                                                                                 { (yyval.tree) = NULL; yyerrok; }
#line 1885 "parser.tab.c"
    break;

  case 62: /* matchedif: WHILE simpleExp DO matchedif  */
#line 227 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1894 "parser.tab.c"
    break;

  case 63: /* matchedif: WHILE error DO matchedif  */
#line 232 "parser.y"
                                                                                 { (yyval.tree) = NULL; 
                                                                                   yyerrok; }
#line 1901 "parser.tab.c"
    break;

  case 64: /* matchedif: WHILE error  */
#line 234 "parser.y"
                                                                                 { (yyval.tree) = NULL; }
#line 1907 "parser.tab.c"
    break;

  case 65: /* matchedif: FOR ID ASGN iterRange DO matchedif  */
#line 236 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = newDeclNode(VarK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->child[0]->expType = Integer;
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1918 "parser.tab.c"
    break;

  case 66: /* matchedif: FOR ID ASGN error DO matchedif  */
#line 243 "parser.y"
                                                                                 { (yyval.tree) = NULL; yyerrok; }
#line 1924 "parser.tab.c"
    break;

  case 67: /* matchedif: FOR error  */
#line 244 "parser.y"
                                                                                 { (yyval.tree) = NULL; }
#line 1930 "parser.tab.c"
    break;

  case 68: /* unmatchedif: IF simpleExp THEN matchedif ELSE unmatchedif  */
#line 247 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1939 "parser.tab.c"
    break;

  case 69: /* unmatchedif: IF error THEN matchedif ELSE unmatchedif  */
#line 252 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 1946 "parser.tab.c"
    break;

  case 70: /* unmatchedif: WHILE simpleExp DO unmatchedif  */
#line 255 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1955 "parser.tab.c"
    break;

  case 71: /* unmatchedif: WHILE error DO unmatchedif  */
#line 260 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 1962 "parser.tab.c"
    break;

  case 72: /* unmatchedif: FOR ID ASGN iterRange DO unmatchedif  */
#line 263 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = newDeclNode(VarK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->child[0]->expType = Integer;
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 1973 "parser.tab.c"
    break;

  case 73: /* unmatchedif: FOR ID ASGN error DO unmatchedif  */
#line 270 "parser.y"
                                                                                { (yyval.tree) = NULL;
                                                                                  yyerrok; }
#line 1980 "parser.tab.c"
    break;

  case 74: /* unmatchedif: IF simpleExp THEN stmt  */
#line 273 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 1988 "parser.tab.c"
    break;

  case 75: /* unmatchedif: IF error THEN matchedif  */
#line 277 "parser.y"
                                                                                { (yyval.tree) = NULL; yyerrok; }
#line 1994 "parser.tab.c"
    break;

  case 76: /* endStmt: expStmt  */
#line 280 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2000 "parser.tab.c"
    break;

  case 77: /* endStmt: compoundStmt  */
#line 281 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2006 "parser.tab.c"
    break;

  case 78: /* endStmt: returnStmt  */
#line 282 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2012 "parser.tab.c"
    break;

  case 79: /* endStmt: breakStmt  */
#line 283 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2018 "parser.tab.c"
    break;

  case 80: /* iterRange: simpleExp TO simpleExp  */
#line 286 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(RangeK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2026 "parser.tab.c"
    break;

  case 81: /* iterRange: simpleExp TO simpleExp BY simpleExp  */
#line 290 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(RangeK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 2035 "parser.tab.c"
    break;

  case 82: /* iterRange: simpleExp TO error  */
#line 295 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2041 "parser.tab.c"
    break;

  case 83: /* iterRange: error BY error  */
#line 296 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 2048 "parser.tab.c"
    break;

  case 84: /* iterRange: simpleExp TO simpleExp BY error  */
#line 298 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2054 "parser.tab.c"
    break;

  case 85: /* returnStmt: RETURN SEMICOLON  */
#line 301 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;}
#line 2061 "parser.tab.c"
    break;

  case 86: /* returnStmt: RETURN exp SEMICOLON  */
#line 304 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenStrInput; 
                                                                                  (yyval.tree)->expType = (yyvsp[-1].tree)->expType;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree);
                                                                                  yyerrok; }
#line 2071 "parser.tab.c"
    break;

  case 87: /* returnStmt: RETURN error SEMICOLON  */
#line 310 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 2078 "parser.tab.c"
    break;

  case 88: /* breakStmt: BREAK SEMICOLON  */
#line 314 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(BreakK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput; }
#line 2085 "parser.tab.c"
    break;

  case 89: /* exp: mutable assignop exp  */
#line 318 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2093 "parser.tab.c"
    break;

  case 90: /* exp: mutable INC  */
#line 322 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree); }
#line 2102 "parser.tab.c"
    break;

  case 91: /* exp: mutable DEC  */
#line 327 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree); }
#line 2111 "parser.tab.c"
    break;

  case 92: /* exp: simpleExp  */
#line 332 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2117 "parser.tab.c"
    break;

  case 93: /* exp: error assignop exp  */
#line 334 "parser.y"
                                                                                { (yyval.tree) = NULL; yyerrok; }
#line 2123 "parser.tab.c"
    break;

  case 94: /* exp: mutable assignop error  */
#line 335 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2129 "parser.tab.c"
    break;

  case 95: /* exp: error INC  */
#line 336 "parser.y"
                                                                                { (yyval.tree) = NULL; yyerrok; }
#line 2135 "parser.tab.c"
    break;

  case 96: /* exp: error DEC  */
#line 337 "parser.y"
                                                                                { (yyval.tree) = NULL; yyerrok; }
#line 2141 "parser.tab.c"
    break;

  case 97: /* assignop: ASGN  */
#line 340 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 2147 "parser.tab.c"
    break;

  case 98: /* assignop: ADDASGN  */
#line 341 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 2153 "parser.tab.c"
    break;

  case 99: /* assignop: MINUSASGN  */
#line 342 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 2159 "parser.tab.c"
    break;

  case 100: /* assignop: MULTASGN  */
#line 343 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 2165 "parser.tab.c"
    break;

  case 101: /* assignop: DIVASGN  */
#line 344 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;}
#line 2171 "parser.tab.c"
    break;

  case 102: /* simpleExp: simpleExp OR andExp  */
#line 347 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2181 "parser.tab.c"
    break;

  case 103: /* simpleExp: andExp  */
#line 353 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2187 "parser.tab.c"
    break;

  case 104: /* simpleExp: simpleExp OR error  */
#line 354 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2193 "parser.tab.c"
    break;

  case 105: /* andExp: andExp AND unaryRelExp  */
#line 357 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2203 "parser.tab.c"
    break;

  case 106: /* andExp: unaryRelExp  */
#line 363 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2209 "parser.tab.c"
    break;

  case 107: /* andExp: andExp AND error  */
#line 364 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2215 "parser.tab.c"
    break;

  case 108: /* unaryRelExp: NOT unaryRelExp  */
#line 367 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[0].tree);}
#line 2224 "parser.tab.c"
    break;

  case 109: /* unaryRelExp: relExp  */
#line 372 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2230 "parser.tab.c"
    break;

  case 110: /* unaryRelExp: NOT error  */
#line 373 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2236 "parser.tab.c"
    break;

  case 111: /* relExp: sumExp relop sumExp  */
#line 376 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 2244 "parser.tab.c"
    break;

  case 112: /* relExp: sumExp relop error  */
#line 380 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2250 "parser.tab.c"
    break;

  case 113: /* relExp: sumExp  */
#line 382 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ;}
#line 2256 "parser.tab.c"
    break;

  case 114: /* relop: LESSTHAN  */
#line 385 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2264 "parser.tab.c"
    break;

  case 115: /* relop: LEQ  */
#line 389 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2272 "parser.tab.c"
    break;

  case 116: /* relop: GREATERTHAN  */
#line 393 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2280 "parser.tab.c"
    break;

  case 117: /* relop: GEQ  */
#line 397 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2288 "parser.tab.c"
    break;

  case 118: /* relop: EQUALS  */
#line 401 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2296 "parser.tab.c"
    break;

  case 119: /* relop: NEQ  */
#line 405 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2304 "parser.tab.c"
    break;

  case 120: /* sumExp: sumExp sumop mulExp  */
#line 410 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 2312 "parser.tab.c"
    break;

  case 121: /* sumExp: mulExp  */
#line 414 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2318 "parser.tab.c"
    break;

  case 122: /* sumExp: sumExp sumop error  */
#line 415 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2324 "parser.tab.c"
    break;

  case 123: /* sumop: PLUS  */
#line 418 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2332 "parser.tab.c"
    break;

  case 124: /* sumop: MINUS  */
#line 422 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2340 "parser.tab.c"
    break;

  case 125: /* mulExp: mulExp mulop unaryExp  */
#line 427 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 2348 "parser.tab.c"
    break;

  case 126: /* mulExp: unaryExp  */
#line 431 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2354 "parser.tab.c"
    break;

  case 127: /* mulExp: mulExp mulop error  */
#line 432 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2360 "parser.tab.c"
    break;

  case 128: /* mulop: MULT  */
#line 435 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2368 "parser.tab.c"
    break;

  case 129: /* mulop: DIVIDE  */
#line 439 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2376 "parser.tab.c"
    break;

  case 130: /* mulop: PERCENT  */
#line 443 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2384 "parser.tab.c"
    break;

  case 131: /* unaryExp: unaryop unaryExp  */
#line 448 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[0].tree); }
#line 2391 "parser.tab.c"
    break;

  case 132: /* unaryExp: factor  */
#line 451 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2397 "parser.tab.c"
    break;

  case 133: /* unaryExp: unaryop error  */
#line 452 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2403 "parser.tab.c"
    break;

  case 134: /* unaryop: MINUS  */
#line 455 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2411 "parser.tab.c"
    break;

  case 135: /* unaryop: MULT  */
#line 459 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2419 "parser.tab.c"
    break;

  case 136: /* unaryop: QMARK  */
#line 463 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2427 "parser.tab.c"
    break;

  case 137: /* factor: mutable  */
#line 468 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2433 "parser.tab.c"
    break;

  case 138: /* factor: immutable  */
#line 469 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2439 "parser.tab.c"
    break;

  case 139: /* mutable: ID  */
#line 472 "parser.y"
                                                                                { (yyval.tree) = newExpNode(IdK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[0].tokenData)->tokenStrInput); }
#line 2446 "parser.tab.c"
    break;

  case 140: /* mutable: ID LBRACKET exp RBRACKET  */
#line 475 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0] = newExpNode(IdK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0]->attr.name = (yyvsp[-3].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->child[0]->isArray = true;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-1].tree); }
#line 2457 "parser.tab.c"
    break;

  case 141: /* immutable: LPAREN exp RPAREN  */
#line 483 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); yyerrok; }
#line 2463 "parser.tab.c"
    break;

  case 142: /* immutable: call  */
#line 484 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2469 "parser.tab.c"
    break;

  case 143: /* immutable: constant  */
#line 485 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2475 "parser.tab.c"
    break;

  case 144: /* immutable: LPAREN error  */
#line 486 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2481 "parser.tab.c"
    break;

  case 145: /* call: ID LPAREN args RPAREN  */
#line 489 "parser.y"
                                                                                { (yyval.tree) = newExpNode(CallK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-3].tokenData)->tokenStrInput);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree);}
#line 2489 "parser.tab.c"
    break;

  case 146: /* call: error LPAREN  */
#line 493 "parser.y"
                                                                                { (yyval.tree) = NULL; yyerrok; }
#line 2495 "parser.tab.c"
    break;

  case 147: /* args: argList  */
#line 496 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2501 "parser.tab.c"
    break;

  case 148: /* args: %empty  */
#line 497 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2507 "parser.tab.c"
    break;

  case 149: /* argList: argList COMMA exp  */
#line 500 "parser.y"
                                                                                { (yyval.tree) = addaSibling((yyvsp[-2].tree), (yyvsp[0].tree)); yyerrok; }
#line 2513 "parser.tab.c"
    break;

  case 150: /* argList: exp  */
#line 501 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2519 "parser.tab.c"
    break;

  case 151: /* argList: argList COMMA error  */
#line 502 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2525 "parser.tab.c"
    break;

  case 152: /* constant: NUMCONST  */
#line 505 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue;
                                                                                  (yyval.tree)->expType = Integer; }
#line 2533 "parser.tab.c"
    break;

  case 153: /* constant: CHARCONST  */
#line 509 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[0].tokenData);
                                                                                  (yyval.tree)->expType = Char; }
#line 2542 "parser.tab.c"
    break;

  case 154: /* constant: STRINGCONST  */
#line 514 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.string = strdup((yyvsp[0].tokenData)->svalue);
                                                                                  (yyval.tree)->isArray = true;
                                                                                  (yyval.tree)->arrLength = (yyvsp[0].tokenData)->strLength;
                                                                                  (yyval.tree)->expType = CharInt; }
#line 2552 "parser.tab.c"
    break;

  case 155: /* constant: BOOLCONST  */
#line 520 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenStrInput;
                                                                                  (yyval.tree)->expType = Boolean; }
#line 2561 "parser.tab.c"
    break;


#line 2565 "parser.tab.c"

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

#line 526 "parser.y"


extern int yydebug;
int main(int argc, char *argv[])
{

    int selOption = 0;
    bool printAST = 0;
    numErrors = 0;
    numWarnings = 0;
    char* outfile;
    extern int optind;
    int options;

    while((selOption = getopt(argc, argv, "dDpPMh")) != -1){

        switch(selOption){

            case'c':
                //do nothing
                break;

            case 'd':
                yydebug = 1;
                break;
            
            case 'p':
                printAST = true;
                TYPES = false;
                options = 0;
                break;

            case 'D':
                symbolTable.debug(1);
                break;

            case 'P':
                //print AST with type information
                printAST = true;
                TYPES = true;
                options = 1;
                break;

            case 'M':
                //case for showing mem / offset values
                printAST = true;
                TYPES = true;
                opM = true;
                printOffset = true;
                options = 1;
                break;

            case 'h':
                printf("usage: -c [options] [sourcefile]\n");
                printf("options:\n");
                printf("-d     - turn on parser debugging\n");
                printf("-D     - turn on symbol table debugging\n");
                printf("-h     - print this usage message\n");
                printf("-p     - print the abstract syntax tree\n");
                printf("-P     - print the abstract syntax tree plus type information\n");
                break;

            default:
                exit(1);
        }
    }


    if(argc > optind){
        if((yyin = fopen(argv[argc-1], "r"))) {
            // file open successful
        }
        else {
            //failed to open
            printf("ERROR(ARGLIST): source file \"%s\" could not be opened.\n", argv[1]);
            numErrors++;
            printf("Number of warnings: %d\n", numWarnings);
            printf("Number of errors: %d\n", numErrors);
            exit(1);
        }
    }

    initErrorProcessing();
    yyparse();

    if(printAST && options == 0 && numErrors == 0){
        printTree(ast, 0, TYPES);
    }
    else if(options == 1 && numErrors == 0){
        setupIO();
        semanticAnalysis(ast, numErrors, numWarnings);
        //COMMENTED OUT THIS IF STATEMENT FOR TESTING ----- CHANGE BACK***********************
        if(numErrors < 1)
        {
            printTree(ast, 0, TYPES);

            //print offset for end of global space if option 'M'
            if(printOffset){
                printf("Offset for end of global space: %d\n", goffset);
            }
        }
    }

    //codegen
    if(numErrors == 0){

        char* newFile;
        int newFileLen;

        std::string out = argv[optind];
        newFileLen = strlen(argv[optind]);
        newFile = (char*)malloc(strlen(argv[optind]) + 1);
        strcpy(newFile, argv[optind]);
        newFile[newFileLen - 2] = 't';
        newFile[newFileLen - 1] = 'm';

        setupIO();
        generateCode(ast, newFile);

    }

    printf("Number of warnings: %d\n", numWarnings);
    printf("Number of errors: %d\n", numErrors);

    return 0;
}
