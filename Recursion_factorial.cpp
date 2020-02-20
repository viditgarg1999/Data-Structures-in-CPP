// Factorial of a given number using recursion

#include<iostream>
using namespace std;


long int factorial(long int n)
{
    if(n==0)
        return 1;
    else
    {
        long int result=n* factorial(n-1);
        return result;
    }

}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    long int result=factorial(n);
    cout<<result;
    return 0;
}
