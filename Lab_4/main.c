#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fptr;
//student structure
typedef struct Student{
	int ID;
	char firstName[30];
	char lastName[30];
	float GPA;
	struct Student *next;
}Student;

//declaration of all functions
void readStudFile();
Student* createStudent(int studID, char firstname[30], char lastname[30], float gpa);
void addStudent(Student* newStud);
void menuStud();
void createNewStudent();
void printStud();
void insertStudent(Student* newStud);
void checkOut(int remID);
void removeStudent(Student* remStud);
void updateStud(int updateID);
void upStudMen(char firsty[30], char lasty[30]);
void saveList();
void freeAll();

//Global head pointer
Student* headStud = NULL;

int main(int argc, char **argv)
{
	printf("hello world\n");
	readStudFile();
	
	int userIn;
	do{
		printf("1) list all students\n");
		printf("2) add student\n");
		printf("3) Remove student\n");
		printf("4) Update student\n");
		printf("5) Quit\n");
		printf("What do you want to do: \n");
		scanf("%d", &userIn);
		int enterID;
		switch(userIn){
			case 1:
				printStud();
				break;
			case 2:
				createNewStudent();
				break;
			case 3:
				printf("Enter the student ID you want to remove:\n");
				scanf("%d", &enterID);
				checkOut(enterID);
				break;
			case 4:
				printf("Enter the student ID you want to update:\n");
				scanf("%d", &enterID);
				updateStud(enterID);
				break;
			case 5:
				break;
		}
	}while(userIn != 5);
	
	//menuStud();
	saveList();
	freeAll();
	return 0;
}

//read in all students from the file
void readStudFile(){
	int numStud;
	int studID;
	char firsty[30];
	char lasty[30];
	float gpa;
	float totGpa;
	float divisor = 0;
	fptr = fopen("Lab_3/studentDat.txt","r");
	if(fptr == NULL){
		printf("file doesn't exist\n");
		exit(-1);
	}
	fscanf(fptr, "Number of students is %d\n", &numStud);
	printf("Number of students is %d\n", numStud);
	for(int i = 0; i<numStud; i++){
		fscanf(fptr, "%d\n", &studID);
		fscanf(fptr,"%s\n", firsty);
		fscanf(fptr,"%s\n", lasty);
		fscanf(fptr,"%f\n", &gpa);
		Student* stud = NULL;
		stud = createStudent(studID, firsty, lasty, gpa);
		addStudent(stud);
		totGpa += gpa;
		divisor++;
		
	}
	printStud();
	printf("The average GPA is: %f\n", totGpa);
	fclose(fptr);
}

//shows menu for user to do things to the list of students
void menuStud(){
	int userIn;
	
	do{
		printf("1) list all students\n");
		printf("2) add student\n");
		printf("3) Remove student\n");
		printf("4) Update student\n");
		printf("5) Quit\n");
		printf("What do you want to do: \n");
		scanf("%d", &userIn);
		int enterID;
		switch(userIn){
			case 1:
				printStud();
				break;
			case 2:
				createNewStudent();
				break;
			case 3:
				printf("Enter the student ID you want to remove:\n");
				scanf("%d", &enterID);
				checkOut(enterID);
				break;
			case 4:
				printf("Enter the student ID you want to update:\n");
				scanf("%d", &enterID);
				updateStud(enterID);
				break;
			case 5:
				break;
		}
	}while(userIn != '5');
	
}

//getting data from user about new student 
//then call the create student function and inserting it into the lonled list based on GPA
void createNewStudent(){
	int studID;
	char firsty[30];
	char lasty[30];
	float gpa;
	printf("Enter student ID: \n");
	scanf("%d", &studID);
	printf("Enter student first name: \n");
	scanf("%s", firsty);
	printf("Enter student last name: \n");
	scanf("%s", lasty);
	printf("Enter student GPA: \n");
	scanf("%f", &gpa);
	Student* addStud = NULL;
	addStud = createStudent(studID, firsty, lasty, gpa);
	insertStudent(addStud);
}

//creating a student
Student* createStudent(int studID, char *firsty, char *lasty, float gpa){
	Student* newStud = NULL;
	newStud = (Student*) malloc(sizeof(Student));
	if(newStud != NULL){
		newStud->ID = studID;
		strcpy(newStud->firstName, firsty);
		strcpy(newStud->lastName, lasty);
		newStud->GPA = gpa;
		newStud->next = NULL;
	}
	return newStud;
}

//add student to list
void addStudent(Student* newStud){
	Student* currentStud = headStud;
	if(headStud == NULL){
		headStud = newStud;
		return;
	}
	while(currentStud->next!=NULL){
		currentStud = currentStud->next;
	}
	currentStud->next = newStud;
}

