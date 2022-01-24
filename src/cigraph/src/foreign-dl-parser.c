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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         igraph_dl_yyparse
#define yylex           igraph_dl_yylex
#define yyerror         igraph_dl_yyerror
#define yydebug         igraph_dl_yydebug
#define yynerrs         igraph_dl_yynerrs

/* First part of user prologue.  */
#line 23 "src/cigraph/src/foreign-dl-parser.y"


/* 
   IGraph library.
   Copyright (C) 2009-2012  Gabor Csardi <csardi.gabor@gmail.com>
   334 Harvard st, Cambridge, MA, 02138 USA
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#include "config.h"
#include "igraph_hacks_internal.h"
#include "igraph_math.h"
#include "igraph_types_internal.h"
#include "foreign-dl-header.h"
#include "foreign-dl-parser.h"
#include <stdio.h>

#define yyscan_t void*

int igraph_dl_yylex(YYSTYPE* lvalp, YYLTYPE* llocp, void* scanner);
int igraph_dl_yyerror(YYLTYPE* locp, igraph_i_dl_parsedata_t* context, 
		      const char *s);
char *igraph_dl_yyget_text (yyscan_t yyscanner );
int igraph_dl_yyget_leng (yyscan_t yyscanner );

int igraph_i_dl_add_str(char *newstr, int length, 
			igraph_i_dl_parsedata_t *context);
int igraph_i_dl_add_edge(long int from, long int to,
			 igraph_i_dl_parsedata_t *context);
int igraph_i_dl_add_edge_w(long int from, long int to, 
			   igraph_real_t weight,
			   igraph_i_dl_parsedata_t *context);

extern igraph_real_t igraph_pajek_get_number(const char *str, long int len);

#define scanner context->scanner
 

#line 130 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_IGRAPH_DL_YY_Y_TAB_H_INCLUDED
# define YY_IGRAPH_DL_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int igraph_dl_yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    NEWLINE = 259,                 /* NEWLINE  */
    DL = 260,                      /* DL  */
    NEQ = 261,                     /* NEQ  */
    DATA = 262,                    /* DATA  */
    LABELS = 263,                  /* LABELS  */
    LABELSEMBEDDED = 264,          /* LABELSEMBEDDED  */
    FORMATFULLMATRIX = 265,        /* FORMATFULLMATRIX  */
    FORMATEDGELIST1 = 266,         /* FORMATEDGELIST1  */
    FORMATNODELIST1 = 267,         /* FORMATNODELIST1  */
    DIGIT = 268,                   /* DIGIT  */
    LABEL = 269,                   /* LABEL  */
    EOFF = 270,                    /* EOFF  */
    ERROR = 271                    /* ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 86 "src/cigraph/src/foreign-dl-parser.y"

  long int integer;
  igraph_real_t real;

#line 201 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int igraph_dl_yyparse (igraph_i_dl_parsedata_t* context);

#endif /* !YY_IGRAPH_DL_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_NEWLINE = 4,                    /* NEWLINE  */
  YYSYMBOL_DL = 5,                         /* DL  */
  YYSYMBOL_NEQ = 6,                        /* NEQ  */
  YYSYMBOL_DATA = 7,                       /* DATA  */
  YYSYMBOL_LABELS = 8,                     /* LABELS  */
  YYSYMBOL_LABELSEMBEDDED = 9,             /* LABELSEMBEDDED  */
  YYSYMBOL_FORMATFULLMATRIX = 10,          /* FORMATFULLMATRIX  */
  YYSYMBOL_FORMATEDGELIST1 = 11,           /* FORMATEDGELIST1  */
  YYSYMBOL_FORMATNODELIST1 = 12,           /* FORMATNODELIST1  */
  YYSYMBOL_DIGIT = 13,                     /* DIGIT  */
  YYSYMBOL_LABEL = 14,                     /* LABEL  */
  YYSYMBOL_EOFF = 15,                      /* EOFF  */
  YYSYMBOL_ERROR = 16,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 17,                  /* $accept  */
  YYSYMBOL_input = 18,                     /* input  */
  YYSYMBOL_trail = 19,                     /* trail  */
  YYSYMBOL_eof = 20,                       /* eof  */
  YYSYMBOL_rest = 21,                      /* rest  */
  YYSYMBOL_formfullmatrix = 22,            /* formfullmatrix  */
  YYSYMBOL_newline = 23,                   /* newline  */
  YYSYMBOL_fullmatrix = 24,                /* fullmatrix  */
  YYSYMBOL_labels = 25,                    /* labels  */
  YYSYMBOL_fullmatrixdata = 26,            /* fullmatrixdata  */
  YYSYMBOL_zerooneseq = 27,                /* zerooneseq  */
  YYSYMBOL_zeroone = 28,                   /* zeroone  */
  YYSYMBOL_labeledfullmatrixdata = 29,     /* labeledfullmatrixdata  */
  YYSYMBOL_reallabeledfullmatrixdata = 30, /* reallabeledfullmatrixdata  */
  YYSYMBOL_labelseq = 31,                  /* labelseq  */
  YYSYMBOL_label = 32,                     /* label  */
  YYSYMBOL_labeledmatrixlines = 33,        /* labeledmatrixlines  */
  YYSYMBOL_labeledmatrixline = 34,         /* labeledmatrixline  */
  YYSYMBOL_edgelist1 = 35,                 /* edgelist1  */
  YYSYMBOL_edgelist1rest = 36,             /* edgelist1rest  */
  YYSYMBOL_edgelist1data = 37,             /* edgelist1data  */
  YYSYMBOL_edgelist1dataline = 38,         /* edgelist1dataline  */
  YYSYMBOL_integer = 39,                   /* integer  */
  YYSYMBOL_labelededgelist1data = 40,      /* labelededgelist1data  */
  YYSYMBOL_labelededgelist1dataline = 41,  /* labelededgelist1dataline  */
  YYSYMBOL_weight = 42,                    /* weight  */
  YYSYMBOL_elabel = 43,                    /* elabel  */
  YYSYMBOL_nodelist1 = 44,                 /* nodelist1  */
  YYSYMBOL_nodelist1rest = 45,             /* nodelist1rest  */
  YYSYMBOL_nodelist1data = 46,             /* nodelist1data  */
  YYSYMBOL_nodelist1dataline = 47,         /* nodelist1dataline  */
  YYSYMBOL_from = 48,                      /* from  */
  YYSYMBOL_tolist = 49,                    /* tolist  */
  YYSYMBOL_labelednodelist1data = 50,      /* labelednodelist1data  */
  YYSYMBOL_labelednodelist1dataline = 51,  /* labelednodelist1dataline  */
  YYSYMBOL_fromelabel = 52,                /* fromelabel  */
  YYSYMBOL_labeltolist = 53                /* labeltolist  */
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  17
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   271


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
      15,    16
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   113,   113,   115,   115,   117,   118,   119,
     122,   122,   124,   124,   126,   127,   128,   131,   132,   138,
     138,   143,   143,   145,   155,   157,   159,   159,   161,   165,
     169,   174,   178,   180,   181,   182,   183,   184,   187,   188,
     191,   193,   197,   200,   201,   204,   206,   210,   213,   229,
     231,   232,   233,   234,   235,   238,   239,   242,   244,   247,
     247,   253,   254,   257,   259,   263,   263
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "NEWLINE", "DL",
  "NEQ", "DATA", "LABELS", "LABELSEMBEDDED", "FORMATFULLMATRIX",
  "FORMATEDGELIST1", "FORMATNODELIST1", "DIGIT", "LABEL", "EOFF", "ERROR",
  "$accept", "input", "trail", "eof", "rest", "formfullmatrix", "newline",
  "fullmatrix", "labels", "fullmatrixdata", "zerooneseq", "zeroone",
  "labeledfullmatrixdata", "reallabeledfullmatrixdata", "labelseq",
  "label", "labeledmatrixlines", "labeledmatrixline", "edgelist1",
  "edgelist1rest", "edgelist1data", "edgelist1dataline", "integer",
  "labelededgelist1data", "labelededgelist1dataline", "weight", "elabel",
  "nodelist1", "nodelist1rest", "nodelist1data", "nodelist1dataline",
  "from", "tolist", "labelednodelist1data", "labelednodelist1dataline",
  "fromelabel", "labeltolist", YY_NULLPTR
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
     265,   266,   267,   268,   269,   270,   271
};
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,    38,    11,    43,  -114,  -114,    44,    57,    46,    46,
      46,    46,    46,    46,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,    69,    53,    63,    66,     6,    65,    46,    46,
    -114,    46,    46,    46,  -114,  -114,    46,    46,  -114,  -114,
    -114,  -114,     5,    19,  -114,  -114,  -114,    76,    84,  -114,
      82,  -114,  -114,  -114,    46,  -114,  -114,  -114,    93,    43,
      46,    46,    46,  -114,  -114,  -114,    46,    46,    46,  -114,
      85,    86,  -114,    43,    23,  -114,  -114,    88,    33,  -114,
    -114,    65,  -114,    85,  -114,  -114,  -114,    90,    46,    46,
      87,    46,  -114,  -114,    46,    46,    87,    46,    25,  -114,
    -114,  -114,    94,  -114,    95,  -114,  -114,    87,    29,  -114,
      96,  -114,  -114,  -114,    49,  -114,  -114,    43,    46,    92,
      46,    84,    46,     2,    46,  -114,  -114,   100,  -114,  -114,
    -114,  -114,  -114,    87,  -114,    87,    87,    87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,    42,     0,     0,    12,    12,
      12,    12,    12,    12,     3,     7,    11,     8,     9,    13,
      19,    17,     0,     0,     0,     0,     5,    14,    12,    12,
      10,    12,    12,    12,    32,    55,    12,    12,    49,     6,
       2,     4,     0,     0,    26,    38,    17,     0,    50,    17,
       0,    20,    23,    22,    12,    18,    16,    24,    12,    33,
      12,    12,    12,    58,    56,    59,    12,    12,    12,    19,
       0,     0,    39,     0,     0,    43,    17,     0,     0,    61,
      17,    15,    21,    25,    29,    28,    27,     0,    12,    12,
      35,    12,    57,    60,    12,    12,    52,    12,     0,    30,
      47,    41,     0,    38,     0,    48,    44,     0,     0,    55,
       0,    64,    62,    65,     0,    31,    40,    34,    12,     0,
      12,    51,    12,     0,    12,    43,    46,     0,    43,    61,
      63,    66,    61,    36,    45,    37,    53,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -114,  -114,  -114,  -114,  -114,  -114,    -9,    83,   -41,    36,
      26,  -114,  -114,  -114,  -114,  -114,  -114,    24,  -114,  -114,
       7,  -114,     4,  -113,  -114,    -7,   -82,  -114,  -114,     9,
    -114,  -114,  -114,   -98,  -114,  -114,  -114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    26,    40,    14,    15,    20,    16,    28,    27,
      42,    53,    56,    57,    58,    86,    83,    84,    17,    34,
      59,    72,    73,    90,   106,   102,   107,    18,    38,    48,
      64,    65,    77,    96,   112,   113,   123
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    22,    23,    24,    25,    60,   130,     6,    66,    51,
      19,     4,   133,     1,   111,   135,   105,    41,    52,    43,
      44,    39,    45,    46,    47,   119,    54,    49,    50,   115,
      88,   136,    89,    55,   137,    91,   120,    55,    52,    97,
      94,   131,    95,    55,     3,    69,     5,    55,     7,    71,
      19,    74,    75,    76,   111,   111,   124,    78,    79,    80,
       8,     9,    10,    55,     8,     9,    10,    11,    12,    13,
      31,    32,    33,    35,    36,    37,    29,    87,   -21,   103,
     104,    93,   108,    61,    62,   109,   110,    63,   114,    67,
      68,     5,    92,   100,   101,   100,   126,    70,   116,    82,
      85,   105,   118,   122,   134,    81,    30,    99,    98,   125,
     117,   128,   127,   129,     0,   132,     0,     0,   121
};

