#include <stdio.h>
#include <stdlib.h>
int theArray[10] = {1,2,3,4,5,6,7,8,9,10};
FILE *fptr;

typedef struct student{
	int ID;
	char firstName[30];
	char lastName[30];
	float GPA;
}Student;

void ReverseArray(void){
	int tempArray[10] = {0};
	for(int i = 0; i < 10; i++){
		tempArray[i] = theArray[9-i];
	}
	for(int i = 0; i<10; i++){
		theArray[i] = tempArray[i];
		printf("%d", theArray[i]);
		
	}
	printf("\n");
}
void enterStudents(){
	int aNumber;
	printf("enter number of students: \n");
	scanf("%d", &aNumber);
	Student **studArray = (Student **)malloc(aNumber*sizeof(Student *));
	for(int j = 0; j < aNumber; j++) {
		studArray[j] = (Student*) malloc(sizeof(Student));
    }
	for(int i = 0; i < aNumber; i++){
		printf("Enter student ID: \n");
		scanf("%d",&studArray[i]->ID);
		printf("Enter student first name: \n");
		scanf("%s",&studArray[i]->firstName);
		printf("Enter student last name: \n");
		scanf("%s",&studArray[i]->lastName);
		printf("Enter student GPA: \n");
		scanf("%f",&studArray[i]->GPA);
		
	}
	for(int k = 0; k < aNumber; k++){
		printf("%d\n", k);
		for(int l = k; l<aNumber;l++){
			if(studArray[k]->GPA<studArray[l]->GPA){
				Student *temp = studArray[k];
				studArray[k] = studArray[l];
				studArray[l] = temp;
				printf("minimum GPA: %f\n", studArray[k]->GPA);
			}
		}
	}
	for(int i = 0;i<aNumber;i++){
		printf("GPA of %s is: %f\n", studArray[i]->firstName, studArray[i]->GPA);
	}
	
	fptr = fopen("Lab_3/studentDat.txt", "w+");
	fprintf(fptr,"Number of students is %d\n", aNumber);
	for(int i = 0; i < aNumber; i++){
		fprintf(fptr, "%d\n",studArray[i]->ID);
		fprintf(fptr, "%s\n",studArray[i]->firstName);
		fprintf(fptr, "%s\n",studArray[i]->lastName);
		fprintf(fptr, "%f\n",studArray[i]->GPA);
	}
	fclose(fptr);
	free(studArray);
}
void readFile(){
	char intro[50];
	int numStud;
	int ID;
	char firstName[30];
	char lastName[30];
	float gpa;
	float totGpa;
	float divisor = 0;
	fptr = fopen("Lab_3/studentDat.txt","r");
	if(fptr == NULL){
		printf("file doesn't exist\n");
		return NULL;
	}
	fscanf(fptr, "Number of students is %d\n", &numStud);
	printf("Number of students is %d\n", numStud);
	for(int i = 0; i< numStud; i++){
		fscanf(fptr, "%d\n", &ID);
		fscanf(fptr,"%s\n", firstName);
		fscanf(fptr,"%s\n", lastName);
		fscanf(fptr,"%f\n", &gpa);
		totGpa += gpa;
		divisor++;
		printf("Student ID: %d\n", ID);
		printf("First: %s\n", firstName);
		printf("Last: %s\n", lastName);
		printf("GPA: %f\n", gpa);
	}
	totGpa = totGpa/divisor;
	printf("The average GPA is: %f\n", totGpa);
	fclose(fptr);
}
int main(int argc, char **argv)
{
	printf("hello world\n");
	ReverseArray();
	enterStudents();
	readFile();
	return 0;
}
