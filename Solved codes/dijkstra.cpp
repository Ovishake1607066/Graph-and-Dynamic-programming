#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll tn,n1,n2,w,source,edge;
vector<vector<pair<ll,ll> > >adj(100);
vector<ll>par;
vector<ll>dis;
vector<ll>co;
priority_queue<pair<ll,ll> >pq;
ll fun(ll x)
{
    if(x!=source && par[x]==-1)
    {
        cout<<"path not found"<<endl;
        return 0;
    }
    else if(x==source)
    {
        cout<<source;
        co.push_back(x);
        return 0;
    }
    fun(par[x]);
    co.push_back(x);
    cout<<" "<<x;
}
int main()
{
    cin>>tn;
    cin>>edge;
    for(ll i=1; i<=edge; i++)
    {
        cin>>n1>>n2>>w;
        adj[n1].push_back(make_pair(n2,w));
        adj[n2].push_back(make_pair(n1,w));
    }
    cout<<"source"<<endl;
    cin>>source;
    par.assign(tn+1,-1);
    dis.assign(tn+1,10000000);
    dis[source]=0;
    pq.push(make_pair(-0,-source));
    while(!pq.empty())
    {
        pair<ll,ll>p2=pq.top();;
        pq.pop();
        ll d=-p2.first;
        ll u=-p2.second;
        if(d>dis[u])
            continue;
        else
        {
            for(ll i=0; i<adj[u].size(); i++)
            {
                pair<ll,ll>p3;
                p3=adj[u][i];
                if(dis[u]+p3.second<dis[p3.first])
                {
                    dis[p3.first]=dis[u]+p3.second;
                    par[p3.first]=u;
                    pq.push(make_pair(-dis[p3.first],-p3.first));
                }
            }
        }
    }
    ll res;
    cin>>res;
    cout<<dis[res]<<endl;
    fun(res);
    cout<<endl;
    for(ll h=0; h<co.size()-1; h++)
    {
        for(ll i=0; i<adj[co[h]].size(); i++)
        {
            pair<ll,ll>p3;
            p3=adj[co[h]][i];
            if(p3.first==co[h+1])
            {
                adj[co[h]][i].second=10000000;
                break;
            }
        }
    }
    par.assign(tn+1,-1);
    dis.assign(tn+1,10000000);
    dis[source]=0;
    pq.push(make_pair(-0,-source));
    while(!pq.empty())
    {
        pair<ll,ll>p2=pq.top();;
        pq.pop();
        ll d=-p2.first;
        ll u=-p2.second;
        if(d>dis[u])
            continue;
        else
        {
            for(ll i=0; i<adj[u].size(); i++)
            {
                pair<ll,ll>p3;
                p3=adj[u][i];
                if(dis[u]+p3.second<dis[p3.first])
                {
                    dis[p3.first]=dis[u]+p3.second;
                    par[p3.first]=u;
                    pq.push(make_pair(-dis[p3.first],-p3.first));
                }
            }
        }
    }
    cout<<"SECOND SHORTEST PATH"<<endl;
    cout<<dis[res]<<endl;
    fun(res);
}
/*3 3
1 2 20
1 3 10
2 3 5*/
