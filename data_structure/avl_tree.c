/*
insertion
search


*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;//aadhar
    int tno;
    int height;
    struct node *lcptr;
    struct node *rcptr;
}*rptr=NULL;
int d=0;
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

struct node* insert(struct node *ptr,int d,int tno)
{
    if(ptr==NULL)
    {
      ptr=malloc(sizeof(struct node));
      ptr->data=d;
      ptr->tno=tno;
    ptr->height=0;
    ptr->lcptr=NULL;
    ptr->rcptr=NULL;
    }
    else
    {
            if(d<ptr->data)
            {  
              
              ptr->lcptr=insert(ptr->lcptr,d,tno); 
              if((findheight(ptr->lcptr)-findheight(ptr->rcptr)==2) || (findheight(ptr->lcptr)-findheight(ptr->rcptr)==2))
              {
              	if(d<ptr->lcptr->data)
              	   ptr=rotateright(ptr);
              	else
              	   ptr=leftright(ptr);
              }
            }
            else
             {
               
                ptr->rcptr=insert(ptr->rcptr,d,tno);
             	if((findheight(ptr->lcptr)-findheight(ptr->rcptr)==2) || (findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2))
              {
              	if(d>ptr->rcptr->data)
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
	  printf("%d \t %d \t%d\t%d\n",ptr->data,ptr->tno,ptr->height,findheight(ptr->lcptr)-findheight(ptr->rcptr));
	  print(ptr->rcptr);
	}
}

void search(struct node *ptr,int k)
{
    if(ptr==NULL) return;

    
    if(ptr->data==k)
    {
        printf("%d present\nIts tno. is %d\n",ptr->data,ptr->tno);
         d=1;
        return;
    }
    
    
    else if(k<ptr->data)    
        search(ptr->lcptr,k);
    else     
        search(ptr->rcptr,k);
        
    
    

}

void main()
{
 int z=0;

    while(z!=7)
	{
		printf("1.ins 2.search 3.print 7.EXIT       \n");
		scanf("%d",&z);
		if(z==1)
		{
			int p,t;
			printf("aadhar no. and teletno no.\n");
			scanf("%d%d",&p,&t);
			rptr=insert(rptr,p,t);
		}
		else if(z==2)
		{
		    d=0;
		    int k;
		    printf("enter aadhar no:");
		    scanf("%d",&k);
		    search(rptr,k);
			if(d==0) printf("NOT present\n");
			
		}
		else if (z==3)
		{
		    printf("ano.\ttno.\theight\tBF\n");
			print(rptr);
			printf("\n root= %d\n",rptr->data );
		}
	}
 }
 
 
 
 
 
 
 
 
 
