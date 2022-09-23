#include <iostream>
#include "student.cpp"
using namespace std;
//declaring a object

int main()
{
    Student s1;  //default constructor will be called
    Student s2(10); //1 parameterized constructor will be called
    Student s3(10,100); //2 parameterized constructor will be called

    Student s4(s3); //Copy constructor is being called
    s3=s2;  //copy assignment is being called
    Student s5 = s3; //Copy constructor is being called





//    Student s1(30,400);
//    Student s2(10,100);
//    s2=s1;
//    Student *s3 = new Student(90,700);
//    *s3=s1;
//    delete s3;

/*
    Student s1(10,100);
    cout<<"Address of s1 is ::"<<&s1<<endl;
    s1.getAge();

    Student s2(20,200);
    cout<<"Address of s2 is ::"<<&s2<<endl;
    s2.getAge(); */


//    Student s1(10,100);
//    s1.display();
//    Student s2(s1);
//    s2.display();
//    Student *s3 = new Student(s2);
//    s3->display();
    /*
   //calling non-parametrized constructors
    Student s1;
    Student s2;
    Student* s3 = new Student;

    s1.display();
    s2.display();
    s3->display();
    //calling parameterized constructors
    Student s5(10);
    Student s6(30);
    Student* s7 = new Student(70);

    s5.display();
    s6.display();
    s7->display();

    Student s8(10,100);
    s8.display();
    */







    return 0;
}
