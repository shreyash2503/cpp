#include <iostream>

using namespace std;

int main()
{
    int a;

    char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cout<<"Enter the number for the height of the hour glass::";
    cin>>a;
    int b = a;
    int c = (a+1)/2;
    int d = 2;
    for(int i=0;i<(a+1)/2;i++)
    {
        for(int j=1;j<=i;j++){
            cout<<" ";
        }
        for(int k=0;k<b;k++)
        {
            cout<<alphabet[k];
        }
        b=b-2;
        cout<<endl;
    }

    for(int i=1;i<(a+1)/2;i++)
    {
        for(int j=1;j<c-1;j++){
            cout<<" ";
        }
        c=c-1;
        for(int k=0;k<=d;k++)
        {
            cout<<alphabet[k];
        }
        d=d+2;

        cout<<endl;
    }
}





