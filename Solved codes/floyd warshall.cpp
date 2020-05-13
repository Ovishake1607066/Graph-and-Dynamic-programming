#include<bits/stdc++.h>
#define ll long long
#define inf 100000000
using namespace std;
ll adj[100][100];
ll par[100][100];
ll tn,te,n1,n2,w;
ll fun(ll source,ll des)
{
    if(source==des)
    {
        cout<<source;
        return 0;
    }
    fun(source,par[source][des]);
    cout<<" "<<des;
}
int main()
{
    cin>>tn>>te;
    for(ll i=1; i<=tn; i++)
    {
        for(ll j=1; j<=tn; j++)
        {
            if(i==j)
                adj[i][j]=0;
            else
                adj[i][j]=inf;
            par[i][j]=i;
        }
    }
    for(ll i=1; i<=te; i++)
    {
        cin>>n1>>n2>>w;
        adj[n1][n2]=w;
    }
    for(ll k=1; k<=tn; k++)
    {
        for(ll i=1; i<=tn; i++)
        {
            for(ll j=1; j<=tn; j++)
            {
                if(adj[i][k]+adj[k][j]<adj[i][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                    par[i][j]=par[k][j];
                }
            }
        }
    }
    ll source,des;
    cin>>source>>des;
    if(adj[source][des]!=inf)
    {
        cout<<adj[source][des]<<endl;
        fun(source,des);
    }
    else
        cout<<"Path not found"<<endl;
}
/*
5 9
1 2 2
1 3 1
1 5 3
2 4 4
3 2 1
3 5 1
4 1 1
4 3 3
4 5 5
*/

















