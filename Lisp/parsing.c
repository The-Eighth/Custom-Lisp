#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"


/*If OS is Windows then use the following functions*/
#ifdef _WIN32

#include <string.h>

static char buffer[2048];

/*Fake readline to replace linux functions*/
char* readline(char* prompt){

	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);

	char* cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);

	cpy[strlen(cpy)-1] = '\0';

	return cpy;

}

/*Fake add_history. Unused*/

void add_histpry(char* unused){}//Do nothing...


/*Otherwise include the following headers as normal*/
#else

#include <editline/readline.h>
#include <histedit.h>

#endif




int main(int argc, char** argv){
	/* NPN Parsers */

	/* Current rules */
	mpc_parser_t* Number = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr = mpc_new("expr");
	mpc_parser_t* Lispy = mpc_new("lipsy");

	/* Rule Definitions
	 * Apparently the string HAS TO BE FORMATED LIKE THIS
	 * Perhaps ill know why in the future because im not quite sure....
	 */
	mpca_lang(MPCA_LANG_DEFAULT,
 	 "                                                     \
   	   number   : /-?[0-9]+/ ;                             \
   	   operator : '+' | '-' | '*' | '/' ;                  \
   	   expr     : <number> | '(' <operator> <expr>+ ')' ;  \
   	   lispy    : /^/ <operator> <expr>+ /$/ ;             \
  	",
 	 Number, Operator, Expr, Lispy);

	/*End of Parsers*/

	puts("Lispy Version 0.0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1){
	
		char* input = readline("lispy -> ");

		add_history(input);

		printf("Echo: %s\n", input);
		
		free(input);
	}

	/* Undefine and delete parsers*/
	mpc_cleanup(4, Number, Operator, Expr, Lispy);
	
	return(0);


}
