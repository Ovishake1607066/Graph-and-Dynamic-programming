#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll chk[1000000];
ll lev[1000000];
vector<vector<ll> >adj(1000000);
int main()
{
    ll tn,n1,n2,k,mx=0,aa=0,bb=0;
    cin>>tn>>k;
    vector<ll>v;
    for(ll i=0; i<tn-1; i++)
    {
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    queue<ll>q;
    ll c=0;
    q.push(1);
    chk[1]=1;
    lev[1]=0;
    ll x;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        c++;
        for(ll i=0; i<adj[x].size(); i++)
        {
            if(!chk[adj[x][i]])
            {
                chk[adj[x][i]]=1;
                q.push(adj[x][i]);
                lev[adj[x][i]]=lev[x]+1;
                mx=max(mx,lev[adj[x][i]]);
            }
        }
    }
    for(ll i=1; i<=tn; i++)
    {
        aa=0;
        cout<<lev[i]<<endl;
    }

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
