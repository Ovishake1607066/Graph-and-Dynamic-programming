#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll,ll> >v;
ll pa[100][100];
ll ta[100][100];
int func(ll n,ll k)
{
    ll select=ta[n][k];

    if(n<=0 || k<=0)
        return 0;
    else if(n==select)
    {
        func(--n,k-(v[select].second));
    }
    else
    {
        select=0;
        func(--n,k);
    }
    if(select)
        cout<<select<<endl;
}
int main()
{
    ll capacity,weight,profit,inputnumber;
    cin>>capacity;
    cin>>inputnumber;
    v.push_back(make_pair(0,0));
    for(ll i=1; i<=inputnumber; i++)
    {
        cin>>weight>>profit;
        v.push_back(make_pair(weight,profit));
    }
    for(ll i=1; i<=inputnumber; i++)
    {
        for(ll j=1; j<=capacity; j++)
        {
            pair<ll,ll>p=v[i];
            if(p.second>j)
            {
                pa[i][j]=pa[i-1][j];
                ta[i][j]=ta[i-1][j];
            }
            else
            {
                ll newprofit=p.first+pa[i-1][j-p.second];
                if(newprofit>pa[i-1][j])
                {
                    pa[i][j]=newprofit;
                    ta[i][j]=i;
                }
                else
                {
                    pa[i][j]=pa[i-1][j];
                    ta[i][j]=ta[i-1][j];
                }
            }
        }
    }
    cout<<pa[inputnumber][capacity]<<endl;
    func(inputnumber,capacity);
}
/*
8
4
15 1
10 5
9 3
5 4
*/
