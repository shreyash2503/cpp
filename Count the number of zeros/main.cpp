#include <iostream>
using namespace std;
int ans=0;
int numberOfZeroes(int n)
{
    if(n==0){
        return ans;
    }
    if(n%10==0)
    {
        ans++;
    }
    numberOfZeroes(n/10);
}

int main()
{
    int n;
    cout<<"Enter the number you have to count zeros in::";
    cin>>n;
    cout<<numberOfZeroes(n);

}
