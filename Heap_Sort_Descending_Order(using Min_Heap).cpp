// Static implementation of Heap_Sort without Heapify(Descending order using Min-Heap)

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
        int temp=a[0];
        a[0]=a[top-1];
        a[top-1]=temp;
        int i=1;
        while(i*2<top)
        {
            int k1=i*2;
            int k2=i*2+1;
            int Min;
            if(k2>=top)
                Min=k1;

            else
            {
                if(a[k1-1]>=a[k2-1])
                    Min=k2;
                else
                    Min=k1;
            }

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

int main()
{
    // Sort in Descending order
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
