/*
set theory
union
intersection
complement
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct node sn;

struct node
{
	int data;
	sn* nptr;
};
struct node *ahead=NULL;
sn* bhead=NULL;
sn* uhead=NULL;
sn* ihead=NULL;
sn* insert(sn* head,int p)
{
	
	sn* thptr=malloc(sizeof(struct node));
	thptr->data=p;
	if(ahead==NULL){

		head=thptr;

		thptr->nptr=NULL;
		}
	else
	{
		
		thptr->nptr=head;
		head=thptr;


		/*
		sn* thptr=malloc(sizeof(sn));
		sn* temp=ahead;
		while(temp->nptr!=NULL)
		{
			temp=temp->nptr;
		}
		temp->nptr=thptr;
		thptr->data=p;
		thptr->nptr=NULL;
		*/

	}
	return head;
}


void print(sn* ptr)
{
	sn* temp=ptr;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->nptr;
	}
	printf("\n");
}
int t=0;
void uni()
{
	sn* curr=ahead;
	sn* temp=bhead;

	while(curr!=NULL)
	{
		t=0;
		while(temp!=NULL)
		{
			if(curr->data==temp->data)
			{
				t=1;
				break;
			}
			else
			{
				temp=temp->nptr;
			}


		}
		if(t==0)
		{
			uhead=insert(uhead,curr->data);			
		}

		curr=curr->nptr;
		temp=bhead;
	}
	sn* ptr=bhead;
	while(ptr!=NULL)
	{
		uhead=insert(uhead,ptr->data);
		ptr=ptr->nptr;
	}
	
	
	
}
void isec()
{
	sn* aptr=ahead;
	sn* bptr=bhead;
	while(aptr!=NULL)
	{

		while(bptr!=NULL)
		{
			if(aptr->data==bptr->data)
			{
		
				ihead=insert(ihead,aptr->data);
				break;
			}
			else
			{
				
				
				bptr=bptr->nptr;
			}
		}
		bptr=bhead;
		aptr=aptr->nptr;
	}
}
void com()
{
	t=0;
	uhead=NULL;
	uni();
	sn* uptr=uhead;
	sn* aptr=ahead;
	while(uptr!=NULL)
	{
				
		t=0;
		while(aptr!=NULL)
		{
	
			if(aptr->data==uptr->data)
			{
				
				t=0;
				break;
			}
			else 
			{
				
				t=1;
			}
			
			aptr=aptr->nptr;

		}
		if(t==1) printf("%d ",uptr->data);
		aptr=ahead;
		uptr=uptr->nptr;
	}
}

int main()
{
	int z=0,p;
	while(z!=8)
	{
	printf("1.insert in A 2. Insert in B 3.union 4.insertion 5.compliment 6.Print A 6.Print B 6.EXIT\n");

	scanf("%d",&z);
	if(z==1)
	{
		scanf("%d",&p);
		ahead=insert(ahead,p);	
	}
	else if(z==2)
	{
		scanf("%d",&p);
		bhead=insert(bhead,p);
	}
	else if(z==3)
	{
		uhead=NULL;
		uni();
		print(uhead);
	}
	else if(z==4)
	{
		ihead=NULL;
		isec();
		//if(ihead==NULL) printf("NULL\n");
	//	else
			print(ihead);
	}
	else if(z==5)
	{
		
		com();
	}
	else if(z==6)
	{	
		if(ahead==NULL) printf("NULL\n");
		else print(ahead);
	}
	else if(z==7)
	{	
		if(bhead==NULL) printf("NULL\n");
		else print(bhead);
	}

	}






	return 0;
}

