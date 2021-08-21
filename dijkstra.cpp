#include<iostream>
using namespace std;
#define INFINITY 10000

class edge{
    public:
    int ever;
    int cost;
    edge *next;
    bool operator==(const edge &rhs)const{
        return (ever==rhs.ever)&&
            (cost==rhs.cost)&&
            (next==rhs.next);
    }
};

class graph{
    public:
    edge *ver;
    graph *next;
    int costFromStart;
    string path;
    bool isVisited;
    bool operator==(const graph &rhs)const{
        return (ver==rhs.ver)&&
            (costFromStart==rhs.costFromStart)&&
            (next==rhs.next);
    }
};

template <typename T>
class pq{
    private:
        T t;
        int p;
        bool isMin;
        pq *f,*b,*next,*prev;
        void nodex(pq **a,pq **b){
            T t=(*a)->t;
            int p=(*a)->p;

            (*a)->t=(*b)->t;
            (*a)->p=(*b)->p;

            (*b)->t=t;
            (*b)->p=p;
        }
        void build(){
            pq *iter=f->next;
            while(iter!=NULL){
                if(isMin){
                    if(iter->p<f->p){
                        nodex(&f,&iter);
                    }
                }
                else{
                    if(iter->p>f->p){
                        nodex(&f,&iter);
                    }
                }
                iter=iter->next;
            }
        }
    public:
        pq(bool isMin){
            this->f=NULL;
            this->b=NULL;
            this->isMin=isMin;
        }
        int len(){
            if(f==NULL&&b==NULL){return 0;}
            if(f==b){return 1;}
            pq *iter=f;int len=0;
            while(iter!=b){
                len++;
                iter=iter->next;
            }
        }
        bool isEmpty(){
            return (this->len()==0)?true:false;
        }
        void enq(T t,int p){
            pq *k=new pq(isMin);
            k->t=t;
            k->p=p;
            k->next=NULL;
            if(f==NULL){f=k;b=k;return;}
            b->next=k;
            k->prev=b;
            b=b->next;
            build();
        }
        void disp(){
            pq *iter=f;
            while(iter!=NULL){
                cout<<iter->p<<'\n';
                iter=iter->next;
            }
        }
        T peek(){
            return (f->t);
        }
        void deq(){
            pq *temp=f;
            if(f->next==NULL){
                f=NULL;
                b=NULL;
                delete temp;
                return;
            }
            f=f->next;
            delete temp;
            build();
        }
        void upp(T p,int op,int np){
            pq *iter=f;
            while(iter!=NULL){
                if(
                    iter->t==p&&
                    iter->p==op
                ){
                    iter->p=np;
                }
                iter=iter->next;
            }
            build();
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
    pq <graph *> q(true);
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
        q.enq(iter,iter->costFromStart);
        iter=iter->next;
    }while(iter!=stitch->next);
    
    while(!q.isEmpty()){
        top=q.peek();
        q.deq();
        top->isVisited=true;
        toptop=top->ver;
        while(toptop!=NULL){
            diter=g;
            for(int i=0;i<toptop->ever;i++){diter=diter->next;}
            if(
                top->costFromStart+toptop->cost<
                diter->costFromStart
            ){
                q.upp(
                    diter,
                    diter->costFromStart,
                    top->costFromStart+toptop->cost
                );
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
