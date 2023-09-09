#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct node* next;

}node;

typedef struct
{
    node* head;
    node* tail;

}linkedList;



linkedList* createList()
{
    linkedList *l=(linkedList*)malloc(sizeof(linkedList));
    if(l==NULL)
    {
       printf("\nNO ENOUGH SPACE\n");
       main();
    }

    l->head=l->tail=NULL;
    return l;
}

node* createNode(int x)
{
    node* n=(node* )malloc(sizeof(node));
    if(n==NULL)
    {
       printf("\nNO ENOUGH SPACE\n");

    }

    n->data=x;
    n->next=NULL;
    return n;
}
void insertBegin(linkedList* l,int x)
{
    node* n=createNode(x);
    if(l->head==NULL)
        l->head=l->tail=n;
    else
    {
        n->next=l->head;
        l->head=n;
    }


}
void insertEnd(linkedList *l,int x)
{
    node* n=createNode(x);
    if(l->head==NULL)
        l->head=l->tail=n;
    else
    {
        l->tail->next=n;
        l->tail=n;
    }

}

void insertMiddle(linkedList *l,int x,int index)
{
    node* n=createNode(x);
    if(l->head==NULL)
        l->head=l->tail=n;
    else if(index==0)
        insertBegin(l,x);
    else if(index>(size(l)-1))
        printf("\nINDEX NOT FOUND\n");
    else if(l->head->next==NULL)
    {
        l->head->next=n;
    }

    else
    {
        node* temp1=l->head;
        node* temp2=l->head->next;
        int count=1;
        while(count != index)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            count++;
        }

        n->next=temp2;
        temp1->next=n;

    }


}

void deleteBegin(linkedList *l)
{

    node* temp=l->head;

    if(l->head==NULL)
        printf("the list is already empty\n");

    else if(l->head->next==NULL)
    {
        l->head=l->tail=NULL;
        free(temp);
    }
    else
    {
        l->head=l->head->next;
        free(temp);

    }

}
void deleteEnd(linkedList *l)
{



    if(l->head==NULL)
        printf("the list is already empty\n");

    else if(l->head->next==NULL)
    {
        free(l->head);
        l->head=l->tail=NULL;

    }
    else
    {
        node* temp=l->head;
        while(temp->next != l->tail)
        {
            temp=temp->next;

        }
        free(l->tail);
        l->tail=temp;
        l->tail->next=NULL;



    }

}

void deleteMiddle(linkedList* l,int index)
{
    if(l->head ==NULL)
        printf("\nTHE LIST IS ALREADY EMPTY\n");
    else if(index==0)
        deleteBegin(l);
    else if(index>(size(l)-1))
        printf("\nINDEX NOT FOUND\n");
    else
    {
        int count=1;
        node* temp1=l->head;
        node* temp2=l->head->next;
        while(count != index)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            count++;
        }

        temp1->next=temp2->next;
        free(temp2);
    }




}






int size(linkedList *l)
{
    node* temp=l->head;
    int count=0;
    while(temp !=NULL)
    {
       count++;
       temp=temp->next;
    }

    return count;
}



void display(linkedList *l)
{
    node* temp=l->head;
    printf("list: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

}

void menu(linkedList *l)
{

    printf("                               *****************LINKEDLIST MENU LOADED*****************\n");
    int n;
    printf("choose an option: ");
    printf("\n1.insert at begining\n2.insert at end\n3.insert at index\n4.delete begining\n5.delete end\n6.delete at index\n7.display list\n8.display number of elements\n");
    scanf("%d",&n);
    int x,i;

    switch (n)
    {

    case 1:
        printf("enter the element you want to add: ");
        scanf("%d",&x);
        insertBegin(l,x);
        break;
    case 2:
        printf("enter the element you want to add: ");
        scanf("%d",&x);
        insertEnd(l,x);
        break;
    case 3:
        printf("enter the element you want to add: ");
        scanf("%d",&x);
        printf("enter the index you want: ");
        scanf("%d",&i);
        insertMiddle(l,x,i);
        break;
    case 4:
        deleteBegin(l);
        break;
    case 5:
        deleteEnd(l);
        break;
    case 6:
        printf("enter the index you want: ");
        scanf("%d",&i);
        deleteMiddle(l,i);
        break;
    case 7:
        printf("\n");
        display(l);
        break;
    case 8:
        printf("%d\n",size(l));
        break;
    default:
        printf("no option found!!\n");


    }
    menu(l);



}


int main()
{
        linkedList* l=createList();
        menu(l);


}
