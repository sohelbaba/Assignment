//Queue with file
#include<stdio.h>
#define SIZE 100
int queue[SIZE];
int front=-1;
int rear=-1;

void insert(int item)
{
    if(rear > SIZE)
        printf("\tQueue is Overflow  : \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
            front = 0;

        rear++;
        queue[rear]=item;
        write_into_file();
    }
}
void Delete()
{
    if(front > rear)
        printf("\tQueue is Underflow : \n");
    else
    {
        printf("\tDelete : %d\n",queue[front]);
        front++;
    }
}
void Display()
{
    int i;
    if(rear == -1 || front > rear)
        printf("\tQueue is Empty \n");
    //printf("Rear : %d\n",rear);
    //printf("Front : %d\n",front);
    printf("\t");
    for(i=front;i<=rear;i++)
        printf("| %d | ",queue[i]);
    printf("\n\n");
}
void write_into_file()
{
    //printf("write_into_file()\n");
	FILE *out_file;

    out_file = fopen("number.txt","w");

    if(out_file == NULL)
    {
        printf("error\n");
    }
    int i=0;
    for(i=front;i<=rear;i++)
    {
        fprintf(out_file,"%d\n",queue[i]);
        //printf("%d",queue[i]);
    }
    fclose(out_file);
}

void read_from_file()
{
    FILE *in_file;
    int n;

    in_file = fopen("number.txt","r");

    if(in_file == NULL)
    {
        printf("error\n");
    }
    while(fscanf(in_file,"%d",&n) != EOF)
    {
       // fscanf(in_file,"%d",&n1);
       insert(n);
    }
    fclose(in_file);
}
void main()
{
    read_from_file();
    printf("\tQUEUE OPERATION USING FILE\n");
    printf("\t1.INSERT\n");
    printf("\t2.DISPLAY\n");
    printf("\t3.DELETE\n");
    printf("\t4.EXIT\n\n");
    int ch;
    do{
        printf("\tEnter Your Choice : " );
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    int d;
                    printf("\tEnter Data : ");
                    scanf("%d",&d);
                    insert(d);
                    break;
                }
            case 2:
                Display();
                break;
            case 3:
                Delete();
                write_into_file();
                break;
            case 4:
                break;
            default:
                printf("\tEnter Proper Choice :\n");
                break;
        }
    }while(ch != 4);
}
