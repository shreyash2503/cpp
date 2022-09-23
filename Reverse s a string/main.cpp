#include <iostream>
#include <string.h>
using namespace std;

int main()
{
   char a[100];
   cin.getline(a,100);
    int start = 0;
    int end = strlen(a);
    cout<<end<<endl;
  while(start<end){
        char c = a[start];
        a[start]=a[end-1];
        a[end-1]=c;
        start++;
        end--;
  }



   cout<<a;
}
