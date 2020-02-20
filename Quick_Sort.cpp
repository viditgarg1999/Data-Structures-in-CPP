#include<iostream>
using namespace std;

void quick_sort(int a[],int l, int r)
{

    if(r>l)
    {
        int p=a[l];
        int i=l;
        int j=r;

        while(i<=j)
        {
            if(a[i]>p && a[j]<=p && i<=r && j>=l)
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                i++;
                j--;
            }

            if(a[i]<=p)
                i++;

            if(a[j]>p)
                j--;
        }
        a[l]=a[j];
        a[j]=p;

        quick_sort(a,l,j-1);
        quick_sort(a,j+1,r);
    }
}



int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int i,l,r;
    int a[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    l=0;
    r=n-1;
    quick_sort(a,l,r);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }

    return 0;
}

// Time Complexity :
// Worse Case - n^2
// Best and Average Case - nlog(n)
// Space Complexity - log(n)
