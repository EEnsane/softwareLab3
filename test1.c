#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void sets(int a[],int K)
{
		int i,j,k,t,prod,temp[2];
		for(i=0;i<3;i++)
		{
			for(j=i+1;j<4;j++)
			{
				prod=1;
				t=0;
				for(k=0;k<4;k++)
				{
					if(k!=i&&k!=j)
					{
						prod=prod*a[k];
						temp[t]=k;
						t++;
					}
				}
				if(a[i]+a[j]+prod<= K)
				{
					//printf("%d,%d,%d,%d\n",a[i],a[j],a[temp[0]],a[temp[1]]);
					//printf("%d,%d,%d,%d\n",a[i],a[j],a[temp[1]],a[temp[0]]);
					//printf("%d,%d,%d,%d\n",a[j],a[i],a[temp[0]],a[temp[1]]);
					//printf("%d,%d,%d,%d\n",a[j],a[i],a[temp[1]],a[temp[0]]);
				}
			}
		}
}
#define number 100

void create()
{
	int b[4];
	int *a;
	a = (int*)malloc(number*sizeof(int));
	int i,j,k,l,K;
	//char c;
	//for(i=0;i<number;i++)
	//	scanf("%d%c",&a[i],&c);
	srand ( time(NULL) );
	for(i=0;i<number;i++)
	{
		a[i]= (int)pow(-1,rand()%2)*(rand() % number + 1);
	}
//	for(i=0;i<number;i++)
//			fprintf(f,"%d\n,",a[i]);
	scanf("%d",&K);
	for(i=0;i<number;i++)
	{
		b[0]=a[i];
		for(j=i+1;j<number;j++)
		{
			b[1]=a[j];
			for(k=j+1;k<number;k++)
			{
				b[2]=a[k];
				for(l=k+1;l<number;l++)
				{
					b[3]=a[l];
					//printf("%d %d %d %d\n",b[0],b[1],b[2],b[3]);
					sets(b,K);
				}
			}
		}
	}

}

int main(void)
{
	create();
	return 0;
}
