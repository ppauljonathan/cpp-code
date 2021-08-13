#include<iostream>
#include<queue>
using namespace std;

struct node{
    int a;
    node *n;
};

struct graph{
    node *ver;
    bool color;
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
    t->color=false;
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

void disNode(node *r){
    node *t=r;
    while(t!=NULL){
        cout<<t->a<<" ";
        t=t->n;
    }
}

void disGraph(graph *g){
    graph *t=g;
    int i=0;
    while(t!=NULL){
        cout<<"node "<<i<<" : ";
        disNode(t->ver);
        cout<<'\n';
        t=t->next;
        i++;
    }
}

void insertIntoGraph(graph **g,int size){
    for(int i=0;i<size;i++){
        cout<<"for vertex "<<i<<'\n';
        insGraph(g,size);
    }   
}

void bfs(graph *g,int n,int start){
    if(g==NULL){return;}
    queue<graph *> q;
    graph *top=new graph,*iter=new graph,*diter=new graph,*mainI=g;
    node *toptop=new node;
    int no;
    graph * s=g;
    while(s->next!=NULL){s=s->next;}
    s->next=mainI;
    s=s->next;
    for(int i=0;i<start;i++){
        s=s->next;
        mainI=mainI->next;
    }
    do{
        if(mainI->color==false){
            mainI->color=true;
            q.push(mainI);
            while(!q.empty()){
                top=q.front();
                q.pop();
                toptop=top->ver;
                while(toptop!=NULL){
                    iter=g;
                    for(int i=0;i<toptop->a;i++){
                        iter=iter->next;
                    }
                    if(iter->color==false){
                        iter->color=true;
                        iter->depth=top->depth+1;
                        q.push(iter);
                    }
                    toptop=toptop->n;
                }
                diter=g;no=0;
                while(diter!=top){
                    no++;
                    diter=diter->next;
                }
                cout<<no<<" "<<top->depth<<"\n";
            }
        }
        mainI=mainI->next;
    }while(mainI!=s);
}

int main(){
    graph *G=NULL;
    int n,start;
    cout<<"enter no of vertices : ";cin>>n;
    insertIntoGraph(&G,n);
    cout<<"enter the vertex to start bfs from : ";cin>>start;
    if(start>n){
        cout<<"\nERR : INVALID VERTEX\n";
    }
    bfs(G,n,start);
    return 0;
}
