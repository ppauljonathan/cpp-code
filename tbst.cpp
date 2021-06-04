#include<iostream>
using namespace std;

struct search{int d;search *l,*r;search(){l=NULL;r=NULL;}};

struct arr{search *c;arr *n;arr(){n=NULL;}};

void add(arr **list,search *node)
{
	arr *k=new arr;
	k->c=node;
	if(*list==NULL){(*list)=k;}
	else
	{
		arr *temp=*list;
		while(temp->n!=NULL){temp=temp->n;}
		temp->n=k;
	}
	return;
}

void disp(arr *list)
{
	arr *t=list;
	while(t!=NULL)
	{
		cout<<t->c->d<<" ";
		t=t->n;
	}
}

void insert(search **root,int data)
{
	search *t=new search;
	if(*root==NULL){t->d=data;*root=t;}
	else
	{
		if((*root)->d>data){insert(&((*root)->l),data);}
       else{insert(&((*root)->r),data);}
	}
	return;
}

void inorder(arr **list,search *root)
{
	if(root==NULL){return;}
	inorder(list,root->l);
	add(list,root);
	inorder(list,root->r);
}

void travtree(search *root)
{
	if(root==NULL){return;}
	travtree(root->l);
	cout<<root->d<<" ";
	travtree(root->r);
}

void thread(arr **list)
{
	arr *itr=*list;
	while(itr!=NULL)
	{
		if(itr->c->l==NULL&&itr->c->r==NULL)
		{
			itr->c->r=itr->n->c;
		}
		itr=itr->n;
	}	
}

int main()
{
	search *root=NULL;
	arr *list=NULL;
	int a[20],count;
	cout<<"enter size : ";cin>>count;
	cout<<"enter elements : ";for (int i=0;i<count;i++){cin>>a[i];}
	for(int i=0;i<count;i++){insert(&root,a[i]);}
	travtree(root);
	cout<<'\n';
	inorder(&list,root);
	disp(list);
	cout<<'\n';
	travtree(root);
	return 0;
}