static const yytype_int16 yycheck[] =
{
       9,    10,    11,    12,    13,    46,     4,     3,    49,     4,
       4,     0,   125,     5,    96,   128,    14,    26,    13,    28,
      29,    15,    31,    32,    33,   107,     7,    36,    37,     4,
       7,   129,     9,    14,   132,    76,     7,    14,    13,    80,
       7,   123,     9,    14,     6,    54,     3,    14,     4,    58,
       4,    60,    61,    62,   136,   137,     7,    66,    67,    68,
       7,     8,     9,    14,     7,     8,     9,    10,    11,    12,
       7,     8,     9,     7,     8,     9,     7,    73,    13,    88,
      89,    77,    91,     7,     8,    94,    95,     3,    97,     7,
       8,     3,     4,     3,     4,     3,     4,     4,     4,    14,
      14,    14,     7,     7,     4,    69,    23,    83,    82,   118,
     103,   120,   119,   122,    -1,   124,    -1,    -1,   109
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    18,     6,     0,     3,    39,     4,     7,     8,
       9,    10,    11,    12,    21,    22,    24,    35,    44,     4,
      23,    23,    23,    23,    23,    23,    19,    26,    25,     7,
      24,     7,     8,     9,    36,     7,     8,     9,    45,    15,
      20,    23,    27,    23,    23,    23,    23,    23,    46,    23,
      23,     4,    13,    28,     7,    14,    29,    30,    31,    37,
      25,     7,     8,     3,    47,    48,    25,     7,     8,    23,
       4,    23,    38,    39,    23,    23,    23,    49,    23,    23,
      23,    26,    14,    33,    34,    14,    32,    39,     7,     9,
      40,    25,     4,    39,     7,     9,    50,    25,    27,    34,
       3,     4,    42,    23,    23,    14,    41,    43,    23,    23,
      23,    43,    51,    52,    23,     4,     4,    37,     7,    43,
       7,    46,     7,    53,     7,    23,     4,    42,    23,    23,
       4,    43,    23,    40,     4,    40,    50,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    17,    18,    19,    19,    20,    20,    21,    21,    21,
      22,    22,    23,    23,    24,    24,    24,    25,    25,    26,
      26,    27,    27,    28,    29,    30,    31,    31,    32,    33,
      33,    34,    35,    36,    36,    36,    36,    36,    37,    37,
      38,    38,    39,    40,    40,    41,    41,    42,    43,    44,
      45,    45,    45,    45,    45,    46,    46,    47,    48,    49,
      49,    50,    50,    51,    52,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     0,     2,     0,     1,     1,     1,     1,
       3,     1,     0,     1,     3,     7,     5,     0,     3,     0,
       3,     0,     2,     1,     1,     3,     0,     3,     1,     1,
       2,     3,     3,     3,     7,     5,     9,     9,     0,     2,
       4,     3,     1,     0,     2,     4,     3,     1,     1,     3,
       2,     7,     5,     9,     9,     0,     2,     3,     1,     0,
       2,     0,     2,     3,     1,     0,     2
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
        yyerror (&yylloc, context, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, context); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, igraph_i_dl_parsedata_t* context)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (context);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, igraph_i_dl_parsedata_t* context)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, context);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, igraph_i_dl_parsedata_t* context)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), context);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, context); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, igraph_i_dl_parsedata_t* context)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (context);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (igraph_i_dl_parsedata_t* context)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* input: DL NEQ integer NEWLINE rest trail eof  */
