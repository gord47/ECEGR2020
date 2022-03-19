#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <typeinfo>
#include <stdlib.h>
using namespace std;
//class comparator
template <class DstType, class SrcType>
bool instanceof(const SrcType* src){
	return dynamic_cast<const DstType*>(src) != nullptr;
}
//Only for prof
enum Department {English, Math, Philosophy, Theology, Biology, Physics, Chemistry, Engineering, Unknown};
//base class for all people
class Person{
//used string instead because it's easier
private:
	int ID;
	string firstName;
	string lastName;
	Person* next;
public:
	//no vals given for person
	virtual ~Person();
	Person(){
		this->ID = 1;
		this->firstName = "Billy";
		this->lastName = "Bob";
		cout<<"base person done"<<endl;
	}
	//construct w/ vals
	Person(int id, string firsty, string lasty){
		this->ID = id;
		this->firstName = firsty;
		this->lastName = lasty;
		this->next = NULL;
	}
	Person(Person &init){
		this->ID = init.ID;
		this->firstName = init.firstName;
		this->lastName = init.lastName;
		this->next = init.next;
	}
	
	//overload operator for person (need for all inherited classes
	Person& operator=(Person const &s){
		this->ID = s.ID;
		this->firstName = s.firstName;
		this->lastName = s.lastName;
		cout<<"Person op overload"<<endl;
		return *this;
	}
	//getter and setter methods
	int getID(void){
		return this->ID;
	}
	void setID(int ID){
		this->ID = ID;
	}
	string getFirst(void){
		return this->firstName;
	}
	void setFirst(string first){
		this->firstName = first;
	}
	string getLast(void){
		return this->lastName;
	}
	void setLast(string last){
		this->lastName = last;
	}
	Person* getNext(){
		return this->next;
	}
	void setNext(Person* newNext){
		this->next = newNext;
	}
};
//destructor Person
Person::~Person(){
	cout<<"destructor called"<<endl;
}
//Student, prof, and employee all inherit from the base person class
class Student: public Person{
//vals specific to student
private:
	float GPA;
public:
	//Student construct w/ vals
	Student(int id, string firsty, string lasty, float gpa):Person(id, firsty, lasty){
		this->GPA = gpa;
	}
	//Student construct no vals
	Student():Person(){
		this->GPA = 1.1;
	}
	//student copy construct
	Student(Student &init):Person(init){
		this->GPA = init.GPA;
	}
	//strudent destruct
	~Student(){
		cout<<"Student deconstructor called"<<endl;
	}
	//overload equal operator for student
	/*Student& operator=(Student const &s):Person& operator=(s){
		
	}*/
	float getGPA(void){
		return this->GPA;
	}
	void setGPA(float newGPA){
		this->GPA = newGPA;
	}
	
};
//this class could also inherit from Employee as professor only adds unique vals from employee
class Professor: public Person{
//vals specific to the professor
private:
	float salary;
	bool tenured;
	Department department;
public:
	//prof construct with no vals given
	Professor():Person(){
		this->salary = 20.0;
		this->tenured = false;
		this->department = Unknown;
	}
	//prof construct w/ vals
	Professor(int id, string firsty, string lasty, float sal, bool ten, Department dep):Person(id, firsty, lasty){
		this->salary = sal;
		this->tenured = ten;
		this->department = dep;
		cout<<"Professor created"<<endl;
	}
	//prof copy constructor
	Professor(Professor &init):Person(init.getID(), init.getFirst(), init.getLast()){
		this->salary = init.salary;
		this->tenured = init.tenured;
		this->department = init.department;
	}
	//prof destruct
	~Professor(){
		cout<<"Prof destructor called"<<endl;
	}
	//get and set salary for prof
	float getSal(){
		return this->salary;
	}
	void setSal(float newSal){
		this->salary = newSal;
	}
	//get and set tenure
	bool getTen(){
		return this->tenured;
	}
	void setTen(bool tenStat){
		this->tenured = tenStat;
	}
	//get and set dep for prof
	Department getDep(){
		return this->department;
	}
	void setDep(Department newDep){
		this->department = newDep;
	}
	
};
class Employee: public Person{
private:
	float salary;
public:
	Employee():Person(){
		this->salary = 0.0;
	}
	Employee(int ID, string firsty, string lasty, float sal):Person(ID, firsty, lasty){
		this->salary = sal;
	}
	~Employee(){
		cout<<"Employee destructor called"<<endl;
	}
	float getSal(){
		return this->salary;
	}
	void setSal(float newSal){
		this->salary = newSal;
	}
};
Person* headPers = NULL;
void readRecords();
void readList();
void saveList();
void addPerson(Person* newPer);
void menuStud();
void createNewPerson();
void printPers();
void insertPerson(Person* newPer);
void checkOut(int remID);
void removePerson(Person* remPer);
void updatePerson(int updateID);
void upStudMen(string firsty, string lasty);
void upProfMen(string firsty, string lasty);
void upEmpMen(string firsty, string lasty);
void freeAll();

