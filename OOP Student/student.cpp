#include <iostream>
using namespace std;
class Student{
    private:
    int age;
    public:
         int rollno;

        Student(){
            cout<<"Constructor called"<<endl;
        }

        Student(int rollno){
            cout<<"Parameterized constructor is being called"<<endl;
            this->rollno = rollno;
        }
        Student(int a ,int rollno){
            cout<<"Constructor 3 called"<<endl;
            cout<<"this:: "<<this<<endl;
            this->rollno = rollno ;
            age = a;
        }

    string name;
        void display(){
            cout<<rollno<<" "<<age<<" "<<name<<" "<<endl;

        }
        int getAge(){
            cout<<"This for get age is ::"<<this<<endl;
            return age;

        }

        void setAge(int a){
            age=a;
        }

        ~Student(){
            cout<<"Destructor is being called"<<endl;

        }

};