#line 111 "src/cigraph/src/foreign-dl-parser.y"
                                             { context->n=(yyvsp[-4].integer); }
#line 1714 "y.tab.c"
    break;

  case 7: /* rest: formfullmatrix  */
#line 117 "src/cigraph/src/foreign-dl-parser.y"
                        { context->type=IGRAPH_DL_MATRIX; }
#line 1720 "y.tab.c"
    break;

  case 8: /* rest: edgelist1  */
#line 118 "src/cigraph/src/foreign-dl-parser.y"
                        { context->type=IGRAPH_DL_EDGELIST1; }
#line 1726 "y.tab.c"
    break;

  case 9: /* rest: nodelist1  */
#line 119 "src/cigraph/src/foreign-dl-parser.y"
                        { context->type=IGRAPH_DL_NODELIST1; }
#line 1732 "y.tab.c"
    break;

  case 10: /* formfullmatrix: FORMATFULLMATRIX newline fullmatrix  */
#line 122 "src/cigraph/src/foreign-dl-parser.y"
                                                     {}
#line 1738 "y.tab.c"
    break;

  case 11: /* formfullmatrix: fullmatrix  */
#line 122 "src/cigraph/src/foreign-dl-parser.y"
                                                                     {}
#line 1744 "y.tab.c"
    break;

  case 14: /* fullmatrix: DATA newline fullmatrixdata  */
