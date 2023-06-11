

//https://www.w3resource.com/c-programming-exercises/linked_list/index.php
///5.Write a program in C to insert a new node at the end of a Singly Linked List.

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
    struct Node *printNode =NULL;


    if (Root ==NULL)
        printf("Not create linked list yet\n");

    else
    {
        printNode=Root;

        while (printNode!=NULL)
        {
            printf(" Data = %d\n",printNode->Data);
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

    printf("\n\nData entered in the list : \n\n");
    print();

    printf("\n\nInput data to insert at the end of the list : ");
    scanf("%d",&value);
    insert(value);

    printf("\n\nData after inserted in the list are : \n\n");
    print();
    return 0;
}