//print all students in list
void printStud(){
	Student* currentStud = headStud;
	while(currentStud->next!=NULL){
		printf("%s %s\n", currentStud->firstName, currentStud->lastName);
		currentStud = currentStud->next;
	}
	printf("%s %s\n", currentStud->firstName, currentStud->lastName);
}

//insert student based on GPA value
void insertStudent(Student *newStud){
	Student* node = headStud;
	while(node->next != NULL){
		Student* nextStud = node->next;
		if((node->GPA > newStud->GPA)&&(newStud->GPA >= nextStud->GPA)){
			newStud->next = node->next;
			node->next = newStud;
			return;
		}
		else if(node->GPA <= newStud->GPA){
			newStud->next = node;
			headStud = newStud;
			return;
		}
		node = node->next;
	}
	node->next = newStud;
	newStud->next = NULL;
	return;
}

void checkOut(int remID){
	Student* node = headStud;
	int check = 0;
	while(node != NULL){
		if(remID == node->ID){
			char firsty[30];
			char lasty[30];
			strcpy(firsty, node->firstName);
			strcpy(lasty, node->lastName);
			removeStudent(node);
			check = 1;
			printf("%s %s was removed from the list \n", firsty, lasty);
			return;
		}
		node = node->next;
	}
	if(check == 0){
		printf("no student exists with this ID\n");
		return;
	}
	return;
}

void removeStudent(Student* remStud){
	Student* curStud = headStud;
	Student* preStud = NULL;
	if(headStud == remStud){
		headStud = headStud->next;
		free(remStud);
		return;
	}
	while(curStud != NULL && curStud != remStud){
		preStud = curStud;
		curStud = curStud->next;
	}
	if(curStud != NULL){
		preStud->next = curStud->next;
	}
	free(remStud);
}
void updateStud(int updateID){
	Student* node = headStud;
	Student* prevStud = node;
	int check = 0;
	int userIn = 0;
	while(node != NULL){
		if(updateID == node->ID){
			do{
				upStudMen(node->firstName, node->lastName);
				scanf("%d", &userIn);
				int newID, oldID;
				char newFirsty[30], oldFirsty[30];
				char newLasty[30], oldLasty[30];
				float newGPA, oldGPA;
				Student* checkID = headStud;
				switch(userIn){
					case 1:
						printf("Enter new ID for student: \n");
						scanf("%d", &newID);
						while(checkID != NULL){
							if(newID == checkID->ID){
								printf("ID used already\n");
								checkID = headStud;
								printf("Enter new student id again: \n");
								scanf("%d", &newID);
							}
							checkID = checkID->next;
						}
						oldID = node->ID;
						node->ID = newID;
						printf("updated %d to %d\n", oldID, newID);
						break;
					case 2:
						printf("enter new first name:\n");
						scanf("%s", newFirsty);
						strcpy(oldFirsty, node->firstName);
						strcpy(node->firstName, newFirsty);
						printf("%s was updated to %s\n", oldFirsty, newFirsty);
						break;
					case 3:
						printf("enter new last name:\n");
						scanf("%s", newLasty);
						strcpy(oldLasty, node->lastName);
						strcpy(node->lastName, newLasty);
						printf("%s was updated to %s\n", oldLasty, newLasty);
						break;
					case 4:
						printf("enter new GPA for the student\n");
						scanf("%f", &newGPA);
						oldGPA = node->GPA;
						if(prevStud == node){
							node->next = NULL;
							insertStudent(node);
						}
						else{
							prevStud->next = node->next;
							insertStudent(node);
						}
						printf("updated successfully\n");
						break;
					
				}
			}while(userIn != 5);
			return;
		}
		prevStud = node;
		node = node->next;
	}
	if(check == 0){
		printf("There is no student with this ID\n");
		return;
	}
}
void upStudMen(char firsty[30], char lasty[30]){
	printf("[1] enter new ID\n");
	printf("[2] enter new first name\n");
	printf("[3] enter new last name\n");
	printf("[4] enter new gpa\n");
	printf("[5] Quit\n\n");
}
void freeAll(){
	Student* node  = headStud;
	Student* nextNode = headStud->next;
	while(node != NULL){
		removeStudent(node);
		node = nextNode;
		nextNode = nextNode->next;
	}
}
void saveList(){
	fptr = fopen("Lab_4\\studentDat.txt", "w");
	Student* node = headStud;
	int studCount = 0;
	while(node != NULL){
		studCount++;
		node = node->next;
	}
	fprintf(fptr, "Number of students: %d\n", studCount);
	node = headStud;
	while(node != NULL){
		fprintf(fptr, "%d\n", node->ID);
		fprintf(fptr, "%s\n", node->firstName);
		fprintf(fptr, "%s\n", node->lastName);
		fprintf(fptr, "%f\n", node->GPA);
		node = node->next;
	}
	fclose(fptr);
}

