#include<iostream>
#include<time.h>
using namespace std;

void swap(int &a,int &b){int t;t=a;a=b;b=t;}

int partition(int *a,int lo,int hi)
{
	int pivot=a[lo],i=hi;
	for(int j=hi;j>=lo;j--)
	{

		if(a[j]>pivot)
		{
			swap(a[i],a[j]);
			i--;
		}
	}
	swap(a[i],a[lo]);
	return i;
}

void quicksort(int *a,int lo,int hi)
{
	if(lo<hi)
	{
		int p=partition(a,lo,hi);
		quicksort(a,lo,p-1);quicksort(a,p+1,hi);
	}
}

int main()
{
	int a[20],n;
    cout<<"enter size: ";cin>>n;
    cout<<"enter array: ";
    for(int i=0;i<n;i++){cin>>a[i];}
	quicksort(a,0,n-1);
	cout<<"sorted array: ";
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
	cout<<"\nno of comparisons"<<count;
}
