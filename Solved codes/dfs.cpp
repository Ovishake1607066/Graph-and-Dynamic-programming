#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll chk[100];
vector<vector<ll> >adj(100);
void dfs(ll n,vector<vector<ll> >adj)
{
    chk[n]=1;
    for(ll i=0;i<adj[n].size();i++)
    {
        if(!chk[adj[n][i]])
        {
            cout<<adj[n][i]<<" ";
            dfs(adj[n][i],adj);
        }
    }
}
int main()
{
    ll tn,n1,n2;
    cin>>tn;
    for(ll i=0;i<tn;i++)
    {
        cin>>n1>>n2;
        adj[n1].push_back(n2);
    }
    cout<<1<<endl;
    dfs(1,adj);
}
/*
8
1 2
1 4
1 5
2 3
4 6
5 6
6 7
7 8
*/
