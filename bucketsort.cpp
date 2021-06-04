#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketsort(vector <float> &v)
{
    int n=v.size();
    vector <float> bucket[v.size()];
    for(auto i=v.begin();i!=v.end();i++)
    {
        bucket[int((*i)*n)].push_back(*i);
    }
    for(int i=0;i<n;i++)
    {
        sort(bucket[i].begin(),bucket[i].end());
    }
    int index = 0;
    for(int i = 0; i<n; i++)
    {
        while(!bucket[i].empty())
        {
            v[index++] = *(bucket[i].begin());
            bucket[i].erase(bucket[i].begin());
        }
   }
}

int main()
{
    vector <float> v;
    int n;float a;
    cout<<"enter size : ";cin>>n;
    cout<<"enter array : ";
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    cout<<"\nsorted array : ";
    //bucketsort
    bucketsort(v);

    for(auto i=v.begin();i!=v.end();i++){cout<<*i<<" ";}
}
