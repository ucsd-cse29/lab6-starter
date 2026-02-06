#include "info.h"

#include "person.h"

int main(){
	Person Andrew = {"Andrew", 319204, 23.9, "pizza", "Lab TA"};
	
	hello(Andrew);
	
	print_person(Andrew);
}
