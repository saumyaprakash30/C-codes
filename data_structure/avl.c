/*
constructing avl tree
insertion,deletion,search

example used as flight reservation system

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node st;

struct node
{
    int pnr;//aadhar
    int sno;
	char name[100];
	int fare;
    int height;
    struct node *lcptr;
    struct node *rcptr;
}*rptr=NULL;
st* delete();
int d=0;
int autopnr=201800,seat=0,netfare=2500;
int findheight(struct node *ptr)
{
	int h1,h2;
	if(ptr==NULL)
	 return -1;
	else
	{
	 h1=findheight(ptr->lcptr);
	 h2=findheight(ptr->rcptr);
	 if(h1 < h2)
	  return(h2+1);
	 else
	  return(h1+1);
	}
}
void updateheight(struct node *ptr)
{
	int h1,h2;
	if(ptr->lcptr==NULL)
	{
	  h1=-1;
	}
	else
		h1=ptr->lcptr->height;
	if(ptr->rcptr==NULL)
	{
	h2=-1;
	}
	else
	h2=ptr->rcptr->height;
	if(h1<h2)
	 ptr->height=h2+1;
	else
	 ptr->height=h1+1;
}
struct node *rotateright(struct node *ptr)
{
 struct node *jptr=ptr;
 struct node *kptr=ptr->lcptr;
 jptr->lcptr=kptr->rcptr;
 kptr->rcptr=jptr;
 updateheight(jptr);
 updateheight(kptr);
 return kptr;
}
struct node *rotateleft(struct node *ptr)
{
 struct node *jptr=ptr;
 struct node *kptr=ptr->rcptr;
 jptr->rcptr=kptr->lcptr;
 kptr->lcptr=jptr;
 updateheight(jptr);
 updateheight(kptr);
 return kptr;
}
struct node *leftright(struct node *ptr)
{
 struct node *jptr=ptr;
 struct node *kptr=ptr->lcptr;
 ptr->lcptr=rotateleft(kptr);
 return(rotateright(jptr));
}
struct node *rightleft(struct node *ptr)
{
 struct node *jptr=ptr;
 struct node *kptr=ptr->rcptr;
 ptr->rcptr=rotateright(kptr);
 return(rotateleft(jptr));
}

struct node* insert(struct node *ptr,int d,char a[])
{
    if(ptr==NULL)
    {
      ptr=malloc(sizeof(struct node));
      ptr->pnr=d;
      strcpy(ptr->name,a);
	  ptr->fare=netfare;
	  ptr->sno=seat;
    ptr->height=0;
    ptr->lcptr=NULL;
    ptr->rcptr=NULL;
    }
    else
    {
            if(d<ptr->pnr)
            {  
              
              ptr->lcptr=insert(ptr->lcptr,d,a); 
              if((findheight(ptr->lcptr)-findheight(ptr->rcptr)==2) || (findheight(ptr->lcptr)-findheight(ptr->rcptr)==2))
              {
              	if(d<ptr->lcptr->pnr)
              	   ptr=rotateright(ptr);
              	else
              	   ptr=leftright(ptr);
              }
            }
            else
             {
               
                ptr->rcptr=insert(ptr->rcptr,d,a);
             	if((findheight(ptr->lcptr)-findheight(ptr->rcptr)==2) || (findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2))
              {
              	if(d>ptr->rcptr->pnr)
              	   ptr=rotateleft(ptr);
              	else
              	   ptr=rightleft(ptr);
              }
             }
    }
     updateheight(ptr);
     return ptr;
}
void print(struct node *ptr)
{
	if(ptr!=NULL)
	{
	  print(ptr->lcptr);
			  printf("PNR:%d\tName:%s\tSeatno:%d\tfare:%d\tHeight:%d\tBF:%d\n",ptr->pnr,ptr->name,ptr->sno,ptr->fare,ptr->height,findheight(ptr->lcptr)-findheight(ptr->rcptr));

	printf("----------------------------------------------------------------------------------------------\n");
int autopnr=0,seat=1,netfare=2500;
	  print(ptr->rcptr);
	}
}

void search(struct node *ptr,int k)
{
    if(ptr==NULL) return;

    
    if(ptr->pnr==k)
    {
        printf("Name:%s\nSeat no.:%d\nFare:%d\n",ptr->name,ptr->sno,ptr->fare);

		d=1;
        return;
    }
    
    
    else if(k<ptr->pnr)    
        search(ptr->lcptr,k);
    else     
        search(ptr->rcptr,k);
        
    
    

}
int least(st*ptr)
{
	printf("least\n");
	st* temp=ptr;
	st* prev;
	while(temp!=NULL)
	{
		prev=temp;
		temp=temp->lcptr;
	}

	printf("after while\n");
	int k=prev->pnr;
	rptr=delete(rptr,k);

	return k;
}
st* delete(st* ptr,int a)
{
	
	if(ptr==NULL) return 0;
	if(a==ptr->pnr)
	{
		if(ptr->lcptr==NULL && ptr->rcptr==NULL)
		{
			return NULL;	
		}
		else if(ptr->lcptr!=NULL && ptr->rcptr==NULL)
		{
			return ptr->lcptr;
		}
		
		else if(ptr->lcptr==NULL && ptr->rcptr!=NULL)
		{
		return ptr->rcptr;
		}
		else 
		{
			printf("in_else\n");
			printf("pnr 1=%d\n",ptr->pnr);
			ptr->pnr=least(ptr->rcptr);
			printf("pnr =%d\n",ptr->pnr);
			printf("before return\n");
			return ptr;
		}
		
	}
	else
	{
		
		if(a<ptr->pnr)
		{
		
			//printf("l\n");
			ptr->lcptr=delete(ptr->lcptr,a);
			if((findheight(ptr->lcptr)-findheight(ptr->rcptr)==2) || (findheight(ptr->lcptr)-findheight(ptr->rcptr)==2))
              {
              	if(a<ptr->pnr)
              	   ptr=rotateleft(ptr);
              	else
              	   ptr=leftright(ptr);
		
				}
		}
		else
		{
			//printf("r\n");
		
			ptr->rcptr=delete(ptr->rcptr,a);
			if((findheight(ptr->lcptr)-findheight(ptr->rcptr)==2) || (findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2))
              {
              	if(a>ptr->pnr)
              	   ptr=rotateright(ptr);
              	else
              	   ptr=rightleft(ptr);
              }
	
		}
		
	}
	updateheight(ptr);
	return ptr;
	
}
void main()
{
 int z=0;

    while(z!=7)
	{
		printf("1.Book a ticket 2.search 3.Cancel ticket 4.print 7.EXIT\n");
		scanf("%d",&z);
		if(z==1)
		{
			int p,t;
			char a[100];
			//printf("Enter PNR:\n");
			//scanf("%d",&p);
			p=++autopnr;
			seat++;
			printf("Enter Name:");
			scanf("%s",a);
			rptr=insert(rptr,p,a);
		}
		else if(z==2)
		{
		    d=0;
		    int k;
		    printf("enter PNR  no:");
		    scanf("%d",&k);
		    search(rptr,k);
			if(d==0) printf("NOT present\n");
			
		}
		else if(z==3)
		{
			int cancel;
			printf("Enter PNR to cancel Ticket:");
			scanf("%d",&cancel);
			rptr=delete(rptr,cancel);
		}
		else if (z==4)
		{
		  //  printf("PNR\t\tName\t\tSeat no.\t\tFare\t\theight\t\tBF\n");
			print(rptr);
			printf("\n root= %d\n",rptr->pnr );
		}
	}
 }
 
 
 
 
 
 
 
 
 
