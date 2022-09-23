#include <bits/stdc++.h>

using namespace std;
void storeOccurences(int a[],int n,int key,vector <int>& v)
{
    if(n==-1)
    {
        return;
    }
    storeOccurences(a,n-1,key,v);
    if(a[n]==key){
        v.push_back(n);
    }
}
int storeOccurencesUsingarray(int a[],int n,int key,int i,int out[],int j)
{
    if(i==n)
    {
        return 0;
    }
    if(a[i]==key)
    {
        out[j]=i;
        return 1+storeOccurencesUsingarray(a,n,key,i+1,out,j+1);
    }
    return 0+storeOccurencesUsingarray(a,n,key,i+1,out,j);

}


int main()
{

        int n;
        vector <int> v;
        int out[10];
        cin>>n;
        int a[n];
        int key;
        cout<<"Enter the key whose position you want to store::";
        cin>>key;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        storeOccurences(a,n,key, v);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        int count = storeOccurencesUsingarray(a,n,key,0,out,0);
        for(int i=0;i<count;i++)
        {
            cout<<out[i]<<" ";
        }
}
