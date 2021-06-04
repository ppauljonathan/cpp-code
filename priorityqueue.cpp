#include<iostream>
using namespace std;

struct node{int d;node *p,*n;node(){p=NULL;n=NULL;}};

void ex(node **a,node **b){int t;t=(*a)->d;(*a)->d=(*b)->d;(*b)->d=t;}

class pq
{
    private:
    node *f,*b;
    int hsize;
    int len(){int i=0;node *t=f;while(t!=NULL){t=t->n;i++;}return i;}
    public:
    void build()
    {
        hsize=len();
        if(hsize<=1){return;}
        node *t=f;int max=f->d;
        while(t!=NULL)
        {
            if(t->d>max){ex(&f,&t);break;}
            t=t->n;
        }
    }
    pq(){f=NULL;b=NULL;}
    void enq()
    {
        int n;
        cout<<"ENTER ELEMENT : ";cin>>n;
        node *temp=new node;temp->d=n;
        if(f==NULL&&b==NULL){f=temp;b=temp;return;}
        temp->p=b;
        b->n=temp;
        b=temp;
    }
    void di()
    {
        if(f==NULL){cout<<"UNDERFLOW";return;}
        node *t=f;
        while(t){cout<<t->d<<" ";t=t->n;}
    }
    void peek(){if(f==NULL){cout<<"UNDERFLOW";return;}cout<<f->d<<" IS TOP ELEMENT"<<'\n';}
    void extop()
    {
        node *temp;
        if(f==NULL){b=NULL;cout<<"UNDERFLOW";return;}
        temp=f;
        cout<<temp->d<<" EXTRACTED";
        f=f->n;
        delete temp;
    }
};

void message(){cout<<"priority queue operations: \n\tPress 1 to enque\n\tPress 2 to peek\n\tPress 3 to extract top : ";}

int main()
{
    pq q;
    int n;
    char c='y';
    while(c=='y'||c=='Y')
    {
        q.build();
        message();
        cin>>n;
        switch(n)
        {
            case 1:q.enq();break;
            case 2:q.peek();break;
            case 3:q.extop();break;
        }
        q.build();
        //q.di();
        cout<<"\n\rdo you want to continue : ";cin>>c;
    }
    return 0;
}