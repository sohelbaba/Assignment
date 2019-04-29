#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head=NULL;

void insert(int data)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head == NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->prev=head;
    }
    else
    {
        temp=head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
        newnode->prev=temp;
    }
}

void Delete()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("LINK LIST EMPTY\n");
    }
    else
    {
        temp=head;
        while(temp->next->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
}

void write_into_file()
{
    //printf("write_into_file()\n");
	FILE *out_file;

    out_file = fopen("Link_list.txt","w");

    if(out_file == NULL)
    {
        printf("error\n");
    }

    struct node *temp;
    temp=head;
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

    in_file = fopen("Link_list.txt","r");

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

void Display()
{
    struct node *temp;
    temp=head;
    while(temp != NULL)
    {
        printf("[ %d ]  -> ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    read_from_file();
    int ch,data,ser;
    printf("\t DOUBLY LINK LIST\n");
    printf("\t 1.INSERT\n");
    printf("\t 2.DELETE\n");
    printf("\t 3.DISPLAY\n");
    printf("\t 4.EXIT\n");
    do{
        printf("\n\tEnter Your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    printf("\tEnter Data : ");
                    scanf("%d",&data);
                    insert(data);
                    write_into_file();
                    break;
                }
            case 2:
                {
                    Delete();
                    write_into_file();
                    break;
                }
            case 3:
                printf("\n\t");
                Display();
                break;
            case 4:
                return;
            default:
                printf("\tEnter Proper Choice : \n");
        }

    }while(ch != 4);
}

