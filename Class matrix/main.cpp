#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Matrix
{
    public:
    vector <vector<int>> v;

    Matrix operator+(Matrix const& m)
    {
        Matrix m1;
        for(int i=0;i<m.v.size();i++)
        {
           vector <int> v1;
            for(int j=0;j<m.v[0].size();j++)
            {
                v1.push_back(this->v[i][j]+m.v[i][j]);
            }
            m1.v.push_back(v1);
        }
        return m1;

    }
    void print()
    {
        for(int i=0;i<v.size();i++)
        {

            for(int j=0;j<v[0].size();j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int t;
    int j,p;
    Matrix m1;
    Matrix m2;

     cin>>n;
     for (int i=0;i<n;i++)
     {

         cin>>j>>p;
         for(int k=0;k<j;k++)
         {
             vector <int> v1;
             for(int q=0;q<p;q++)
             {
                 cin>>t;
                 v1.push_back(t);
             }
             m1.v.push_back(v1);
         }
         for(int k=0;k<j;k++)
         {
             vector <int> v1;
             for(int q=0;q<p;q++)
             {
                 cin>>t;
                 v1.push_back(t);
             }
             m2.v.push_back(v1);
         }
     }
     Matrix m3 = m1+m2;
     m3.print();
    return 0;
}
