#include<stdio.h>
struct Node
{
    int Data;
    struct Node *Next;
    struct Node *Previous;
};

struct Node *Root= NULL;
struct Node *Last= NULL;

void Insert(int value)
{
    struct Node *newNode =(struct Node*)malloc(sizeof(struct Node));

    newNode->Data=value;
    newNode->Next=NULL;
    newNode->Previous=NULL;

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

void print(int x)
{
    if(Root==NULL)
        printf("There is nothing to show!\n");
    else
    {
        if(x==1)
        {
            ///Forward
            struct Node *printNode=Root;
            while(printNode!=NULL)
            {
                printf("%d ", printNode->Data);
                printNode=printNode->Next;
            }
        }
        else if(x==2)
        {
            ///Backward
            struct Node *printNode=Last;
            while(printNode!=NULL)
            {
                printf("%d ", printNode->Data);
                printNode=printNode->Previous;
            }
        }
    }
    printf("\n");
}

void search(int value)
{
    if(Root==NULL)
        printf("Linklist has no value");
    else
    {
        struct Node *searchNode= Root;
        while(searchNode!=NULL)
        {
            if(searchNode->Data==value)
            {
                printf("\nFound %d \n", searchNode->Data);
                break;
            }
            searchNode=searchNode->Next;
        }
        if(searchNode==NULL)
            printf("\nNot found!\n");
    }
}
void Delete(int value)
{
    struct Node *deleteNode= Root;
    if(Root==NULL)
        printf("Linklist has no value");
    else
    {
        while(deleteNode!=NULL)
        {
            if(deleteNode->Data==value)
            {
                if(deleteNode->Previous==NULL)
                {
                    deleteNode=deleteNode->Next;
                    deleteNode->Previous=NULL;
                    Root=deleteNode;
                    break;
                }
                if(deleteNode->Next==NULL)
                {
                    deleteNode=deleteNode->Previous;
                    deleteNode->Next=NULL;
                    Last=deleteNode;
                    break;
                }
                else
                {
                    deleteNode->Previous->Next=deleteNode->Next;
                    deleteNode->Next->Previous=deleteNode->Previous;
                    break;
                }
            }
            deleteNode=deleteNode->Next;
        }
        if(deleteNode==NULL)
        {
            printf("Doesn't match the value which you have entered.\n");
        }
    }
}

int main()
{
    int bORf;
    printf("Forward print linklist press 1. \nBackward print linklist press 2. \n");
    scanf("%d", &bORf);
    Insert(10);
    Insert(80);
    Insert(70);
    Insert(50);
    Insert(500);
    print(bORf);

    Delete(500);
    Delete(10);
    Delete(50);
    //Insert(60);
    print(bORf);

    //search(70);
    return 0;
}
