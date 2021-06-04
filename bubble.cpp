#include<iostream>
using namespace std;

int comp=0,swapno=0;

void swp(int *a,int *b){int t=*a;*a=*b;*b=t;}

void bubbleSort(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            comp++;
            if(a[j]>a[j+1])
            {
                swapno++;
                swp(&a[j],&a[j+1]);
            }
        }
    }
    cout<<"STATS COMPS : "<<comp<<" SWAPS : "<<swapno<<'\n';
}

int main()
{
    int a[20],n;
    cout<<"enter the no of elements : ";cin>>n;
    cout<<"enter the array : ";
    for(int i=0;i<n;i++){cin>>a[i];}
    bubbleSort(a,n);
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
    return 0;
}