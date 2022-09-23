#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Byte stuffing program using linked list

struct node
{
	 char data;
	struct node *next;
};

void ByteCount()
{
	int a[100];
	int i = 0 ;
	char temp;
	int flag = 0;
	int count = 1;
	printf("Enter the data by seprating frames by -1::");
 do { 
      scanf("%d%c", &a[i], &temp); 
      i++; 
  } while(temp != '\n');

  for(int j=1;j<i;j++)
  {
	if(a[j] == -1)
	{
		a[flag] = count;
		flag = j;
		count = 1;
	} 
  	count++;
  } 	
  printf("The data to be sent the receiver is::");
	for(int j=0;j<i-1;j++)
	{
		printf("%d ",a[j]);
	}
	printf("\n");

}

void ByteStuffing()
{
	struct node *head = NULL,*p = NULL;
	struct node *tail = head;
	int n;
	printf("Enter the number of bits in the data::");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		p = malloc(sizeof(struct node));
		scanf(" %c",&p->data);
		p->next = NULL;
		if(head == NULL)
		{
			head = p;
			tail = head;
		}
		else
		{
			tail->next = p;
			tail = p;
		}

	}
	struct node *temp = head;
	struct node *prev = NULL;
	while(temp->next && temp)
	{
        if(temp->data == 'E' || temp->data == 'F')
        {
            struct node* flag = malloc(sizeof(struct node));
            flag->data = 'E';
            flag->next = temp;
            prev->next = flag;
            prev = temp;
            temp = temp->next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
	}
	printf("F ");
	while(head != NULL)
	{
		printf("%c ",head->data);

		head = head->next;

	}
	printf("F \n");

}

void BitStuffing()
{
	int n;
	int i=0,j=0,k;
	int count = 1;
	int a[100],b[100];
	printf("\nEnter the length of the data you want to enter::");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	while(i<n)
	{
		if(a[i] == 1)
		{
			b[j] = a[i];
			for(k=i+1;a[i]==1 && k<n && count <5;k++)
			{
				j++;
				b[j] = a[k];
				count++;
				if(count == 5)
				{
					j++;
					b[j] = 0;
				}
				i = k;
			}
		}
		else
		{
			b[j] = a[i];
		}
		i++;
		j++;
	}
	printf("The bit stuffed data is::");
	for(int i =0;i<=j;i++)
	{
		printf("%d",b[i]);
	}
	printf("\n");

}



int main()
{
// 	int  a[100];
// 	int temp = 0;
// 	int j=1;
// 	printf("Enter the data to be sent here by seprating frames by c::");
	
// 	for(int i=1;i<=strlen(a);i++)
// 	{
// 		if(a[i]=='c')
// 		{
// 			a[temp] = j+'0';
// 			temp = i;
// 			j=1;
// 		}
// 		j++;
// 	}

// 	for(int i=0;i<strlen(a);i++)
// 	{
// 		printf("%c ",a[i]);
// 	}
//ByteStuffing();
//BitStuffing();
	int option;
	do
	{
	printf("1).ByteStuffing\n2).ByteCount\n3).BitStuffing\n4).Exit\n");
	printf("Enter the number of the framing method you want to do::");
	scanf("%d",&option);
	if(option == 1)
	{
		ByteStuffing();
	}
	else if(option == 2)
	{
		ByteCount();
	}
	else if(option == 3)
	{
		BitStuffing();
	}
	else if(option == 4)
	{
		exit(0);
		break;
	}
	} while (1);



 }