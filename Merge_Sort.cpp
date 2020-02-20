#include<iostream>

using namespace std;
void merger(int a[],int l, int mid, int r);

void merge_sort(int a[],int l, int r)
{
    int mid=(l+r)/2;

    if(l<r)
    {
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        merger(a,l,mid,r);
    }
}

void merger(int a[],int l, int mid, int r)
{
    int b[r];
    int p,q,i,j;
    int k=l;
    p=l;
    q=mid+1;

    while(p<=mid && q<=r)
    {
        if(a[p]<=a[q])
        {
            b[k]=a[p];
            p++;
        }
        else
        {
            b[k]=a[q];
            q++;
        }
        k++;

    }

    if(p<=mid)
    {
        for(j=p;j<=mid;j++)
        {
            b[k++]=a[j];
        }
    }
    if(q<=r)
    {
        for(j=q;j<=r;j++)
        {
            b[k++]=a[j];
        }
    }


    for(i=l;i<=r;i++)
    {
        a[i]=b[i];
    }


}


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
    int l=0;
    int r=n-1;
    merge_sort(a,l,r);
    for(i=0;i<=r;i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}

// Time Complexity:
// Worst Case and Average Case- nlog(n)
// Best Case - nlog(n)
// Space Complexity - n
