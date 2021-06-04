#include<iostream>
using namespace std;

struct node{
    int data,bal;
    node *l,*r;
};

void printTree(node *root,int l,int h){
    if(root==NULL){return;}
    printTree(root->r,l+h,h);
    for(int i=0;i<l;i++){cout<<" ";}
    cout<<root->data<<" "<<root->bal<<'\n';
    printTree(root->l,l+h,h);
}

int height(node *root){
    if(root==NULL){return 0;}
    int l=height(root->l),r=height(root->r);
    return 1+((l>r)?l:r);
}

void balancer(node **);

void balanceAssigner(node **root){
    if((*root)==NULL){return;}
    balanceAssigner(&(*root)->l);
    balanceAssigner(&(*root)->r);
    int l=height((*root)->l),r=height((*root)->r);
    (*root)->bal=r-l;
    if((*root)->bal==2||(*root)->bal==-2){
        balancer(root);
    }
}

void rightRotate(node **root){
    node *a=*root,*b=(*root)->l;
    a->l=b->r;
    b->r=a;
    *root=b;
}

void leftRotate(node **root){
    node *a=*root,*b=(*root)->r;
    a->r=b->l;
    b->l=a;
    *root=b;
}

void balancer(node **root){
    if((*root)->bal==2){
        if((*root)->r==NULL||(*root)->r->bal==1){leftRotate(root);}
        else if((*root)->r->bal==-1){
            rightRotate(&((*root)->r));
            leftRotate(root);
        }
    }
    else if((*root)->bal==-2){
        if((*root)->l==NULL||(*root)->l->bal==-1){rightRotate(root);}
        else if((*root)->l->bal==1){
            leftRotate(&((*root)->l));
            rightRotate(root);
        }
    }
    balanceAssigner(root);
}

void insertion(node **root,int data){
    if((*root)==NULL){
        (*root)=new node;
        (*root)->data=data;
        (*root)->bal=0;
        (*root)->l=NULL;
        (*root)->r=NULL;
        return;
    }
    if(data<(*root)->data){insertion(&((*root)->l),data);}
    else if(data>(*root)->data){insertion(&((*root)->r),data);}
    else{cout<<"DUPLICATE KEYS NOT ALLOWED\n";return;}
    balanceAssigner(root);
}

node *findMin(node *root){
    while(root->l!=NULL){root=root->l;}
    return root;
}

node *findNode(node *root,int key){
    if(root==NULL){cout<<"NOT FOUND\n";return NULL;}
    if(root->data==key){return root;}
    if(root->data>key){return findNode(root->l,key);}
    else{return findNode(root->r,key);}
}

node *findPar(node *root,node *n){
    if(root==n){return NULL;}
    if(root->l==n||root->r==n){return root;}
    if(root->data>n->data){return findPar(root->l,n);}
    else{return findPar(root->r,n);}
}

void deletion(node **root,int key){
    bool check=false;
    if((*root)==NULL){cout<<"Tree is already empty\n";return;}
    node *del=findNode((*root),key);
    if(del==NULL){return;}
    node *par=findPar((*root),del);
    if(par==(*root)){check=true;}
    if(del->r==NULL&&del->l==NULL){
        if(par==NULL){(*root)=NULL;}
        else{
            if(del==par->r){par->r=NULL;}
            else{par->l=NULL;}
        }
    }
    else if(del->r==NULL){
        if(par==NULL){
            (*root)=del->l;
        }
        else{
            if(del==par->r){par->r=del->l;}
            else{par->l=del->l;}
            delete(del);
        }
    }
    else if(del->l==NULL){
        if(par==NULL){
            (*root)=del->r;
        }
        else{
            if(del==par->r){par->r=del->r;}
            else{par->l=del->r;}
            delete(del);
        }
    }
    else{
        node *succ=findMin(del->r);
        int rep=succ->data;
        deletion(root,rep);
        if(par==NULL){(*root)->data=rep;}
        else{del->data=rep;}
    }
    if(check==true){(*root)=par;}
    balanceAssigner(root);
}

int main(){
    node *root=NULL;
    char c='y';
    int op,d;

    while(c=='y'||c=='Y'){
        cout<<"enter op 1 to ins 2 to del : ";cin>>op;
        if(op==1){cout<<"enter data to insert : ";cin>>d;insertion(&root,d);}
        else if(op==2){cout<<"enter key to delete : ";cin>>d;deletion(&root,d);}
        else{cout<<"no op\n";}
        printTree(root,0,10);
        cout<<"\ndo you want to enter more (y/n) : ";cin>>c;
    }
    return 0;
}
