#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

};

Node* head=NULL;
Node* temp;
Node* del_1,*del_2;
char choice,choice_1;


void add()
{
   Node* p=new Node();
   cout<<"Enter data : ";
   cin>>p->data;
   p->prev = NULL;
   p->next = head;
   temp=head;
   if(head !=  NULL)
   head->prev = p ;
   head = p;
   cout<<"Want to enter again ? ";
   cin>>choice;
   while(choice=='y')
   {
       add();
   }
    head->prev=temp->next;


}

void display()
{
    Node* curr;
    curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"<----";
        curr=curr->next;
    }
}


void del_node()
{
    Node* del;
    del=head;
    del_1=temp;
    int size=0;
    while(del!=NULL)
    {
        size++;
        del=del->next;
    }
    del=head;
    for(int i=size;i>1;i--)
    {
        del_1=del_1->prev;
    }
    del_2=del_1;
    head=del_2;
    del->prev=NULL;
    del->next=NULL;

    delete del;
    display();





}

int main()
{
    add();
    cout<<"Doubly linked list is : \n";
    display();
    cout<<"Want to delete ? ";
    cin>>choice_1;
    del_node();

    return 0;
}
