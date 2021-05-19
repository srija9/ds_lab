#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;
void push(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    if(top==NULL)
        cout<<"stack underflow\n";
    else{
        cout<<"deleted element is"<<top->data<<endl;
        top=top->next;
    }
}

void display()
{
    struct node *ptr;
    if(top==NULL)
        cout<<"stack is empty\n";
    else
        {
         ptr=top;
      cout<<"sack elements are\n";
      while(ptr!=NULL)
      {
          cout<<ptr->data<<" ";
          ptr=ptr->next;
      }
        }
        cout<<endl;
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
