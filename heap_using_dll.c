#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

struct node{
    int priority;
    struct node *prev,*next;
};

int BiggestOfThree(int a,int b,int c){return a>b?a>c?a:c:b>c?b:c;}

void nodex(struct node *n1,struct node *n2){
    if(n1==NULL||n2==NULL){return;}
    int t=n1->priority;
    n1->priority=n2->priority;
    n2->priority=t;
}

int sizeOfQueue(struct node *pq){
    int l=0;
    while(pq!=NULL){
        l++;
        pq=pq->next;
    }
    return l;
}

struct node * getNodeAtIndex(struct node *pq,int i){
    int l;
    for(l=0;l<i;l++){
        if(pq==NULL){return NULL;}
        pq=pq->next;
    }
    return pq;
}

void addAtEnd(struct node **pq,int pri){
    struct node *nod=(struct node *)malloc(sizeof(struct node));
    nod->priority=pri;nod->next=NULL;nod->prev=NULL;
    if((*pq)==NULL){(*pq)=nod;return;}
    struct node *head=*pq;
    while (head->next!=NULL){head=head->next;}
    head->next=nod;
    nod->prev=head;
}

void heapify(struct node *pq,int index){

    struct node 
    *a=getNodeAtIndex(pq,index),
    *b=getNodeAtIndex(pq,(2*(index+1))-1),
    *c=getNodeAtIndex(pq,(2*(index+1)));
    if(b==NULL&&c==NULL){return;}
    if(c==NULL){
        if(a->priority>b->priority){return;}
        nodex(a,b);
    }
    else{
        int big=BiggestOfThree(
            a->priority,
            b->priority,
            c->priority
        );
        if(big==a->priority){return;}
        else if(big==b->priority){nodex(a,b);}
        else if(big==c->priority){nodex(a,c);}
    }
    if(index==0){return;}
    heapify(pq,index/2);
}

void buildHeap(struct node **pq){
    int size=sizeOfQueue(*pq);
    int i;
    for(i=(size/2);i>=0;i--){
        heapify(*pq,i);
    }
}

void display(struct node *pq){
    while (pq!=NULL){
        printf("%d ",pq->priority);
        pq=pq->next;
    }
}

void insert(struct node **pq,int pri){
    addAtEnd(pq,pri);
    buildHeap(pq);
}


void extractMax(struct node **pq){
    struct node *temp=*pq;
    temp->next->prev=NULL;
    *pq=temp->next;
    free(temp);
    buildHeap(pq);
}

void changeKey(struct node **pq,int oldk,int newk){
    int i=0;
    struct node *k=*pq;
    while(k->priority!=oldk){
        if(k==NULL){
            printf("ERR:ELEMENT NOT FOUND");
        }
        k=k->next;
        i++;
    }
    k->priority=newk;
    buildHeap(pq);
}

void deletion(struct node **pq,int key){
    changeKey(pq,key,MAX);
    extractMax(pq);
}

void message(){
    printf("1-insert(key)\n2-extractMax()\n3-changeKey(old,new)\n4-delete(key):");
}

int main(){
    struct node *PQ=NULL;
    int op;
    while(1){
        message();
        scanf("%d",&op);
        switch (op)
        {
        case 1:
        int key;
        scanf("%d",&key);
        insert(&PQ,key);
            break;
        case 2:
        extractMax(&PQ);        
            break;
        case 3:
        int k1,k2;
        scanf("%d %d",&k1,&k2);
        changeKey(&PQ,k1,k2);
            break;
        case 4:
        int k;
        scanf("%d",&key);
        deletion(&PQ,key);
            break;
        default:
            printf("no-op");
            break;
        }
        display(PQ);
        printf("\n");
    }
    return 0;
}
