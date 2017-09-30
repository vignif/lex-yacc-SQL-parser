/*
 * Symbol table management functions
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include <unistd.h>

/* head of symbol table list */
symbtbl *st=NULL;

/* add a symbol to table given column and type */

symbtbl *putsymb(char *column,char *table, int type) {
	symbtbl *ptr;
	if((ptr=(symbtbl *)(malloc(sizeof(symbtbl))))==NULL) {
		return(NULL); /* allocation failed */
	}
	ptr->column = strdup(column);/*inserisce column in struttura puntata*/
	ptr->table = strdup(table);
	ptr->type = type;
printf("Row #%d is correct \n columns: %s\n tables: %s\n\n ",type,strdup(column),strdup(table));
FILE *fileptr;
char filename[] = "results.txt";
fileptr = fopen(filename,"a");
fprintf(fileptr,"line: %d \n columns: %s \n tables: %s\n",type,strdup(column),strdup(table));
fclose(fileptr);


	if(ptr->column==NULL) {
		free(ptr);
		return(NULL); /* allocation failed */
	}
	ptr->type=type;
	/* add to list */
	ptr->next=st;
	st=ptr;
	return ptr;
}

/* get a symbol from table */

symbtbl *getsymb(char *column) {
	symbtbl *ptr;
	/* scan the list for element */
	for(ptr=st;ptr!=NULL;ptr=ptr->next)
		if(!strcmp(ptr->column,column))
		   return ptr;

	return(NULL); /* not found */
}
