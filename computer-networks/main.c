#include <stdio.h>
#include <string.h>

///function to perform the xor operation-----------
void xor(char input[],char key[],char remainder[],int keylength,int inputlength)
{
  char quot[100];
  char key1[50];
  char temp[100];


  for(int i=0;i<keylength;i++)
  {
    key1[i]=key[i];
  }


  for(int i=0;i<keylength;i++)
  {
    temp[i]=input[i];
  }

  for(int i=0;i<inputlength;i++)
  {
      quot[i]=temp[0];
      if(quot[i]=='0')
      {
        for(int j=0;j<keylength;j++)
        {
          key[j]='0'; ///If the value of the temp's first character is zero we make the entire key zero so that we can shift the temp variable to the left i.e 0111 becomes 111
        }
      }
      else
      {
        for(int j=0;j<keylength;j++)
        {
          key[j]=key1[j];
        }
      }
      ///perform the actual xor operation, we exploit xor operation such that if values are equal 0 will be stored else 1; But this loop continues only upto keylenght-1 we assign the last character to rem in strcpy function after the loop
      for(int j=keylength-1;j>0;j--)
      {
        if(temp[j]==key[j])
        {
          remainder[j-1]='0';
        }
        else
        {
          remainder[j-1]='1';
        }
      }
      remainder[keylength-1] = input[keylength+i];
      strcpy(temp,remainder);
  }
}
//Function to receive the encoded string and then check if it is valid-----------
void Receiver(char input[], char key[], int keylength, int inputlength)
{
  char rem[100];
  printf("\n\nReceiver function was called");
  xor(input,key,rem,keylength,inputlength);
  int flag=0;
  for(int i=0;i<keylength-1;i++)
  {
    if(rem[i]!='0')
    {
      flag=1;
      break;
    }
  }
  if(flag==0)
  {
    printf("\n");
    printf("\n");
    printf("--> --------------------Data successfully sent and accepted---------------------");

  }
}
void errorFunction(char input[],char key[],int keylength,int inputlength)
{
  char r[100];
  int flag =1;
  printf("\n\n Error function was called::\n");
  if(input[inputlength+keylength-1]=='0')
  {
    input[inputlength+keylength-1]=='1';
  }
  else
  {
    input[inputlength+keylength-1]=='0';
  }
  printf("The data in which error is introduced is::");
  for(int i=0;i<keylength+inputlength;i++)
  {
    printf("%c",input[i]);

  }
  printf("\n");
  xor(input,key,r,keylength,inputlength);
  for(int i=0;i<keylength;i++)
  {
    if(r[i]=='0')
    {
     flag=0;
    }
    else{
      printf("\n\n---------------------------Data not accepted----------------------------------");
      flag=1;
      break;
    }
  }
  if(flag==0)
  {
    printf("Data accepted");
  }
}


int main()
{
  char input[100];
  char key[50];
  char  remainder[50];
  int  inputlength;
  int j=0;
  int keylength;

  ///Taking input from the user/////////////////
  printf("Enter the message to be sent here::");
  gets(input);
  printf("\n");
  printf("Enter the CRC key here(The length of the crc key must be small than the message to be sent and should not begin with 0)::");
  gets(key);



  /////Finding the length of the data and length of the key
  inputlength = strlen(input);
  keylength = strlen(key);

  ////Appending 0 in input equal to key-1
  for(int i=0;i<keylength-1;i++)
    input[inputlength+i]='0';



  ///Finding the remainder of the xor operation
  xor(input,key,remainder,keylength,inputlength);


  ///output the data/////////////////
  
  for(int i=inputlength;i<(inputlength+keylength);i++)
  {
    input[i]=remainder[j];
    j++;
  }
  printf("\n");
  printf("--> The encoded data is ::");
  for(int i=0;i<strlen(input);i++)
  {
    printf("%c",input[i]);
  }
  printf("\n");
  printf("\n");
  printf("--> Sending the encoded data to receiver....");
  printf("\n");
  Receiver(input, key, keylength, inputlength);
  printf("\n");
  errorFunction(input,key,keylength,inputlength);
}
