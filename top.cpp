#include<iostream>
using namespace std;

struct node{int a;node *l,*r;node(){l=NULL;r=NULL;}};

void insert(node **root)
{
    node *t=new node;
    char c;
    t->l=NULL;t->r=NULL;
    cout<<"enter data : ";cin>>t->a;
    *root=t;
    cout<<"does this (value="<<(*root)->a<<") have any left child?: ";cin>>c;
    if(c=='y'||c=='y'){insert(&((*root)->l));}
    cout<<"does this (value="<<(*root)->a<<")have any right child?: ";cin>>c;
    if(c=='y'||c=='y'){insert(&((*root)->r));}
}

void travleft(node *root){if(root==NULL){return;}travleft(root->l);cout<<root->a<<" ";}

void travright(node *root){if(root==NULL){return;}cout<<root->a<<" ";travright(root->r);}

void top(node *root){travleft(root->l);cout<<root->a<<" ";travright(root->r);}

int main()
{
    node *root=NULL;
    insert(&root);
    cout<<"top veiw of binary tree :\n\t";
    top(root);
    return 0;
}