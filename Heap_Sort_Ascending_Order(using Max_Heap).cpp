// Static implementation of Heap_Sort(Ascending order using Max-Heap)

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
            if(a[k1]>=a[i-1])
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
        int temp=a[0];
        a[0]=a[top-1];
        a[top-1]=0;
        int i=1;
        while(i*2<=top)
        {
            int k1=i*2;
            int k2=i*2+1;
            int Max;
            if(k2>top)
                Max=k1;

            else
            {
                if(a[k1-1]>=a[k2-1])
                    Max=k1;
                else
                    Max=k2;
            }

            if(a[Max-1]<=a[i-1])
                break;
            else
            {
                int temp=a[Max-1];
                a[Max-1]=a[i-1];
                a[i-1]=temp;
                i=Max;
            }
        }
        a[top-1]=temp;
        top--;
    }
}

int main()
{
    // Sort in Ascending order
    int i,n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements:"<<"\n";
    for(i=0;i<n;i++)
    {
        int p;
        cin>>p;
        Insertion(p);
    }

    while(top!=0)
    {
        Deletion();
    }

    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";


    return 0;
}


// Time complexity:
// Worst, Average, Best case - O(nlogn)
// Space Complexity - O(1)
