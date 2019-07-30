/* 
 * File:   main.cpp
 * Author: kaustubh
 *
 * Created on July 30, 2019, 7:26 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <malloc.h>

typedef int BOOL;
#define TRUE 1;
#define FALSE 0;

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
BOOL deletelast(PPNODE);
BOOL insertfirst(PPNODE,int);
void display(PNODE);
int count(PNODE);
BOOL insertlast(PPNODE,int);
BOOL deletefirst(PPNODE);
BOOL insertatposition(PPNODE,int,int);
BOOL deleteatposition(PPNODE,int);


/*
 * 
 */
int main(int argc, char** argv) {
    PNODE head=NULL;
    BOOL bret;
    int sum=0;
    bret=insertfirst(&head,11);
    bret=insertfirst(&head,51);
    bret=insertfirst(&head,21);
    //display(head);
    bret=insertatposition(&head,251,4);
    bret=insertlast(&head,201);
    bret=insertlast(&head,301);
     bret=insertlast(&head,401);
    //display(head);
    bret=deletefirst(&head);
    bret=deletefirst(&head);
    bret=deletelast(&head);
    bret=deletelast(&head);
    
    //display(head);
    bret=deleteatposition(&head,3);
    display(head);
    sum=count(head);
    printf("%d \n",sum);
    return 0;
}
BOOL insertfirst(PPNODE first,int no)
{
    PNODE newn=NULL;
    newn=(PNODE) malloc (sizeof (NODE));
    if(newn==NULL)
    {
        return FALSE;
    }
    newn->data=no;
    newn->next=NULL;
    if(*first ==NULL)
    {
        *first=newn;
    }
    else
    {
        newn->next=*first;
       *first=newn; 
}
    return TRUE;
}
void display(PNODE first)
{
    while(first != NULL)
    {
        printf("%d ",first->data);
        first=first->next;
    }
}
int count(PNODE first)
{
    int icnt=0;
    while(first!=NULL)
    {
        icnt++;
        first=first->next;
    }
    return icnt;
}
 BOOL insertlast(PPNODE first,int no)
 {
     PNODE newn=NULL;
     PNODE temp=*first;
     newn=(PNODE)malloc(sizeof(NODE));
     if(newn ==NULL)
     {
         return FALSE;
     }
     else
     {
         newn->data=no;
         newn->next=NULL;
     }
     if(*first==NULL)
     {
      *first=newn;   
     }
     else
     {
         while(temp->next !=NULL)
         {
             temp=temp->next;
         }
         temp->next=newn;

     }
     return TRUE;
 }
 BOOL deletefirst(PPNODE first)
 {
     PNODE temp=NULL;
     if(*first==NULL)
     {
         return FALSE;
     }
     else
     {
         temp=(*first)->next;
         free(*first);
         *first=temp;
         return TRUE;
     }
 }
 BOOL deletelast(PPNODE first)
 {
     PNODE temp=*first;
     if((*first)==NULL)
     {
         return FALSE;
     }
     else if(temp->next==NULL)
     {
         free(*first);
         *first=NULL;
     }
     else
     {
         while(temp->next->next!=NULL)
         {
             temp=temp->next;
         }
         free(temp->next);
         temp->next=NULL;
     }
 }
 BOOL insertatposition(PPNODE first,int no,int ipos)
 {              
     if((ipos <1) ||(ipos>count(*first)+1))
     {
         return FALSE;
     }
     if(ipos==1)
     {
         insertfirst(first,no);
     }
     if(ipos=count(*first)+1)
     {
         insertlast(first,no);
     }
     else
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
             while(ipos!=2)
             {
                 temp=temp->next;
                 ipos--;
                 
             }
             newn->next=temp->next;
             temp->next=newn;
             return TRUE;
     }
 }
    BOOL deleteatposition(PPNODE first,int ipos)
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
    
    

