#include <iostream>

using namespace std;
void printSteps(int n,char  s,char  d,char h)
{

    if(n==0)
    {

        return;
    }
    printSteps(n-1,s,h,d);
    cout<<"Moving disk "<<n<<" "<<s<<"->"<<d<<endl;
    printSteps(n-1,h,d,s);

}

int main()
{
    int n;
    cin>>n;
    printSteps(n,'A','C','B');
}
