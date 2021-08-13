#include<iostream>
using namespace std;

struct node{
    int a;
    node *n;
};

struct graph{
    node *ver;
    int color;
    graph *next;
    int depth;
};

void insNode(node **r,int size){
    node *t=new node;
    t->n=NULL;
    cout<<"enter the vertex connected : ";
    cin>>t->a;
    if(t->a>=size){
        cout<<"\nERR : INVALID NODE\n";
        return;
    }
    if(*r==NULL){
        *r=t;
        return;
    }
    node *k=*r;
    while(k->n!=NULL){
        k=k->n;
    }
    k->n=t;
}

void insGraph(graph **g,int size){
    graph *t=new graph;
    t->ver=NULL;
    t->next=NULL;
    t->color=0;
    t->depth=0;
    char c;
    cout<<"is there edge (y/n) : ";
    cin>>c;
    while(c=='y'||c=='Y'){
        insNode(&(t->ver),size);
        cout<<"enter more (y/n) : ";
        cin>>c;
    }
    if(*g==NULL){
        *g=t;
        return;
    }
    graph *k=*g;
    while(k->next!=NULL){
        k=k->next;
    }
    k->next=t;
}

void insertIntoGraph(graph **g,int size){
    for(int i=0;i<size;i++){
        cout<<"for vertex "<<i<<'\n';
        insGraph(g,size);
    }   
}

void nextLevel(graph *g,graph *mainI){
    graph *iter,*diter=g;
    int no=0;
    node *top;
    if(mainI->color!=0){return;}
    mainI->color=1;
    while(diter!=mainI){
        no++;
        diter=diter->next;
    }
    cout<<no<<" ";
    top=mainI->ver;
    while(top!=NULL){
        iter=g;
        for(int i=0;i<top->a;i++){iter=iter->next;}
        nextLevel(g,iter);
        top=top->n;
    }
}

void dfs(graph *g,int n,int start){
    if(g==NULL){return;}
    graph *mainI=g,*st=g,*iter;
    node *top;
    while(st->next!=NULL){st=st->next;}
    st->next=mainI;st=st->next;
    for(int i=0;i<start;i++){st=st->next;mainI=mainI->next;}
    do{
        nextLevel(g,mainI);
        mainI=mainI->next;
    }while(mainI!=st);
}

int main(){
    graph *G=NULL;
    int n,start;
    cout<<"enter no of vertices : ";cin>>n;
    insertIntoGraph(&G,n);
    cout<<"enter the vertex to start dfs from : ";cin>>start;
    if(start>n){cout<<"\nERR : INVALID VERTEX\n";}
    dfs(G,n,start);
    return 0;
}
