#include <bits/stdc++.h>

using namespace std;
float geometricSum(int n)
{
    if(n==0)
    {
        return 1;
    }
    return pow(0.5,n)+geometricSum(n-1);
}

int main()
{
    int n;
    cin>>n;
    cout<<geometricSum(n);


}
