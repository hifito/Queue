#include <stdio.h>
#include <stdlib.h>
#define MAKS 8

typedef char itemType;
typedef struct
{
    itemType data[MAKS];
    int count;
    int front;
    int rear;
}queue;

void inisialisasi(queue *);
void enqueue(queue *, itemType);
int isempty(queue *);
int isfull(queue *);
itemType dequeue(queue *);

int main()
{
    queue antrian;
    char jwb;
    itemType x;
    inisialisasi(&antrian);
    do
    {
        fflush(stdin);
        printf("Data yang mau diisi : ");
        scanf("%c", &x);
        fflush(stdin);
        enqueue(&antrian, x);
        fflush(stdin);
        printf("Masukkan data lagi? ");
        fflush(stdin);
        jwb=getchar();
    }while(jwb=='y'||jwb=='Y');

    do
    {
        printf("%c\n", dequeue(&antrian));
    }while(isempty(&antrian)!=1);
    return 0;
}

void inisialisasi(queue *q)
{
    q->count=0;
    q->front=0;
    q->rear=0;
}

int isfull(queue *q)
{
    if(q->count == MAKS)
        return 1;
    else
        return 0;
}

int isempty(queue *q)
{
    if(q->count==0)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, itemType x)
{
    if(isfull(q)==1)
    {
        puts("Data penuh");
        return;
    }
    else
    {
        q->data[q->rear]=x;
        q->rear=(q->rear+1)%MAKS;
        (q->count)++;
    }
}

itemType dequeue(queue *q)
{
    itemType temp;
    temp = q->data[q->front];
    (q->count)--;
    q->front=(q->front+1)%MAKS;
    return temp;
}

