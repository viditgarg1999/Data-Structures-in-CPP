#include<iostream>

using namespace std;

int main()
{

    int i,j,n;
    cout<<"Enter the total number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements: "<<"\n";

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    // Ascending order
    for(i=1;i<n;i++)
    {
        int k=0;
        for(j=i-1;j>=0;j--)
        {
            if(a[i]<a[j])
            {
                k++;
            }
            if(k==0)
                break;
        }
        int temp=a[i];
        for(j=i;j>i-k;j--)
        {
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }

    return 1;
}

// Time Complexity:
// Best Case - n
// Worst and Average Case - n^2
// Space Complexity - 1
