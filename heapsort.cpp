#include<iostream>
using namespace std;

int heapsize=0,size=0;

void exchange(int &x,int&y){int z=x;x=y;y=z;}

void heapify(int *a,int i)
{
    int l=((i+1)*2)-1,r=((i+1)*2),b;
    if(l<=heapsize&&a[l]>a[i]){b=l;}
    else{b=i;}
    if(r<=heapsize&&a[r]>a[b]){b=r;}
    if(b!=i)
    {
        exchange(a[i],a[b]);
        heapify(a,b);
    }
}

void buildheap(int *a)
{
    heapsize=size;
    for(int i=(size/2);i>=0;i--){heapify(a,i);}
}

void heapsort(int *a)
{
    buildheap(a);
    for(int i=size;i>=1;i--)
    {
        exchange(a[0],a[i]);
        heapsize-=1;
        heapify(a,0);
    }
}

int main()
{
    int a[20];
    cout<<"enter size : ";cin>>::size;
    cout<<"enter array : ";for(int i=0;i<::size;i++){cin>>a[i];}
    heapsort(a);
    cout<<"sorted array : ";for(int i=0;i<::size;i++){cout<<a[i]<<" ";}
    return 0;
}