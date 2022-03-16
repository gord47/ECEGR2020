#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
enum Department {English, Math, Philosophy, Theology, Biology, Physics, Chemistry, Engineering, Unknown};

//student structure
class Student{
//used string instead because it's easier
private:
	int ID;
	char* firstName;
	char* lastName;
	float  GPA;
	Student *next;
public:
	//no vals given for person
	Student(){
		this->ID = 1;
		this->firstName = (char*) malloc(sizeof(strlen((char*) "Billy")+1));
		strcpy(this->firstName, (char*) "Billy");
		this->lastName = (char*) malloc(sizeof(strlen((char*) "Bob")+1));
		strcpy(this->lastName, (char*) "Bob");
		this->GPA = 1.0;
		cout<<"base person done"<<endl;
	}
	//construct w/ vals
	Student(int id, char* firsty, char* lasty, float gpa){
		this->ID = id;
		this->firstName = (char*) malloc(sizeof(strlen(firsty)+1));
		strcpy(this->firstName, firsty);
		this->lastName =(char*) malloc(sizeof(strlen(lasty)+1));
		strcpy(this->lastName, lasty);
		this->GPA = gpa;
	}
	Student(Student &init){
		this->ID = init.ID;
		if(init.firstName){
			setFirst(init.firstName);
		}
		if(init.lastName){
			setLast(init.lastName);
		}
		this->GPA = init.GPA;
	}
	//destructor Person
	~Student(){
		if(firstName){
			free(firstName);
		}
		if(lastName){
			free(lastName);
		}
		cout<<"destructor called"<<endl;
	}
	//overload operator for person (need for all inherited classes
	Student& operator=(Student const &s){
		this->ID = s.ID;
		this->firstName = s.firstName;
		this->lastName = s.lastName;
		cout<<"Person op overload"<<endl;
		return *this;
	}
	//getter and setter methods
	int getID(){
		return this->ID;
	}
	void setID(int newID){
		this->ID = newID;
	}
	char* getFirst(void){
		return this->firstName;
	}
	void setFirst(char* first){
		this->firstName = (char*) realloc(this->firstName, sizeof(strlen(first)+1));
		strcpy(this->firstName, first);
	}
	char* getLast(void){
		return this->lastName;
	}
	void setLast(char* last){
		this->lastName =(char*) realloc(this->firstName, sizeof(strlen(last)+1));
		strcpy(this->lastName, last);
	}
	float getGPA(void){
		return this->GPA;
	}
	void setGPA(float newGPA){
		this->GPA = newGPA;
	}
	Student* getNext(){
		return next;
	}
	void setNext(Student* newNext){
		this->next = newNext;
	}
	
};
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
void upStudMen(char* firsty, char* lasty);
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
			default:
				printf("invalid \n");
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
	ifstream readerRec;
	int studTot = 0;
	readerRec.open("studentThing.txt");
	if(!readerRec.is_open()){
		cerr<<"couldn't open the file"<<endl;
	}
	else{
		string temp = "";
		readerRec >> temp;
		readerRec >> temp;
		readerRec >> studTot;
		cout<<temp<<endl;
		cout << "Number of Students: "<<studTot<<endl;
		for(int i = 0; i <studTot; i++){
			int readID = 0;
			char* readFirst = NULL;
			char* readLast = NULL;
			float readGPA = 0.0;
			readerRec>>temp;
			readerRec>>temp;
			readerRec>>readID;
			readerRec>>temp;
			readerRec>>temp;
			readerRec>>temp;
			readFirst = (char*) malloc(strlen((temp.c_str())+1));
			strcpy(readFirst, temp.c_str());
			printf("%s", readFirst);
			readerRec>>temp;
			readerRec>>temp;
			readerRec>>temp;
			readLast = (char*)malloc(strlen((temp.c_str())+1));
			strcpy(readLast, temp.c_str());
			readerRec>>temp;
			readerRec>>readGPA;
			Student* newStudent = new Student(readID, readFirst, readLast, readGPA);
			insertStudent(newStudent);
			free(readFirst);
			free(readLast);
		}
		
	}
	/*int numStud;
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
	*/
	
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
	char* firsty;
	char* lasty;
	float gpa;
	Student* checkID = headStud;
	string temp;
	printf("Enter student ID: \n");
	cin>>studID;
	while(checkID != NULL){
		if(studID == checkID->getID()){
			printf("ID already used \n");
			checkID = headStud;
			printf("Enter student ID: \n");
			cin>>studID;
		}
		checkID = checkID->getNext();
	}
	printf("Enter student first name: \n");
	cin>>temp;
	firsty = (char*) malloc(sizeof(strlen(temp.c_str())+1));
	strcpy(firsty, temp.c_str());
	printf("Enter student last name: \n");
	cin>>temp;
	lasty = (char*) malloc(sizeof(strlen((temp.c_str())+1)));
	strcpy(lasty, temp.c_str());
	printf("Enter student GPA: \n");
	cin>>gpa;
	Student* addStud = new Student(studID, firsty, lasty, gpa);
	insertStudent(addStud);
	free(firsty);
	free(lasty);
}

//creating a student
/*Student* createStudent(int studID, char *firsty, char *lasty, float gpa){
	Student newStud = new S;
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
*/

//add student to list
void addStudent(Student* newStud){
	Student* currentStud = headStud;
	if(headStud == NULL){
		headStud = newStud;
		return;
	}
	while(currentStud->getNext()!=NULL){
		currentStud = currentStud->getNext();
	}
	currentStud->setNext(newStud);
}

