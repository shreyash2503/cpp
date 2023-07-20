#include <bits/stdc++.h>
using namespace std;
/*
! If strin1 is apple and string2 is ample
! Then the longest common subsequence is aple and its length is 4 and we want the function to return that
  0 A p p l e
0 0 0 0 0 0 0 -> This row indicates that there is nothing common between 0 characters of "Ample" and 1 or 2 or ..n characters of apple
A 0 1 1 1 1 1
m 0 1 1 1 1 1
p 0 1 2 2 1 1 -> d[i][j] indicates the common characters between i character of string 1 and j characters of string 2
l 0 1 2 2 3 1
e 0 1 2 2 3 4

 */

int longestCommonSubsequence(string a, string b,string &c){
	int m = a.size();
	int n = b.size();
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			} else if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				c += a[i - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

		}

	}
	cout<<"This is the 2d array generated"<<endl;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[m][n];
}

int main(){
	string a;
	string b;
	cout<<"Enter the first string ::";
	cin>>a;
	cout<<"Enter the second string ::";
	cin>>b;
	string c = "";
	cout<<longestCommonSubsequence(a, b, c);
	cout<<c;
}