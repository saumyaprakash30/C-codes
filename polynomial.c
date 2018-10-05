//Polynomial
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int degree;
    struct node *nptr;
};

struct node *head=NULL;
int count=0;
void new();
void add();
int val();
void print();
int main()
{
    int z=0;
   
        
    
    
    while(z!=6)
    {
        printf("1.adding term 2.value at x 3. new polynomial 4.print 6.EXIT\n");
        scanf("%d",&z);
        if(z==1)    
        {
            count++;
            add();
        }
        else if(z==2)
        {
            
            val();
        
        }
        else if(z==3)
        {
            
            new();
        
        }
        
        else if(z==4)
        {
            print();
        }
        
    
    
    
    }
    
    
    
}

void add()
{
    struct node *thptr=malloc(sizeof(struct node));
    int a,d;
    printf("enter coeff.:");
    scanf("%d",&a);
    printf("enter degree:");
    scanf("%d",&d);
    
    thptr->data=a;
    thptr->degree=d;
    int i=0;
    struct node *temp=head;
    
    if(count==1)
    {
        head=thptr;
        thptr->nptr=NULL;
        
    }
    
    else 
    {
        
        thptr->nptr=head;
        head=thptr;
        
    }
}


int val()
{
    if(count==0)
    {
        printf("no polynomial\n");
    }
    else
    {
    int x,d=1;
    printf("x=");
    scanf("%d",&x);
    
    int sum=0;
    struct node *temp=head;
    
    while(temp->nptr!=NULL)
    {
        for(int i=0;i<temp->degree;i++)
        {
            d=d*x;
        }
        sum=sum+(temp->data)*d;
        d=1;
        temp=temp->nptr;
    
    
    }
    for(int i=0;i<temp->degree;i++)
        {
            d=d*x;
        }
    sum=sum+(temp->data)*d;
    d=1;
    
    printf("at x=%d value = %d\n",x,sum);   
    
    }
    
}

void print()
{
    if(count==0)
    {
        printf("no polynomial\n");
    }
    else
    {
        struct node *temp=head;
        while(temp->nptr!=NULL)
        {
            printf("%dx^%d + ",temp->data,temp->degree);
            temp=temp->nptr;
        }
        printf("%dx^%d \n",temp->data,temp->degree);
    }
}


void new()
{
    head=NULL;
    count=0;
}





