//print all students in list
void printStud(){
	Student* currentStud = headStud;
	while(currentStud->getNext()!=NULL){
		printf("%s %s\n", currentStud->getFirst(), currentStud->getLast());
		currentStud = currentStud->getNext();
	}
	printf("%s %s\n", currentStud->getFirst(), currentStud->getLast());
}

//insert student based on GPA value
void insertStudent(Student *newStud){
	if(headStud == NULL){
		headStud = newStud;
		return;
	}
	else if(headStud->getNext() == NULL){
		if(headStud->getGPA() >= newStud->getGPA()){
			headStud->setNext(newStud);
			return;
		}
		else{
			Student* temp = headStud;
			headStud = newStud;
			headStud->setNext(temp);
			return;
		}
	}
	Student* node = headStud;
	while(node->getNext() != NULL){
		Student* nextStud = node->getNext();
		if((node->getGPA() > newStud->getGPA())&&(newStud->getGPA() >= nextStud->getGPA())){
			newStud->setNext(node->getNext());
			node->setNext(newStud);
			return;
		}
		else if(node->getGPA() <= newStud->getGPA()){
			newStud->setNext(node);
			headStud = newStud;
			return;
		}
		node = node->getNext();
	}
	node->setNext(newStud);
	newStud->setNext(NULL);
	return;
}

void checkOut(int remID){
	Student* node = headStud;
	int check = 0;
	while(node != NULL){
		if(remID == node->getID()){
			char* firsty;
			char* lasty;
			strcpy(firsty, node->getFirst());
			strcpy(lasty, node->getLast());
			removeStudent(node);
			check = 1;
			printf("%s %s was removed from the list \n", firsty, lasty);
			free(firsty);
			free(lasty);
			return;
		}
		node = node->getNext();
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
		headStud = headStud->getNext();
		delete(remStud);
		return;
	}
	while(curStud != NULL && curStud != remStud){
		preStud = curStud;
		curStud = curStud->getNext();
	}
	if(curStud != NULL){
		preStud->setNext(curStud->getNext());
	}
	delete(remStud);
}
void updateStud(int updateID){
	Student* node = headStud;
	Student* prevStud = node;
	int check = 0;
	int userIn = 0;
	while(node != NULL){
		if(updateID == node->getID()){
			do{
				upStudMen(node->getFirst(), node->getLast());
				cin>>userIn;
				int newID, oldID;
				char* newFirsty; 
				char* oldFirsty;
				char* newLasty; 
				char* oldLasty;
				float newGPA, oldGPA;
				string temp = "";
				Student* checkID = headStud;
				switch(userIn){
					case 1:
						printf("Enter new ID for student: \n");
						cin>>newID;
						while(checkID != NULL){
							if(newID == checkID->getID()){
								printf("ID used already\n");
								checkID = headStud;
								printf("Enter new student id again: \n");
								cin>>newID;
							}
							checkID = checkID->getNext();
						}
						oldID = node->getID();
						node->setID(newID);
						printf("updated %d to %d\n", oldID, newID);
						break;
					case 2:
						printf("enter new first name:\n");
						cin>>temp;
						newFirsty = (char*) malloc(strlen(temp.c_str()+1));
						strcpy(newFirsty, temp.c_str());
						oldFirsty = (char*) malloc(strlen(node->getFirst()+1));
						strcpy(oldFirsty, node->getFirst());
						node->setFirst(newFirsty);
						printf("%s updated to %s\n", oldFirsty, newFirsty);
						free(oldFirsty);
						free(newFirsty);
						break;
					case 3:
						printf("enter new last name:\n");
						cin>>temp;
						newLasty = (char*) malloc(strlen(temp.c_str()+1));
						strcpy(newLasty, temp.c_str());
						oldLasty = (char*) malloc(strlen(node->getLast()+1));
						strcpy(oldLasty, node->getLast());
						node->setLast(newLasty);
						printf("%s updated to %s\n", oldLasty, newLasty);
						free(oldLasty);
						free(newLasty);
						break;
					case 4:
						printf("enter new GPA for the student\n");
						scanf("%f", &newGPA);
						oldGPA = node->getGPA();
						if(prevStud == node){
							node->setNext(NULL);
							insertStudent(node);
						}
						else{
							prevStud->setNext(node->getNext());
							insertStudent(node);
						}
						printf("updated successfully\n");
						break;
					
				}
			}while(userIn != 5);
			return;
		}
		prevStud = node;
		node = node->getNext();
	}
	if(check == 0){
		printf("There is no student with this ID\n");
		return;
	}
}
void upStudMen(char* firsty, char* lasty){
	printf("[1] enter new ID\n");
	printf("[2] enter new first name\n");
	printf("[3] enter new last name\n");
	printf("[4] enter new gpa\n");
	printf("[5] Quit\n\n");
}
void freeAll(){
	Student* node  = headStud;
	Student* nextNode = headStud->getNext();
	while(node != NULL){
		removeStudent(node);
		node = nextNode;
		nextNode = nextNode->getNext();
	}
}
void saveList(){
	ofstream recorder;
	recorder.open("Lab_6/studentDat.txt");
	Student* node = headStud;
	int studCount = 0;
	while(node != NULL){
		studCount++;
		node = node->getNext();
	}
	if(!recorder.is_open()){
		cout<<"Can't write to file"<<endl;
	}
	else{
		recorder<<"Num students: "<<studCount<<endl;
		node = headStud;
		while(node != NULL){
			recorder<<"Student ID: "<<node->getID()<<endl;
			recorder<<"First name: "<<node->getFirst()<<endl;
			recorder<<"Last name: "<<node->getLast()<<endl;
			recorder<<"GPA: "<<node->getGPA()<<endl;
			node = node->getNext();
			
		}
		recorder.close();
	}
}


