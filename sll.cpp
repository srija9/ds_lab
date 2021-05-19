#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class sll
{
    node *head,*tail;
public:
    sll();
    void insertAtStart(int);
    void insertAtEnd(int);
    void insertAtPosition(int,int);
    void deleteNode(int);
    void deleteList();
    void display();
    void isListExist();
};

sll::sll()
{
    head=NULL;
    tail=NULL;
}

void sll::insertAtStart(int data)
{
    node *ptr;
    ptr=new node;
    ptr->data = data;
    if(head==NULL)
    {
        head = ptr;
        tail = ptr;
        ptr->next=NULL;
        return;
    }
    ptr->next=head;
    head=ptr;
}

void sll::insertAtEnd(int data)
{
    node *ptr =new node;
    ptr->data=data;
    ptr->next=NULL;
    if(tail==NULL)
    {
        head = ptr;
        tail = ptr;
    }
    tail->next=ptr;
    tail=ptr;
}

void sll::insertAtPosition(int pos,int data)
{
    node *ptr,*temp;
    ptr=new node;
    int i=1;
    ptr->data=data;
    ptr->next=NULL;
    if(head==NULL||pos==1)
    {
        if(!head)
        {
            head=ptr;
            tail=ptr;
            return;
        }
        ptr->next=head;
        head=ptr;
        return;
    }
    temp = head;
    while(temp)
    {
        if(pos=i+1)
        {
            ptr->next=temp->next;
            temp->next=ptr;
            if(ptr->next==NULL)
                tail=ptr;

            break;
        }
        i++;
        temp=temp->next;
    }
}

void sll::deleteNode(int data)
{
    node *ptr,*temp;
    int res=0;
    ptr=head;
    if(ptr->data==data)
    {
        if(ptr->next==NULL)
        {
            delete ptr;
            head=tail=NULL;
        }
        head=ptr->next;
        delete ptr;
        return;
    }
    while((ptr!=NULL)&&(ptr->next!=NULL))
    {
        if(ptr->next->data==data)
        {
            temp=ptr->next;
            ptr->next=temp->next;
            if(ptr->next==NULL)
                tail=ptr;
            delete temp;
            res=1;
        }
        ptr=ptr->next;
    }
    if(!res)
        cout<<"operation failed"<<endl;
}

void sll::deleteList()
{
    node *ptr;
    ptr=head;
    while(ptr)
    {
        head=ptr->next;
        delete ptr;
        ptr=head;
    }
}

void sll::display()
{
    node *ptr;
    ptr=head;
    while(ptr)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

void sll::isListExist()
{
    if(head)
        cout<<"list is available\n";
    else
        cout<<"list is unavailable\n";
}

int main()
{
    sll ob;
    int ch,data,pos,result;
    cout<<"1.insertion at start\n";
    cout<<"2.insert at end\n";
    cout<<"3.insert at position\n";
    cout<<"4.delete node\n";
    cout<<"5.delete list\n";
    cout<<"6.display\n";
    cout<<"7.is list exist\n";
    cout<<"8.exit\n";

    while(1)
    {
        cout<<"enter ur choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"enter data\n";
            cin>>data;
            ob.insertAtStart(data);
            break;
        case 2:
            cout<<"enter data\n";
            cin>>data;
            ob.insertAtEnd(data);
            break;

        case 3:
            cout<<"enter pos and data\n";
            cin>>pos>>data;
            ob.insertAtPosition(pos,data);
            break;
        case 4:
            cout<<"enter value to delete\n";
            cin>>data;
            ob.deleteNode(data);
            break;
        case 5:
            ob.deleteList();
            break;
        case 6:
            ob.display();
            break;
        case 7:
            ob.isListExist();
            break;
        case 8:
            exit(0);
        default: cout<<"invalid";

        }
    }
    return 0;
}
