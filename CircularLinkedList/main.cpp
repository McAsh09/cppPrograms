#include<iostream>

using namespace std;

class Node
{   public:
    int data;
    Node* next;
};
Node* head = NULL;
Node* temp;
Node* size;
Node* temp1 = head;


char choice;

void insert()
{
    Node* p = new Node();
    cout<<"Enter data: ";
    cin>>p->data;

    if(head == NULL)
    {
        head = p;
        head->next = NULL;
    }

    else
    {
        temp->next = p;
    }
    temp = p;
    cout<<"Want to enter more (y/n)? ";
    cin>>choice;

    while(choice == 'y')
    {
        insert();
    }

    temp->next = temp1;
    size = head;

}

void display()
{
    for(int i=0;i<4;i++)
    {
        cout<<size->data<<"----->";
        size = size->next;
    }
}


int main()
{
    insert();
    display();
    return 0;
}
