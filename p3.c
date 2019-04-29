#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int top=-1;
char arr[MAX_SIZE];

int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(){
    if(top == MAX_SIZE-1){
        return 1;
    }else{
        return 0;
    }
}

void push(char item){
    if(isFull())
    {
            printf("Stack is full");
    }
    else
    {
        top++;
        arr[top] = item;
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack is empty");
    }else{
        top--;
    }
}

char gettop(){
    return arr[top];
}

int ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return 1;
	else if(opening == '{' && closing == '}') return 1;
	else if(opening == '[' && closing == ']') return 1;
	return 0;
}

//read data from file
void read_from_file()
{
    FILE *in_file;
    char in_expr;

    in_file = fopen("parenthesis.txt","r");

    if(in_file == NULL)
    {
        printf("error\n");
    }
    printf("\nGiven Code Below to find Any mis Paranthesis \n\n");
    while(fscanf(in_file,"%c",&in_expr) != EOF)
    {
        printf("%c",in_expr);
		if(in_expr == '(' || in_expr == '{' || in_expr == '[')
		{
                push(in_expr);
        }
		else if(in_expr == ')' || in_expr == '}' || in_expr == ']')
		{
            char a = gettop();
            if(isEmpty() || !ArePair(gettop(),in_expr))
			{
                printf("\nResult - Invalid expression - Not a Balanced one !");
                return 0;
            }
			else
			{
                pop();
            }
        }
    }
    fclose(in_file);
}
void main()
{

    read_from_file();

    if(isEmpty()){
        printf("\n\nResult - Valid expression - Perfectly Balanced !");
    }else{
        printf("\n\nResult - Invalid expression - Not a Balanced one !");
    }
    printf("\n");
}
