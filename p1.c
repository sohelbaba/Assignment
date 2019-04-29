#include<stdio.h>
#include<string.h>
int number[2];
void swap(int *x1,int *x2)
{
    int temp;
    temp=*x1;
    *x1=*x2;
    *x2=temp;
}
void palingdrom(int x1)
{
    int n1=x1;
    int d=0;
    printf("value of N1 : %d\n",x1);
    while(x1 != 0)
    {
        d = d * 10;
        d = d + x1%10;
        x1= x1/10;
    }
    if(n1 == d)
    {
        printf(" %d is Palingdrom \n",n1);
    }
    else
    {
        printf(" %d is not palingdrom \n",n1);
    }
}
void read_from_file()
{
    FILE *in_file;
    int n;

    in_file = fopen("swap_number.txt","r");
    if(in_file == NULL)
    {
        printf("error\n");
    }

    int i=0;
    while(fscanf(in_file,"%d",&n) != EOF)
    {
       number[i]=n;
       i++;
    }
    fclose(in_file);
}

int main()
{
    int n1,n2;
    read_from_file();
    n1=number[0];
    n2=number[1];
    //printf("%d\t %d",n1,n2);
    void (*p)(int,int)=&swap;
    (*p)(&n1,&n2);
    printf("\n");
    printf("Check This Two numbers are palingdrom or not :\n");
    printf("Number  1 : \n");
    palingdrom(n1);
    printf("\n");
    printf("Number  2 : \n");
    palingdrom(n2);
}


