#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100];
    cout<<"Enter your string here";
    cin>>str;
    for(int i=0;i<strlen(str);i++){
        for(int j=0;j<=i;j++){
            cout<<str[j];
        }
        cout<<endl;
    }
}
