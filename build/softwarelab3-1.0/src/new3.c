#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int count=0,base[4000000][4];

int compare(int arr[4])
{
    int i;

    for(i=0; i<count; i++)
    {
        if(base[i][0]==arr[0]&&base[i][1]==arr[1]&&base[i][2]==arr[2]&&base[i][3]==arr[3])
            return 1;
    }

    for(i=0; i<4; i++)
        base[count][i]=arr[i];
    count++;
    return 0;

}

void sets(int a[],int K)
{
    if(a[0]+a[1]+a[2]*a[3]<=K)
    {
        //printf("%d,%d,%d,%d\n",a[0],a[1],a[2],a[3]);
        //printf("%d,%d,%d,%d\n",a[0],a[1],a[3],a[2]);
        //printf("%d,%d,%d,%d\n",a[1],a[0],a[2],a[3]);
        //printf("%d,%d,%d,%d\n",a[1],a[0],a[3],a[2]);
    }
    if(a[0]+a[2]+a[1]*a[3]<=K)
    {
        //printf("%d,%d,%d,%d\n",a[0],a[2],a[1],a[3]);
        //printf("%d,%d,%d,%d\n",a[0],a[2],a[3],a[1]);
        //printf("%d,%d,%d,%d\n",a[2],a[0],a[1],a[3]);
        //printf("%d,%d,%d,%d\n",a[2],a[0],a[3],a[1]);
    }
    if(a[0]+a[3]+a[1]*a[2]<=K)
    {
        //printf("%d,%d,%d,%d\n",a[0],a[3],a[1],a[2]);
        //printf("%d,%d,%d,%d\n",a[3],a[0],a[2],a[1]);
        //printf("%d,%d,%d,%d\n",a[3],a[0],a[1],a[2]);
        //printf("%d,%d,%d,%d\n",a[0],a[3],a[2],a[1]);
    }
    if(a[1]+a[2]+a[0]*a[3]<=K)
    {
        //printf("%d,%d,%d,%d\n",a[1],a[2],a[0],a[3]);
        //printf("%d,%d,%d,%d\n",a[1],a[2],a[3],a[0]);
        //printf("%d,%d,%d,%d\n",a[2],a[1],a[0],a[3]);
        //printf("%d,%d,%d,%d\n",a[2],a[1],a[3],a[0]);
    }
    if(a[1]+a[3]+a[0]*a[2]<=K)
    {
        //printf("%d,%d,%d,%d\n",a[3],a[1],a[2],a[0]);
        //printf("%d,%d,%d,%d\n",a[3],a[1],a[2],a[0]);
        //printf("%d,%d,%d,%d\n",a[1],a[3],a[0],a[2]);
        //printf("%d,%d,%d,%d\n",a[1],a[3],a[0],a[2]);
    }
    if(a[2]+a[3]+a[0]*a[1]<=K)
    {
        //printf("%d,%d,%d,%d\n",a[2],a[3],a[0],a[1]);
        //printf("%d,%d,%d,%d\n",a[2],a[3],a[1],a[0]);
        //printf("%d,%d,%d,%d\n",a[3],a[2],a[1],a[0]);
        //printf("%d,%d,%d,%d\n",a[3],a[2],a[0],a[1]);
    }

}

#define number 50

void create()
{
    int b[4],action;
    int *a;
    a = (int*)malloc(number*sizeof(int));
    int i,j,k,l,K;
    char c;
    for(i=0; i<number; i++)
        scanf("%d%c",&a[i],&c);
    //srand (time(NULL));
    //for(i=0;i<number;i++)
//	{
//		a[i]= (int)pow(-1,rand()%2)*(rand() % number + 1);
//	}
//	for(i=0;i<number;i++)
//			fprintf(f,"%d\n,",a[i]);
    scanf("%d",&K);
    for(i=0; i<number; i++)
    {
        b[0]=a[i];
        for(j=i+1; j<number; j++)
        {
            b[1]=a[j];
            for(k=j+1; k<number; k++)
            {
                b[2]=a[k];
                for(l=k+1; l<number; l++)
                {
                    b[3]=a[l];
                    //printf("%d %d %d %d\n",b[0],b[1],b[2],b[3]);
                    action = compare(b);
                    if(action==0)
                        sets(b,K);
                }
            }
        }
    }

}

int main(void)
{
    int i,j;
    create();
    //printf("stored");
    //for(i=0;i<count;i++)
    //{
    //	for(j=0;j<4;j++)
    //		printf("%d,",base[i][j]);
    //	printf("\n");
    //}
    return 0;
}