#line 126 "src/cigraph/src/foreign-dl-parser.y"
                                          { }
#line 1750 "y.tab.c"
    break;

  case 15: /* fullmatrix: LABELS newline labels newline DATA newline fullmatrixdata  */
#line 127 "src/cigraph/src/foreign-dl-parser.y"
                                                                        { }
#line 1756 "y.tab.c"
    break;

  case 16: /* fullmatrix: LABELSEMBEDDED newline DATA newline labeledfullmatrixdata  */
#line 128 "src/cigraph/src/foreign-dl-parser.y"
                                                                        { }
#line 1762 "y.tab.c"
    break;

  case 17: /* labels: %empty  */
#line 131 "src/cigraph/src/foreign-dl-parser.y"
                    {}
#line 1768 "y.tab.c"
    break;

  case 18: /* labels: labels newline LABEL  */
#line 132 "src/cigraph/src/foreign-dl-parser.y"
                                   { 
	      igraph_i_dl_add_str(igraph_dl_yyget_text(scanner), 
                                  igraph_dl_yyget_leng(scanner), 
				  context); }
#line 1777 "y.tab.c"
    break;

  case 19: /* fullmatrixdata: %empty  */
#line 138 "src/cigraph/src/foreign-dl-parser.y"
                {}
#line 1783 "y.tab.c"
    break;

  case 20: /* fullmatrixdata: fullmatrixdata zerooneseq NEWLINE  */
