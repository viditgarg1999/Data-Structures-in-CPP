#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string operators = "+-/*^()";

int check_priority(int index)
{
    if(operators[index]=='+' || operators[index]=='-')
        return 1;

    else if(operators[index]=='/' || operators[index]=='*')
        return 2;

    else if(operators[index]=='^')
        return 3;

    else if(operators[index]=='(')
        return 4;

    else if(operators[index]==')')
        return 0;
}

int main()
{
    string infix,postfix,temp_stack;
    postfix="";
    temp_stack="";
    cout<<"Enter the expression in the form of characters only without any space in b/w:";
    cin>>infix;
    int l = infix.length();

    for(int i=0;i<l;i++)
    {
        int index = operators.find(infix[i]);
        if(index==-1)
        {
            postfix = postfix + infix[i];
        }
        else
        {
            int top = temp_stack.length();

            if(top==0)
            {
                temp_stack = infix[i];
            }

            else
            {
                int p =top-1;
                int priority = check_priority(index);

                int priority_old = check_priority(operators.find(temp_stack[p]));

                if(priority!=0)
                {

                    while(priority<=priority_old && p>=0)
                    {
                        if(priority_old!=4)
                        {
                            postfix = postfix + temp_stack[p];
                            temp_stack.replace(p,1,"");
                            p=p-1;
                            priority_old = check_priority(operators.find(temp_stack[p]));
                        }
                        else
                            break;
                    }

                }

                if(priority==0)
                {

                    while(priority_old!=4 && p>=0)
                    {
                        postfix = postfix + temp_stack[p];
                        temp_stack.replace(p,1,"");
                        p=p-1;
                        priority_old = check_priority(operators.find(temp_stack[p]));
                    }
                    int l1=temp_stack.rfind("(");
                    if(l1!=-1)
                        temp_stack.replace(l1,1,"");
                }

                temp_stack = temp_stack + infix[i];
                int l4=temp_stack.rfind(")");
                if(l4!=-1)
                    temp_stack.replace(l4,1,"");
            }
        }
     //   cout<<temp_stack<<"\n";
    }

    reverse(temp_stack.begin(),temp_stack.end());
    postfix=postfix+temp_stack;
    int l1=postfix.find(")");
    while(l1!=-1)
    {
        postfix.replace(l1,1,"");
        l1=postfix.find(")");
    }

    cout<<"Postfix expression is: "<<postfix;

    return 0;
}
