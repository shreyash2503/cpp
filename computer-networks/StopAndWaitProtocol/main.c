#include <stdio.h>
#include <stdlib.h>

//Program to stimulate stop and wait protocol using c
int receiver(int j)
{
	printf("Acknowledgement received for frame %d\n\n",j);
	int acknowl = 0;
	return acknowl;
}
int sender(int j)
{
	
	int random = (rand()%5+0);	
	if((random > 2 && random < 5))
	{
		for(int i=1;i<=2;i++)
		{
			printf("Waiting for the frame %d for %d seconds\n",j,i);
			int acknowl = receiver(j);
			break;
			return acknowl;

		}
	}
	else if(random == 2)
	{
		for(int i=1;i<3;i++)
		{
			printf("Waiting for the frame  %d for %d seconds\n",j,i);
		}
		printf("Session TimeOut\nWaiting for re-transmission\n");
		int acknowl = 1;
		return acknowl;
	}

	else if (random < 2)
	{

		int acknowl = receiver(j);
		return acknowl;

	}
}



int main()
{

	int timer = 0;
	int noOfFrames = 0;
	printf("Enter the number of frames you want to send::");
	scanf("%d",&noOfFrames);
		for(int i=1;i<noOfFrames+1;i++)
		{
			printf("Sending frame %d\n",i);;
			int acknowl = sender(i);
			if(acknowl != 0)
			{
				if(i == 1)
				{
					i = 0;
					printf("Waiting for re-transmission\n");
				}
				else
				{
					i = i-1;
					printf("Waiting for re-transmission\n");
				}
			}
		}

}