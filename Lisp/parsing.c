#include <stdio.h>
#include <stdlib.h>


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

	puts("Lispy Version 0.0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1){
	
		char* input = readline("lispy -> ");

		add_history(input);

		printf("Echo: %s\n", input);
		
		free(input);
	}

	return(0);



}
