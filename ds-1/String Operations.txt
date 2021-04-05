#include <stdio.h>
#include<stdlib.h>
void reverse(char str1[100],char str2[100]);
int compare(char str1[100],char str2[100]);
void subs(char str1[100],char str2[100]);
void accept(char str1[100]);
void display(char str1[100]);
int length(char str1[100]);
int main()
{
    int ch;
    char str1[100],str2[100];
    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("1.Find reverse of a string\n2.Compare two strings\n3.Check if a string is a palindrome\n4.Check if an entered string is a substring\n5.exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {   
                    printf("\nEnter a string to find its reverse:\n");
                    accept(str1);
                    reverse(str1,str2);
                    printf("\nReversed string: ");
                    display(str2);
                    break;
                }
            case 2:
                {   
                    printf("\nEnter first string:\n");
                    accept(str1);
                    printf("\nEnter second string:\n");
                    accept(str2);
                    int i=compare(str1,str2);
                    if(i>0)
                        printf("\n%s is greater than %s\n",str1,str2);
                    else if(i==0)
                        printf("\n%s is equal to %s\n",str1,str2);
                    else
                        printf("\n%s is less than %s\n",str1,str2);
                    break;
                }
            case 3:
                {
                    printf("\nEnter a string:\n");
                    accept(str1);
                    reverse(str1,str2);
                    if(compare(str1,str2)==0)
                        printf("%s is a palindrome",str1);
                    else
                        printf("%s is not a palindrome",str1);
                    break;
                }
            case 4:
                {
                    printf("Enter a string");
                    accept(str1);
                    printf("Enter another string to check substring");
                    accept(str2);
                    subs(str1,str2);
                }
            case 5:
                {
                    exit(0);
                }
        }
    }
    return 0;
}

void reverse(char str1[100],char str2[100])
{
    int t=0;
    int len=length(str1);
    int e=len-1;
    for (t = 0; t < len; t++) 
   {
      str2[t] = str1[e];
      e--;
   }
    str2[t]='\0';
}

int compare(char str1[100],char str2[100])
{
    int s=0;
    while((str1[s]==str2[s])&&(str1[s]!='\0'))
    {
        s++;
    }
    if(str1[s]>str2[s])
        return 1;
    else if(str1[s]==str2[s])
        return 0;
    else
        return -1;
}
void subs(char str1[100],char str2[100])
{
    int c1=0,c2=0,flag,cj=0,rj=0;
    c1=length(str1);
    c2=length(str2);
    for(int i=0;i<c1;i++)
    {
        for(int j=i,rj=0;j<i+c2;j++,rj++)
        {
            if(str1[j]==str2[rj])
                flag=1;
            else
                {flag=0;
                break;}
                
        }
        if(flag==1)
        {
            cj++;
        }
    }
    if(cj!=0)
    {
        printf("Substring found %d times",cj);
    }
    else
    printf("Substring not found");
}
void accept(char str1[100])
{
    scanf("%s",str1);
}
void display(char str1[100])
{
    printf("%s\n",str1);
}
int length(char str1[100])
{
    int p=0;
    while(str1[p]!=0)
    {
        p++;
    }
    return p;
}

