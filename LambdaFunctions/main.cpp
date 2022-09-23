#include <iostream>
using namespace std;

//Lambda function are also called lambda functions
//Lambda function signature
//[capture list](pararmeters)->return type{
//  Funtion body  };
//Capture list
//Lets say you declare two variable a and b outside the lamda function but you want to use them inside the lambda function this is where 
// lambda functions come into picture
/*

int a{5};
int b{5};
auto func = [a,b]()->int{
	return a+b;
} ;
a and b are not formal paramaters but two variables outside the scope of lambda function
This is also called as capture by value i.e copies will be created of the variables passed into the capture list
even if they are changed inside the lambda function they will not be changed outside the lambda function


b
Capture list by pass by reference
int c{5 }
auto func = [&c](){
	cout<<"The value of c is::"<<c<<endl;
} 

Capture everyting outside the lambda function by value

auto func = [=](){
	In this function body now we can use everything outside the lambda function but a value will be created and copied
}


Capture everything outside the scope of the lambda function by reference
auto func = [&](){
	In this function you can use everything outside the lambda function but now copy will not be
	created and if make some changes here they will be even visible outside the lambda function
	
}


*/
int main()
{
	int a = 5;
	int b = 6;
	auto result = [](int a, int b)
	{
		return a+b;
	}(3,5);
	cout<<"The result of the lambad function is"<<result<<endl;	
	cout<<"Result::"<<[](int a, int b){ return (a+b); }(5,3)<<endl;
	auto answer = [](double a, double b)->double{return a+b;}(15.4, 0.6);
	cout<<"The answer is ::"<<answer<<endl;
	auto myAnswer = [a,b]()->int{
		return (a+b);
	};
	cout<<"The answer to the question is::"<<myAnswer();

}	
