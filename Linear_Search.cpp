#include<iostream>
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

    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            cout<<"Element present at "<<i<<" index";
            break;
        }
    }

    if(i==n)
        cout<<"Element not found!"<<"\n";

    return 0;
}
