#include <stdio.h>
#include <math.h>

int maxNumberPackets(int Tt, int Tp)
{
	return(1+2*(int)(Tp/Tt));
}

int NoOfBitsInSequence(int n)
{
	int result = (int)(log(n)/log(2));
	return result;
}

int windowSize(int n, int max)
{
	int size = pow(2,n);
	if(size < max)
	{
		return size;
	}
	else
	{
		return max;
	}
}

void firstFrame(int *windowSize, int *p, int Tp, int Tt , int *r)
{
	for(int i=0;i<(*windowSize);i++)
	{
		printf("Sender::Sending frame %d\n", i);
		printf("Receiver:: Receive frame %d at %d\n", i, (Tp+Tt+i));
		p[i+1] = 2*Tp + Tt + i;
		(*r)++;
	}
}

int FramesafterFirst(int *windowSize, int *p ,int Tp, int Tt, int *count,int size,int startingIndex, int endingIndex, int maxPackets)
{
	int j = *count ;
	int s = *count;
	printf("Hello");
		for(int i=startingIndex;i<=endingIndex;i++)
		{
			printf("Sender::Received Acknowledgement for frame %d at %d \n",i , p[i]);
			if(j < maxPackets)
			{
				printf("Sender::Sending frame %d\n", j);
				p[i] = p[j - *windowSize] + 2*Tp;
				j++;
				(*count)++;
			}
		}

	return s;
}

int main()
{
	int Tt, Tp;
	int a[100];
	int count = 1;
	printf("Enter the Transmission Time::");
	scanf("%d",&Tt);
	printf("Enter the Propogation Time::");
	scanf("%d",&Tp);
	int maxPackets = maxNumberPackets(Tt, Tp);
	int bits = NoOfBitsInSequence(maxPackets);
	int windowsize = windowSize(bits, maxPackets);
	printf("%d %d %d",maxPackets, bits, windowsize);
	firstFrame(&windowsize, a, Tp, Tt, &count );
	int s = FramesafterFirst(&windowsize, a, Tp, Tt, &count, (windowsize-count), 0, windowsize, maxPackets );
	for(int i=0;i<count-65 ;i++)
	{
		printf("Received Acknowledgement at::");
		printf("%d", a[i]);
		printf("\n");
	}

		
	

	
}