#include<stdio.h>
#include<stdlib.h>
#include <math.h> 

void insertionSort(int array[], int n);
void printArray(int array[], int n);
void merge(int array[], int l, int m, int r);
void mergeSort(int array[], int l, int r);
int binaryScr(int array[], int low, int high, int m);





int main()
{

   int n,choice,i,a,h,m,x,y,k,l,r,low,high;
   char ch[20];
   printf("Enter no. of elements u want to sort : ");
   scanf("%d",&n);
   int array[n];
   for(i=0;i<n;i++)
   {
        printf("Enter %d Element : ",i+1);
        scanf("%d",&array[i]);
   }
    printf("Please select any option Given Below for Sorting : \n");

 int arr_size = sizeof(array)/sizeof(array[0]);
 
while(1)
   {

    printf("\n1. Insertion Sort\n2. Merge Sort\n3. Binary Search\n4. Display Array\n5. Exit the Program.\n");
    printf("\nEnter your Choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        insertionSort(array,n);
        break;
    case 2:
        
        mergeSort(array, 0, arr_size - 1);
        printf("\nSorted array is \n");
        printArray(array, arr_size);
        break;
    case 3:
        
        printf("Enter the number to be searched\n");
        scanf("%d", &m);
        int result = binaryScr(array, 0, arr_size- 1, m);

        (result == -1) ? printf("The element is not present in array\n"):
        printf("The element is present at index %d\n",result);

        break;
    case 4:
        printArray(array,n);
        break;
   case 5:
        return 0;
    default:
        printf("\nPlease Select only 1-5 option ----\n");
    }
}
return 0;

}







//---------------Function to print the elements of an array-----------------


void printArray(int array[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", array[i]); 
    
}



//-------------------------Insertion Sort Function----------------------------


void insertionSort(int array[], int n) 
{ 
    int i, element, j; 
    for (i = 1; i < n; i++) { element = array[i]; j = i - 1; while (j >= 0 && array[j] > element) { 
            array[j + 1] = array[j]; 
            j = j - 1; 
        } 
        array[j + 1] = element; 
    } 
    printf("After Insertion sort Elements are : \n");
    printArray(array,n);

} 
   

//----------------------------Merge Sort Function----------------------------------


void mergeSort(int array[], int l, int r)
{ 

if (l < r)
{
// Finding mid element
int m = l+(r-l)/2;
// Recursively sorting both the halves
mergeSort(array, l, m);
mergeSort(array, m+1, r);
 
// Merge the array
merge(array, l, m, r);
}

 
}




void merge(int array[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
// Create temp arrays
int L[n1], R[n2];
// Copy data to temp array
for (i = 0; i < n1; i++)
L[i] = array[l + i];
for (j = 0; j < n2; j++)
R[j] = array[m + 1+ j];
// Merge the temp arrays
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
array[k] = L[i];
i++;
}
else
{
array[k] = R[j];
j++;
}
k++;
}

while (i < n1)
{
array[k] = L[i];
i++;
k++;
}

while (j < n2)
{
array[k] = R[j];
j++;
k++;
}

}


//---------------------------Binary Search Function------------------------ 


int binaryScr(int a[], int low, int high, int m)
{
mergeSort(a,low,high);        
if (high >= low) {
int mid = low + (high - low) / 2;
if (a[mid] == m)
return mid;
if(a[mid] > m)
return binaryScr(a, low, mid - 1, m);
return binaryScr(a, mid + 1, high, m);
}
return -1;

}



