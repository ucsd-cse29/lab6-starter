#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for malloc

typedef struct String {
	int len; 
	char * contents; //members start at a byte address aligned to their size 
					 // contents is 8 bytes long (it is a char* [an address])
					 // so C tries to start that member at an address that is
					 // a multiple of 8 (8-byte aligned)
}String;

/*
	| 4 byte len | |4 byte "padding" | | 8 bytes for contents |
*/

// 1. Reading a line of input without pre-allocating a buffer or thinking about
// sizes
// 2. Concatenating two strings without thinking about result params

String readline(){
	char input[10000];
	if(!fgets(input, 10000, stdin)){
		exit(0);
	}
	
	int length = strlen(input);
	char * contents = malloc(length+1);
	if(contents == NULL){
		printf("Malloc returned NULL\n");
	}
	strcpy(contents, input);
	String s = {
		length,
		contents
	};
	return s;
}

int main(int argc, char * argv[]){
	char* to_find = argv[1];
	while(1) {
		String s = readline();
		if(strstr(s.contents, to_find) != NULL){
			printf("%s\n", s.contents);
		}
	}

}

