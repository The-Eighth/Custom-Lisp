#include <stdio.h>

/*Input buffer*/
static char input[2048];

int main(int argc, char** argv){

	puts("Lispy Version 0.0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1){
	
		fputs("lispy-> ", stdout);

		fgets(input, 2048, stdin);

		printf("Echo: %s", input);
	
	}

	return(0);



}
