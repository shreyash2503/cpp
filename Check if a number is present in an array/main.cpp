#include <iostream>

using namespace std;
bool numberPresent(int a[],int s,int n,int key)
{
    int mid = s+n/2;
    if(a[mid]==key){
        return true;
    }
    else if(a[mid]>key){
        n=mid-1;
        if(numberPresent(a,s,n,key))
        {
            return true;
    }
    else{
        return false;
    }
    }
    else if(a[mid]<key){
        s=mid+1;
        if(numberPresent(a,s,n,key))
        {
            return true;
        }
        else{
            return false;
        }


}
}

int main()
{
    int n,s,key;
    cout<<"Enter the size of the array and the starting position from where you would like to search::";
    cin>>n>>s;
    cout<<"Enter the element you would like to search:: ";
    cin>>key;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<numberPresent(a,s,n-1,key);
}
