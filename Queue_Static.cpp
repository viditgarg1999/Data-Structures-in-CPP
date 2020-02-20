#include<iostream>
using namespace std;

int Max=20;
int top=-1;
int Front=0;
int a[20];

int isfull()
{
    if(top==Max-1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(top<Front)
        return 1;
    else
        return 0;
}

void insertion(int n)
{
    if(isfull())
        cout<<"Queue is already full"<<"\n";

    else
    {
        a[++top]=n;
    }

}

void display()
{
    if(isempty())
        cout<<"Queue is empty"<<"\n";
    else
    {
        cout<<"Elements are:"<<"\n";
        for(int i=Front;i<=top;i++)
        {
            cout<<a[i]<<"\t";
        }
        cout<<"\n";
    }
}

void deletion()
{
    if(isempty())
        cout<<"Queue is already empty"<<"\n";
    else
    {
        cout<<"Element "<<a[Front]<<" is popped"<<"\n";
        a[Front]=0;
        Front++;
    }
}

int main()
{
    int i,j,n,ch;
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
                insertion(n);
                break;
            }
        case 2:
            {
                deletion();
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
