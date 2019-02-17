#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int i=-1,j=0;

int * space(int);
void push(int *,int);
void pop(int *,int);
void display(int *);

void main()
{
	int a,b,*x;
	printf("What size of queues you want : ");
	scanf("%d",&b);
	x = space(b);
	start: printf("\nMenu :--");
    printf("\n1. push\n2. pop\n3. display\n4. exit\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			push(x,b);
			break;
		case 2:
			pop(x,b);
			break;
		case 3:
			display(x);
			break;
		case 4:
			return ;
			break;
		default :
			printf("\nwrong input.");
	}
	
	if(a!=4)
		goto start;
}

int * space(int b)
{
	int *p;
	printf("aa");
	p=(int *)calloc(b,sizeof(int));
	return p;
}

void push(int *x,int b)
{
	int n;
	printf("\nEnter a num : ");
	scanf("%d",&n);
	if(i==b-1)
		printf("queue oveflow.");
	else
	{
		i++;
		x[i]=n;
		printf("num successfully push.");
	}		
}

void pop(int *x,int b)
{
	
	if(i==-1)
		printf("queue underflow.");
	else
	{
		printf("Deleted element :-- %d",x[j]);	
		j++;
	}		
}

void display(int *x)
{
	int k;
	printf("Elements of queue :-- ");
	for(k=j; k<=i; k++)
	{
		printf("%d",x[k]);
		printf("   ");
	}
}

