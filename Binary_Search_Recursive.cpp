#include<iostream>
#include<algorithm>
using namespace std;

int Binary_search(int a[],int low,int high,int x)
{
    int mid;
    mid=(low+high)/2;

    if(high>=low)
    {
        if(a[mid]==x)
            return mid;

        else if(a[mid]<x)
            Binary_search(a,mid+1, high,x);

        else if(a[mid]>x)
            Binary_search(a,low,mid-1, x);
    }
    else
        return -1;
}

int main()
{
    int n,i,j;
    cout<<"Enter the total number of Elements: ";
    cin>>n;
    cout<<"Enter the Elements:"<<"\n";
    int a[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int x;
    cout<<"Enter the number you want to search: ";
    cin>>x;

    sort(a,a+n); //Sorting of array

    int low=0;
    int high=n-1;

    int k=Binary_search(a,low, high,x);

    if(k==-1)
        cout<<"Element not Found!!"<<"\n";

    else
        cout<<"Element Found at index "<<k<<"\n";

    return 0;

}
