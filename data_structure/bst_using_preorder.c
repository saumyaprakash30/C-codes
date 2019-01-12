/*
constructing bst given pre oreder

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct bst st;
struct bst 
{
	st* lptr;
	int data;
	st* rptr;

};
st* root =NULL;

st * insert(st* ptr,int a);
void print();
int main()
{

	int n;
	printf("Enter no. node:");
	scanf("%d",&n);
	int temp;
	printf("Enter pre-order:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		root=insert(root,temp);
	}
	
	printf("post-order:");
	print(root);

	printf("\n");





	return 0;
}

st * insert(st* ptr,int a)
{


	if(ptr==NULL)
	{
		st* thptr=malloc(sizeof(st));
		thptr->data=a;

		thptr->lptr=NULL;
		thptr->rptr=NULL;
		return thptr;
	}
	if(a<ptr->data)
		{
			ptr->lptr=insert(ptr->lptr,a);

		}
	else if (a>ptr->data)
		ptr->rptr=insert(ptr->rptr,a);
	else printf("ERROR same element\n");
	return ptr;
}
void print(st* ptr)
{
	if(ptr==NULL) return;
	print(ptr->lptr);	
	print(ptr->rptr);
	printf("%d ",ptr->data);
}

