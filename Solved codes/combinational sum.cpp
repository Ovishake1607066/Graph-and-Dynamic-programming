#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll res[100][100],a[100],sum,r,c,cou,n;
/*4
2 4 6 8
8*/
vector<ll>temp;
vector<ll>cnt;
void func(ll pos,ll s2)
{
    if(pos>=n)
        return ;
    cout<<pos<<" "<<s2<<endl;
    if(s2+a[pos]<=sum)
    {
        if(s2+a[pos]==sum)
        {
            temp.push_back(a[pos]);
            if(temp.size()>c)
                c=temp.size();
            for(ll i=0;i<temp.size();i++)
                cout<<temp[i]<<" ";
            cout<<endl;
            for(ll i=0; i<temp.size(); i++)
                res[r][i]=temp[i];
            r++;
            temp.pop_back();
            func(pos+1,s2);
        }
        else
        {
            if(cou==pos)
                cnt.push_back(a[pos]);
            temp.push_back(a[pos]);
            s2+=a[pos];
            func(pos,s2);
        }
    }
    else
    {
        if(cnt.size()==0)
            return ;
        s2-=cnt[cnt.size()-1];
        cnt.pop_back();
        if(pos==cou)
            pos++;
        temp[cnt.size()-1]=0;
        if(cnt.size()==0)
        {
            cnt.clear();
            temp.clear();
            cou++;
            pos=cou;
            s2=0;
        }
        func(pos,s2);
    }
}
int main()
{
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>sum;
    func(0,0);
    for(ll i=0;i<r;i++)
    {
        for(ll j=0;j<c;j++)
        {
            if(res[i][j]==0)
                continue;
            else
                cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }


}
