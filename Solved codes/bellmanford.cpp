#include<bits/stdc++.h>
#define ll long long
#define inf 10000000
using namespace std;
ll tn,n1,n2,w,source,edge;
vector<vector<pair<ll,ll> > >adj(100);
vector<ll>par;
vector<ll>dis;
vector<ll>chk;
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
        chk.push_back(source);
        return 0;
    }
    fun(par[x]);
    chk.push_back(x);
    cout<<" "<<x;
}
int main()
{
    cin>>tn;
    cin>>edge;
    for(ll i=0; i<edge; i++)
    {
        cin>>n1>>n2>>w;
        adj[n1].push_back(make_pair(n2,w));
    }
    cout<<"source"<<endl;
    cin>>source;
    par.assign(tn,-1);
    dis.assign(tn,10000000);
    dis[source]=0;
    for(ll i=0; i<tn-1; i++)
    {
        for(ll u=0; u<tn; u++)
        {
            for(ll j=0; j<adj[u].size(); j++)
            {
                pair<ll,ll> v=adj[u][j];
                if(dis[u]==10000000 || v.second==10000000)
                    continue;
                if(dis[u]+v.second<dis[v.first])
                {
                    dis[v.first]=dis[u]+v.second;
                    par[v.first]=u;
                }
            }
        }
    }
    ll check =0;
    for(ll u=0; u<tn; u++)
    {
        for(ll j=0; j<adj[u].size(); j++)
        {
            pair<ll,ll> v=adj[u][j];
            if(dis[u]==10000000 || v.second==10000000)
                continue;
            if(dis[u]+v.second<dis[v.first])
            {
                check =1;
                break;
            }
        }
        if(check)
            break;
    }
    if(check)
    {
        cout<<"IT has negative cycle"<<endl;
    }
    else
    {
        ll res;
        cin>>res;
        cout<<dis[res]<<endl;
        fun(res);
        /*par.assign(tn,-1);
        dis.assign(tn,10000000);
        for(ll i=0; i<chk.size()-1; i++)
        {
            for(ll j=0;j<adj[chk[i]].size();j++)
            {
                if(adj[chk[i]][j].first==chk[i+1])
                {
                    adj[chk[i]][j].second=10000000;
                    break;
                }
            }
        }
        dis[source]=0;
        for(ll i=0; i<tn-1; i++)
        {
            for(ll u=0; u<tn; u++)
            {
                for(ll j=0; j<adj[u].size(); j++)
                {
                    pair<ll,ll> v=adj[u][j];
                    if(dis[u]==10000000 || v.second==10000000)
                        continue;
                    if(dis[u]+v.second<dis[v.first])
                    {
                        dis[v.first]=dis[u]+v.second;
                        par[v.first]=u;
                    }
                }
            }
        }
        ll check =0;
        for(ll u=0; u<tn; u++)
        {
            for(ll j=0; j<adj[u].size(); j++)
            {
                pair<ll,ll> v=adj[u][j];
                if(dis[u]==10000000 || v.second==10000000)
                    continue;
                if(dis[u]+v.second<dis[v.first])
                {
                    check =1;
                    break;
                }
            }
            if(check)
                break;
        }
        if(check)
        {
            cout<<"IT has negative cycle"<<endl;
        }
        else
        {
            cout<<"Second shortest path"<<endl;
            cout<<dis[res]<<endl;
            fun(res);
        }*/
    }
}
/*5 10
0 1 -1
0 2 2
0 3 4
1 0 2
1 2 3
2 3 5
2 4 3
3 2 -1
4 3 4
4 1 -3
0 3 */
