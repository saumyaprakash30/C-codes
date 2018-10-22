#include<stdio.h>
#include<string.h>

int main()
{
        int i,j;
        char a[100];
printf("Enter word to check pallindrome\n");     
scanf("%s",&a);
//b tells no. of characters in string a
        int b;
        b=strlen(a);
   
               
//printf("b=%d\n",b);
int k=0;
for(i=0,j=b-1;i<=j;i++,j--){
        if (a[i]==a[j]){k++;}
        else {break;}
}
//printf("k=%d\n",k);
if (b%2==0){
        if (k==b/2)printf("%s is Palindrome\n",a);
       else printf("%s is not a Palindrome\n",a);
}
if (b%2!=0){
        if (k==b/2+1) printf("%s is Palindrome\n",a);
       else printf("%s is not a Palindrome\n",a);
}








}
