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
    int lml=0;
    for(i=0;i<n-1;i++)
    {
        int flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
                flag=1;
            }

        }
        lml++;
        if(flag==0)
            break;
    }

    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";

    cout<<"\n"<<"Total number of iterations are: "<<lml;

    // Time Complexity:
    // Best case - n (Loop break after first comparison)
    // Worst and Average case - n^2
    // Space Complexity - 1

}
