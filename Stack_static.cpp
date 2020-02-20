// Static Stack Implementation

#include<iostream>
using namespace std;
int max1 = 10;
int top=-1;
int a[10];

int isfull()
{
    if(top==max1-1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int push(int x)
{
    if(isfull())
        cout<<"Stack is already full."<<"\n";
    else
    {
        a[++top]=x;
        cout<<"Inserted Successfully"<<"\n";
    }
}

int pop()
{
    if(isempty())
        cout<<"Stack is Already empty."<<"\n";
    else
    {
        a[top]=0;
        top--;
    }
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        cout<<a[i]<<"\t";
    }

}

int main()
{
    int s=1;
    cout<<"Hello user:"<<"\n";
    while (s!=4)
    {
    cout<<"1. Insertion"<<"\n";
    cout<<"2. Deletion"<<"\n";
    cout<<"3. Display"<<"\n";
    cout<<"4. Exit"<<"\n";
    cout<<"Enter your choice:";

    cin>>s;

    switch(s)
    {
    case 1:
        {
            int x;
            cout<<"Enter the number:"<<"\n";
            cin>>x;
            push(x);
            break;
        }

    case 2:
        {
            pop();
            break;
        }
    case 3:
        {
            display();
            break;
        }
    case 4:
        {
            cout<<"Terminates"<<"\n";
            break;
        }
    default:
        {
            cout<<"Invalid Choice"<<"\n";
        }

    }
    }

    return 0;
}
