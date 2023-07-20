#include <stdio.h>
//Hamming code is a error correction algorithm--------------------->>>>
//Hamming code is used to correct only bit which is wrong in the data
//Cannot be used to detect multiple error
int mul(int rbit)
{
  int r = 1;
  for(int i=0;i<rbit;i++)  //2^r >= messageLength + r +1 --->Formula to calulate r 
  {
    r = 2*r;
  }
  return r;
}

/// This function will add parity bits to our data
void addParityBits(int data[], int messageLength, int rbit, int Array[])
{
  //We are making use of even parity here i.e if the count is 4 then make rbit as 0 as evenparity already exits if count is 3 make the rbit as 1 as now 3+1 = 4 and hence even parity
  int count = 0;
  int p = 0;
  int q = 1;
  int s = 1;
  int r = 0;
  for(int i=(messageLength+rbit);i>=1;i--)// the value of i will start for the end of the messageLength+rbit
  {                                       // lets say our messageLength is 7 and hence rbits == 4  and hence total length will be 11    
    if(data[i] == 7 || s == mul(r))                     // we start from 11 i.e for this loop its like 1 and 7 will be stored here from earlier
    {                                    //1 2   3  4  5 6   7 8   9 10 11
      count = 0;                  ///     11 10  9  8  7  6  5 4   3  2  1
      
      for(int j=i;j>=1;)           //for i=2, j=2 then we will continue inner for loop for 2 rounds as q=2 and parity bit is 2 so we have to do for 10-9 6-5 i.e 2-3 6-7
      {
        for(int k=0;k<q;k++)
        {
          if(data[j] == 1)
          {
            count++;
          }
          printf("j is %d\n",j);
          j--;     // we start from 10 so for first j=9 and for second j=8 but our next bits are 6 and 5 so we subtract q
        }
        j = j-q;
      }
      q = q*2;
      printf("Count for position %d is %d\n",i,count);
      if(count%2 == 0)
      {
        data[i] = 0;
        Array[p] = 0;
        p++;
      }
      else
      {
        data[i] = 1;
        Array[p] = 1;
        p++;
      }
      r++;

    }
    s++;
  }
  
 
}

int binaryToDecimal(int a[],int rbit)
{
  int r =1;
  int x = 0;
  for(int i=0;i<rbit;i++)
  {
    x = r*a[i]+x;
    r = r*2;
  }
  return x;
}


int main()
{
  //Declaring the required arrays
  int messageLength, rbit = 0, message[100], data[100],i,j,k,count,error,copyData[100];
  int parityArray[100], Array[100];
  printf("Enter the size of the message you want ot enter::");
  scanf("%d",&messageLength);
  printf("\n");


  //Calculating the value of rbit--
  while(1)
  {
    if(mul(rbit)>=(messageLength+rbit+1))
    {
      break;
    }
    rbit++;
  }





  //Taking the message as input----------------------------
  printf("Enter the message below::\n");
  for(int i=1;i<=messageLength;i++)
  {
    scanf("%d",&message[i]);
  }
  printf("\n");








  //Adding the redundant bits to our code so now the lenght of the message becomes rbit+messageLength
  //Name of the for loop ---->> 1'
  j = 1;
  for(int i=(messageLength+rbit);i>=1;i--) // here we are making our data array to store values like 11 10 9 8.. for rbit = 4 
                                           // this will help us to identify the rbit and put 7 in the rbit in the data place
                                           // Placing 7 in the data array will help us to perform parity operations in the parity function
    {
      data[j] = i;
      j++;
    }





  //Printing the data here------------
  printf("Number assigned Data-->\n");
  for(int i=1;i<=(messageLength+rbit);i++)
    {
      printf("%d ",data[i]);
    }
  printf("\n");


                                                           
// Next shreyash you  are putting 7 in rbits place and putting message bits in the data bits place but we start to put message bits from the end and hence i = messageLength
// i.e 1st bit of the message will go in the last place of the data bit-----> Told by Ranjana Maam--->refer the algortim showm by maam;
  k = 0;
  i = messageLength;
  for(j=(messageLength+rbit);j>=1;j--)
  {
    if(data[j] == mul(k)) //what we did in the for loop 1' will help us here i.e we check if data[j] stores a parity value[1,2,4,8....] ? data[j] = 7 : data = message[i] // Code by shreyash tekade
    {
      data[j] = 7;
      k++;
    }
    else
    {
      data[j] = message[i];
      i--;
    }

  }

//-------------------------
  printf("\n");
//-------------------------
//Printing the data after putting 7's in place of rbits in the data array
  printf("New data with 7 in place where there are parity bits and data in place of data bits--->>\n");
  for(int i=1;i<=(messageLength+rbit);i++)
    {
      printf("%d ",data[i]); 
    }
  printf("\n");
  printf("<-------------------------------Add parity bits function is begin called----------------------------------->\n");
  //Calculating the value of rbits
  /*
   r1 = 1+3+5+7+9+......
   r2 = 2+3+6+7+10+11+.....
   r4 = 4+5+6+7+12+13+14+15.......... // here addition indicates that we are counting the no of 1's
   r8 = 8+9+.............
   */
  //Calling the parity function----->>>
  addParityBits(data,messageLength,rbit,parityArray);
  printf("Data after adding the parity bits--->>");
  for(int i=1;i<=(messageLength+rbit);i++)
  {
    printf("%d",data[i]);
  }
  printf("\n");

  //Introducing error---------->>>
  printf("_____________________________Introducing Error in the array___________________________\n");
  printf("\n");






  printf("<---------------Message---------------------->\n");
  for(int i=1;i<=(messageLength+rbit);i++)
  {
    printf("%d   ",data[i]);
  }
  printf("\n");
  for(int i=1;i<=(messageLength+rbit);i++)
  {
    printf("-   ");
  }
  printf("\n");
  for(int i=(messageLength+rbit);i>=1;i--)
  {
    if((int)i/2>=5)
    {
      
    printf("%d  ",i);
    }
    else
    {
      printf("%d   ",i);
    }
  }




  printf("\n");


  //Introduce the error by taking input from the user
  printf("<-------------------------------------------->");
  printf("\n");
  printf("\nEnter the bit where you want to put error::");
  scanf("%d",&error);
  if(data[((messageLength+rbit+1)-error)] == 0)
  {
    data[((messageLength+rbit+1)-error)] = 1;
  }
  else
  {
    data[((messageLength+rbit+1)-error)] = 0;
  }








  //Printing the error introduced array;
  printf("Error introduced message--->\n");
  for(int i=1;i<=(messageLength+rbit);i++)
  {
    printf("%d",data[i]);
  }
  printf("\n");





  ///For copying data into copy data;
  for(int i=1;i<=(messageLength+rbit);i++)
  {
    copyData[i] = data[i];
  }


  addParityBits(data,messageLength,rbit,Array);



  //Printing the parity bits of the error data
  printf("The parity bits for the error messages are::\n");
  for(int i=0;i<rbit;i++)
  {
    printf("%d",Array[i]);
  }
  printf("\n");







  i = binaryToDecimal(Array,rbit);
  printf("The error was introduced at position %d", i);
  printf("\n\n");
  //Correcting the error that was introduced in the array
  if(copyData[messageLength+rbit+1-i]==1)
  {
    copyData[messageLength+rbit+1-i] = 0;
  }
  else
  {
    copyData[messageLength+rbit+1-i] = 1;
  }
  printf("\n");
  printf("\nCorrected Data--->\n");
  for(int i=1;i<=(messageLength+rbit);i++)
  {
    printf("%d",copyData[i]);
  }
}
