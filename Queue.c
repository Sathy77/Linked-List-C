#include<stdio.h>
int index=-1,array[];

void Enqueue(int Data)
{
    index++;
    array[index]=Data;

}

void Dequeue()
{
    int i=0;
    if(index<0)
        printf("Worng! Queue has no value\n");

    else
    {

         for(i=0; i<5; i++)
    {
        array[i]=array[i+1];
        //printf("%d ", array[i]);
    }
    index--;
    }
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
    printf("if you want Enqueue, press 1.\n\nif you want Dequeue, press 2.\n\nif you want to see the array, press 3.\n\nif you want to stop, press 4.\n\n");
    while(1)
    {
        scanf("%d",&n);
        if(n==1)

        {
            printf("Enqueue= ");
            scanf("%d", &Data);
            Enqueue(Data);
        }

        if(n==2)
        {
            printf("Dequeue Done \n");
            Dequeue(Data);
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