#line 138 "src/cigraph/src/foreign-dl-parser.y"
                                                       {
  context->from += 1;
  context->to = 0;
 }
#line 1792 "y.tab.c"
    break;

  case 22: /* zerooneseq: zerooneseq zeroone  */
#line 143 "src/cigraph/src/foreign-dl-parser.y"
                                 { }
#line 1798 "y.tab.c"
    break;

  case 23: /* zeroone: DIGIT  */
#line 145 "src/cigraph/src/foreign-dl-parser.y"
               {
  if (igraph_dl_yyget_text(scanner)[0]=='1') {
    IGRAPH_CHECK(igraph_vector_push_back(&context->edges, 
					 context->from));
    IGRAPH_CHECK(igraph_vector_push_back(&context->edges, 
					 context->to));
  }
  context->to += 1;
}
#line 1812 "y.tab.c"
    break;

  case 24: /* labeledfullmatrixdata: reallabeledfullmatrixdata  */
#line 155 "src/cigraph/src/foreign-dl-parser.y"
                                                 {}
#line 1818 "y.tab.c"
    break;

  case 25: /* reallabeledfullmatrixdata: labelseq NEWLINE labeledmatrixlines  */
#line 157 "src/cigraph/src/foreign-dl-parser.y"
                                                               {}
#line 1824 "y.tab.c"
    break;

  case 28: /* label: LABEL  */
