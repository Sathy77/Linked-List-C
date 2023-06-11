
//https://www.w3resource.com/c-programming-exercises/linked_list/index.php
///5.Write a program in C to insert a node in the middle of a Singly Linked List.

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

void addNumberMiddle (int value, int node)
{
    struct Node *tempurary=(struct Node*) malloc (sizeof(struct Node));
    struct Node *addNodeNext;
    struct Node *addNodePrevious;
    int i=1;

    if (Root==NULL)
    {
        insert(value);
    }

    else
    {
        addNodeNext=Root;
        while(i<=node)
        {
            if(i==node-1)
            {
                addNodePrevious=addNodeNext;
            }

            addNodeNext=addNodeNext->Next;
            i++;
        }

        if(addNodeNext==NULL)
            insert(value);

        else
        {
            addNodeNext=addNodeNext->Previous;

            tempurary->Data=value;
            tempurary->Next=NULL;
            tempurary->Previous=NULL;

            addNodePrevious->Next=tempurary;
            addNodeNext->Previous=tempurary;
            tempurary->Next=addNodeNext;
        }

    }


}

int main()
{

    int NumberNode, value, i=1;

    printf("\nInput the number of nodes (3 or more) :");
    scanf("%d", &NumberNode);

    while(NumberNode!=0)
    {
        printf("\nInput data for node %d : ",i++);
        scanf("%d", &value);
        insert(value);
        NumberNode--;
    }

    printf("\n\nData entered in the list : \n\n");
    print();

    printf("\n\nInput data to insert in the middle of the list : ");
    scanf("%d",&value);
    printf("\nInput the position to insert new node : ");
    scanf("%d",&NumberNode);
    addNumberMiddle(value,NumberNode);

    printf("\n\nInsertion completed successfully. \n\n");

    printf("\n\nThe new list are : \n\n");
    print();
    return 0;
}



