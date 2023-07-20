#include <bits/stdc++.h>
using namespace std;

void HashMap(int a[][2], int size, int row)
{
	int data;
	for(int i=0;i<size;i++)
	{
		cin>>data;
		int index = data%11;
		int flag1 = 0;
		if(a[index][0] == -1 && flag1 == 0)
		{
			a[index][0] = data;
			flag1 = 1;
		}
		if(a[index][1] == -1 && flag1 == 0)
		{
			a[index][1] = data;
			flag1 = 1;
		}
		if(a[index][0] != -1 && a[index][1] != -1)
		{
			
			int temp = index;
			index = (index+1)%11;
			int flag = 0;
			
			while(index != temp)
			{
				int flag3 = 0;
				if(a[index][0] == -1 && flag3 == 0)
				{
					a[index][0] = data;
					flag = 1;
					flag3 = 1;
					break;
				}
				else if(a[index][1] == -1 && flag3 == 0)
				{
					a[index][1] = data;
					flag = 1;
					flag3 = 1;
					break;
				}
				index = (index+1)%11;
			}
			if(flag == 0)
			{
				cout<<"The hashMap is already full"<<endl;
			}
		}
	}
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int a[11][2];
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<2;j++)
		{
			a[i][j] = -1;
		}
	}
	int size;
	cout<<"Enter the size of the input::";
	cin>>size;
	HashMap(a,size,11);

}