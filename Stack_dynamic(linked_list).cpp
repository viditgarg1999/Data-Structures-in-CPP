#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};
struct node * start=NULL;

int isempty()
{
    if(start==NULL)
        return 1;
    else
        return 0;
}

void insertion_beg(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=NULL;

    if(isempty())
    {
        start=temp;
    }

    else
    {
        temp->link=start;
        start=temp;
    }

}


void display()
{

    if(isempty())
        cout<<"Stack is empty"<<"\n";

    else
    {
        struct node *p=start;
        while(p->link!=NULL)
        {
            cout<<p->data<<"\t";
            p=p->link;
        }
        cout<<p->data;
        cout<<"\n";
    }

}

void deletion_beg()
{
    if(isempty())
        cout<<"Stack is already empty"<<"\n";

    else
    {

        struct node *p=start;
        cout<<start->data<<" is popped"<<"\n";
        start=start->link;
        free(p);
    }
}


int main()
{
    int i,j,n,ch,pos;
    ch=1;
    while(ch!=4)
    {
        cout<<"1. Insertion"<<"\n";
        cout<<"2. Deletion"<<"\n";
        cout<<"3. Display"<<"\n";
        cout<<"4. Exit"<<"\n";
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
                deletion_beg();
                break;
            }

        case 3:
            {
                display();
                break;
            }
        case 4:
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

