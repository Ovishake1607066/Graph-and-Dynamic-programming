#include<bits/stdc++.h>
#define ll long long
#define loop for(ll i=0;i<n;i++)
#define loop2 for(ll j=0;j<m1;j++)
using namespace std;
ll a[4][4],p1,p2,c;
void func(ll p1,ll p2)
{
    if(c==16)
        return;
    cout<<p1<<p2<<endl;
    a[p1][p2]=1;
    c=0;
    for(ll i=0; i<4; i++)
    {
        for(ll j=0; j<4; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    for(ll i=0; i<4; i++)
        for(ll j=0; j<4; j++)
            if(a[i][j]==1)
                c++;
    cout<<endl<<endl;
    if(c==16)
        {
            return;
        }
    if(p1+2<4  && p2+1<4 && a[p1+2][p2+1]==0)
    {
        func(p1+2,p2+1);
            if(c==16)
        return;
        a[p1+2][p2+1]=0;
    }
    if(p1+2<4 && p2-1>=0 && a[p1+2][p2-1]==0)
    {
        func(p1+2,p2-1);
            if(c==16)
        return;
        a[p1+2][p2-1]=0;
    }
    if(p1+1<4 && p2+2<4 && a[p1+1][p2+2]==0)
    {
        func(p1+1,p2+2);
            if(c==16)
        return;
        a[p1+1][p2+2]=0;
    }
    if(p1-1>=0 && p2+2<4 && a[p1-1][p2+2]==0)
    {
        func(p1-1,p2+2);
            if(c==16)
        return;
        a[p1-1][p2+2]=0;
    }
    if(p1-2>=0  && p2-1>=0 && a[p1-2][p2-1]==0)
    {
        func(p1-2,p2-1);
            if(c==16)
        return;
        a[p1-2][p2-1]=0;
    }
    if(p1-2>=0 && p2+1<4 && a[p1-2][p2+1]==0)
    {
        func(p1-2,p2+1);
            if(c==16)
        return;
        a[p1-2][p2+1]=0;
    }
    if(p1-1>=0 && p2-2>=0 && a[p1-1][p2-2]==0)
    {
        func(p1-1,p2-2);
            if(c==16)
        return;
        a[p1-1][p2-2]=0;
    }
    if(p1+1<4 && p2-2>=0 && a[p1+1][p2-2]==0)
    {
        func(p1+1,p2-2);
            if(c==16)
        return;
        a[p1+1][p2-2]=0;
    }
}
int main()
{
    func(0,0);
    for(ll i=0; i<4; i++)
    {
        for(ll j=0; j<4; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
