//queue using link list with file
#include<stdio.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;
void insert(int item)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    if(head == NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void Delete()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("Queue is Empty \n");
    }
    temp=head;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("Queue is Empty \n");
    }
    printf("\t");
    while(temp != NULL)
    {
        printf("| %d | -> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void write_into_file()
{
    //printf("write_into_file()\n");
	FILE *out_file;

    out_file = fopen("number.txt","w");

    struct node *temp;
    temp=head;

    if(head==NULL)
    {
        printf("\tQueue is Empty \n");
    }

    while(temp != NULL)
    {
        fprintf(out_file,"%d\n",temp->data);
        temp=temp->next;
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
    int ch,item;
    printf("\t1. INSERT\n");
    printf("\t2. DELETE\n");
    printf("\t2. DISPLAY\n");
    printf("\t3. EXIT\n");
    do{
        printf("\tEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\tEnter Data : ");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                Delete();
                write_into_file();
                break;
            case 3:
                 display();
                 break;
            case 4:
                 break;
        }
    }while(ch!=4);
}

