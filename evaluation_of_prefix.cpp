#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<sstream>
#include<algorithm>

using namespace std;

string operators="+-*/^";


int main()
{
    string prefix;
    cout<<"Enter the prefix expression separated by commas and don't have any black-space: ";
    cin>>prefix;
   // reverse(prefix.begin(),prefix.end());
    int n=prefix.length();

    string temp_stack[n];

    int index1,index2;
    index1=0;
    prefix=prefix + ",";
    index2=prefix.find(",");
    int i=0;
    while(index2!=-1)
    {
        temp_stack[i++]=prefix.substr(index1,index2-index1);
        prefix.replace(index2,1,".");
        index1=prefix.find(".");
        index2=prefix.find(",");
        prefix.replace(index1,1,"?");
        index1++;
    }
    reverse(temp_stack,temp_stack + i);
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
                arr[lml-1]=arr[lml]+arr[lml-1];
            }

            if(temp_stack[i]=="-")
            {
                arr[lml-1]=arr[lml]-arr[lml-1];
            }

            if(temp_stack[i]=="*")
            {
                arr[lml-1]=arr[lml]*arr[lml-1];
            }

            if(temp_stack[i]=="/")
            {
                arr[lml-1]=arr[lml]/arr[lml-1];
            }

            if(temp_stack[i]=="^")
            {
                arr[lml-1]=pow(double(arr[lml]),double(arr[lml-1]));
            }
            lml=lml-1;

        }

    }
    cout<<arr[0];


    return 0;
}

