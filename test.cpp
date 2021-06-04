#include<iostream>
using namespace std;

void stableqs(int *a,int b,int n)
{
    if(n<=1){return;}
    int at[n];for(int i=b;i<n;i++){at[b-i]=a[i];}
    int mid=(n-b)/2;int pivot=at[mid];
    int s=b,g=b+mid+1;
    for(int i=0;i<n;i++)
    {
        if(i!=mid)
        {
            if(at[i]<pivot){a[b-s]=at[i];s++;}
            else if(at[i]>pivot){a[b-g]=at[i];g++;}
            else
            {
                if(i<mid){a[s]=at[i];s++;}
                else{a[g]=at[i];g++;}
            }
        }
    }
    stableqs(a,b,s);stableqs(a,g,n);
}

int main()
{
    int a[20],n;
    cout<<"enter size: ";cin>>n;
    cout<<"enter array: ";
    for(int i=0;i<n;i++){cin>>a[i];}
    stableqs(a,0,n);
	cout<<"sorted array: ";
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
}