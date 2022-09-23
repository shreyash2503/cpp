#include <iostream>

using namespace std;
void insertionSort(int arr[],int n)
{

    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;

    }
}
void BubbleSort(int arr[],int n)
{
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void SelectionSort(int arr[],int n)
{
    for(int i=0;i<=n-2;i++)
        {
            int smallest = i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[smallest]>arr[j])
                {
                    smallest = j;
                }

            }
            swap(arr[i],arr[smallest]);
        }

}

int main(void)
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //insertionSort(arr,n);
    //BubbleSort(arr,n);
    SelectionSort(arr,n);
    for(int i=0;i<n;i++)
    {

        cout<<arr[i]<<" ";
    }
}



