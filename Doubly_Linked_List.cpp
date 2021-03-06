#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node * start=NULL;

void insertion_beg(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;

    if(start==NULL)
    {
        start=temp;
    }

    else
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
}

void insertion_end(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));

    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;

    if(start==NULL)
    {
        start=temp;
    }

    else
    {
        struct node *p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
    }
}

void insertion_mid(int x,int pos)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;

    struct node *p=start;

    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }

    temp->next=p->next;
    temp->prev=p;
    (temp->next)->prev=temp;
    p->next=temp;
}


void display()
{
    struct node *p=start;

    while(p->next!=NULL)
    {
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<p->data;
    cout<<"\n";
}

void display_rev()
{
    struct node *p=start;

    while(p->next!=NULL)
    {
        p=p->next;
    }

    while(p->prev!=NULL)
    {
        cout<<p->data<<"\t";
        p=p->prev;
    }
    cout<<p->data;
    cout<<"\n";
}

void deletion_beg()
{
    struct node *p=start;
    start=start->next;
    start->prev=NULL;
    free(p);
}

void deletion_end()
{
    struct node *p=start;
    struct node *pre;

    while(p->next!=NULL)
    {
        pre=p;
        p=p->next;
    }
    pre->next=NULL;
    free(p);
}

void deletion_mid(int pos)
{
    struct node *p=start;
    struct node *pre;
    for(int i=0;i<pos-1;i++)
    {
        pre=p;
        p=p->next;
    }
    pre->next=p->next;
    (p->next)->prev=pre;
    free(p);

}


int main()
{
    int i,j,n,ch,pos;
    ch=1;
    while(ch!=9)
    {
        cout<<"1. Insert in beginning"<<"\n";
        cout<<"2. Insert in middle"<<"\n";
        cout<<"3. Insert in end"<<"\n";
        cout<<"4. Delete from beginning"<<"\n";
        cout<<"5. Delete from middle"<<"\n";
        cout<<"6. Delete from end"<<"\n";
        cout<<"7. Display"<<"\n";
        cout<<"8. Display in reverse"<<"\n";
        cout<<"9. Exit"<<"\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                cout<<"Enter the number:";
                cin>>n;
                insertion_beg(n);
                break;
            }
        case 2:
            {
                cout<<"Enter the number and position:";
                cin>>n>>pos;
                insertion_mid(n,pos);
                break;
            }
        case 3:
            {
                cout<<"Enter the number:";
                cin>>n;
                insertion_end(n);
                break;
            }

        case 4:
            {
                deletion_beg();
                break;
            }

        case 5:
            {
                cout<<"Enter the position:";
                cin>>pos;
                deletion_mid(pos);
                break;
            }

        case 6:
            {
                deletion_end();
                break;
            }

        case 7:
            {
                display();
                break;
            }

        case 8:
            {
                display_rev();
                break;
            }
        case 9:
            {
                cout<<"Exit"<<"\n";
                break;
            }

        default:
            {
                cout<<"Invalid Choice"<<"\n";
                break;
            }

        }
    }

    return 0;
}
