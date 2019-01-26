/*
adding and sub. large integers

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

sn* aroot=NULL;
sn* broot=NULL;
sn* addroot=NULL;
sn* subroot=NULL;
sn* inc=NULL;
void print();
sn* insert();
void add();
void sub();
sn* convert();
int hc,kk;
void arprint();

int main()
{
	char a[100];
	char b[100];
	char ac[100];
	char bc[100];
	printf("enter 1st no.:");
	scanf("%s",a);
	printf("enter 2nd no.:");
	scanf("%s",b);
	int alen=strlen(a);
	int temp=a[0];
	int blen=strlen(b);
	
	
	if(a[0]=='0'){
		a[0]='+';
		a[1]='0';
	}
	if(b[0]=='0')
	{
		b[0]='+';
		b[1]='0';
		}
	if(alen>blen) hc=alen;
	else hc=blen;
	//printf("HC=%d\n",hc);
	int ar1[alen];
	int ar2[blen];
	//printf("inside main bfr con\n"); 
	aroot=convert(aroot,a,alen);
	broot=convert(broot,b,blen);
	strcpy(ac,a+1);
	strcpy(bc,b+1);
	//printf("%s..%s\n",ac,bc);
	
	
	int z=0;
	while(z!=7)
	{
		printf("1.print A 2. print B 3.Add 4.Sub 5.Inc A 6.Dec A 7. EXIT\n");
		scanf("%d",&z);
		if(z==1)
		{
			printf("%c",aroot->data);
			print(aroot);
			printf("\n"); 
		}
		else if(z==2)
		{
			printf("%c",broot->data);
			print(broot);
			printf("\n"); 
		}
		else if(z==3)
		{	

				if(addroot!=NULL)
				{
					addroot=NULL;
				}
			if(aroot->data==43 && broot->data==43)
			{

				printf("+");
				add(aroot,broot);
				printf("\n");
			}
			else if(aroot->data==43 && broot->data==45)
			{
				if(alen>blen)
				{
					printf("+");
					sub(aroot,broot);
					printf("\n");
				}
				else if(alen<blen)
				{
					printf("-");
					sub(broot,aroot);
					printf("\n");
				}
				else if((strcmp(ac,bc)==0))
				{
					printf("0\n");
				}

				else 
				{
					if((strcmp(ac,bc)>0))
					{
						sub(aroot,broot);
					}
					else if((strcmp(ac,bc)<0))

					{
						printf("-");
						sub(broot,aroot);
					}
				}

			}
			
			else if(aroot->data==45 && broot->data==43)
			{
							
				if(alen>blen)
				{
					printf("-");
					sub(aroot,broot);
					printf("\n");
				}
				else if(alen<blen)
				{
					printf("+");
					sub(broot,aroot);
					printf("\n");
				}
				else if((strcmp(ac,bc)==0))
				{
					printf("0\n");
				}

				else 
				{
					if((strcmp(ac,bc)>0))
					{
						printf("-");
						sub(aroot,broot);
					}
					else if((strcmp(ac,bc)<0))

					{
						printf("+");
						sub(broot,aroot);
					}
				}

			}
			else if(aroot->data==45 && broot->data==45)
			{
				printf("-");
				add(aroot,broot);
			}
			//add(aroot,broot);
		}
		else if(z==4)
		{	
				if(subroot!=NULL)
				{
					subroot=NULL;
					
				}
				else
				{
					
			if(aroot->data==43 && broot->data==43)
			{
				if(alen>blen)
				{
					printf("+");
					sub(aroot,broot);

				}
				else if(alen<blen)
				{
					printf("-");
					sub(broot,aroot);
				}
				else if(alen==blen)
				{
					
					if((strcmp(ac,bc)>0))
					{
						printf("+");
						sub(aroot,broot);
					}
					else if((strcmp(ac,bc)<0))

					{
						printf("-");
						sub(broot,aroot);
					}
					
					else if((strcmp(ac,bc)==0))
					{
						printf("0");
					}
				}
	

			}
			else if(aroot->data==43 && broot->data==45)
			{
				printf("+");
				add(aroot,broot);

			}
			else if(aroot->data==45 && broot->data==43)
			{
				printf("-");
				add(aroot,broot);

			}
			else if(aroot->data==45 && broot->data==45)
			{
						
				if(alen>blen)
				{
					printf("-");
					sub(aroot,broot);
					printf("\n");
				}
				else if(alen<blen)
				{
					printf("+");
					sub(broot,aroot);
					printf("\n");
				}
				else if((strcmp(ac,bc)==0))
				{
					printf("0\n");
				}

				else if(alen==blen)
				{
					if((strcmp(ac,bc)>0))
					{
						printf("-");
						sub(aroot,broot);
					}
					else if((strcmp(ac,bc)<0))

					{
						printf("+");
						sub(broot,aroot);
					}
				}
			}

		
		}
	
	}
	else if(z==5)
	{
		
		char a[3]="+1";
		inc=NULL;
		inc =convert(inc,a,2);
		addroot=NULL;
		if(aroot->data=='+') add(aroot,inc);
		else
		{
			printf("-");
 			sub(aroot,inc);
		}

	}
	else if(z==6)
	{
		
		char a[3]="-1";
		inc=NULL;
		inc =convert(inc,a,2);	//using same pointer to dec.
		subroot=NULL;
		if(aroot->data=='+') sub(aroot,inc);
		else
		{
			printf("-");
 			add(aroot,inc);
		}

	}
}
	return 0;
}
sn* insert(sn* head,int p)
{
	//printf("inside ins\n"); 
	sn* thptr=malloc(sizeof(struct node));
	thptr->data=p;
	if(head==NULL){

		head=thptr;

		thptr->nptr=NULL;
		}
	else
	{
		
		thptr->nptr=head;
		head=thptr;

	}
	return head;
}
sn* convert(sn* head,char a[],int n)
{
	//printf("inside con"); 
	int p;
	for(int i=1;i<n;i++)
	{
		p=a[i]-48;
		head=insert(head,p);
	}
		p=a[0];
	    head=insert(head,p);//43= + 45= -
	return head;
}

void print(sn* ptr)
{
	//printf("inside print\n"); 
	if(ptr==NULL) return;
	print(ptr->nptr);
	if(ptr->data!=45 && ptr->data!=43)printf("%d",ptr->data);
	return;
}
void arprint(sn* ptr)
{
	while(ptr!=NULL) 
	{
		printf("%d",ptr->data);
		ptr=ptr->nptr;
	}
}
void add(sn* aptr,sn* bptr)
{
	int p,a,b,c=0;
	aptr=aptr->nptr;
	bptr=bptr->nptr;
	//sn* thptr=malloc(sizeof(sn));
	int i=0;
	while(i<hc)
	{
		
	//	printf("\n..in while\n");
		if(aptr==NULL) a=0;
		else a=aptr->data;
		if(bptr==NULL) b=0;
		else b=bptr->data;
	//	printf("%d:%d\n",a,b);
		p=(c+a+b);
		if(p>9) c=1;
		else c=0;
		p=p%10;
		addroot=insert(addroot,p);
		p=0;
		if(aptr!=NULL)
		{
		//	printf("in a\n");	
			 aptr=aptr->nptr;
		}
		if(bptr!=NULL)
		{
			
	//		printf("in   b\n");
			bptr=bptr->nptr;
		}
	i++;
	}
	addroot=insert(addroot,c);
	arprint(addroot);
	printf("\n");
	
}
void sub(sn* aptr,sn* bptr)
{
	int p,a,b,c=0;
	aptr=aptr->nptr;
	bptr=bptr->nptr;
	//sn* thptr=malloc(sizeof(sn));
	int i=0;
	while(i<(hc-1))
	{
	//	printf("start\n");
		//if(aptr==NULL) a=0;
		a=aptr->data-c;
		if(bptr==NULL) b=0;
		else b=bptr->data;
		p=a-b;
	//	printf("..%d..\n",p);
		if(p<0)
		{
			c=1;
			p=10+p;
		}
		else c=0;
		subroot=insert(subroot,p);
		
		if(aptr!=NULL)
		{
	//		printf("in a\n");	
			 aptr=aptr->nptr;
		}
		if(bptr!=NULL)
		{
			
	//		printf("in b\n");
			bptr=bptr->nptr;
		}
	//	printf("end sub\n");
		i++;
	}	
//	printf("after while\n");
	//addroot=insert(addroot,c);
	arprint(subroot);
	printf("\n");
	
}













