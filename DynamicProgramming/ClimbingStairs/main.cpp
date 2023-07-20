#include <bits/stdc++.h>
using namespace std;

int minSteps(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	if(n == 2){
		return 2;
	}
	return minSteps(n - 1) + minSteps(n - 2);
}


// ! Memorization approach
int minSteps(int n, int* arr){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}

	if(n == 2){
		return 2;
	}
	if(arr[n] != -1){
		return arr[n];
	}
	int ans = minSteps(n - 1, arr) + minSteps(n - 2, arr);
	arr[n] = ans;
	return ans;
}

// ! The above two solutions are only for steps 1 and 2 but for k<n the solution =>
int climbStairs(int n, int k){
	int* arr = new int[n+1];
	for(int i=0;i<=n;i++){
		arr[i] = 0;
	}
	arr[0] = 1;
	arr[1] = 1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j > i){
				break;
			}
			arr[i] += arr[i - j];
		}
	}
	return arr[n];
}



int main(){
	int x;
	cout<<"Enter the number of steps::";
	cin>>x;
	int k;
	cout<<"Enter the values of k::";
	cin>>k;
	int* arr = new int[x + 1];
	for(int i=0;i<=x;i++){
		arr[i] = -1;
	}
	cout<<minSteps(x, arr)<<endl;
	cout<<climbStairs(x,k);
	cout<<[](int a,int b)->int{return (a+b);}(5,3);


}