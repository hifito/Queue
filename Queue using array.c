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
} queue;

void inisialisasi(queue *);
void enqueue(queue *, itemType);
int isempty(queue *);
int isfull(queue *);
void fifo(queue *);
void menu();
itemType dequeue(queue *);
queue antrian;

int main()
{
    inisialisasi(&antrian);
    do
    {
        menu(&antrian);
    }while(1);
    return 0;
}

void menu(queue *q)
{
    itemType x;
    int pilih;
    int temp;
    printf("Menu : \n");
    printf("1. Tambah Antrian\n");
    printf("2. Ambil Antrian\n");
    printf("3. Tampilkan Antrian\n");
    printf("4. Keluar\n");
    printf("Silahkan pilih : ");
    scanf("%d", &pilih);
    fflush(stdin);
    if(pilih==1)
    {
        fflush(stdin);
        printf("Data yang mau diisi : ");
        scanf("%c", &x);
        fflush(stdin);
        enqueue(&antrian, x);
        fflush(stdin);
    }
    else if(pilih==2)
    {
        if(isempty(&antrian)==1)
        {
            puts("Data kosong");
            return " ";
        }
        else
            printf("Data yang diambil adalah %c\n", dequeue(&antrian));
    }
    else if(pilih==3)
    {
        fifo(&antrian);
    }
    else
        exit(0);
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
    itemType temp = ' ';
    if(isempty(q)==1)
    {
        puts("Data kosong");
    }
    else
    {
        temp = q->data[q->front];
        (q->count)--;
        q->front=(q->front+1)%MAKS;
    }
    return temp;
}

void fifo(queue *q)
{
    int read, i;
    if(isempty(q)==1)
        puts("Data kosong\n");
    else
    {
        puts("Isi antrian : \n");
        read = q->front;
        for(i=0; i<q->count; i++)
        {
            printf("%c\n", q->data[read]);
            {
                read = (read+1)%MAKS;
            }
        }
    }
}

