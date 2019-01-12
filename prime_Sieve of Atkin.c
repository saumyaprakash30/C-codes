#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int data;
	struct node *nptr;
};
typedef struct node sn;
sn *head=NULL;
void insert(int a);
void print(sn* ptr);
void delete(int a);
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		insert(i);
	}
	//print(head);
	sn* temp=head;
	sn* t1=head->nptr;
	sn* prev=head;

	while(temp!=NULL)
	{
		int k=temp->data;
		//printf("k=%d\n",k);
		while(t1!=NULL)
		{
			if(t1->data%k==0)
			{
				prev->nptr=t1->nptr;
				t1=t1->nptr;
			}
			else
			{
				t1=t1->nptr;
				prev=prev->nptr;
			}
		}


		temp=temp->nptr;
		if(temp==NULL) break;
		//printf("\n..%d..\n",temp->data);
		t1=temp->nptr;
		prev=temp;
	}





	print(head);







	return 0;
}
void insert(int a)
{
	sn* ptr=malloc(sizeof(sn));
	ptr->data=a;
	ptr->nptr=NULL;
	if (head==NULL)
	{


		head=ptr;
	
	}
	else
	{
		sn* temp=head;
		while(temp->nptr!=NULL)
		{
			//printf("..\n");
			temp=temp->nptr;
		}
		temp->nptr=ptr;
	}

	

}
void print(sn* ptr)
{
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->nptr;
	}
}

void delete(int a)
{
	sn* ptr=head;
	sn* prev=head;
	if(head==NULL) return;
	if(ptr->data==a && prev==head)
	{
		head=NULL;
	}
	while(ptr->data!=a)
	{
		prev=ptr;
		ptr=ptr->nptr;
	}
	prev->nptr=ptr->nptr;
}













