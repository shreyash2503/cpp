#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
    int age;
    int rollNo;
    string name;
    void setAge(int a){
        age = a;

    }
}

int main()
{
    char a[100];
    cin.getline(a,10,'a');
    cout<<a;
}
