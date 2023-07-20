#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>

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
	//receiver code for hamming
    int data[10];
    int rbit;
    
	int clientsocket,a,b,sum;
	int  serverresponse[256], datareceived[11];
	struct sockaddr_in serveraddress;
	int messageLength = 11;

	//get data from reciever
	clientsocket=socket(AF_INET,SOCK_STREAM,0);// create socket
	//SOCKET function returns the integer
	if(clientsocket<0)
		printf("socket not created\n");
	else 
		printf("socket created succesfully\n");
	serveraddress.sin_family=AF_INET;
	serveraddress.sin_port=htons(1234);
	serveraddress.sin_addr.s_addr= INADDR_ANY;
	int constatus=connect(clientsocket,(struct sockaddr *) &serveraddress, sizeof(serveraddress));
	 
	if(constatus==-1)
		printf("Connectivity not establshed\n");
	else
		printf("connection estableshed\n");
	// int messageLength=sizeof(datareceived);
	//recv(clientsocket,&datareceived,messageLength,0);
	bzero(datareceived, 100);
	int n = read(clientsocket, datareceived, 100);
	close(clientsocket);
	printf("%d\n ", messageLength);
	for(int i=0;i<11;i++)
	{
		printf("%d ",datareceived[i]);
	}


  // //Introducing error---------->>>
  // printf("_____________________________Introducing Error in the array___________________________\n");
  // printf("\n");




  // printf("<---------------Message---------------------->\n");
  // for(int i=1;i<=(messageLength+rbit);i++)
  // {
  //   printf("%d   ",data[i]);
  // }
  // printf("\n");
  // for(int i=1;i<=(messageLength+rbit);i++)
  // {
  //   printf("-   ");
  // }
  // printf("\n");
  // for(int i=(messageLength+rbit);i>=1;i--)
  // {
  //   if((int)i/2>=5)
  //   {
      
  //   printf("%d  ",i);
  //   }
  //   else
  //   {
  //     printf("%d   ",i);
  //   }
  // }




  // printf("\n");


  // //Introduce the error by taking input from the user
  // printf("<-------------------------------------------->");
  // printf("\n");
  // printf("\nEnter the bit where you want to put error::");
  // scanf("%d",&error);
  // if(data[((messageLength+rbit+1)-error)] == 0)
  // {
  //   data[((messageLength+rbit+1)-error)] = 1;
  // }
  // else
  // {
  //   data[((messageLength+rbit+1)-error)] = 0;
  // }








  // //Printing the error introduced array;
  // printf("Error introduced message--->\n");
  // for(int i=1;i<=(messageLength+rbit);i++)
  // {
  //   printf("%d",data[i]);
  // }
  // printf("\n");





  // ///For copying data into copy data;
  // for(int i=1;i<=(messageLength+rbit);i++)
  // {
  //   copyData[i] = data[i];
  // }


  // addParityBits(data,messageLength,rbit,Array);



  // //Printing the parity bits of the error data
  // printf("The parity bits for the error messages are::\n");
  // for(int i=0;i<rbit;i++)
  // {
  //   printf("%d",Array[i]);
  // }
  // printf("\n");







  // i = binaryToDecimal(Array,rbit);
  // printf("The error was introduced at position %d", i);
  // printf("\n\n");
  // //Correcting the error that was introduced in the array
  // if(copyData[messageLength+rbit+1-i]==1)
  // {
  //   copyData[messageLength+rbit+1-i] = 0;
  // }
  // else
  // {
  //   copyData[messageLength+rbit+1-i] = 1;
  // }
  // printf("\n");
  // printf("\nCorrected Data--->\n");
  // for(int i=1;i<=(messageLength+rbit);i++)
  // {
  //   printf("%d",copyData[i]);
  // }
	
	 
	
}
