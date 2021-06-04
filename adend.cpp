
#include<iostream>
using namespace std;

struct node{int data;node*next;};

void adend(node**head)
{
    node*ptr=new node,*temp=*head;
    cout<<"enter:";cin>>ptr->data;ptr->next=NULL;
    if(*head==NULL)
    {
        *head=ptr;
    }
    else
    {
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }
}

void disp(node *head)
{
    node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }      
}

int main()
{
    node *head=NULL;
    char c='y';
    while(c=='y'||c=='Y')
    {
        adend(&head);
        cout<<"enter more(y/n)";
        cin>>c;
    }
    disp(head);
}