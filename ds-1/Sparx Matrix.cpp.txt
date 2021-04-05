#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void accept(int m,int n,int a[10][10],int *ptr)
{


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\n %d X %d:",i,j);
            scanf("%d",&a[i][j]);
             if (a[i][j] == 0)
            {
                (*ptr) = (*ptr)+1;
            }
        }
    }
    printf("\n\n");

}


void display(int m,int n,int a[10][10],int *ptr)

{

     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\t%d",a[i][j]);

        }
        printf("\n\n");

    }
    if((m*n)/2 <= (*ptr))
    {
        printf("this is a sparse matrix\n");
    }
    else{
        printf("this is not a sparse matrix\n");
    }
    printf("\n");

}

void compact(int m,int n,int a[10][10],int b[10][10],int *ptr)
{
    if((m*n)/2 <= (*ptr))
    {
        int x = 1;
        b[0][0]=m;
        b[0][1]=n;
        b[0][2]=(m*n)-(*ptr);
        printf("%d\t%d\t%d",b[0][0],b[0][1],b[0][2]);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j] != 0)
                {
                    b[x][0]=i;
                    b[x][1]=j;
                    b[x][2] = a[i][j];
                    printf("\n%d\t%d\t%d",b[x][0],b[x][1],b[x][2]);
                    x++;

                }

            }
        }

    }
    else
    {
        printf("this is not a sparse matrix");
    }

    printf("\n\n");
}

void simptranspose(int b[10][10],int *ptr,int *ptr1)
{
    int c[10][10];
    for(int i=0;i<(*ptr1);i++)
    {
        c[i][0]=b[i][0];

        b[i][0]=b[i][1];

        b[i][1]=c[i][0];



    }

    for(int i=0;i<(*ptr1);i++)
    {
        printf("\n");
        for(int j=0;j<3;j++)
        {
            printf("%d\t",b[i][j]);

        }

    }
    printf("\n\n\n");


}



int main()
{
    int m;
    int n;
    int num;
    int count = 0;
    int *ptr;
    ptr = &count;
    int no;
    int *ptr1;
    ptr1 = &no;


    int a[10][10];
    int b[10][10];

    do{

        printf("\n1.Create matrix\n2.Display matrix\n3.compacting\n4.Simple transpose\n5.exit\n");
        printf("\nEnter choice: ");
        scanf("%d",&num);
        switch(num){
        case 1:
            printf("\nEnter the number of row :");
            scanf("%d",&m);

            printf("\nEnter the number of coloum :");
            scanf("%d",&n);
            *ptr1 = (m*n) - (*ptr);
            accept(m,n,a,&count);
            break;

        case 2:
            printf("\nDisplaying\n\n");
            display(m,n,a,&count);
            printf("Number of zeros: %d\n",count);
            break;

        case 3:
            printf("\n Compact Matrix \n\n");
            compact(m,n,a,b,&count);

            break;

        case 4:
            printf("Simple transpose ");

            simptranspose(b,&count,&no);
            break;

        case 5:
            printf("FastTranspose ");
            break;
        
        case 6:
            printf("\nExiting\n");
            exit(0);


        }
    }while(1);



    return 0;
}
