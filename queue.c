#include <stdio.h>
#include <stdlib.h>
 typedef struct
 {
     int data;
     struct node* next;

 }node;

 typedef struct
 {
     node* front;
     node* rear;

 }queue;

 queue* createQueue()
 {
     queue* q=(queue* )malloc(sizeof(queue));
     q->front=q->rear=NULL;
     return q;
 }

 node* newnode(int x)
 {
     node* n=(node* )malloc(sizeof(node));
     n->data=x;
     n->next=NULL;
     return n;
 }

 void enqueue(queue* q,int x)
 {
     node* n=newnode(x);
     if(q->front==NULL)
        q->front=q->rear=n;
     else
     {
         q->rear->next=n;
         q->rear=n;
     }
 }

 int dequeue(queue* q)
 {

     if(q->front->next==NULL)
     {
         q->rear=NULL;
         free(q->front);
         q->front=NULL;
     }
     else
     {
         int x=q->front->data;
         node* temp=q->front;
         q->front=q->front->next;
         free(temp);
         return x;

     }
 }

 void display(queue* q)
 {
     if(q->front==NULL)
        printf("THE QUEUE IS EMPTY\n");
     else
     {
         node* temp=q->front;
         while(temp != NULL)
         {
             printf("%d  ",temp->data);
             temp=temp->next;
         }
     }
     printf("\n");
 }

 void menu(queue *q)
 {
     printf("                       ******************************QUEUE MENU LOADED******************************\n");
     printf("choose an option:\n1.enqueue\n2.dequeue\n3.display\n");
     int n,x;
     scanf("%d",&n);
     switch (n)
     {
     case 1:
        printf("enter the value you want to enqueue: ");
        scanf("%d",&x);
        enqueue(q,x);
        break;
     case 2:
        if(q->front == NULL)
        {
            printf("THE QUEUE IS ALREADY EMPTY\n");
            break;
        }
        else
        {
          printf("output of dequeue: %d\n",dequeue(q));
          break;
        }
     case 3:
        display(q);
        break;
     default:
        printf("NO SUCH OPTION\n");

     }

     menu(q);
 }



int main()
{

    queue *q=createQueue();
    menu(q);

}
