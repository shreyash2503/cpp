#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void printSubs(string input,string output)
{

    if(input.length() == 0)
    {
        cout<<output<<endl;
        return;
    }
    printSubs(input.substr(1),output);
    printSubs(input.substr(1),output+input[0]);
}

void printSubs2(char input[],char output[],int i)
{
    if(input[0]=='\0')
    {
        output[i]='\0';
        cout<<output<<endl;
        return;
    }
    //code for excludding i is not incremented as there is no need for incrementing of i
    printSubs2(input+1,output,i);
    //code for including , i is incremented as output needs to increment to store value
    output[i]=input[0];
    printSubs2(input+1,output,i+1);
}
int main()
{
    string nput,utput="";
    char output[100];
    cout<<"Enter the string whose substring you want::";
    cin>>nput;
    printSubs(nput,utput);
    cout<<endl;
    char input[100]="abc";
    printSubs2(input,output,0);
}
