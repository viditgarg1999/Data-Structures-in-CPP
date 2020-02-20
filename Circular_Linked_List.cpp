#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};
struct node * last=NULL;

void insertion_beg(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=temp;

    if(last==NULL)
    {
        last=temp;
    }

    else
    {
        temp->link=last->link;
        last->link=temp;
    }
}

void insertion_end(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));

    temp->data=x;
    temp->link=temp;

    if(last==NULL)
    {
        last=temp;
    }

    else
    {
        temp->link=last->link;
        last->link=temp;
        last=temp;
    }
}

void insertion_mid(int x,int pos)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=temp;

    struct node *p=last->link;

    for(int i=0;i<pos-1;i++)
    {
        p=p->link;
    }

    temp->link=p->link;
    p->link=temp;
}


void display()
{
    struct node *p=last->link;

    while(p->link!=last->link)
    {
        cout<<p->data<<"\t";
        p=p->link;
    }
    cout<<p->data;
    cout<<"\n";
}

void deletion_beg()
{
    struct node *p=last->link;
    last->link=p->link;
    free(p);
}

void deletion_end()
{
    struct node *p=last;

    while(p->link!=last)
    {
        p=p->link;
    }
    p->link=last->link;
    last=p;
    free(p);
}

void deletion_mid(int pos)
{
    struct node *p=last->link;
    struct node *prev;
    for(int i=0;i<pos-1;i++)
    {
        prev=p;
        p=p->link;
    }
    prev->link=p->link;
    free(p);

}


int main()
{
    int i,j,n,ch,pos;
    ch=1;
    while(ch!=8)
    {
        cout<<"1. Insert in beginning"<<"\n";
        cout<<"2. Insert in middle"<<"\n";
        cout<<"3. Insert in end"<<"\n";
        cout<<"4. Delete from beginning"<<"\n";
        cout<<"5. Delete from middle"<<"\n";
        cout<<"6. Delete from end"<<"\n";
        cout<<"7. Display"<<"\n";
        cout<<"8. Exit"<<"\n";
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
