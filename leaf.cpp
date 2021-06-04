#include<iostream>
using namespace std;

struct leaf
{
	int data;
	leaf *left,
	*right,
	*next;
	leaf(){left=NULL;right=NULL;next=NULL;}
};

void add(leaf **list,leaf *node)
{
	if(*list==NULL)
	{
		*list=node;
	}
	else
	{
		leaf *t=*list;
		while(t->next!=NULL)
		{t=t->next;}
		t->next=node;
	}	
}

void rem(leaf **list)
{
	if(*list==NULL)return;
	*list=(*list)->next;
	rem(list);
}

void inorder(leaf *tree,leaf **list)
{
	if(tree==NULL){return;}
	inorder(tree->left,list);
	if(tree->left==NULL&&tree->right==NULL){add(list,tree);}
	inorder(tree->right,list);
}

void insert(leaf **tree,int n,leaf **list)
{
	leaf *node=new leaf;
	node->data=n;
	if(*tree==NULL)
	{
		*tree=node;
	}
	else
	{
		if((*tree)->data>n){insert(&((*tree)->left),n,list);}
		else{insert(&((*tree)->right),n,list);}
	}
}

void traverse(leaf *list)
{
	leaf *i=list;
	while(i!=NULL)
	{
		cout<<i->data<<" ";
		i=i->next;
	}	
}

int main()
{
	int a[20],n;
	leaf *tree=NULL,*list=NULL;
	cout<<"enter the size of array : ";cin>>n;
	cout<<"enter the array : ";
	for(int i=0;i<n;i++){cin>>a[i];}
	for(int i=0;i<n;i++){rem(&list);insert(&tree,a[i],&list);inorder(tree,&list);}
	traverse(list);
	return 0;
}
