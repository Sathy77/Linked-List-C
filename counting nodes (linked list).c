//https://www.w3resource.com/c-programming-exercises/linked_list/index.php
///3.Write a program in C to create a singly linked list of n nodes and count the number of nodes.

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

int print()
{
    struct Node *printNode =Root;
    int countNode=0;

    if (Root ==NULL)
        {
            printf("Not create linked list yet\n");
            return countNode;

        }

    else
    {
        printNode=Root;

        printf("\n\nData entered in the list : \n\n");

        while (printNode!=NULL)
        {
            printf(" Data = %d\n",printNode->Data);
            printNode=printNode->Next;
            countNode++;
        }
        return countNode;
    }
}


int main()
{

    int NumberNode, value, i=1,countNode;

    printf("\nInput the number of nodes :");
    scanf("%d", &NumberNode);

    while(NumberNode!=0)
    {
        printf("\nInput data for node %d: ",i++);
        scanf("%d", &value);
        insert(value);
        NumberNode--;
    }

    countNode=print();
    printf("\nTotal number of nodes = %d",countNode);

    return 0;
}



