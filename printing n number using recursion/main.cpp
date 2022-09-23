#include <bits/stdc++.h>
using namespace std;
void  print(int n,int count){
    if(n==0){
        return;
    }
    cout<<count++<<" ";
    
    print(n-1,count);

}

int main(){
    int n;
    int count=1;
    cin>>n;
    print(n,count);
}