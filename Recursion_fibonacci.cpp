// Fibonacci series using Recursion
#include<iostream>
using namespace std;

int fibonacci(int n)
{
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else
    {
        int result = fibonacci(n-1)+ fibonacci(n-2);
        return result;
    }

}

int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
    int result = fibonacci(n);
    cout<<result;
    return 0;
}
