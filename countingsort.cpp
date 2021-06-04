#include<iostream>
using namespace std;

int max_el(int *a,int n)
{
    int m=a[0];
    for(int i=0;i<n;i++){if(a[i]>m){m=a[i];}}
    return m+1;
}

void countingsort(int *a,int n)
{
    int maxim=max_el(a,n);
    int tally[maxim],temp[n];
    for(int i=0;i<n;i++){temp[i]=a[i];}
    for(int i=0;i<maxim;i++){tally[i]=0;}
    for(int i=0;i<n;i++){tally[temp[i]%maxim]++;}
    int sum=0;
    for(int i=0;i<maxim;i++){sum+=tally[i];tally[i]=sum;}
    for(int i=0;i<n;i++){a[--tally[temp[i]]]=temp[i];}
}

int main()
{
    int a[20],n;
    cout<<"enter size : ";cin>>n;
    cout<<"enter array : ";
    for(int i=0;i<n;i++){cin>>a[i];}
    countingsort(a,n);
    cout<<"\nsorted array : ";
     for(int i=0;i<n;i++){cout<<a[i]<<" ";}  
    return 0;
}