/* 
 * File:   main.cpp
 * Author: kaustubh
 *
 * Created on July 27, 2019, 11:02 PM
 */

#include <iostream>
using namespace std;
typedef int BOOL;
#define TRUE 1;
#define FALSE 0;
struct node
{
 struct node* prev;
 struct node* next;
 int data;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class Doublyll
{
private :
    PNODE head;
public:
Doublyll();
~Doublyll();
void display();
BOOL insertfirst(int);
BOOL insertlast(int);
BOOL insertatposition(int,int);
BOOL deletefirst();
BOOL deletelast();
int count();
BOOL deleteatposition(int);
void displayreverse();
};
Doublyll::Doublyll()
{
    PNODE head=NULL;
}
BOOL Doublyll::insertfirst(int no)
{
    PNODE newn=NULL;
    newn=new NODE;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    if(head==NULL)
    {
        head=newn;
    }
    else
    {
    newn->next=head;
    head->prev=newn;
    head=newn;    
    }
    return TRUE;
}
BOOL Doublyll::insertlast(int no)
{
    PNODE newn=NULL;
    PNODE temp=head;
    newn=new NODE;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newn->prev=temp;
        temp->next=newn;
}
    return TRUE;
}
BOOL Doublyll::deletefirst()
{
    PNODE temp=head;
    if(head==NULL)
    {
        return FALSE;
    }
    else if(head->next==NULL)
    {
        head=NULL;
    }
    else
    {
        temp = head->next;
        head->next->prev=NULL;
        head=temp;
        
    }
    return TRUE;
}
BOOL Doublyll::deletelast(){
  PNODE temp=head;
    if(head==NULL)
    {
        return FALSE;
    }
    else if(head->next==NULL)
    {
        head=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        temp->prev=NULL;
        delete(temp);
        
    }
  return TRUE;
 }
void Doublyll::display()
{
    PNODE temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }    
}
int  Doublyll::count()
{
    PNODE temp=head;
    int icnt=0;
    while(temp!=NULL)
    {
        icnt++;
        temp=temp->next;
    }
return icnt;    
}
BOOL Doublyll::insertatposition(int ipos, int no)
{
    PNODE temp=head;
    if((ipos<1) || (ipos>(count()+1)))
    {
        return FALSE;
    }
    if(ipos==1)
    {
        insertfirst(no);
    }
    else if(ipos==(count()+1))
    {
        insertlast(no);
    }    
    else
    {
     PNODE newn=NULL;
     newn=new(NODE);
     newn->next=NULL;
     newn->prev=NULL;
     newn->data=no;
     while(ipos!=2)
     {
         temp=temp->next;
         ipos--;
     }
     newn->prev=temp;
     newn->next=temp->next;
     temp->next=newn;
     temp->next->prev=newn;
    }
        return TRUE;

}
BOOL Doublyll::deleteatposition(int ipos)
{
    PNODE temp=head;
    if((ipos<1) || (ipos>(count())))
    {
        return FALSE;
    }
    if(ipos==1)
    {
        deletefirst();
    }
    else if(ipos==(count()))
    {
        deletelast();
    }    
    else
    {   
        while(ipos!=2)
        {
            temp=temp->next;
            ipos--;
        }
     temp->next=temp->next->next;   
     
     temp->next->prev=temp;
    
}
    return true;
    
}
Doublyll::~Doublyll()
{
    PNODE temp=head;
    while(head!=NULL)
    {
        temp=head->next;
        delete head;
        head=temp;
    }
    
}
void Doublyll::displayreverse()
{
    PNODE temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->prev;
}    
}
int main(int argc, char** argv) {
    Doublyll dobj;
    dobj.insertfirst(20);
    dobj.insertfirst(30);
    dobj.insertfirst(40);
    dobj.insertfirst(50);
    dobj.insertlast(10);
    dobj.insertlast(0);
    dobj.deletefirst();
    dobj.deletelast();
    dobj.insertatposition(3,25);
    dobj.deleteatposition(3);
    dobj.display();
    dobj.displayreverse();
    cout<<dobj.count();
    return 0;
}

