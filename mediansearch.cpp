#include<iostream>
using namespace std;

int select(int m,int *s,int n)
{
    if(n==1){return s[0];}
    int s1[n],s3[n],s2[n],a=0,b=0,c=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]<s[n-1]){s1[a]=s[i];a++;}
        else if(s[i]==s[n-1]){s2[b]=s[i];b++;}
        else{s3[c]=s[i];c++;}
    }
    if(a>=m){return select(m,s1,a);}
    else if(a+1>=m){return s2[0];}
    else{return select(m-a-b,s3,c);}
}

int main()
{
    int n,a[20],m;
    cout<<"enter size : ";cin>>n;
    cout<<"enter array : ";for(int i=0;i<n;i++){cin>>a[i];}
    cout<<"enter no median : ";cin>>m;
    cout<<select(m,a,n);
    return 0;
}