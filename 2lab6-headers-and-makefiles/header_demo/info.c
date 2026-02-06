#include "person.h"
#include <string.h>
#include <stdio.h>

void print_person(Person person){
	printf("Name: %s\n", person.name);
	printf("id: %d\n", person.id);
	printf("age: %f\n", person.age);
	printf("role: %s\n", person.role);
	printf("Favorite Food: %s\n", person.fav_food);
}
