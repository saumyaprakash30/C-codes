#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree 
{
	struct tree *lptr;
	int sno;
	int item;
	char name[100];
	char aname[100];
	struct tree *rptr;

};
char a[100];
void print();
void insert();
void lins();
void rins();
void rdel();
struct tree * leastnode();
int search();
int delete();
int k,j,count;
struct tree *root=NULL;
struct tree *temp=NULL;
struct tree *curr=NULL;
int main()
{
	struct tree l; 
	int z=0;
	while(z!=6)
	{	
		printf("1.add 2.del 3.search 6.EXIT\n");
		scanf("%d",&z);
		if(z==1)
		{
			temp=root;
			insert(&l);
		}
		else if(z==2)
		{
			k=0;
			j=0;
			count=0;
			scanf("%s",a);
			delete(root);
		}
		else if(z==3)
		{
			
			k=0;
			scanf("%s",a);
			printf("status code :%d\n",search(root));
			//if(k==0) printf("%s not Found\n");
		}
		else if(z==4)
		{
			//printf("sno.\tBook name\tAutho\n");
			//temp=root;
			print(root);
		}
		
	
	}

}


void insert(struct tree *l)
{
	struct tree *thptr=malloc(sizeof(struct tree));
	//printf("enter ref. no.:");
	//scanf("%d",&thptr->sno);
	printf("enter Book name and author:");
	scanf("%s",thptr->name  );
	//printf("enter Author name:");
	//scanf("%s",thptr->aname);
	curr=thptr;	
	curr->lptr=NULL;
	curr->rptr=NULL;
	
	if(root==NULL)
	{
		root=thptr;
		root->lptr=NULL;
		root->rptr=NULL;
	}
	else if((strcmp(curr->name,temp->name))<0)
	{
		lins();
	
	}
	else if((strcmp(curr->name,temp->name))>0)
	{
		rins();
	}
	
	
}
void lins()
{
	if((strcmp(curr->name,temp->name))<0)
	{
		if(temp->lptr==NULL)
		{
			temp->lptr=curr;
			
			return;
		}
		else 
		{	
			temp=temp->lptr;
			lins();
			return;
		}
	
	}
	else if((strcmp(curr->name,temp->name))>0)
	{
		rins();
	}
}
void rins()
{
	if((strcmp(curr->name,temp->name))>0)
	{
		if(temp->rptr==NULL)
		{
			temp->rptr=curr;
			return;
		}
		else 
		{	
			temp=temp->rptr;
			rins();
			return;
		}
	
	}
	else if((strcmp(curr->name,temp->name))<0)
	{
		lins();
	}
}

void print(struct tree *ptr)
{

	if(ptr==NULL)
		return;
	print(ptr->lptr);
	//printf("%d\t",ptr->sno);
	printf("%s\n",ptr->name);
	//printf("%s\n",ptr->aname);

	print(ptr->rptr);






	/*
	if(temp->lptr!=NULL)
	{
		temp=temp->lptr;
		print();
	}
	else printf("%s",temp->name);
	if(temp->rptr!=NULL)
	{
		temp=temp->rptr;
		print();
	}
	else 
	{
	if(temp->lptr!=NULL) 
		{
			printf("%s",temp->name);	
		}
	
	}
	
	if(temp->lptr==NULL || temp->rptr++NULL)
	{
		printf("%s",temp->name);
		return;
	}
	
	*/
	
}	
int search(struct tree *ptr)
{		

		
		if(ptr==NULL) return k;
		if((strcmp(a,ptr->name))==0)
		{
			printf("%s is present!\n",ptr->name);
			k=1;
			return k ;	 		
		}
		
		search(ptr->lptr);
		search(ptr->rptr);
		
		return k;
		
		//pr    intf("%s is not present\n");
}




int delete(struct tree *ptr)
{
		//printf(".3..\n");

		if(ptr==NULL) return ;
		else count++;
		if((strcmp(a,ptr->name))==0)
		{	
			
			if(count==1)
			{
				rdel(root);
				return;
			}
			else if(ptr->lptr==NULL && ptr->rptr==NULL)
			{
				k=11;
			//	printf(".4..\n");
				return k;

			}
			else if(ptr->lptr!=NULL && ptr->rptr!=NULL)
			{

			    k=12;
    		}
			else if(ptr->lptr!=NULL && ptr->rptr==NULL)
			{
			    k=13;
			}
			else if(ptr->lptr==NULL && ptr->rptr!=NULL)
			{
			    k=14;
			}
			
			return ;	 		
		}
		    j=12;
		  //  printf("l\n");
		delete(ptr->lptr);
		    if(k==11 && j==12)
		    {
			    ptr->lptr=NULL;
		 //   printf(".1_!..\n");
		    k=0;
		    }
		    else if(k==12)
		    {
		    //    printf(".1_2..\n");
		        ptr->lptr->rptr->lptr=ptr->lptr->lptr;
		        ptr->lptr=ptr->lptr->rptr;
		        k=0;
		    
		    }
		    else if(k==13)
		    {
		        ptr->lptr=ptr->lptr->lptr;
		        k=0;
		    }
		    else if(k==14)
		    {
		        ptr->lptr=ptr->lptr->rptr;
		        k=0;
		    }
		    j=13;
		//    printf("r\n");
		delete(ptr->rptr);
		
		    if (k==11 && j==13)
		    {
			    ptr->rptr=NULL;
		 //   printf(".2_1..\n");
		    k=0;
		    }
		    else if(k==12)
		    {
		     //   printf(".2_2..\n");
		        ptr->rptr->rptr->lptr=ptr->rptr->lptr;
		        ptr->rptr=ptr->rptr->rptr;
		        k=0;
		    
		    }
		    else if(k==13)
		    {
		        ptr->rptr=ptr->rptr->lptr;
		        k=0;
		    }
		    else if(k==14)
		    {
		        ptr->rptr=ptr->rptr->rptr;
		        k=0;
		    }

		return ;
}

void rdel(struct tree * ptr)
{
	//struct tree *rptr=ptr;
//	printf("iside rdel\n");
	
	if(ptr->lptr==NULL && ptr->rptr==NULL)
	{
		root=NULL;
	}
	
	else if(ptr->lptr==NULL && ptr->rptr!=NULL)
	{
		root=ptr->rptr;
	}

	else if(ptr->lptr!=NULL && ptr->rptr==NULL)
	{
		root=ptr->lptr;
	}
	else
	{
		
		struct tree *jptr=leastnode(ptr->rptr);
		jptr->lptr=ptr->lptr;
		root=ptr->rptr;
		
		
	}
}

struct tree* leastnode(struct tree *ptr)
{
	//printf("isideln\n");
	struct tree *current=ptr;
	while(current->lptr!=NULL)
	{
		current=current->lptr;
	}
	return current;
}





















