#include<iostream>
#include<algorithm>
using namespace std;

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
    int mid;
    int pp=0;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==x)
        {
            cout<<"Element found at index "<<mid<<"\n";
            pp=1;
            break;
        }
        else if(x>a[mid])
        {
            low = mid+1;
        }
        else if(x<a[mid])
        {
            high=mid-1;
        }
    }

    if(pp==0)
        cout<<"Element not found!!"<<"\n";


    return 0;
}
