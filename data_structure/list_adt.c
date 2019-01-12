/*
insert
delete
search
isempty
isfull



*/

#include<stdio.h>

struct list 
{
	int a[10];
	int size;
};
int insert();
void print();
void delete();
void search();

int main()
{
	struct list l;
	int i;
	l.size=0;
	int z,d=1;int r[10];
	while(z!=7)
	{
	        printf("1.Insert 2.Delete 3.Search 4.isempty 5.isfull 6.Print 7.Exit\n");
	        
	        scanf("%d",&z);
	        if (z==1)
	        {       
	                if(l.size==10)
	                {
	                        printf("ERROR ! array full  insert()\n");
	                }
	                
	                
	                else
	                {
	                printf("no. of instertions\n");
	                scanf("%d",&d);
	                if (d<1 || d>10)printf ("Error invalid entry\n");
	                
	                else
	                {
	                for(i=0;i<d;i++)
	                {
	                scanf("%d%d",&r[0],&r[1]);
	                //insert(&l,r[0],r[1]);
	                if (insert(&l,r[0],r[1])==0)
	                        {
	                                i=i-1;
	                        }
	                }
	                }
	                }
	        }
	        
	        else if(z==2)
	        {
	                if (l.size==0)
	                {
	                        printf("ERROR ! empty array  delete()\n");
	                }
	        
	                else
	                {
	                        printf("enter position\n");
	                        scanf("%d",&r[2]);
	                        delete(&l,r[2]);        
	                }
	        }
	        
	        else if(z==3)
	        {       
	                if (l.size==0 )
	                {      
	                        printf("Error empty array\n" );
	                        
	                
	                }
	                else
	                {
	                printf("enter a no.\n");
	                scanf("%d",&r[3]);
	                
	                search(&l,r[3]);
	        }
	        }
	        
	        else if(z==4)
	        {
	                //printf("%d\n",isempty(&l));
	                isempty(&l);
	        }
	        else if (z==5)
	        {
	               // printf("%d\n",isfull(&l));
	               isfull(&l);
	        }
	        
	        else if (z==6)
	        {
	                print(&l);
	        }
	        
	        else if (z==7)
	        {
	               
	        }
	        
	        else printf("error!\n");
	
	}
	
}

void print(struct list *p)
{	
	int i;
	//printf("%d\n",isempty());
	if(p->size==0) printf("Error\n");
	else
	{
	for (i=0;i<p->size;i++)
	{
		printf("%d  ",p->a[i]);
		
	}
	printf("\n");
	}
}



int insert(struct list *pl,int pos,int x)
{
	int i;
	if (pos<0 || pos>9 || pos>pl->size)
	{
	        printf("ERROR !! enter valid pos.! for pos = %d ,insert()\n", pos);
		return(0);
	}
	
	else 
	{
	        for(i=(pl->size);i>=pos;i--)
		{	
			//int q=isfull(&pl);
			//printf("...%d....\n",q);
			//if (q==0)
			pl->a[i]=pl->a[i-1]; 
		}
		
		//printf("%d is in insert\n",pl->size);
	        
		pl->a[pos]=x;
		//printf("x=%d\n",x);
	        (pl->size)++;
	        
	        
	        
	        
		;
	}
	
	//printf(" size= %d \n",pl->size);
}


void delete(struct list *pd,int pos)
{		
	int i;
	
	
	
	if (pos<0 || pos>9 || pos>=pd->size)
	{	
	        printf("ERROR ! enter valid pos  delete()\n");

	
	
	}
	else 
	        
	        {
	                printf("item deleted= %d at POS %d \n",(pd->a[pos]),pos);	
		
		for (i=pos;i<(pd->size)-1;i++)
		{
			pd->a[i]=pd->a[i+1];
		
		}
		
		(pd->size)--;
	
	                       
	        }
}


void search(struct list *p,int x)
{
	int i,k=0;
	//if(p->size==0) printf("Error\n");
	
	//else
	{
	for(i =0;i<p->size;i++)
	{
		if(p->a[i]==x)
		{
		printf("%d is at pos %d\n",p->a[i],i+1)	;
		k=1;
		}
		else if (i==p->size-1 && k!=1)
		{	
			printf("%d is not in array\n",x);
			
		}	
	
	}
	}

}

int isempty(struct list *p)
{
	if (p->size==0)
	
	{
	printf("Yes\n");
	return(1);}
	else {
	printf("No\n");
	return(0); }
}

int isfull(struct list *p)
{
	if (p->size==10)
	{ 
	printf("yes\n");
	return(1);}
	else {
	printf("No\n");
	return(0);}
}















































