#include<stdio.h>
#include<stdlib.h>

void bsort();
void isort();
void ssort();
int wavg();
int array();
                
int k[10][3];int t=0,p;

int a[100];
int main()
{
	int n[10];
		for(p=0;p<10;p++)
	{
		scanf("%d",&n[p]);
		
		if(p==0) printf("no. of i/o👺😎\tbsort\tisort\tssort\n");
	        array(n[p]);
	        
	      
		bsort(a,n[p]);
		isort(a,n[p]);
		ssort(a,n[p]);
		
	
	}
	
	/*for(int i=0;i<10;i++)
	{
	        for (int j=0;j<3;j++)
	        {
	                printf("%d ",k[i][j]);
	        }
	printf("\n");
	}
	*/
	
	wavg();

}


void bsort(int b[],int n)
{       
        int d[n];
        for(int i=0;i<n;i++)
                d[i]=b[i];
      
      
	int i,j,temp,comp=0;
	
	
	
	/*for(i=0;i<n;i++)
	printf("%d ",d[i]);
	*/
	
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{	comp++;
			if(d[j]>d[j+1])
			{
				temp=d[j];
				d[j]=d[j+1];
				d[j+1]=temp;
			}
		
		}
	}
	
	
	
	//printf("\n");	
	/*for(i=0;i<n;i++)

	printf("%d ",d[i]);
	*/
	printf("%d \t\t%d",n,comp);
	
	k[p][t]=comp;//printf("%d..%d",p,t);
	t++;
	return;
	
}

void isort(int d[],int a)
{
        int b[a];
        for(int i=0;i<a;i++)
                b[i]=d[i];        
        
        
        
	int i,j,temp,comp=0;
	
	
	
	/*for(i=0;i<a;i++)
	printf("%d ",b[i]);
	*/
	
	for(i=1;i<a;i++)
	{
		for(j=i;j>0;j--)
		{	comp++;
			if(b[j]<b[j-1])
			{
				temp=b[j];
				b[j]=b[j-1];
				b[j-1]=temp;
			}
			else break;
		
		}
	}
	
	
	
	//      printf("\n");	
	/*for(i=0;i<a;i++)

	printf("%d ",b[i]);
	*/
	printf("\t%d",comp);
	
		k[p][t]=comp;//printf("%d..%d",p,t);
	        t++;
	
}

void ssort(int d[],int size)
{       
        int b[size];
        for(int i=0;i<size;i++)
                b[i]=d[i]; 
                
                
                
        /*for(int i=0;i<size;i++)
	printf("%d ",b[i]);
	*/
	
        int temp,comp=0;
        for(int i=0;i<size;i++)
        {
                int max=b[0],tmax=0;
                for(int j=1;j<size-i;j++)
                {
                        comp++;
                        if (max<b[j])
                        {
                                max=b[j];
                                tmax=j;                
                        }
                        
                }
                
                temp=b[tmax];
                b[tmax]=b[size-i-1];
                b[size-i-1]=temp; 
                
                              
        }
       //printf("\n");	
	/*for(int i=0;i<size;i++)

	printf("%d ",b[i]);
	*/
	printf("\t%d ",comp);
	
		k[p][t]=comp;//printf("%d...%d",p,t);
	        t=0;
        printf("\n");
}
 int array(int n)
 {
        for(int i=0;i<n;i++)
        {
                a[i]=rand() % 100+1;
        }
      
        	
 }

int wavg()
{       float x=0;float j=10;
        printf("\n\n");
        for(int i=0;i<10;i++)
        {
                x=x+k[i][0]*j;
                j=j+10;
        }
        
        printf("w(b)= %f\n",x/550);
        
        x=0;j=10;
        for(int i=0;i<10;i++)
        {
                x=x+k[i][1]*j;
                j=j+10;
        }
        
        printf("w(i)= %f\n",x/550);

       x=0;j=10;
        for(int i=0;i<10;i++)
        {
                //printf("value of k initial :%d:\n",k[i][2]);
                x=x+k[i][2]*j;
                j=j+10;//printf("value of x :%f:\n",x);
        }
        
        printf("w(s)= %f\n",x/550);













}




























