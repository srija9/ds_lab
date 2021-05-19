#include<iostream>
using namespace std;

int Queue[100],n=100,Front=-1,rear=-1;

void Insert()
{
    int val;
    if(rear==n-1)
        cout<<"queue overflow\n";
    else
    {
        if(Front==-1)
            Front =0;
        cout<<"insert the element"<<endl;
        cin>>val;
        rear++;
        Queue[rear] = val;

    }
}

void Delete()
{
    if(Front==-1||Front>rear)
    {
        cout<<"queue overflow\n";
        return;
    }
    else{
        cout<<"element deleted from the queue "<<Queue[Front]<<endl;
        Front++;
    }
}

void display()
{
    if(Front==-1)
        cout<<"queue is empty"<<endl;
    else
    {
        cout<<"queue elements are\n";
        for(int i=Front;i<=rear;i++)
            cout<<Queue[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    int ch,val;
    cout<<"1. insert into queue\n";
    cout<<"2. delete from queue\n";
    cout<<"3. display\n";
    cout<<"4.exit\n";
    do{
        cout<<"enter choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:{


               Insert();
               break;
            }
            case 2:
                {
                    Delete();
                    break;
                }
            case 3: {
                 display();
                 break;
            }
            case 4:{
             cout<<"exit"<<endl;
            }
            default:cout<<"INVALID"<<endl;
        }

    }while(ch!=4);

    return 0;
}

