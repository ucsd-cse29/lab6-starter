#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for malloc

typedef struct Student {
	int year; 
	int id;
	char * name; 
	char * major;
	char * college;

} Student;

Student students[1000];
int numStudents = 0;

Student makeStudent(){
	char input[10000];
	Student stu;
	printf("Making a new student...\nInput year\n");
	for(int i = 0; i < 5; i++){
		if(!fgets(input, 10000, stdin)){
			exit(0);
		}
		input[strcspn(input, "\n")] = '\0';
		switch (i) {
			case 0: 
				stu.year = atoi(input);
				printf("Input ID\n");
				break;
			case 1:
				stu.id = atoi(input);
				printf("Input Name\n");
				break;
			case 2: 
				stu.name = malloc(strlen(input)+1);
				strcpy(stu.name, input);
				printf("Input Major\n");
				break;
			case 3:
				stu.major = malloc(strlen(input)+1);
				strcpy(stu.major, input);
				printf("Input College\n");
				break;
			case 4:
				stu.college = malloc(strlen(input)+1);
				strcpy(stu.college, input);
				break;
		}
	}

	numStudents++;
	return stu;
}

void printStudent(Student s){
	printf("Year: %d\nID: %d\nName: %s\nMajor: %s\nCollege: %s\n\n", s.year, s.id, s.name, s.major, s.college); 
}

void removeStudent(Student student){
	printf("removing student:\n");
	printStudent(student);
	numStudents--;
}

int main(int argc, char * argv[]){
	char cmd[1000];
	printf("welcome\n");
	while(fgets(cmd, sizeof(cmd), stdin)) {
		if(strstr(cmd, "exit")) {
			printf("Exiting...\n");
			break;
		}
		if(strstr(cmd, "new")){
			students[numStudents] = makeStudent();			
			printf("New student created:\n");
			printStudent(students[numStudents-1]);
		}
		else if(strstr(cmd, "rm")){
			removeStudent(students[numStudents-1]);
		}
		else if(strstr(cmd, "print")){
			for(int i = 0; i < numStudents; i++){
				printStudent(students[i]);
			}
		}
		else {
			printf("No option selected:");
		}
		printf("Options are \"new\", \"rm\", \"print\" and \"exit\"\n");
	}
	while(numStudents > 0){
		removeStudent(students[numStudents-1]);
	}
	return 0;
}

