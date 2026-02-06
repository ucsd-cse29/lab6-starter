#include <stdio.h>
#include <assert.h>
#include "structs.h"
int main(){

	char ch = 'A';
	struct Lab1 lab1 = {'a', 29, 29, &ch}; 
	struct Lab2 lab2 = {'a', 10, 19, &ch}; 
	
	printf("&lab1.x == %p, &lab1.n == %p\n&lab1.y == %p\n&lab1.p == %p\n\n", 
			&lab1.x, &lab1.n, &lab1.y,&lab1.p);
	printf("&lab2.x == %p, &lab2.y == %p, &lab2.n == %p\n&lab2.p == %p\n", 
			(char*)&lab2.x, (int *)&lab2.y, (char*)&lab2.n,(char**)&lab2.p);
}
