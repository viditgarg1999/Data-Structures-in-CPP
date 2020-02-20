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

    for(i=0;i<n-1;i++)
    {
        int Max=a[0];
        int index=0;
        for(j=0;j<n-i;j++)
        {
            if(a[j]>Max)
            {
                Max=a[j];
                index =j;
            }
        }

        a[index]=a[n-i-1];
        a[n-i-1]=Max;
    }

    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";

    return 0;
}

// Time Complexity:
// Best case - n^2 because even if the array is in sorted order then the algorithm have to check for all the values
// Worst and Average case - n^2
// Space Complexity - 1
