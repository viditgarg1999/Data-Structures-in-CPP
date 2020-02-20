#include<iostream>
using namespace std;

int Max=10;
int Rear=-1;
int Front=-1;
int a[10];


int isfull()
{
    if(Front==(Rear+1)%Max)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(Front==-1)
        return 1;
    else
        return 0;
}

void enqueue(int n)
{
    if(isfull())
        cout<<"Queue is already full"<<"\n";

    else
    {
        Rear=(Rear+1)%Max;
        a[Rear]=n;

        if(Front==-1)
            Front=0;
    }

}

void display()
{
    if(isempty())
        cout<<"Queue is empty"<<"\n";
    else
    {
        cout<<"Elements are:"<<"\n";
        if(Front<=Rear)
        {
            for(int i=Front;i<=Rear;i++)
            {
                cout<<a[i]<<"\t";
            }
        }

        if(Front>Rear)
        {
            for(int i=Front;i<Max;i++)
            {
                cout<<a[i]<<"\t";
            }
            for(int i=0;i<=Rear;i++)
            {
                cout<<a[i]<<"\t";
            }
            cout<<"\n";
        }

        cout<<"\n";
    }
}

void dequeue()
{
    if(isempty())
        cout<<"Queue is already empty"<<"\n";
    else if(Front==Rear)
    {
        cout<<"Element "<<a[Front]<<" is popped"<<"\n";
        Front=-1;
        Rear=-1;
    }
    else
    {
        cout<<"Element "<<a[Front]<<" is popped"<<"\n";
        a[Front]=0;
        Front=(Front+1)%Max;
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
                enqueue(n);
                break;
            }
        case 2:
            {
                dequeue();
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
