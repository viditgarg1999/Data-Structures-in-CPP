// Static implementation of Heap-Tree

#include<iostream>
using namespace std;
int Max=20;
int top=0;
int a[20];

void Insertion(int n)
{
    if(top==20)
        cout<<"Heap is Full"<<"\n";
    else
    {
        a[top++]=n;
        int i=top;
        while(i>1)
        {
            int k1=i/2 -1;
            if(a[k1]<=a[i-1])
                break;
            else
            {
                int temp=a[k1];
                a[k1]=a[i-1];
                a[i-1]=temp;
                i=i/2;
            }
        }
    }
}

void Deletion()
{
    if(top==0)
        cout<<"Heap is Empty"<<"\n";
    else
    {
        cout<<"Element popped is "<<a[0]<<"\n";
        int kk=a[0];
        a[0]=a[top-1];
        a[top-1]=a[0];
        int i=1;
        while(2*i<top)
        {
            int k1=i*2;
            int k2=i*2+1;
            int Min=k1;
            if(a[k1-1]>=a[k2-1] && k1<=top && k2<=top)
                Min=k2;
            else if(a[k1-1]<a[k2-1] && k1<=top && k2<=top)
                Min=k1;

            if(a[Min-1]>=a[i-1])
                break;
            else
            {
                int temp=a[Min-1];
                a[Min-1]=a[i-1];
                a[i-1]=temp;
                i=Min;
            }
        }
        top--;
    }
}


void Display()
{
   if(top==0)
        cout<<"Heap is Empty"<<"\n";
    else
    {
        for(int i=0;i<top;i++)
            cout<<a[i]<<"\t";
        cout<<"\n";
    }
}

int main()
{
    int ch=1;
    cout<<"Min-Heap Tree Construction"<<"\n";

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
                int n;
                cout<<"Enter the element you want to insert: ";
                cin>>n;
                Insertion(n);
                break;
            }
        case 2:
            {
                Deletion();
                break;
            }
        case 3:
            {
                Display();
                break;
            }
        case 4:
            {
                break;
            }
        default:
            {
                cout<<"Invalid Input"<<"\n";
            }
        }
    }

    return 0;
}



// Time Complexity:
// Insertion - O(nlogn)
// Deletion - O(nlogn)
// Space Complexity - O(1)
