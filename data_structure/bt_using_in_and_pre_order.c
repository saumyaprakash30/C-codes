/*
given in and pre order traversal
constructing binary tree (not binary search tree)
and printing post order

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct node sn;
struct node
{
	int data;
	sn* lptr;
	sn* rptr;

};
sn* rootbst=NULL;
int n;
int pre=0;
sn* newroot(int val)
{
	sn* ptr=malloc(sizeof(sn));
	ptr->data=val;
	ptr->lptr=NULL;
	ptr->rptr=NULL;
	return ptr;
}
int search(int a[],int val)
{

	for(int i=0;i<=n;i++)
		if(a[i]==val)
			return i;
}
sn* buildtree(int ino[],int preo[],int instart,int inend)
{	


	if(instart>inend)
		return NULL;
	
	sn* root=newroot(preo[pre++]);

	if(instart==inend)
	{
		return root;
	}

	int in=search(ino,preo[pre-1]);
	root->lptr=buildtree(ino,preo,instart,in-1);
	root->rptr=buildtree(ino,preo,in+1,inend);
}
void print(sn* ptr)
{
	

	if(ptr==NULL)
		return;
	print(ptr->lptr);
	print(ptr->rptr);
	printf("%d ",ptr->data);

}
int main()
{

	printf("Enter no. of nodes:");
	scanf("%d",&n);
	int ino[n],preo[n];
	printf("enter ino\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ino[i]);
	}
	printf("enter preo");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&preo[i]);
	}
	
	rootbst=buildtree(ino,preo,0,n-1);
	printf("postorder:");
	print(rootbst);
	printf("\n");
	




	return 0;
}

