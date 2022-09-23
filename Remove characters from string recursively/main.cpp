#include <iostream>

using namespace std;

void replaceCharacter(char input[],char k)
{
    if(input[0]=='\0')
    {
        return;
    }
    if(input[0]!=k)
    {
        replaceCharacter(input+1,k);
    }
    else{
        for(int i=0;input[i]!='\0';i++)
        {
            input[i]=input[i+1];
        }
        replaceCharacter(input,k);
    }
}

int main()
{
    char input[100];
    char k;
    cout<<"Enter the string from which you want to remove characters::";
    cin.getline(input,50);
    cout<<"Enter the character you want to remove from the string::";
    cin>>k;
    replaceCharacter(input,k);
    cout<<input;
}
