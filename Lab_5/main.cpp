#include <iostream>
#include <cstring>

using namespace std;
//Only for prof
enum Department {English, Math, Philosophy, Theology, Biology, Physics, Chemistry, Engineering, Unknown};
//base class for all people
class Person{
//used string instead because it's easier
private:
	int ID;
	char* firstName;
	char* lastName;
public:
	//no vals given for person
	Person(){
		this->ID = 1;
		
		this->firstName = (char*) malloc(sizeof(strlen((char*) "Billy")+1));
		strcpy(this->firstName, (char*) "Billy");
		this->lastName = (char*) malloc(sizeof(strlen((char*) "Bob")+1));
		strcpy(this->lastName, (char*) "Bob");
		cout<<"base person done"<<endl;
	}
	//construct w/ vals
	Person(int id, char* firsty, char* lasty){
		this->ID = id;
		this->firstName = (char*) malloc(sizeof(strlen(firsty)+1));
		strcpy(this->firstName, firsty);
		this->lastName =(char*) malloc(sizeof(strlen(lasty)+1));
		strcpy(this->lastName, lasty);
	}
	Person(Person &init){
		this->ID = init.ID;
		this->firstName = (char*) malloc(sizeof(strlen(init.firstName)+1));
		strcpy(this->firstName, init.firstName);
		this->lastName =(char*) malloc(sizeof(strlen(init.lastName)+1));
		strcpy(this->lastName, init.lastName);
	}
	//destructor Person
	~Person(){
		if(firstName){
			free(firstName);
		}
		if(lastName){
			free(lastName);
		}
		cout<<"destructor called"<<endl;
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
	char* getFirst(void){
		return this->firstName;
	}
	void setFirst(char* first){
		this->firstName = (char*) malloc(sizeof(strlen(first)+1));
		strcpy(this->firstName, first);
	}
	char* getLast(void){
		return this->lastName;
	}
	void setLast(char* last){
		this->lastName =(char*) malloc(sizeof(strlen(last)+1));
		strcpy(this->lastName, last);
	}
	
};
//Student, prof, and employee all inherit from the base person class
class Student: public Person{
//vals specific to student
private:
	float GPA;
public:
	//Student construct w/ vals
	Student(int id, char* firsty, char* lasty, float gpa):Person(id, firsty, lasty){
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
	Professor(int id, char* firsty, char* lasty, float sal, bool ten, Department dep):Person(id, firsty, lasty){
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
	Employee(int ID, char* firsty, char* lasty, float sal):Person(ID, firsty, lasty){
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


int main(int argc, char **argv)
{
	printf("hello world\n");
	//creation of people
	Student* boy = new Student();
	Professor* ohYeah = new Professor(3, (char*)"Thomas", (char*)"Engine", 20000, true, Engineering);
	//copy constructor
	Student* boyT = new Student(*boy);
	//basic calls to getter and setter methods
	cout<<"Student last name: "<<boy->getLast()<<endl;
	cout<<"Other stud last: "<<boyT->getLast()<<endl;
	cout<<boy->getFirst()<<"'s GPA: "<<boy->getGPA()<<endl;
	cout<<ohYeah->getFirst()<<"'s salary is: "<<ohYeah->getSal()<<endl;
	boy->setGPA(2.2);
	cout<<"New GPA for "<<boy->getFirst()<<": "<<boy->getGPA()<<endl;
	delete(boy);
	delete(ohYeah);
	delete(boyT);
	return 0;
}
