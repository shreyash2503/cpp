#include <iostream>

using namespace std;
//The steps the person can take to climb the staircase can only be of 1,2 and 3;
int  noOfWays(int n)
{

    if(n==0 || n==1)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    return noOfWays(n-1)+noOfWays(n-2)+noOfWays(n-3);

}

int main()
{
    int n;
    cout<<"Enter the no of stairs::";
    cin>>n;
    cout<<noOfWays(n);
}
