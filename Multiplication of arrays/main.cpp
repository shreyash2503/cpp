#include <iostream>

using namespace std;

int main()
{
   int m,n,k;
   cout<<"Enter the no. of rows you want in the first matrix::";
   cin>>m;
   cout<<"Enter the number of columns or no. of rows you want in the first or second matrix::";
   cin>>n;
   cout<<"Enter the number of columns you want in the second matrix::";
   cin>>k;

  int m1[100][100];
  int m2[100][100];
  int mul[100][100];
  cout<<"Enter the first matrix::"<<endl;
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           cin>>m1[i][j];
       }
   }
    cout<<"Enter the second matrix::"<<endl;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<k;j++)
       {
           cin>>m2[i][j];
       }
   }

   for(int i=0;i<m;i++)
   {
       for(int j=0;j<k;j++)
       {
           for(int p=0;p<n;p++)
           {
               mul[i][j]=mul[i][j]+m1[i][p]*m2[p][j];
           }
       }
   }
    cout<<"The multiplication of the matrices is::"<<endl;
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           cout<<mul[i][j]<<" ";
       }
       cout<<endl;
   }
}