#line 161 "src/cigraph/src/foreign-dl-parser.y"
             { igraph_i_dl_add_str(igraph_dl_yyget_text(scanner), 
                                   igraph_dl_yyget_leng(scanner), 
				   context); }
#line 1832 "y.tab.c"
    break;

  case 29: /* labeledmatrixlines: labeledmatrixline  */
#line 165 "src/cigraph/src/foreign-dl-parser.y"
                                      {
	         context->from += 1; 
		 context->to = 0;
               }
#line 1841 "y.tab.c"
    break;

  case 30: /* labeledmatrixlines: labeledmatrixlines labeledmatrixline  */
#line 169 "src/cigraph/src/foreign-dl-parser.y"
                                                    { 
	         context->from += 1; 
		 context->to = 0;
               }
#line 1850 "y.tab.c"
    break;

  case 31: /* labeledmatrixline: LABEL zerooneseq NEWLINE  */
#line 174 "src/cigraph/src/foreign-dl-parser.y"
                                            { }
#line 1856 "y.tab.c"
    break;

  case 32: /* edgelist1: FORMATEDGELIST1 newline edgelist1rest  */
#line 178 "src/cigraph/src/foreign-dl-parser.y"
                                                 {}
#line 1862 "y.tab.c"
    break;

  case 33: /* edgelist1rest: DATA newline edgelist1data  */
#line 180 "src/cigraph/src/foreign-dl-parser.y"
                                            {}
#line 1868 "y.tab.c"
    break;

  case 34: /* edgelist1rest: LABELS newline labels newline DATA newline edgelist1data  */
#line 181 "src/cigraph/src/foreign-dl-parser.y"
                                                                        {}
#line 1874 "y.tab.c"
    break;

  case 35: /* edgelist1rest: LABELSEMBEDDED newline DATA newline labelededgelist1data  */
#line 182 "src/cigraph/src/foreign-dl-parser.y"
                                                                        {}
#line 1880 "y.tab.c"
    break;

  case 36: /* edgelist1rest: LABELS newline labels newline LABELSEMBEDDED newline DATA newline labelededgelist1data  */
#line 183 "src/cigraph/src/foreign-dl-parser.y"
                                                                                                      {}
#line 1886 "y.tab.c"
    break;

  case 37: /* edgelist1rest: LABELSEMBEDDED newline LABELS newline labels newline DATA newline labelededgelist1data  */
#line 184 "src/cigraph/src/foreign-dl-parser.y"
                                                                                                      {}
#line 1892 "y.tab.c"
    break;

  case 38: /* edgelist1data: %empty  */
#line 187 "src/cigraph/src/foreign-dl-parser.y"
                        {}
#line 1898 "y.tab.c"
    break;

  case 39: /* edgelist1data: edgelist1data edgelist1dataline  */
#line 188 "src/cigraph/src/foreign-dl-parser.y"
                                               {}
#line 1904 "y.tab.c"
    break;

  case 40: /* edgelist1dataline: integer integer weight NEWLINE  */
#line 191 "src/cigraph/src/foreign-dl-parser.y"
                                                  {
                   igraph_i_dl_add_edge_w((yyvsp[-3].integer)-1, (yyvsp[-2].integer)-1, (yyvsp[-1].real), context); }
#line 1911 "y.tab.c"
    break;

  case 41: /* edgelist1dataline: integer integer NEWLINE  */
#line 193 "src/cigraph/src/foreign-dl-parser.y"
                                           {
		   igraph_i_dl_add_edge((yyvsp[-2].integer)-1, (yyvsp[-1].integer)-1, context);
}
#line 1919 "y.tab.c"
    break;

  case 42: /* integer: NUM  */
#line 197 "src/cigraph/src/foreign-dl-parser.y"
             { (yyval.integer)=igraph_pajek_get_number(igraph_dl_yyget_text(scanner), 
					  igraph_dl_yyget_leng(scanner)); }
#line 1926 "y.tab.c"
    break;

  case 43: /* labelededgelist1data: %empty  */
#line 200 "src/cigraph/src/foreign-dl-parser.y"
                        {}
