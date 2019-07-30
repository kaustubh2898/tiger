/* 
 * File:   main.cpp
 * Author: kaustubh
 *
 * Created on July 28, 2019, 2:31 AM
 */

#include <stdio.h>
#include <malloc.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0;
struct node
{
    struct node* next;
    int data;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void display(PNODE,PNODE);
int count(PNODE,PNODE);
BOOL insertfirst(PPNODE,PPNODE,int);
BOOL insertlast(PPNODE,PPNODE,int);
BOOL deletefirst(PPNODE,PPNODE);
BOOL deletelast(PPNODE,PPNODE);
BOOL deleteatposition(PPNODE,PPNODE,int);
BOOL insertatposition(PPNODE,PPNODE,int,int);


/*
 * 
 */
int main(int argc, char** argv) {
    PNODE head=NULL;
    PNODE tail=NULL;
    BOOL bret;
  bret=insertfirst(&head,&tail,10); 
  bret=insertfirst(&head,&tail,20);
  bret=insertfirst(&head,&tail,30);
  bret=insertfirst(&head,&tail,40);
  bret=deleteatposition(&head,&tail,3); 
  
  bret=insertatposition(&head,&tail,3,120);
  bret=insertlast(&head,&tail,60);
  display(head,tail);
  bret=deletefirst(&head,&tail);
  bret=deletelast(&head,&tail);
    return 0;
}

BOOL insertfirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;
    if(newn==NULL)
    {
        return FALSE;
}
    else if((*first==NULL) &&(*last==NULL))
    {
        *first=newn;
        *last=newn;
        (*last)->next=*first;
    }
    else
    {
        newn->next=*first;
        *first=newn;
        (*last)->next=*first;
        
    }
    return TRUE;
}
BOOL insertlast(PPNODE first,PPNODE last,int no)
{
    PNODE temp=*first;
PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;
    if(newn==NULL)
    {
        return FALSE;
    }
    else if((*first==NULL) &&(*last==NULL))
    {
        *first=newn;
        *last=newn;
        (*last)->next=*first;
    }
    else
    {
        (*last)->next=newn;
        *last=newn;
        newn->next=*first;
        
}
}
BOOL insertatposition(PPNODE first,PPNODE last,int ipos,int no)
{
    PNODE temp=*first;

    if((ipos<1) &&(ipos>count(*first,*last)+1))
    {
        return FALSE;
    }
    if(ipos==1)
    {
        insertfirst(first,last,no);
    }
    else if(ipos==count(*first,*last))
    {
    insertlast(first,last,no);    
    }
    else
    {
        PNODE newn=NULL;
        newn=(PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;
        while(ipos!=2)
        {
         temp=temp->next;
         ipos--;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
    return TRUE;
}    
void display(PNODE first,PNODE last)
{
    if((first!=NULL) && (last!=NULL))
    {
        do
        {
         printf("%d \t",first->data);
         first=first->next;
        }while(first!=last->next);
    }
}
int count(PNODE first,PNODE last)
{
    int icnt=0;
    if((first!=NULL) && (last!=NULL))
    {
        do
        {
            icnt++;
         first=first->next;
        }while(first!=last->next);
    }
}
BOOL deletefirst(PPNODE first,PPNODE last)
{
    if((*first==NULL) &&(*last==NULL))
    {
        return FALSE;
    }
    else if((*first)->next=NULL)
{
    *first=NULL;
    *last=NULL;
    }
    else
    {
     *first=(*first)->next;
     free(*last->next);
     (*last)->next=*first;
     
}
}
BOOL deletelast(PPNODE first,PPNODE last)
{
    PNODE temp=*first;
    if((*first==NULL) &&(*last==NULL))
    {
        return FALSE;
    }
    else if((*first)->next=NULL)
{
    *first=NULL;
    *last=NULL;
    }
    else
    {
        while(temp->next!=*last)
        {
            temp=temp->next;
            
    }
        free(*last);
        *last=temp;
        *last->next=*first;
    }
    return TRUE;
}
BOOL deleteatposition(PPNODE first,PPNODE last,int ipos)
    {
        
        PNODE temp=*first;
        PNODE temp2=NULL;
        if((ipos <0) || (ipos>count(*first)))
        {
            return false;
        }
        if(ipos==1)
        {
            deletefirst(first);
        }
        if(ipos=count(*first))
        {
            deletelast(first);
        }
        else 
        {
            while(ipos!=2)
            {
                temp=temp->next;
                ipos--;
        }
            temp2=temp->next;
            temp2->next=temp->next;
            free(temp2);
        }
    }

    