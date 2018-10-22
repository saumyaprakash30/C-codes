#include<stdio.h>
int main(){
        char a[100];
        char b[100];
        printf("Enter string:\n");
        scanf("%s",&a);
        printf("Enter sub-string:\n");
        scanf("%s",&b);
        //counting no. of letters 
        int c;          //for b[]
        printf("%s%n\n",b,&c); 
        //printf("c(b)=%d\n",c);     
        
        int d;          //for a[]
        printf("%s%n\n",a,&d);
        //printf("d(a)=%d\n",d);
        
        int i,j,k,count;
        for(j=0;j<(d-c+1);j++){
                count=0;
                if (b[0]==a[j]){
              //  printf("j=%d\n",j);
                        for (i=0,k=j;i<c;i++,k++){
                           //     printf("i=%d  j=%d  k=%d \n",i,j,k);
                                if (b[i]==a[k]) {
                             //           printf("inside if --  i=%d  j=%d  k=%d \n",i,j,k);
                                        count++;
                                        if (count==c){printf("yess, %s is sub-string of %s\n",b,a);return 0;}
                                        
                                }
                        
                        }
                 
                }
        }
printf("noo, %s is NOT a substring of %s\n",b,a);
}
