//https://www.w3resource.com/c-programming-exercises/linked_list/index.php
///1. Write a program in C to create and display a Singly Linked List.

#include<stdio.h>

struct Node
{
    int Data;
    struct Node *Next;

};

struct Node *Root= NULL;
struct Node *Last= NULL;

void insert (int value)
{

    struct Node *newNode =(struct Node*) malloc (sizeof(struct Node));

    newNode->Data=value;
    newNode->Next=NULL;

    if(Root==NULL)
    {
        Root=newNode;
        Last=newNode;
    }
    else
    {
        Last->Next=newNode;
        Last=newNode;
    }
}

void print()
{
    struct Node *printNode =Root;

    if (Root ==NULL)
        printf("Not create linked list yet\n");

    else
    {
        printNode=Root;
        printf("\n\nData entered in the list : \n\n");
        while (printNode!=NULL)
        {
            printf(" Data =%d\n",printNode->Data);
            printNode=printNode->Next;
        }
    }
}

int main()
{

    int NumberNode, value, i=1;

    printf("\nInput the number of nodes :");
    scanf("%d", &NumberNode);

    while(NumberNode!=0)
    {
        printf("\nInput data for node %d: ",i++);
        scanf("%d", &value);
        insert(value);
        NumberNode--;
    }

    print();
    return 0;
}

