/*
 * Symbol Table element
 * The Symbol Table is a list of entries
 * that represent variables or functions
 */

typedef struct SymbTbl {
  char *column; /* symbol name */
  char *table;
  int type; /* symbol type VAR|FNCT */
	struct SymbTbl *next; /* list forward pointer */
} symbtbl;

/* global variables */

extern symbtbl *st; /* head of symbol table list */

/* function prototypes */

symbtbl *putsymb(char *,char *,int);
symbtbl *getsymb(char *);
