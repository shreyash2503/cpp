#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    cin>>n;         
    int ans=fib(n);
    cout<<ans;
    cout<<"cpp is the best language out there";
}
