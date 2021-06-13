#include<stdio.h>
struct Node{
    int Data;
    struct Node *Next;

};

struct Node *Root =NULL;
struct Node *Last =NULL;

void Insert(int value)
{
    struct Node *newNode =(struct Node*) malloc (sizeof(struct Node));
    newNode->Data= value;
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
    if(Root==NULL)
    {
        printf("There is nothing to show!\n");
    }
    else
    {
        struct Node *printNode =Root;
        while(printNode!=NULL)
        {
            printf("%d ", printNode->Data);
            printNode=printNode->Next;
        }
    }
}

int main()
{
    Insert(5);
    Insert(10);
    Insert(30);
    Insert(15);
    print();

    return 0;
}
