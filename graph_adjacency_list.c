#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int size;

struct node{int a;struct node *n;};

struct graph{struct node *ver;struct graph *next;};

void insnode(struct node **r)
{
    struct node *t=(struct node *) malloc(sizeof(struct node));
    t->n=NULL;
    printf("enter the vertex connected : ");
    scanf("%d",&t->a);
    if(t->a>size){printf("\nINVALID NODE\n");return;}
    if((*r)==NULL){(*r)=t;return;}
    struct node *k=*r;
    while(k->n!=NULL){k=k->n;}k->n=t;
}

void insgraph(struct graph **g)
{
    struct graph *t=(struct graph* )malloc(sizeof(struct graph));
    t->ver=NULL;
    t->next=NULL;
    char c;
    printf("is there any vertex (y/n) : ");fflush(stdin);scanf("%c",&c);fflush(stdin);
    while(c=='y'||c=='Y')
    {
        insnode(&(t->ver));
        printf("enter more (y/n) : ");
        fflush(stdin);
        scanf("%c",&c);
        fflush(stdin);
    }
    if((*g)==NULL){*g=t;return;}
    struct graph *k=*g;
    while(k->next!=NULL){k=k->next;}k->next=t;
}

void disnode(struct node *r){struct node *t=r;if(t==NULL){return;}while(t!=NULL){printf("%d ",t->a);t=t->n;}printf("\n");}

void dis(struct graph *g)
{
    int i=1;
    struct graph *t=g;
    if(t==NULL){return;}
    while(t!=NULL)
    {
        printf("node %d : ",i);
        disnode(t->ver);
        t=t->next;i++;
    }
}

int main()
{
    struct graph *g=NULL;
    printf("enter the no of vertices : ");scanf("%d",&size);
    int i;
    for(i=0;i<size;i++){printf("for vertex %d\n",i+1);insgraph(&g);}
    printf("FINAL GRAPH IS\n");
    dis(g);
    return 0;
}
