/* C-Language Definition Include File 		*/
/* This file makes 'C' more readable 		*/
/* We use CHILL Keywords instead of C Keywords  */

/************************************************************************/
/* I. Keywords 								*/
/************************************************************************/

/* Scope and Storage Classes Identifiers */

#define GLOBAL
#define EXTERN        extern
#define LOCAL         static
#define LOCAL_PROC    static
#define STATIC        static

/* Block Keywords */

#define DCL
#define PROC
#define PROCESS
#define BEGIN_PROCESS {
#define END_PROCESS   }

#define BEGIN         {
#define END           }
#define RETURN        return


/* Type (Modes) Specifiers */

#define MODE          typedef
#define CHAR          char
#define BYTE          unsigned char
#define INT           short int
#define INT_          short int
#define WORD          unsigned short int
#define LONG          unsigned long int
#define LONG_         unsigned long int
#define DOUBLE        unsigned long int
#define VOID          void

typedef unsigned char   BOOL;
typedef unsigned char * PTR;

/* Set and Structure Declarrators */

#define SET           enum
#define STRUCT        struct
#define UNION         union

/* Control Flow Keywords */

#define FOR           for
#define FOREVER       while (1)

#define WHILE         while
#define DO            {
#define OD            ;}

#define REPEAT        do {
#define UNTIL(expr)   ;} while (!(expr))

/* Conditional Keywords */

#define IF            if (
#define THEN          ) {
#define ELSE          ;} else {
#define ELSIF         ;} else if (
#define FI            ;}

#define CASE(cond)    switch ( (short int)(cond) ) {
#define OF            break; case
#define OROF          : case
#define OTHERWISE     break; default:
#define ESAC          ;}

#define GOTO          goto

/************************************************************************/
/* II. Operators 							*/
/************************************************************************/

#define EQ         ==
#define NE         !=
#define GT         >
#define GE         >=
#define LT         <
#define LE         <=

#define DIV        /
#define MOD        %
#define NOT        !
#define AND        &&
#define OR         ||

#define B_AND      &
#define B_OR       |
#define B_XOR      ^
#define B_NOT      ~

/************************************************************************/
/* III. Constants 							*/
/************************************************************************/

#define FALSE         (0x0)
#define TRUE          (0x1)
#define NULL          ((PTR)0xFFFFFFFFL)
