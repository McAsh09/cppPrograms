#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class stack
{
    Node* Top;
    public:
    stack()
    {
        Top == NULL;
    }
    void push();
    void pop();
    void display();
};

    void stack::push()
    {
        Node* p = new Node();
        if(p == NULL)
        {
            cout<<"OVERFLOW !";
            return;

        }
        cout<<"Enter data: ";
        cin>>p->data;

        if(Top == NULL)
        {
            Top = p;
        }
        else
        {
            p->next = Top;
            Top = p;
        }
    }

    void stack::pop()
    {
        if(Top == NULL)

        {
            cout<<"UNDERFLOW";
            return;
        }
        Node* del;
        del = Top;
        Top = Top->next;
        del->next = NULL;
        delete del;
    }

    void stack::display()
    {
        Node* ptr = Top;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<endl;
            ptr = ptr->next;
        }
    }

int main()
    {
        stack st;
        int choice = 1;
        while(choice == 1)
        {
           cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display";
           cout<<"Enter choice : ";
           int ch;
           cin>>ch;
           switch(ch)
           {
               case 1: st.push();
               break;

               case 2: st.pop();
               break;

               case 3: st.display();
               break;

               default: cout<<"Wrong choice !";

           }
           cout<<"Want to enter again?(PRESS 1) ";
           cin>>choice;
        }

        }

