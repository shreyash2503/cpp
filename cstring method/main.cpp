#include <iostream>
#include <cstring>

using namespace std;

bool mystrcmp(char str1[],char str2[]){
    if(strlen(str1)!= strlen(str2)) return false;
    for(int i=0;i<strlen(str1);i++){
        if(str1[i]!=str2[i]){
            return false;
        }
    }
    return true;
}

int stcmp(char str1[],char str2[]){
    int j=0;
    for(int i=0;i<strlen(str1);i++){
        if(str1[i]==str2[i]){
             j=1;
        }
        else{
            j=str1[i]-str2[i];
            break;
        }
    }
    if(j==1){
        return 0;
    }
    else {
        return j;
    }
}


int main()
{
//  char str[100];
//  char str1[100];
//  cin>>str;
//  cin>>str1;
//  if(mystrcmp(str,str1)){
//    cout<<"The entered strings are equal"<<endl;
//
//  }
//  else{
//    cout<<"The entered strings are not equal"<<endl;
//  }
//  cout<<stcmp(str,str1);
    char str1[100]="abcd";
    char str2[100]="Hello";
    cout<<"Before copying"<<endl;
    cout<<str1<<endl;
    cout<<str2<<endl;
    strcat(str1,str2);
    cout<<"After copying"<<endl;
    cout<<str1<<endl;
    cout<<str2<<endl;


}
