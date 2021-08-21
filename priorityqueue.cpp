#include<iostream>
using namespace std;

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
