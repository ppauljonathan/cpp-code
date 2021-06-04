#include<iostream>
using namespace std;

void linearSearch(int *a,int len,int query)
{
    for(int i=0;i<len;i++){if(a[i]==query){cout<<"instance at index "<<i<<'\n';break;}}
}

int main()
{
    int a[20]={1,3,2,4,6,5,9,7,8,0,10,13,12,14,11,16,17,15,18,19},query,len=20;
    cout<<"enter a no to search";cin>>query;
    linearSearch(a,len,query);
    return 0;
}