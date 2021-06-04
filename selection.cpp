#include<iostream>
using namespace std;

int comp=0,swapno=0;

void swp(int *a,int *b){int t=*a;*a=*b;*b=t;}

void selectionSort(int *a,int n)
{
    int min;
    for(int i=0;i<n;i++)
    {
        min=i;
        for(int j=i;j<n;j++)
        {
            comp++;
            if(a[j]<a[min]){min=j;}
        }
        if(min!=i){swp(&a[i],&a[min]);swapno++;}
    }
    cout<<"STATS COMPS : "<<comp<<" SWAPS : "<<swapno<<'\n';
}

int main()
{
    int a[20],n;
    cout<<"enter the no of elements : ";cin>>n;
    cout<<"enter the array : ";
    for(int i=0;i<n;i++){cin>>a[i];}
    selectionSort(a,n);
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
    return 0;
}