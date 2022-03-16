#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

//Only for prof
enum Department {English, Math, Philosophy, Theology, Biology, Physics, Chemistry, Engineering, Unknown};
//base class for all people
class Person{
//used string instead because it's easier
private:
	int ID;
	string firstName;
	string lastName;
public:
	//no vals given for person
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
	}
	Person(Person &init){
		this->ID = init.ID;
		this->firstName = init.firstName;
		this->lastName = init.lastName;
	}
	//destructor Person
	~Person(){
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
	
};
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


int main(int argc, char **argv)
{
	printf("hello world\n");
	//creation of people
	Student* boy = new Student();
	Professor* ohYeah = new Professor(3, "Thomas", "Engine", 20000, true, Engineering);
	//copy constructor
	Student* boyT = new Student(*boy);
	//basic calls to getter and setter methods
	cout<<"Student last name: "<<boy->getLast()<<endl;
	cout<<"Other stud last: "<<boyT->getLast()<<endl;
	cout<<boy->getFirst()<<"'s GPA: "<<boy->getGPA()<<endl;
	cout<<ohYeah->getFirst()<<"'s salary is: "<<ohYeah->getSal()<<endl;
	boy->setGPA(2.2);
	cout<<"New GPA: "<<boy->getGPA()<<endl;
	delete(boy);
	delete(ohYeah);
	delete(boyT);
	return 0;
}
