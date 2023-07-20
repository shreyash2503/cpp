#include <bits/stdc++.h>
// ! This is the recursive solution and not very efficient

// ! -> Leet Code => Edit distance 
// ! Given two strings, convert string1 to string2 with only using minimum number of  operations insert, delete and replace

/*

  0 h o r s e
0 0
r
o
s
*/

int editDistance(std::string a, int m , std::string b, int n){
	if(m == 0){
		return n;
	}
	if (n == 0){
		return m;
	}
	if(a[m - 1] == b[n - 1]){
		return editDistance(a, m - 1, b, n - 1);
	}
	int insert = editDistance(a, m, b, n - 1);
	int del = editDistance(a, m - 1, b, n);
	int replace = editDistance(a,m - 1, b, n - 1);
	return 1 + std::min(std::min(insert, del), replace);
}
//Dynamic Programming approach

int editDistance(std::string a, std::string b){
	int m = a.size();
	int n = b.size();
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i == 0){
				dp[i][j] = j;
			} else if(j == 0){
				dp[i][j] = i;
			}else if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			} else{
				dp[i][j] = 1 + std::min(std::min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]); // ! => min(min(insert, delete), replace)
			}
		}
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			std::cout<<dp[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return dp[m][n];
}

int main(){
	std::string a;
	std::string b;
	std::cout<<"Enter the string 1::";
	std::cin>>a;
	std::cout<<"Enter the string 2::";
	std::cin>>b;
	std::cout<<"The minimum distance to convert string 1 to string 2 is ::"<<editDistance(a, b);

}