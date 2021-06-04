#include<iostream>
using namespace std;

struct Node{int data;Node *left,*right;};

Node *findMin(Node *root){while(root->left!=NULL){root=root->left;}return root;}
Node *findPar(Node *root,Node *q)
{
	if(root==q){return NULL;}
	if(root->left==q||root->right==q){return root;}
	if(root->data<q->data){return findPar(root->right,q);}
	if(root->data>q->data){return findPar(root->left,q);}
}

void insertion(Node **root,int dat)
{
	if((*root)==NULL)
	{
		(*root)=new Node;
		(*root)->data=dat;
		(*root)->left=NULL;
		(*root)->right=NULL;
		return;
	}
	if((*root)->data>dat){insertion(&((*root)->left),dat);}
	else{insertion(&((*root)->right),dat);}
}

void deletion(Node **root,int query)
{
	if((*root)==NULL){return;}
	if((*root)->data>query){deletion(&((*root)->left),query);return;}
	if((*root)->data<query){deletion(&((*root)->right),query);return;}
	Node *rtemp=*root;
	if(rtemp->left==NULL&&rtemp->right==NULL)
	{
		*root=NULL;
		delete(rtemp);
		return;
	}
	if(rtemp->right==NULL)
	{
		*root=rtemp->left;
		delete(rtemp);
		return;
	}
	if(rtemp->left==NULL)
	{
		*root=rtemp->right;
		delete(rtemp);
		return;
	}
	Node *inor=findMin(rtemp->right);
	int rep=inor->data;
	Node *par=findPar(rtemp,inor);
	deletion(&par,rep);
	(*root)->data=rep;
} 

void printTree(Node *root,int l)
{
    if(root==NULL){return;}
    l+=10;
    printTree(root->right,l);
    cout<<endl;
    for(int i=10;i<l;i++){cout<<" ";}
    cout<<root->data<<'\n';
    printTree(root->left,l);
}

int main()
{
	Node *root=NULL;
	char c='y';
	int op,q;
	while(c=='y'||c=='Y')
	{
		system("clear");
		cout<<"enter op 1:ins 2:del : ";cin>>op;
		if(op==1){
			cout<<"enter data : ";cin>>q;
			insertion(&root,q);
		}
		else if(op==2){
			cout<<"enter query : ";cin>>q;
			deletion(&root,q);
		}
		else{
			cout<<"no op";
		}
		printTree(root,0);
		cout<<"\ndo you want to op more : ";cin>>c;
	}
	return 0;	
}
