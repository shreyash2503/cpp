#include <iostream>

using namespace std;
void removeDuplicates(char input[])
{
    if(input[0]=='\0')
    {
        return;
    }
    if(input[0]==input[1])
    {
        for(int i=1;input[i]!='\0';i++)
        {
            input[i]=input[i+1];
        }
        removeDuplicates(input);
    }
    else{
        removeDuplicates(input+1);
    }
}

int main()
{
   char input[100];
   cout<<"Enter the string::";
   cin.getline(input,100);
   removeDuplicates(input);
   cout<<input;

}
