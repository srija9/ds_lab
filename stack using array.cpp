#include<iostream>
using namespace std;

int Stack[100],n=100,top=-1;

void push(int val)
{
    if(top>=n-1)
        cout<<"stack overflown"<<endl;
    else{
        top++;
        Stack[top] = val;
    }
}

void pop()
{
    if(top<=-1)
        cout<<"stack overflown"<<endl;
    else{
        cout<<"the popped element is"<<Stack[top]<<endl;
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        cout<<"Stack elements are:";
        for(int i=top;i>=0;i--)
            cout<<Stack[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"stack is empty";

}

int peek()
{
    if(top<=-1)
    {
        cout<<"stack is empty";
        return 0;
    }
    else
    {
        int x =Stack[top];
        cout<<"op element is"<<x<<endl;
        return x;
    }
}

bool isempty()
{
    if(top<=-1)
        cout<<"stack is empty";
    return true;
}

int main()
{
    int ch,val;
    cout<<"1. push in stack\n";
    cout<<"2. pop from stack\n";
    cout<<"3. display\n";
    cout<<"4.exit\n";
    do{
        cout<<"enter choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:{

               cout<<"enter the value to be pushed"<<endl;
               cin>>val;
               push(val);
               break;
            }
            case 2:
                {
                    pop();
                    break;
                }
            case 3: {
                 display();
                 break;
            }
            case 4:{
             cout<<"exit"<<endl;
            }
            default:cout<<"exit"<<endl;
        }

    }while(ch!=4);

    return 0;
}