#line 1932 "y.tab.c"
    break;

  case 44: /* labelededgelist1data: labelededgelist1data labelededgelist1dataline  */
#line 201 "src/cigraph/src/foreign-dl-parser.y"
                                                             {}
#line 1938 "y.tab.c"
    break;

  case 45: /* labelededgelist1dataline: elabel elabel weight NEWLINE  */
#line 204 "src/cigraph/src/foreign-dl-parser.y"
                                                       {
                          igraph_i_dl_add_edge_w((yyvsp[-3].integer), (yyvsp[-2].integer), (yyvsp[-1].real), context); }
#line 1945 "y.tab.c"
    break;

  case 46: /* labelededgelist1dataline: elabel elabel NEWLINE  */
#line 206 "src/cigraph/src/foreign-dl-parser.y"
                                                {
			  igraph_i_dl_add_edge((yyvsp[-2].integer), (yyvsp[-1].integer), context);
 }
#line 1953 "y.tab.c"
    break;

  case 47: /* weight: NUM  */
#line 210 "src/cigraph/src/foreign-dl-parser.y"
            { (yyval.real)=igraph_pajek_get_number(igraph_dl_yyget_text(scanner), 
					 igraph_dl_yyget_leng(scanner)); }
#line 1960 "y.tab.c"
    break;

  case 48: /* elabel: LABEL  */
#line 213 "src/cigraph/src/foreign-dl-parser.y"
              {
  /* Copy label list to trie, if needed */
  if (igraph_strvector_size(&context->labels) != 0) {
    long int i, id, n=igraph_strvector_size(&context->labels);
    for (i=0; i<n; i++) {
      igraph_trie_get(&context->trie,
		      STR(context->labels, i), &id);
    }
    igraph_strvector_clear(&context->labels);
  }
  igraph_trie_get2(&context->trie, igraph_dl_yyget_text(scanner), 
		   igraph_dl_yyget_leng(scanner), &(yyval.integer));
 }
#line 1978 "y.tab.c"
    break;

  case 49: /* nodelist1: FORMATNODELIST1 newline nodelist1rest  */
#line 229 "src/cigraph/src/foreign-dl-parser.y"
                                                 {}
#line 1984 "y.tab.c"
    break;

  case 50: /* nodelist1rest: DATA nodelist1data  */
#line 231 "src/cigraph/src/foreign-dl-parser.y"
                                    {}
#line 1990 "y.tab.c"
    break;

  case 51: /* nodelist1rest: LABELS newline labels newline DATA newline nodelist1data  */
#line 232 "src/cigraph/src/foreign-dl-parser.y"
                                                                        {}
#line 1996 "y.tab.c"
    break;

  case 52: /* nodelist1rest: LABELSEMBEDDED newline DATA newline labelednodelist1data  */
#line 233 "src/cigraph/src/foreign-dl-parser.y"
                                                                        {}
#line 2002 "y.tab.c"
    break;

  case 53: /* nodelist1rest: LABELS newline labels newline LABELSEMBEDDED newline DATA newline labelednodelist1data  */
#line 234 "src/cigraph/src/foreign-dl-parser.y"
                                                                                                      {}
#line 2008 "y.tab.c"
    break;

  case 54: /* nodelist1rest: LABELSEMBEDDED newline LABELS newline labels newline DATA newline labelednodelist1data  */
#line 235 "src/cigraph/src/foreign-dl-parser.y"
                                                                                                      {}
#line 2014 "y.tab.c"
    break;

  case 55: /* nodelist1data: %empty  */
#line 238 "src/cigraph/src/foreign-dl-parser.y"
                        {}
#line 2020 "y.tab.c"
    break;

  case 56: /* nodelist1data: nodelist1data nodelist1dataline  */
#line 239 "src/cigraph/src/foreign-dl-parser.y"
                                               {}
#line 2026 "y.tab.c"
    break;

  case 57: /* nodelist1dataline: from tolist NEWLINE  */
#line 242 "src/cigraph/src/foreign-dl-parser.y"
                                       {}
