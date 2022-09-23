#include <iostream>

using namespace std;

int main()
{
    int **arry;
    arry = new int*[row];
    for(int i=0;i<row;i++)
    {
        arry[i]=new int[col];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arry[i][j];
        }
    }
}
