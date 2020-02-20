#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<sstream>

using namespace std;

string operators="+-*/^";


int main()
{
    string postfix;
    cout<<"Enter the postfix expression separated by commas and don't have any black-space: ";
    cin>>postfix;
    int n=postfix.length();

    string temp_stack[n];

    int index1,index2;
    index1=0;
    postfix=postfix + ",";
    index2=postfix.find(",");
    int i=0;
    while(index2!=-1)
    {
        temp_stack[i++]=postfix.substr(index1,index2-index1);
        postfix.replace(index2,1,".");
        index1=postfix.find(".");
        index2=postfix.find(",");
        postfix.replace(index1,1,"?");
        index1++;
    }
    int kk=i;
    int arr[kk];
    int lml=-1;
    for(i=0;i<kk;i++)
    {
        int dd=operators.find(temp_stack[i]);

        if(dd==-1)
        {
             stringstream ss(temp_stack[i]);
             int x=0;
             ss >> x;
             arr[++lml]=x;
        }

        else
        {
            if(temp_stack[i]=="+")
            {
                arr[lml-1]=arr[lml-1]+arr[lml];
            }

            if(temp_stack[i]=="-")
            {
                arr[lml-1]=arr[lml-1]-arr[lml];
            }

            if(temp_stack[i]=="*")
            {
                arr[lml-1]=arr[lml-1]*arr[lml];
            }

            if(temp_stack[i]=="/")
            {
                arr[lml-1]=arr[lml-1]/arr[lml];
            }

            if(temp_stack[i]=="^")
            {
                arr[lml-1]=pow(double(arr[lml-1]),double(arr[lml]));
            }
            lml=lml-1;

        }

    }
    cout<<arr[0];


    return 0;
}
