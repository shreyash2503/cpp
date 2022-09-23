#include <bits/stdc++.h>
using namespace std;
void replaceCharacter(char input[],char a, char k)
{
    if(input[0]=='\0')
    {
        return;
    }
    if(input[0]==a)
    {
        input[0]=k;
    }
    replaceCharacter(input+1,a,k);
}
int main()
{
    char input[100];
    char a;
    char k;
    cout<<"Enter the string in which you want to replace the character";
    cin>>input;
    cout<<"Enter the character you want to replace in the string::";
    cin>>a;
    cout<<"Enter the character you want to replace with in the string::";
    cin>>k;
    replaceCharacter(input,a,k);
    cout<<input;

}
