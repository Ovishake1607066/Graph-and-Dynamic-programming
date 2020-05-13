#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll vis[100];
ll s;
vector<vector<pair<ll,ll> > >v(100);
priority_queue<pair<ll,pair<ll,ll> > >pq;
ll fun(ll x)
{
    vis[x]=1;
    for(ll i=0;i<v[x].size();i++)
    {
        if(!vis[v[x][i].first])
        {
            pq.push(make_pair(-v[x][i].second,make_pair(-v[x][i].first,x)));
        }
    }
    return 0;
}
int main()
{
    ifstream in("prims.txt");
    ll tn,n1,n2,w,a,b;
    in>>tn;
    while(in>>n1>>n2>>w)
    {
        v[n1].push_back(make_pair(n2,w));
        v[n2].push_back(make_pair(n1,w));
    }
    /*for(ll i=0;i<tn;i++)
        for(ll j=0;j<v[i].size();j++)
        cout<<i<<" - "<<v[i][j].first<<" "<<v[i][j].second<<endl;*/
    ll source;
    cout<<"Enter Source node "<<endl;
    cin>>source;
    fun(source);
    while(!pq.empty())
    {
        ll w,n,u;
        w=-pq.top().first;
        n=-pq.top().second.first;
        u=pq.top().second.second;
        pq.pop();
        if(!vis[n])
        {
            s+=w;
            fun(n);
            cout<<u<<" "<<n<<" "<<w<<endl;
        }
    }
    cout<<s<<endl;
}
