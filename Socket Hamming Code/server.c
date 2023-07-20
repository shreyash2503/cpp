#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

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




void main(){
  int messageLength, rbit = 0, message[100], data[100],i,j,k,count,error,copyData[100];
  int parityArray[100], Array[100];

	int serversocket,client_socket,bindstatus,a,b,sum=0;
	struct sockaddr_in serveraddress, cli_addr;
	socklen_t clilen;
	

  printf("Enter the size of the message you want to enter::");
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

 
	//socket connection
	serversocket=socket(AF_INET,SOCK_STREAM,0);
	serveraddress.sin_family=AF_INET;
	serveraddress.sin_port=htons(1234);
	serveraddress.sin_addr.s_addr= INADDR_ANY;

	bindstatus=bind(serversocket,(struct sockaddr *)&serveraddress, sizeof(serveraddress));
	if(bindstatus<0)
		printf("\nbinding failed\n");
	else
		printf("\nbinding is successful\n");

	listen(serversocket,3);
	printf("Sending data...\n");
	clilen = sizeof(cli_addr);
	client_socket=accept(serversocket,(struct sockaddr*) &cli_addr,&clilen);
	if(client_socket<0)
		printf("connection rejected\n");
	else
		printf("Connected...\n");
	printf("\n");
	
	//send data
	send(client_socket , data , (messageLength+rbit) , 0 );
	printf("\nData sent.\n");
	close(serversocket);
}

