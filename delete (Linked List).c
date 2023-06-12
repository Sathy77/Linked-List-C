
//https://www.w3resource.com/c-programming-exercises/linked_list/index.php
///8. Write a program in C to delete a node from the middle of a Singly Linked List.

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
    struct Node *printNode =NULL;
    int countNode=0;


    if (Root ==NULL)
        {
            printf("Not create linked list yet\n");
            return countNode;

        }

    else
    {
        printNode=Root;

        while (printNode!=NULL)
        {
            printf(" Data = %d\n",printNode->Data);
            printNode=printNode->Next;
            countNode++;
        }
        return countNode;
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

void Delete(int node)
{
    int i=1;
    struct Node *deleteNode, *temp;
    if(node==1)
    {
        Root=Root->Next;
    }

    else
    {

        deleteNode=Root;
        while(i<node)
        {
            deleteNode=deleteNode->Next;
            i++;
        }

        if (deleteNode->Next==NULL)
        {
            Last->Previous->Next=NULL;
            Last=Last->Previous;
        }

        else
        {

            deleteNode->Previous->Next= deleteNode->Next;
            deleteNode->Next->Previous = deleteNode->Previous;
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
                addNodePrevious=addNodeNext;/// add node previous value

            }

            addNodeNext=addNodeNext->Next;
            i++;
        }



        if(addNodeNext==NULL)
            insert(value);

        else
        {

            addNodeNext=addNodeNext->Previous; /// add node next value


            tempurary->Data=value;
            tempurary->Next=NULL;
            tempurary->Previous=NULL;

            tempurary->Previous= addNodeNext->Previous;
            tempurary->Next= addNodePrevious->Next;
            addNodeNext->Previous= tempurary;
            addNodePrevious->Next=tempurary;


        }


    }
}

int main()
{

    int NumberNode, value, i=1, countNode;

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
    printf("---------------------\n");
    countNode=print();


    printf("\n\nInput data to insert in the middle of the list : ");
    scanf("%d",&value);
    printf("\nInput the position to insert new node : ");
    scanf("%d",&NumberNode);
    addNumberMiddle(value,NumberNode);

    printf("\n\nInsertion completed successfully. \n\n");

    printf("\n\nThe new list are : \n\n");
    printf("---------------------\n");
    countNode=print();


    printf("\n\n Linked List has %d node!\n Enter the delete node number: ", countNode);
    scanf("%d", &value);

    Delete(value);

    printf("---------------------\n");
    countNode=print();

    printf("---------------------\n");
    reversePrint();
    return 0;
}




