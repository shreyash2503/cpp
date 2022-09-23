#include <iostream>

using namespace std;
int length(char input[])
{
    if(input[0]=='\0')
    {
        return 0;
    }
    return 1+length(input+1);
}

int str_to_int(char input[],int n)
{
    if(n==0)
    {
        return 0;
    }
    return (str_to_int(input,n-1)*10)+input[n-1]-'0';
}

int main()
{
    char input[100];
    cin>>input;
    cout<<str_to_int(input,length(input));
}
