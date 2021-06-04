#include<iostream>
using namespace std;
struct node{int d; node *l=NULL,*r=NULL;};

void insert(node **root)
{
    node *t=new node;
    char c;
    t->l=NULL;t->r=NULL;
    cout<<"enter data";cin>>t->d;
    *root=t;
    cout<<"does this (value="<<(*root)->d<<") have any left child?: ";cin>>c;
    if(c=='y'||c=='y'){insert(&((*root)->l));}
    cout<<"does this (value="<<(*root)->d<<")have any right child?: ";cin>>c;
    if(c=='y'||c=='y'){insert(&((*root)->r));}
}

void dfs(node *root)
{
    cout<<root->d<<",";
    if(root->l!=NULL){dfs(root->l);}
    if(root->r!=NULL){dfs(root->r);}
    return;
}

int main()
{
    node *root=NULL;
    insert(&root);
    dfs(root);
}