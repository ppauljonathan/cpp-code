struct node{
  int data;
  node *l,*r;
};

node * invert(node *root){
    if(root==NULL){return NULL;}
    root->l=invert(root->l);
    root->r=invert(root->r);
    node *tl=root->l;
    root->l=root->r;
    root->r=tl;
    return root;
}
