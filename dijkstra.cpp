#include<iostream>
#include<queue>
using namespace std;
#define INFINITY 10000

struct edge{
    int ever;
    int cost;
    edge *next;
};

struct graph{
    edge *ver;
    graph *next;
    int costFromStart;
    string path;
    bool isVisited;
};

struct node{
    graph *d;
    node *n,*p;
};

void ex(node **a,node **b){graph *t;t=(*a)->d;(*a)->d=(*b)->d;(*b)->d=t;}

class pq
{
    private:
    node *f,*b;
    int hsize;
    public:
    pq(){f=NULL;b=NULL;}
    int len(){
        if(f==NULL||b==NULL){return 0;}
        int i=0;
        node *t=f;
        while(t!=NULL){
            t=t->n;
            i++;
        }
        return i;
    }
    void build()
    {
        if(f==NULL||b==NULL){return;}
        hsize=len();
        if(hsize<=1){return;}
        node *t=f;int min=f->d->costFromStart;
        while(t!=NULL)
        {
            if(t->d->costFromStart<min){ex(&f,&t);break;}
            t=t->n;
        }
    }
    void enq(graph *g){
        node *temp=new node;temp->d=g;
        if(f==NULL&&b==NULL){f=temp;b=temp;return;}
        temp->p=b;
        b->n=temp;
        b=temp;
    }
    bool isEmpty(){
        if(this->len()==0){return true;}
        return false;
    }
    graph * extop(){
        node *temp;
        if(f==NULL){b=NULL;return NULL;}
        temp=f;
        f=f->n;
        return temp->d;
    }
};

void insEdge(edge **head,int size){
    edge *e=new edge;
    e->next=NULL;
    cout<<"enter vertex connected to : ";cin>>e->ever;
    if(e->ever>size){cout<<"\nERR : INVALID NODE\n";return;}
    cout<<"enter cost of this edge : ";cin>>e->cost;
    if(*head==NULL){*head=e;return;}
    edge *i=*head;
    while(i->next!=NULL){i=i->next;}
    i->next=e;
}

void insVer(graph **head,int size){
    graph *g=new graph;
    g->ver=NULL;
    g->next=NULL;
    g->costFromStart=INFINITY;
    g->path="";
    g->isVisited=false;
    char c;
    cout<<"is there an edge (y/n) : ";cin>>c;
    while(c=='y'||c=='Y'){
        insEdge(&(g->ver),size);
        cout<<"are there any more edges (y/n) : ";cin>>c;
    }
    if(*head==NULL){*head=g;return;}
    graph *i=*head;
    while(i->next!=NULL){i=i->next;}
    i->next=g;
}

void inserIntoGraph(graph **G,int size){
    for(int i=0;i<size;i++){
        cout<<"for vertex "<<i<<" : \n";
        insVer(G,size);
    }
}

void dijkstra(graph *g,int size,int start){
    pq q;
    graph *stitch=g;
    while(stitch->next!=NULL){stitch=stitch->next;}
    stitch->next=g;
    graph *iter=g;
    graph *top,*diter;
    edge *toptop;
    for(int i=0;i<start;i++){stitch=stitch->next;iter=iter->next;}
    iter->costFromStart=0;
    iter->path="0";

    do{
        q.build();
        q.enq(iter);
        iter=iter->next;
    }while(iter!=stitch->next);
    
    while(!q.isEmpty()){
        q.build();
        top=q.extop();
        top->isVisited=true;
        toptop=top->ver;
        while(toptop!=NULL){
            // cout<<toptop->ever<<'\n';
            diter=g;
            for(int i=0;i<toptop->ever;i++){diter=diter->next;}
            if(
                top->costFromStart+toptop->cost<
                diter->costFromStart
            ){
                diter->costFromStart=top->costFromStart+toptop->cost;
                diter->path=top->path+"->"+to_string(toptop->ever);
            }
            toptop=toptop->next;
        }
    }

    diter=g;
    int no=0;
    do{
        if(diter->costFromStart==INFINITY){
            cout<<"SHORTEST PATH BETWEEN NODE "<<start<<" AND NODE "<<no<<" DOES NOT EXIST\n";
        }
        else{
            cout<<"SHORTEST PATH BETWEEN NODE "<<start<<" AND NODE "<<no<<" IS "<<diter->path<<" WITH COST OF "<<diter->costFromStart<<'\n';
        }
        diter=diter->next;
        no++;
    }while(diter!=g);
}

int main(){
    graph *G=NULL;
    int size,start,end;
    cout<<"enter no of vertexes : ";cin>>size;
    inserIntoGraph(&G,size);
    cout<<"enter vertex to start from : ";cin>>start;
    cout<<"GRAPH ALGO\n";
    dijkstra(G,size,start);
    return 0;
}
