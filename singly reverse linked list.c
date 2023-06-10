//https://www.w3resource.com/c-programming-exercises/linked_list/index.php
///2. Write a program in C to create a singly linked list of n nodes and display it in reverse order.

#include<stdio.h>

struct Node
{
    int Data;
    struct Node *Next;
    struct Node *Previous;

};

struct Node *Root= NULL;
struct Node *Last= NULL;

void insert (int value)
{

    struct Node *newNode =(struct Node*) malloc (sizeof(struct Node));

    newNode->Data=value;
    newNode->Next=NULL;
    newNode->Previous= NULL;

    if(Root==NULL)
    {
        Root=newNode;
        Last=newNode;
    }
    else
    {
        newNode->Previous=Last;
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
            printf(" Data = %d\n",printNode->Data);
            printNode=printNode->Next;
        }
    }
}

void reversePrint()
{
    struct Node *printNode =Root;

    if (Root ==NULL)
        printf("Not create linked list yet\n");

    else
    {
        printNode=Last;
        printf("\n\nThe list in reverse are : \n\n");
        while (printNode!=NULL)
        {
            printf(" Data = %d\n",printNode->Data);
            printNode=printNode->Previous;
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
    reversePrint();
    return 0;
}


