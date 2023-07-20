#include <bits/stdc++.h>
using namespace std;

int fib(int n){
	if(n == 0 || n == 1){
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}


int fib1(int n){
	int a = 0;
	int b = 1;
	int c = 0;
	for(int i=n-1;i>0;i--){
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int fib2(int n , int* arr){
	if(n == 0 || n == 1){
		return n;
	}
	if(arr[n] != 0){
		return arr[n];
	}
	int output = fib2(n - 1,arr) + fib2(n - 2,arr);
	arr[n] = output;
	return output;
}



int main(){
	int n;
	cin>>n;

	int* arr = new int[n+1];
	for(int i=0;i<n+2;i++){
		arr[i] = 0;

	}
	cout<<fib1(n)<<endl;
	cout<<fib2(n, arr)<<endl;
	cout<<fib(n);
}
