#include<iostream>
using namespace std;

int comp_count=0;

void mergesort(int *a,int n)
{
    if(n==1){return;}
    else
    {
        int q=n/2;
        int n1=q,n2=n-q;
        int l[10],r[10];
        int x=0,y=0,z=0;
        for(int i=0;i<n1;i++){l[i]=a[i];}
        for(int i=0;i<n2;i++){r[i]=a[i+n1];}
        mergesort(l,n1);mergesort(r,n2);
        while(x<n1&&y<n2)
        {
            comp_count++;
            if(l[x]<r[y]){a[z]=l[x];z++;x++;}
            else{a[z]=r[y];z++;y++;}
        }
        while(x<n1){a[z]=l[x];z++;x++;}
        while(y<n2){a[z]=r[y];z++;y++;}
    }    
}

int main()
{
    int a[20]={12, 8, 20, 15, 22, 21, 11, 5, 7, 35, 31},n=11;
    // cout<<"enter size: ";cin>>n;
    // cout<<"enter array: ";
    // for(int i=0;i<n;i++){cin>>a[i];}
    mergesort(a,n);
    cout<<"sorted array: ";
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
    cout<<"\nno of comparisons: "<<comp_count;
}