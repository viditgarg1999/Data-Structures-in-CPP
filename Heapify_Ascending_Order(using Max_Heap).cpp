// Static implementation of Heap_Sort(Ascending order using Max-Heap)

#include<iostream>
using namespace std;
int limit=20;
int a[20];

void Max_Heapify(int arr[], int n, int i)
{
    int Max = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if (l < n && arr[l] > arr[Max])
        Max = l;


    if (r < n && arr[r] > arr[Max])
        Max = r;


    if (Max != i)
    {
        int temp=arr[i];
        arr[i]=arr[Max];
        arr[Max]=temp;

        Max_Heapify(arr, n, Max);
    }
}


int main()
{
    // Sort in Ascending order
    int i,n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements:"<<"\n";
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }


    for(i=n/2-1;i>=0;i--)
        Max_Heapify(a,n,i);

    for (int i=n-1; i>=0; i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        Max_Heapify(a, i, 0);
    }

    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";

    return 0;
}


// Time complexity:
// Worst, Average, Best case - O(nlogn)
// Space Complexity - O(1)

