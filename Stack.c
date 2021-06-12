#include<stdio.h>
int index=-1,array[];

void Push(int Data)
{
    index++;
    array[index]=Data;

}

void Pop()
{
    if(index<0)
        printf("Worng! Stack has no value\n");
    else
        index--;
}
void Array ()
{
    int i=0;
    if(index<0)

        printf("No value\n");
    else
    {
        for( ; i<=index; i++)
            printf("%d ", array[i]);

    }
    printf("\n");
}


int main ()

{
    int n, Data;
    printf("if you want push, press 1.\n\nif you want pop, press 2.\n\nif you want to see the array, press 3.\n\nif you want to stop, press 4.\n\n");
    while(1)
    {
        scanf("%d",&n);
        if(n==1)

        {
            printf("Push= ");
            scanf("%d", &Data);
            Push(Data);
        }

        if(n==2)
        {
            printf("Pop Done \n");
            Pop(Data);
        }
        if(n==3)
        {
            printf("The final array= ");
            Array();
        }
        if(n==4)
            break;


    }


    return 0;
}

