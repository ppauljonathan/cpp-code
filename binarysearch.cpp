#include<iostream>
using namespace std;
void binsearch(int *a,int sindex,int eindex,int query)
{
    if(eindex<sindex){cout<<"Query not in array\n";return;}
    int mid=(sindex+eindex)/2;
    if(a[mid]==query){cout<<"instance at index "<<mid<<'\n';return;}
    if(a[mid]<query){binsearch(a,mid+1,eindex,query);}
    else{binsearch(a,sindex,mid-1,query);}
}
int main()
{
    int a[20]={1,2,4,6,7,8,10,13,15,16,17,18,20,23,26,27,33,34,38,40},len=20,query;
    cout<<"enter a no to search : ";cin>>query;
    binsearch(a,0,len-1,query);
    return 0;
}