int main(int argc, char **argv)
{
	printf("hello world\n");
	readRecords();
	int userIn;
	do{
		printf("1) list all people\n");
		printf("2) add person\n");
		printf("3) Remove person\n");
		printf("4) Update person\n");
		printf("5) Quit\n");
		printf("What do you want to do: \n");
		scanf("%d", &userIn);
		int enterID;
		switch(userIn){
			case 1:
				readList();
				break;
			case 2:
				createNewPerson();
				break;
			case 3:
				printf("Enter the Person ID you want to remove:\n");
				scanf("%d", &enterID);
				checkOut(enterID);
				break;
			case 4:
				printf("Enter the person ID you want to update:\n");
				cin>>enterID;
				updatePerson(enterID);
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

void readRecords(){
	ifstream readerRec;
	int peopleTot = 0;
	readerRec.open("allRecords.txt");
	if(!readerRec.is_open()){
		cerr<<"couldn't open the file"<<endl;
	}
	else{
		string temp = "";
		readerRec >> temp;
		readerRec >> temp;
		readerRec >> peopleTot;
		cout<<temp<<endl;
		cout << "Number of People: "<<peopleTot<<endl;
		for(int i = 0; i <peopleTot; i++){
			readerRec >> temp;
			if(temp == "Student"){
				int readID = 0;
				string readFirst = "";
				string readLast = "";
				float readGPA = 0.0;
				readerRec>>temp;
				readerRec>>readID;
				readerRec>>temp;
				readerRec>>temp;
				readerRec>>readFirst;
				readerRec>>temp;
				readerRec>>temp;
				readerRec>>readLast;
				readerRec>>temp;
				readerRec>>readGPA;
				Student* newStudent = new Student(readID, readFirst, readLast, readGPA);
				insertPerson(newStudent);
			}
			else if(temp == "Professor"){
				int readID = 0;
				string readFirst = "";
				string readLast = "";
				float readSal = 0.0;
				Department readDep = Unknown;
				bool readTenure = false;
				readerRec>>temp;
				readerRec>>readID;
				readerRec>>temp;
				readerRec>>temp;
				readerRec>>readFirst;
				readerRec>>temp;
				readerRec>>temp;
				readerRec>>readLast;
				readerRec>>temp;
				readerRec>>readSal;
				readerRec>>temp;
				readerRec>>readTenure;
				readerRec>>temp;
				readerRec>>temp;
				if(temp == "English"){
					readDep = English;
				}
				else if(temp == "Math"){
					readDep = Math;
				}
				else if(temp == "Philosophy"){
					readDep = Philosophy;
				}
				else if(temp == "Theology"){
					readDep = Theology;
				}
				else if(temp == "Biology"){
					readDep = Biology;
				}
				else if(temp == "Physics"){
					readDep = Physics;
				}
				else if(temp == "Chemistry"){
					readDep = Chemistry;
				}
				else if(temp == "Engineering"){
					readDep = Engineering;
				}
				else{
					readDep = Unknown;
				}
				Person* newProf = new Professor(readID, readFirst, readLast, readSal, readTenure, readDep);
				insertPerson(newProf);
			}
			else if(temp == "Employee"){
				int readID = 0;
				string readFirst = "";
				string readLast = "";
				float readSal = 0.0;
				readerRec>>temp;
				readerRec>>readID;
				readerRec>>temp;
				readerRec>>temp;
				readerRec>>readFirst;
				readerRec>>temp;
				readerRec>>temp;
				readerRec>>readLast;
				readerRec>>temp;
				readerRec>>readSal;
				Person* newEmp = new Employee(readID, readFirst, readLast, readSal);
				insertPerson(newEmp);
			}
			else{}
		}
		readerRec.close();
		cout<<"Finished reading the file"<<endl;
	}
}
void readList(){
	Person* node = headPers;
	cout<<"------Records------"<<endl;
	while(node != NULL){
		if(instanceof<Student>(node)){
			Student* tempStud = (Student*) node;
			cout<<"Student\n"<<endl;
			cout<<"ID: "<<tempStud->getID()<<endl;
			cout<<"First name: "<<tempStud->getFirst()<<endl;
			cout<<"Last name: "<<tempStud->getLast()<<endl;
			cout<<"GPA: "<<tempStud->getGPA()<<endl;
			delete(tempStud);
		}
		else if(instanceof<Professor>(node)){
			Professor* tempProf = (Professor*) node;
			cout<<"Professor"<<endl;
			cout<<"ID: "<<tempProf->getID()<<endl;
			cout<<"First name: "<<tempProf->getFirst()<<endl;
			cout<<"Last name: "<<tempProf->getLast()<<endl;
			cout<<"Salary: "<<tempProf->getSal()<<endl;
			if(tempProf->getTen()){
				cout<<"Professor is tenured"<<endl;
			}
			else{
				cout<<"Professor isn't tenured"<<endl;
			}
			
			if(tempProf->getDep() == English)
			{
				cout << "Department: English"<<endl;
			}
			else if(tempProf->getDep() == Math)
			{
				cout << "Department: Math"<<endl;
			}
			else if(tempProf->getDep() == Philosophy)
			{
				cout << "Department: Philosophy"<<endl;
			}
			else if(tempProf->getDep() == Theology)
			{
				cout << "Department: Theology"<<endl;
			}
			else if(tempProf->getDep() == Biology)
			{
				cout << "Department: Biology"<<endl;
			}
			else if(tempProf->getDep() == Physics)
			{
				cout << "Department: Physics"<<endl;
			}
			else if(tempProf->getDep() == Chemistry)
			{
				cout << "Department: Chemistry"<<endl;
			}
			else if(tempProf->getDep() == Engineering)
			{
				cout << "Department: Engineering"<<endl;
			}
			else
			{
				cout << "Department: Unknown"<<endl;
			}
			delete(tempProf);
		}
		else if(instanceof<Employee>(node)){
			Employee* tempEmp = (Employee*) node;
			cout<<"Employee"<<endl;
			cout<<"ID: "<<tempEmp->getID()<<endl;
			cout<<"First name: "<<tempEmp->getFirst()<<endl;
			cout<<"Last name: "<<tempEmp->getLast()<<endl;
			cout<<"Salary: "<<tempEmp->getSal()<<endl;
			delete(tempEmp);
		}
		node = node->getNext();
		cout<<"---------------------------"<<endl;
	}
	cout<<"================================="<<endl;
}
void saveList(){
	ofstream newRecords;
	newRecords.open("allRecords.txt");
	Person* node = headPers;
	int count;
	while(node != NULL){
		count++;
		node = node->getNext();
	}
	if(!newRecords.is_open()){
		cout<<"Couldn't write"<<endl;
	}
	else{
		newRecords<<"Number of people: "<<count<<endl;
		node = headPers;
		while(node!=NULL){
			if(instanceof<Student>(node)){
				Student* nodeStud = (Student*) node;
				newRecords<<"Student"<<endl;
				newRecords<<"ID: "<<nodeStud->getID()<<endl;
				newRecords<<"First Name: "<<nodeStud->getFirst()<<endl;
				newRecords<<"Last Name: "<<nodeStud->getLast()<<endl;
				newRecords<<"GPA: "<<nodeStud->getGPA()<<endl;
				delete(nodeStud);
			}
			else if(instanceof<Professor>(node)){
				Professor* nodeProf = (Professor*) node;
				newRecords <<"Professor"<<endl;
				newRecords<<"ID: "<<nodeProf->getID()<<endl;
				newRecords<<"First Name: "<<nodeProf->getFirst()<<endl;
				newRecords<<"Last Name: "<<nodeProf->getLast()<<endl;
				newRecords<<"Salary: "<<nodeProf->getSal()<<endl;
				newRecords<<"Tenured: "<<nodeProf->getTen()<<endl;
				if(nodeProf->getDep() == English)
				{
					newRecords << "\nDepartment: English";
				}
				else if(nodeProf->getDep() == Math)
				{
					newRecords << "\nDepartment: Math";
				}
				else if(nodeProf->getDep() == Philosophy)
				{
					newRecords << "\nDepartment: Philosophy";
				}
				else if(nodeProf->getDep() == Theology)
				{
					newRecords << "Department: Theology"<<endl;
				}
				else if(nodeProf->getDep() == Biology)
				{
					newRecords << "Department: Biology"<<endl;
				}
				else if(nodeProf->getDep() == Physics)
				{
					newRecords << "Department: Physics"<<endl;
				}
				else if(nodeProf->getDep() == Chemistry)
				{
					newRecords << "Department: Chemistry"<<endl;
				}
				else if(nodeProf->getDep() == Engineering)
				{
					newRecords << "Department: Engineering"<<endl;
				}
				else
				{
					newRecords << "Department: Unknown"<<endl;
				}
				delete(nodeProf);
			}
			else if(instanceof<Employee>(node)){
				Employee* nodeEmp = (Employee*) node;
				newRecords << "Employee"<<endl;
				newRecords<<"ID: "<<nodeEmp->getID()<<endl;
				newRecords<<"First Name: "<<nodeEmp->getFirst()<<endl;
				newRecords<<"Last Name: "<<nodeEmp->getLast()<<endl;
				newRecords<<"Salary: "<<nodeEmp->getSal()<<endl;
				delete(nodeEmp);
			}
			node = node->getNext();
		}
		newRecords.close();
	}
}
void insertPerson(Person* newPer){
	if(headPers == NULL){
		headPers = newPer;
		return;
	}
	else if(headPers->getNext() == NULL){
		if(headPers->getID() >= newPer->getID()){
			headPers->setNext(newPer);
			return;
		}
		else{
			Person* temp = headPers;
			headPers = newPer;
			headPers->setNext(temp);
			return;
		}
	}
	Person* node = headPers;
	while(node->getNext() != NULL){
		Person* nextPer = node->getNext();
		if((node->getID() > newPer->getID())&&(newPer->getID() >= nextPer->getID())){
			newPer->setNext(node->getNext());
			node->setNext(newPer);
			return;
		}
		else if(node->getID() <= newPer->getID()){
			newPer->setNext(node);
			headPers = newPer;
			return;
		}
		node = node->getNext();
	}
	node->setNext(newPer);
	newPer->setNext(NULL);
	return;
}

void removePerson(Person* remPer){
	Person* curPers = headPers;
	Person* prePers = NULL;
	if(headPers == remPer){
		headPers = headPers->getNext();
		delete(remPer);
		return;
	}
	while(curPers != NULL && curPers != remPer){
		prePers = curPers;
		curPers = curPers->getNext();
	}
	if(curPers != NULL){
		prePers->setNext(curPers->getNext());
	}
	delete(remPer);
}

void checkOut(int remID){
	Person* node = headPers;
	int check = 0;
	while(node != NULL){
		if(remID == node->getID()){
			string firsty = node->getFirst();
			string lasty = node->getLast();
			removePerson(node);
			check = 1;
			cout<<firsty<<" "<<lasty<<" was removed from the list \n"<<endl;
			return;
		}
		node = node->getNext();
	}
	if(check == 0){
		printf("no person exists with this ID\n");
		return;
	}
	return;
}

void createNewPerson(){
	int userIn = 0;
	do{
		int inID;
		string firsty;
		string lasty;
		float gpa, salary;
		bool ten;
		Department dep;
		Person* checkID = headPers;
		string temp;
		cout<<"--Would you like to add--"<<endl;
		cout<<"1) Student"<<endl;
		cout<<"2) Professor"<<endl;
		cout<<"3) Employee"<<endl;
		cout<<"4) Quit"<<endl;
		cout<<"----------------------"<<endl;
		cin>>userIn;
		switch(userIn){
			case 1:
			{
				printf("Enter ID of student: \n");
				cin>>inID;
				while(checkID != NULL){
					if(inID == checkID->getID()){
						cout<<"ID already used"<<endl;
						checkID = headPers;
						printf("Enter ID of student: \n");
						cin>>inID;
					}
					checkID = checkID->getNext();
				}
				printf("Enter first name:\n");
				cin>>firsty;
				printf("Enter last name:\n");
				cin>>lasty;
				printf("Enter GPA:\n");
				cin>>gpa;
				Person* newStud = new Student(inID, firsty, lasty, gpa);
				insertPerson(newStud);
				break;
			}
			case 2:
			{
				printf("Enter ID of professor: \n");
				cin>>inID;
				while(checkID != NULL){
					if(inID == checkID->getID()){
						cout<<"ID already used"<<endl;
						checkID = headPers;
						cout<<"Enter ID of professor: "<<endl;
						cin>>inID;
					}
					checkID = checkID->getNext();
				}
				printf("Enter first name:\n");
				cin>>firsty;
				printf("Enter last name:\n");
				cin>>lasty;
				printf("Enter salary:\n");
				cin>>salary;
				printf("Are they tenured (yes/no)\n");
				cin>>temp;
				string yes = "yes";
				string no = "no";
				if(strcasecmp(yes.c_str(), temp.c_str())==0){
					ten = true;
				}
				else if(strcasecmp(yes.c_str(), temp.c_str())==0){
					ten = false;
				}
				else{
					bool valTen = true;//variable to that is true when the input isn't Y or N
					while(valTen){
						cout<<"Invalid answer, indicate yes or no"<<endl;
						cin>>temp;
						if(strcasecmp(yes.c_str(), temp.c_str())==0){
							ten = true;
							valTen = false;
						}
						else if(strcasecmp(yes.c_str(), temp.c_str())==0){
							ten = false;
							valTen = false;
						}
					}
				}
				cout<<"Enter the professor's Department"<<endl;
				cin>>temp;
				if(temp == "English"){dep = English;}
				else if(temp == "Math"){dep = Math;}
				else if(temp == "Philsophy"){dep = Philosophy;}
				else if(temp == "Theology"){dep = Theology;}
				else if(temp == "Biology"){dep = Biology;}
				else if(temp == "Physics"){dep = Physics;}
				else if(temp == "Chemistry"){dep = Chemistry;}
				else if(temp == "Engineering"){dep = Engineering;}
				else{dep = Unknown;}
				Person* aProf = new Professor(inID, firsty, lasty, salary, ten, dep);
				insertPerson(aProf);
				break;
			}
			case 3:
			{
				printf("Enter ID of Employee: \n");
				cin>>inID;
				while(checkID != NULL){
					if(inID == checkID->getID()){
						cout<<"ID already used"<<endl;
						checkID = headPers;
						printf("Enter ID of employee: \n");
						cin>>inID;
					}
					checkID = checkID->getNext();
				}
				printf("Enter first name:\n");
				cin>>firsty;
				printf("Enter last name:\n");
				cin>>lasty;
				printf("Enter salary:\n");
				cin>>salary;
				Person* aEmp = new Employee(inID, firsty, lasty, salary);
				insertPerson(aEmp);
				break;
			}
			case 4:
				break;
			default:
				cout<<"invalid input"<<endl;
		}
	}while(userIn != 4);
	
}

void updatePerson(int updateID){
	Person* node = headPers;
	int userIn = 0;
	while(node != NULL){
		if(updateID == node->getID()){
			if(instanceof<Student>(node)){
				do{
					upStudMen(node->getFirst(), node->getLast());
					cin>>userIn;//input usied in switch case
					cin>>userIn;
					int newID, oldID = 0;
					string newFirsty = ""; 
					string oldFirsty = "";
					string newLasty = ""; 
					string oldLasty = "";
					float newGPA, oldGPA;
					string temp = "";
					Person* checkID = headPers;
					Student* tempStud = (Student*) node;
					switch(userIn){
						case 1:
						{
							printf("Enter new ID for student: \n");
							cin>>newID;
							while(checkID != NULL){
								if(newID == checkID->getID()){
									printf("ID used already\n");
									checkID = headPers;
									printf("Enter new student id again: \n");
									cin>>newID;
								}
								checkID = checkID->getNext();
							}
							oldID = tempStud->getID();
							tempStud->setID(newID);
							node = tempStud;
							printf("updated %d to %d\n", oldID, newID);
							break;
							
						}
						case 2:
						{
							printf("enter new first name:\n");
							cin>>newFirsty;
							oldFirsty = tempStud->getFirst();
							tempStud->setFirst(newFirsty);
							cout<<oldFirsty<<" updated to "<< newFirsty<<endl;
							node = tempStud;
							break;
							
						}
						case 3:
						{
							printf("enter new last name:\n");
							cin>>newLasty;
							oldLasty = tempStud->getLast();
							tempStud->setFirst(newLasty);
							cout<<oldLasty<<" updated to "<< newLasty<<endl;
							node = tempStud;
							break;
							
						}
						case 4:
						{
							printf("enter new GPA for the student\n");
							scanf("%f", &newGPA);
							oldGPA = tempStud->getGPA();
							tempStud->setGPA(newGPA);
							node = tempStud;
							printf("updated successfully\n");
							break;
							
						}
					}
				}while(userIn != 5);
				return;
			}
			else if(instanceof<Professor>(node)){
				do{
					upProfMen(node->getFirst(), node->getLast());
					cin>>userIn;//input usied in switch case
					int newID, oldID = 0;
					string newFirsty = ""; 
					string oldFirsty = "";
					string newLasty = ""; 
					string oldLasty = "";
					float newSal, oldSal = 0.0;
					bool oldTen, newTen = false;
					Department newDep;
					string temp, temp2 = "";
					Person* checkID = headPers;
					Professor* tempProf = (Professor*) node;
					switch(userIn){
						case 1:
						{
							printf("Enter new ID for professor: \n");
							cin>>newID;
							while(checkID != NULL){
								if(newID == checkID->getID()){
									printf("ID used already\n");
									checkID = headPers;
									printf("Enter new professor id again: \n");
									cin>>newID;
								}
								checkID = checkID->getNext();
							}
							oldID = tempProf->getID();
							tempProf->setID(newID);
							node = tempProf;
							printf("updated %d to %d\n", oldID, newID);
							break;
						}
						case 2:
						{
							printf("enter new first name:\n");
							cin>>newFirsty;
							oldFirsty = tempProf->getFirst();
							tempProf->setFirst(newFirsty);
							cout<<oldFirsty<<" updated to "<< newFirsty<<endl;
							node = tempProf;
							break;
						
						}
						case 3:
						{
							printf("enter new last name:\n");
							cin>>newLasty;
							oldLasty = tempProf->getLast();
							tempProf->setFirst(newLasty);
							cout<<oldLasty<<" updated to "<< newLasty<<endl;
							node = tempProf;
							break;
							
						}
						case 4:
						{
							printf("Enter new salary:\n");
							cin>>newSal;
							oldSal = tempProf->getSal();
							tempProf->setSal(newSal);
							node = tempProf;
							cout<<oldSal<<" updated to "<<newSal<<endl;
							break;
						}
						case 5:
						{
							cout << "\nAre they tenured? (yes/no) ";
							cin >> temp;
							string yes = "yes";
							string no = "no";
							if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
								newTen = true;
							else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
								newTen = false;
							else
							{
								bool check = true;
								while(check)
								{
									cout << "Please indicate yes or no: "<<endl;
									cin >> temp;
									if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
									{
										newTen = true;
										check = false;
									}
										
									else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
									{
										newTen = false;
										check = false;
									}
								}
							}
							oldTen = tempProf->getTen();
							tempProf->setTen(newTen);
							node = tempProf;
							if(newTen == oldTen){
								cout<<"no change made"<<endl;
							}
							else{
								cout<<"changed successfully"<<endl;
							}
							break;
						}
						case 6:
						{
							cout<<"enter professor department"<<endl;
							cin>>temp;
							if(temp == "English"){newDep = English;}
							else if(temp == "Math"){newDep = Math;}
							else if(temp == "Philsophy"){newDep = Philosophy;}
							else if(temp == "Theology"){newDep = Theology;}
							else if(temp == "Biology"){newDep = Biology;}
							else if(temp == "Physics"){newDep = Physics;}
							else if(temp == "Chemistry"){newDep = Chemistry;}
							else if(temp == "Engineering"){newDep = Engineering;}
							else{newDep = Unknown;}
							if(tempProf->getDep() == English)
							{
								temp2 = "English";
							}
							else if(tempProf->getDep() == Math)
							{
								temp2 = "Math";
							}
							else if(tempProf->getDep() == Philosophy)
							{
								temp2 = "Philosophy";
							}
							else if(tempProf->getDep() == Theology)
							{
								temp2 = "Theology";
							}
							else if(tempProf->getDep() == Biology)
							{
								temp2 = "Biology";
							}
							else if(tempProf->getDep() == Physics)
							{
								temp2 = "Physics";
							}
							else if(tempProf->getDep() == Chemistry)
							{
								temp2 = "Chemistry";
							}
							else if(tempProf->getDep() == Engineering)
							{
								temp2 = "Engineering";
							}
							else
							{
								temp2 = "Unknown";
							}
							tempProf->setDep(newDep);
							node = tempProf;
							cout << "\n" << temp2 << " was successfully updated to " << temp;
							break;
						}
						case 7:
						{
							break;
						}
						default:
							cout<<"invalid input"<<endl;
					}
				}while(userIn !=7);
				return;
			}
			else if(instanceof<Employee>(node)){
				do{
					upEmpMen(node->getFirst(), node->getLast());
					cin>>userIn;//input usied in switch case
					int newID, oldID = 0;
					string newFirsty = ""; 
					string oldFirsty = "";
					string newLasty = ""; 
					string oldLasty = "";
					float newSal, oldSal = 0.0;
					string temp = "";
					Person* checkID = headPers;
					Employee* tempEmp = (Employee*) node;
					switch(userIn){
						case 1:
						{
							printf("Enter new ID for professor: \n");
							cin>>newID;
							while(checkID != NULL){
								if(newID == checkID->getID()){
									printf("ID used already\n");
									checkID = headPers;
									printf("Enter new professor id again: \n");
									cin>>newID;
								}
								checkID = checkID->getNext();
							}
							oldID = tempEmp->getID();
							tempEmp->setID(newID);
							node = tempEmp;
							printf("updated %d to %d\n", oldID, newID);
							break;
						}
						case 2:
						{
							printf("enter new first name:\n");
							cin>>newFirsty;
							oldFirsty = tempEmp->getFirst();
							tempEmp->setFirst(newFirsty);
							cout<<oldFirsty<<" updated to "<< newFirsty<<endl;
							node = tempEmp;
							break;
						
						}
						case 3:
						{
							printf("enter new last name:\n");
							cin>>newLasty;
							oldLasty = tempEmp->getLast();
							tempEmp->setFirst(newLasty);
							cout<<oldLasty<<" updated to "<< newLasty<<endl;
							node = tempEmp;
							break;
							
						}
						case 4:
						{
							printf("Enter new salary:\n");
							cin>>newSal;
							oldSal = tempEmp->getSal();
							tempEmp->setSal(newSal);
							node = tempEmp;
							cout<<oldSal<<" updated to "<<newSal<<endl;
							break;
						}
						case 5:
						{
							break;
						}
						default:
							cout<<"invalid input"<<endl;
					}
					
				}while(userIn != 5);
				return;
			}
		}
		node = node->getNext();
	}
	cout<<"no person exists with the ID given"<<endl;
}
void upStudMen(string firsty, string lasty){
	cout<<"------Student updater------"<<endl;
	cout<<"What do you want to update for "<<firsty<<" "<<lasty<<endl;
	cout<<"1) ID"<<endl;
	cout<<"2) first name"<<endl;
	cout<<"3) last name"<<endl;
	cout<<"4) GPA"<<endl;
	cout<<"5) Quit"<<endl;
}
void upProfMen(string firsty, string lasty){
	cout<<"------Professor updater------"<<endl;
	cout<<"What do you want to update for "<<firsty<<" "<<lasty<<endl;
	cout<<"1) ID"<<endl;
	cout<<"2) first name"<<endl;
	cout<<"3) last name"<<endl;
	cout<<"4) Salary"<<endl;
	cout<<"5) Tenure"<<endl;
	cout<<"6) Department"<<endl;
	cout<<"7) Quit"<<endl;
}
void upEmpMen(string firsty, string lasty){
	cout<<"------Student updater------"<<endl;
	cout<<"What do you want to update for "<<firsty<<" "<<lasty<<endl;
	cout<<"1) ID"<<endl;
	cout<<"2) first name"<<endl;
	cout<<"3) last name"<<endl;
	cout<<"4) Salary"<<endl;
	cout<<"5) Quit"<<endl;
}
void freeAll(){
	Person* node  = headPers;
	Person* nextNode = headPers->getNext();
	while(node != NULL){
		removePerson(node);
		node = nextNode;
		nextNode = nextNode->getNext();
	}
}
