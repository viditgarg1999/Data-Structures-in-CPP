#include<iostream>
#include<algorithm>
using namespace std;

void binary_number(int N,int n, char series[])
{
    if(n<1)
    {
        reverse(series,series+N);
        for(int i=0;i<N;i++)
        {
            cout<<series[i];
        }
        cout<<"\n";
    }

    else
    {
        series[n-1]='0';
        binary_number(N,n-1,series);
        series[n-1]='1';
        binary_number(N,n-1,series);

    }
}

int main()
{
    int n;
    cout<<"Enter the value of N: ";
    cin>>n;
    char series[n];
   // char series[n]='\0'
    int N=n;
    binary_number(N,n,series);
    return 0;
}
