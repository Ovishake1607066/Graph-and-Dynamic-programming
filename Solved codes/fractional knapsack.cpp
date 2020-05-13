#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll,ll> >v;
priority_queue<pair<ll,ll> >pq;
int main()
{
    ll capacity,weight,profit,inputnumber;
    cin>>capacity;
    cin>>inputnumber;
    v.push_back(make_pair(0,0));
    for(ll i=0;i<inputnumber;i++)
    {
        cin>>weight>>profit;
        v.push_back(make_pair(weight,profit));
    }
    for(ll i=1;i<=inputnumber;i++)
    {
        pq.push(make_pair(v[i].second/v[i].first,i));
    }
    ll tprofit=0,uprofit;
    while(!pq.empty() && capacity)
    {
        pair<ll,ll>p;
        p=pq.top();
        pq.pop();
        if(v[p.second].first<=capacity)
        {
            capacity-=v[p.second].first;
            tprofit+=v[p.second].second;
        }
        else
        {
            tprofit+=capacity*p.first;
            capacity=0;
        }
    }
    cout<<tprofit<<endl;
}
/*
10
5
4 12
8 32
2 40
6 30
1 50
*/
