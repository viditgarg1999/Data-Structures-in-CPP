#include<iostream>
using namespace std;

int greatest_common_divisor(int a,int b)
{
    if(a==1 || b==1)
        return 1;
    else
    {
        if(a==b)
            return a;
        if(a%b==0)
            return b;
        if(b%a==0)
            return a;

        if(a>b)
            return greatest_common_divisor(a%b,b);

        if(a<b)
            return greatest_common_divisor(a,b%a);

    }
    return 0;

}

int main()
{
    int a,b;
    cout<<"Enter the numbers: "<<"\n";
    cin>>a>>b;
    int result=greatest_common_divisor(a,b);
    cout<<result;
    return 0;
}
