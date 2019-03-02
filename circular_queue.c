#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int i=-1,j=0,l=0,m=-1,p=-1;

int * space(int);
void push(int *,int);
void pop(int *,int);
void display(int *,int);
int next(int,int);

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
			display(x,b);
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
	p=(int *)calloc(b,sizeof(int));
	return p;
}

void push(int *x,int b)
{
	int n, p;
	p = next(i,b);
	// TODO check for overflow 
	if(p==m)
		printf("overflow");
	else
	{
		printf("\nEnter a num : ");
		scanf("%d", &n);
		x[p]=n;
		i = p;
		if (m == -1)
			m++;
		printf("num successfully push.");
    }
}

void pop(int *x,int b)
{	
	int a;
	a = next(m,b);
	// TODO check for underflow 
	if(m==-1)
		printf("underflow");
	else
	{
		printf("Deleted element :-- %d",x[m]);
		m=a;
		if(p+1==m)
		{
			i=-1;
			p=-1;
			m=-1;
		} 
	}
}

void display(int *x, int b)
{
	int k;
	k = next(m,b);
	// TODO check for underflow 
	if(m==-1)
		return ;
	
	printf("Elements of queue :-- ");
	k=m;
	
	do 
	{
		printf("%d",x[k]);
		printf("   ");
		k=next(k,b);
	} while(k!=next(i,b));

}

int next(int c,int s)
{
	return (c+1)%s;
}
