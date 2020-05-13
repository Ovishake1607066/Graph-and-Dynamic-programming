#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll par[100];
ll fin(ll x)
{
    if(par[x]==x)
        return x;
    else
        return fin(par[x]);
}
ll uni(ll x,ll y)
{
    par[fin(x)]=fin(y);
    return 0;
}
int main()
{
    ifstream in("prims.txt");
    ll tn,n1,n2,w;
    in>>tn;
    for(ll i=0;i<tn;i++)
        par[i]=i;
    vector<pair<ll,pair<ll,ll> > >v;
    while(in>>n1>>n2>>w)
    {
        v.push_back(make_pair(w,make_pair(n1,n2)));
    }
    sort(v.begin(),v.end());
    ll e=0,s=0,i=0;
    while(e<tn-1)
    {
        ll n1=v[i].second.first;
        ll n2=v[i].second.second;
        ll w=v[i].first;
        if(fin(n1)!=fin(n2))
        {
            s+=w;
            e++;
            cout<<n1<<" "<<n2<<" "<<w<<endl;
            uni(n1,n2);
        }
        i++;
    }
    cout<<s<<endl;
}