#line 2032 "y.tab.c"
    break;

  case 58: /* from: NUM  */
#line 244 "src/cigraph/src/foreign-dl-parser.y"
          { context->from=igraph_pajek_get_number(igraph_dl_yyget_text(scanner),
							  igraph_dl_yyget_leng(scanner)); }
#line 2039 "y.tab.c"
    break;

  case 59: /* tolist: %empty  */
#line 247 "src/cigraph/src/foreign-dl-parser.y"
        {}
#line 2045 "y.tab.c"
    break;

  case 60: /* tolist: tolist integer  */
#line 247 "src/cigraph/src/foreign-dl-parser.y"
                            { 
  IGRAPH_CHECK(igraph_vector_push_back(&context->edges, 
				       context->from-1)); 
  IGRAPH_CHECK(igraph_vector_push_back(&context->edges, (yyvsp[0].integer)-1));
 }
#line 2055 "y.tab.c"
    break;

  case 61: /* labelednodelist1data: %empty  */
#line 253 "src/cigraph/src/foreign-dl-parser.y"
                                {}
#line 2061 "y.tab.c"
    break;

  case 62: /* labelednodelist1data: labelednodelist1data labelednodelist1dataline  */
#line 254 "src/cigraph/src/foreign-dl-parser.y"
                                                           {}
#line 2067 "y.tab.c"
    break;

  case 63: /* labelednodelist1dataline: fromelabel labeltolist NEWLINE  */
#line 257 "src/cigraph/src/foreign-dl-parser.y"
                                                         { }
#line 2073 "y.tab.c"
    break;

  case 64: /* fromelabel: elabel  */
#line 259 "src/cigraph/src/foreign-dl-parser.y"
                   {
  context->from=(yyvsp[0].integer);
 }
#line 2081 "y.tab.c"
    break;

  case 66: /* labeltolist: labeltolist elabel  */
#line 263 "src/cigraph/src/foreign-dl-parser.y"
                                  {
  IGRAPH_CHECK(igraph_vector_push_back(&context->edges, 
				       context->from));
  IGRAPH_CHECK(igraph_vector_push_back(&context->edges, (yyvsp[0].integer)));
 }
#line 2091 "y.tab.c"
    break;


#line 2095 "y.tab.c"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, context, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, context);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, context);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, context, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, context);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, context);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 269 "src/cigraph/src/foreign-dl-parser.y"


int igraph_dl_yyerror(YYLTYPE* locp, igraph_i_dl_parsedata_t* context, 
		      const char *s) {
  snprintf(context->errmsg, 
	   sizeof(context->errmsg)/sizeof(char)-1, 
	   "%s in line %i", s, locp->first_line);
  return 0;
}

int igraph_i_dl_add_str(char *newstr, int length, 
			igraph_i_dl_parsedata_t *context) {
  int tmp=newstr[length];
  newstr[length]='\0';
  IGRAPH_CHECK(igraph_strvector_add(&context->labels, newstr));
  newstr[length]=tmp;
  return 0;
}

int igraph_i_dl_add_edge(long int from, long int to, 
			 igraph_i_dl_parsedata_t *context) {
  IGRAPH_CHECK(igraph_vector_push_back(&context->edges, from));
  IGRAPH_CHECK(igraph_vector_push_back(&context->edges, to));
  return 0;
}

int igraph_i_dl_add_edge_w(long int from, long int to, 
			   igraph_real_t weight,
			   igraph_i_dl_parsedata_t *context) {
  long int n=igraph_vector_size(&context->weights);
  long int n2=igraph_vector_size(&context->edges)/2;
  if (n != n2) {
    igraph_vector_resize(&context->weights, n2);
    for (; n<n2; n++) {
      VECTOR(context->weights)[n]=IGRAPH_NAN;
    }
  }
  IGRAPH_CHECK(igraph_i_dl_add_edge(from, to, context));
  IGRAPH_CHECK(igraph_vector_push_back(&context->weights, weight));
  return 0;
}
