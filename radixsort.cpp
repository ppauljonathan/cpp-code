#include<iostream>
using namespace std;

int pow(int a,int b)
{
    int pr=1;
    for(int i=0;i<b;i++){pr*=a;}
    return pr;
}

struct node{int data;node *next;};

void insert(node **head,int el)
{
    node *t=new node,*m=*head;
    t->data=el;t->next=NULL;
    if(*head==NULL){*head=t;}
    else
    {
        while(m->next!=NULL){m=m->next;}
        m->next=t;
    }
}

int pull(node *&head)
{
    node *t=head;
    int a=t->data;
    head=head->next;
    delete(t);
    return a;
}

int max_el(int *a,int n)
{
    int m=a[0];
    for(int i=0;i<n;i++){if(a[i]>m){m=a[i];}}
    return m;
}

int digit(int n)
{
    int a=0;
    while(n>0){n/=10;a++;}
    return a;
}

//RADIX SORT LSD BASE 10
void radixsort(int *a,int n)
{
    node *buckets[10];
    for(int i=0;i<10;i++){buckets[i]=NULL;}
    int m=max_el(a,n);
    int limit=digit(m);
    for(int i=1;i<=limit;i++)
    {
        for(int j=0;j<n;j++){insert(&buckets[((a[j]%pow(10,i))/(pow(10,i-1)))],a[j]);}
        int j=0,k=0;
        while(j<n&&k<10)
        {
            while(buckets[k]!=NULL)
            {
                a[j]=pull(buckets[k]);
                j++;
            }
            k++;
        }
    }
}

int main()
{
    int a[20],n;
    cout<<"enter size : ";cin>>n;
    cout<<"enter array : ";
    for(int i=0;i<n;i++){cin>>a[i];}
    radixsort(a,n);
    cout<<"\nsorted array : ";
    for (int i = 0; i < n; i++){cout<<a[i]<<" ";}
    return 0;
}
