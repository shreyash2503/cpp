#include <bits/stdc++.h>
// This the recursive approach and this approach is not very efficient
// int maxProfit(int size, int weight, vector<int> price, vector<int> Sackweight){
// 	if(size == 0 || weight == 0){
// 		return 0;
// 	}
// 	if(Sackweight[n - 1] > weight){
// 		return maxProfit(size - 1, weight, price, Sackweight);
// 	} else {
// 		int include = price[n - 1] + maxProfit(size - 1, weight - Sackweight[n - 1], price , Sackweight);
// 		int exclude = maxProfit(size - 1, weight, price, Sackweight); 
// 	 	return max(include, exclude);
// 	}

// }

// The dynamic Programming approach
int maxProfit(std::vector<int> &price, std::vector<int> &sackWeight, int weight){
	  int m = price.size();
	  int n = weight;
	  int dp[m + 1][n + 1];
	  for(int i=0;i<=m;i++){
	  	for(int j=0;j<=n;j++){
	  		if(i == 0 || j == 0){
	  			dp[i][j] = 0;
	  		} else if(sackWeight[n - 1] > j){
	  			dp[i][j] = dp[i - 1][j];
	  		} else {
	  			int include = price[i - 1] + dp[i - 1][j - sackWeight[i - 1]];
	  			int exclude = dp[i - 1][j];
	  			dp[i][j] = std::max(include, exclude);
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
	std::vector<int> price =  {60, 100, 120};
	std::vector<int> sackWeight =  {10, 20, 30};
	int weight = 50;
	std::cout<<maxProfit(price, sackWeight, weight);


}