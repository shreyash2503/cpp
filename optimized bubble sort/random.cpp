#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    cin>>n>>q;
    int i,j;
    int input;
    vector<vector<int>>v;
    for(int i=0;i<n;i++)
    {
        while(cin>>input){
            v[i].push_back(input);
        }
    }
    for(int i=0;i<q;i++){
        cin>>i>>j;
        cout<<v[i][j]<<endl;
    }
    return 0;
}

