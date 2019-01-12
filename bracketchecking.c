#include<stdio.h>
int main()
{
        char b[100];int k=0;
        scanf("%s",b);
        for(int i=0;i<100;i++)
        {
        
                if (k<0)
                {
                        printf("wrong )))(((\n");
                        return 0;
                }
                else 
                {
        
                        if (b[i]==40)
                        {
                                k++;
                        }
                        else if (b[i]==41)
                        {
                                k--;
                        }
                        
                }
        }
        if (k!=0)
        {
                printf("error((()))))");
        }
        else printf("correct\n");
        
        
}
