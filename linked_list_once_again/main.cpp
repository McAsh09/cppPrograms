#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};
Node* head=NULL;
Node* temp;

Node* temp_1;
char choice,choice_1,choice_2,choice_3,choice_4;

int add()
{
    Node* p=new Node();
    cout<<"Enter data : ";
    cin>>p->data;
    if(head==NULL)
    {
        head=p;
        p->next=NULL;
    }

    else
    {
        temp->next=p;
    }
    temp=p;
    cout<<"Want to enter more : \n";
    cin>>choice;
    while(choice=='y')
    {
    add();
    }
    temp->next=NULL;
    return 0;
}

void display(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"--->";
        head=head->next;
    }
}

int add_beg()
{
    Node* p_1=new Node();
    cout<<"Enter data : ";
    cin>>p_1->data;
    p_1->next=head;
    head=p_1;
    return 0;
}

int add_end()
{
    Node* p_2=new Node();
    cout<<"Enter data : ";
    cin>>p_2->data;
    temp->next=p_2;
    p_2->next;
    return 0;
}




int delete_beg()
{
    Node* del;

    del=head;
    head=head->next;
    del->next=NULL;
    delete del;

}

int delete_end()
{
    Node* del_1;

    del_1=head;
    int size=0;
    while(del_1!=NULL)
    {
        size++;
        del_1=del_1->next;
    }
    del_1=head;
    cout<<size;
    for(int i=1;i<size-1;i++)
    {
        del_1=del_1->next;
    }

    temp_1=del_1->next;
    del_1->next=NULL;
    delete temp_1;

    return 0;
}




int main ()
{
    add();
    display(head);
    cout<<"Want to add in beginning : ";
    cin>>choice_1;
    if(choice_1=='y')
    {
        add_beg();
        cout<<"After adding in front :\n";
        display(head);
    }
    cout<<"Want to add in the end : ";
    cin>>choice_2;
    if(choice_2=='y')
    {
        add_end();
        cout<<"After adding in the end :\n ";
        display(head);
    }
    cout<<"Want to delete from beginning : ";
    cin>>choice_3;
    if(choice_3=='y')
    {
        delete_beg();
        cout<<"After deleting : \n";
        display(head);
    }




    cout<<"Want to delete at the end : ";
    cin>>choice_4;
    if(choice_4=='y')
    {

        delete_end();

        cout<<"After deleting : \n";
        display(head);

    }

    return 0;
}




