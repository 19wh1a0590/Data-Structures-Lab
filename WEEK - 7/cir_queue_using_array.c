#include<stdio.h>
#include<stdlib.h>
#define maxsize 6
int f=-1,r=-1,cq[maxsize];
int isfull()
{
	if(f == (r+1)%maxsize)
		return 1;
	else
		return 0;
}
int isempty()
{
	if(f == -1)
		return 1;
	else
		return 0;
}
void enqueue(int x)
{

	if(f == -1)
		f=0;
	r = ((r + 1) % maxsize);
	cq[r] = x;
}
int dequeue()
{
	int x;
	x = cq[f];
	if(f == r)
		f = r = -1;
	else
	{
		f = ((f + 1) % maxsize);
	}
	return x;
}
void display()
{
	int i;
	if(f == -1)
		printf("cq is empty\n");
	else
	{
		while(i != r)
		{
			printf("%d\t",cq[i]);
			i = (i+1) % maxsize;
		}
		printf("%d",cq[i]);

	}
}
int main()
{
	int ch,x;
	while(1)
	{
	 	printf("\n1-enqueue\n2-dequeue\n3-dispaly\n4-exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(isfull())
				printf(" circular queue overflowflow\n");
				else
				{
					printf("Enter the data to insert\n");
					scanf("%d",&x);
					enqueue(x);
				}
				break;
			case 2: if(isempty())
					printf("cq is empty\n");
				else
				{
					printf("Deleted element is %d\n",dequeue());
				}
				break;
			case 3: display();
				break;
			case 4: exit(0);
				break;
		}
	}
}
