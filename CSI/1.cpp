#include <bits/stdc++.h>
using namespace std;

class Student{
public:  // -> Encapsulation
	char* name;
	int age;
	Student(char* name, int age){ // --> Parameterized constructor 
		this->name = name;
		this->age = age;
	}
	~Student(){ // -> Destructor
		delete name;
	}

};

class Person{
public:
	char* name;
	int age;
	Person(char* name, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}
};

int main()
{
	// ! Initialiazing a class;
	char name1[] = "Shreyash";
	char name2[] = "Pratik";

	// ! Two different ways to initialize a class;

	Student s1(name1, 21); // ! Instance of a class
	Student* s2 = new Student(name2, 21);  // s2 stores 400 


	cout<<s2->name<<endl; // -> Arrow operator this is same as calling (*s2).name
	cout<<s1.name<<endl;

	//Shallow copy and Deep copy
	Person p(name1, 21);
	name1[0] = 'T';
	cout<<"Output when shallow copy"<<endl;
	cout<<s1.name<<endl;

	cout<<"Output when deep copy"<<endl;
	cout<<p.name<<endl;


}