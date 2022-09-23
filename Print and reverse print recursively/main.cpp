#include <iostream>

using namespace std;
void print(char input[])
{
    if(input[0]=='\0')
    {
        return;
    }
    cout<<input[0]<<endl;
    print(input+1);
}
void reversePrint(char input[])
{
    if(input[0]=='/0')
    {
       return;
    }
     print(input+1);
     cout<<input[0]<<endl;
}

int main()
{
    char a[]="Hello";
    print(a);
    cout<<endl;
    reversePrint(a);

}
