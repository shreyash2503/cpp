#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int> > table){
	cout<<"  STATE/INPUT  ";
	char a='a';
	for(int i=0;i<table[0].size();i++){
		cout<<"|  "<<a++<<"  ";
	}
	cout<<endl;
	for(int i=0;i<table.size();i++){
		cout<<"       "<<i<<"      ";
		for(int j=0;j<table[i].size();j++){
			cout<<" |  ";
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int temp;
	vector<vector<int> > dfa;
	int states,alpha,final;
	cout<<"Enter number of states in DFA : ";
	cin>>states;
	cout<<"Enter number of elements in alphabet : ";
	cin>>alpha;
	cout<<"Enter number of final states : ";
	cin>>final;
	vector<int> final_states(final);
	cout<<"Enter final state(s) : ";
	for(int i=0;i<final;i++){
		cin>>final_states[i];
	}
	for(int i=0;i<states;i++){
		cout<<"For state "<<i<<" :"<<endl;
		char a='a';
		vector<int> v(alpha,-1);
		for(int j=0;j<alpha;j++){
			cout<<"Enter output state for input "<<a<<" : ";
			cin>>temp;
			if(temp != -1)
			{
				v[j] = temp;
			}
			else
			{
				v[j] = -1; 
			}
			a++;
		}
		dfa.push_back(v);
	}
	char ch='n';
	cout<<endl<<"   GIVEN DFA :"<<endl;
	print(dfa);
	do{
		string s;
		cout<<"Enter the string : ";
		cin>>s;
		int curr=0,out;
		for(int i=0;i<s.length();i++){
			int t = s[i] - 'a';
			// if(t >= dfa[curr].size()-1)
			// {
			// 	cout<<"String not accepted by DFA "<<endl;
			// 	break;
			// }
			out=dfa[curr][s[i]-'a'];
			curr=out;
		
		}
		if(find(final_states.begin(),final_states.end(),out)!=final_states.end()){
			cout<<"String is accepted by the DFA at "<<out<<" state."<<endl;
		}else{
			cout<<"String is not accepted by the DFA."<<endl;
		}
		cout<<"Enter 'y' to continue : ";
		cin>>ch;
	}while(ch =='y');

	cout<<"String is not accepted by the DFA"<<endl;

	return 0;
}
