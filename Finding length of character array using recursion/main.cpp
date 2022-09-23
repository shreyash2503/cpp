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

int main()
{
   char input[]="Shreyash is the best";
   cout<<length(input)<<endl;
}
