#include <bits/stdc++.h>
using namespace std;

// ! Brute force approach to reach 1 
int minTo1(int n){
	int x = INT_MAX;
	int y = INT_MAX;
	int z = INT_MAX;
	if(n == 1){
		return 0;
	}
	if(n%3 == 0){
		x = minTo1(n/3);

	}
	if(n%2 == 0){
		y = minTo1(n/2);
	}
	if(n > 1){
		z = minTo1(n - 1);
	}
	return min(min(x,y), z) + 1;
}

// ! Bottom-Up Approach => The optimized approach
int minSteps(int n){
	int* dp = new int[n+1];
	dp[0] = 0;
	dp[1] = 0;
	for(int i=2;i<=n;i++){
		int x = dp[i-1];
		int y = INT_MAX;
		int z = INT_MAX;
		if(i%2 == 0){
			y = dp[i/2];
		}
		if(i%3 == 0){
			z = dp[i/3];
		}
		dp[i] = min(min(x,y), z) + 1;

	}
	return dp[n];
}

// ! Memorization i.e Top Down DP => Dynamic Programming
// ! One of the approaches but the answer is always one less than the original answer
int minTo1(int n, int* arr){
	if(n <= 1 ) return 0;
	int x = INT_MAX;
	int y = INT_MAX;
	int z = INT_MAX;

	x = minTo1(n - 1, arr);
	arr[n] = x;
	if(n%3==0 && arr[n/3] != -1){
		y = arr[(int)n/3];
	} 
	if(n%2 == 0 && arr[n/2] != -1){
		z = arr[(int)n/2];
	}
	return min(min(x,y), z) + 1;
}


// ! Proper Memorizaion Approach
int helper(int n, int* arr){
	if(n <= 1) return 0;
	if(arr[n] != -1){
		return arr[n];
	}
	int x = INT_MAX;
	int y = INT_MAX;
	int z = INT_MAX;
	x = helper(n - 1, arr);
	if(n%3 == 0){
		y = helper(n/3, arr);
	}
	if(n%2 == 0){
		z = helper(n/2, arr);
	}
	int ans = min(min(x,y), z) + 1;
	arr[n] = ans;
	return ans;
}

void minToOne(int n){
	int* arr = new int[n+1];
	for(int i=0;i<n+2;i++){
		arr[i] = -1;
	}
	int ans = helper(n, arr);
	cout<<ans<<endl;
}

// ! Most optimized approach to this problems

int minStepsM(int n){
	int* dp = new int[n+1];
	dp[0] = 0;
	dp[1] = 0;
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + 1;
		if(i%2 == 0){
			dp[i] = min(dp[i], dp[n/2]+1);
		}
		if(i%3 == 0){
			dp[i] = min(dp[i], dp[n/3]+1);
		}

	}
	int ans = dp[n];
	delete []dp;
	return ans;
}


int main(){
	int n;
	cin>>n;
	// int* arr = new int[n+1];
	// for(int i=0;i<n+2;i++){
	// 	arr[i] = -1;
	// }
	// cout<<minTo1(n, arr)<<endl;
	// cout<<minTo1(n)<<endl;
	// minToOne(n);
	cout<<minStepsM(n);

}