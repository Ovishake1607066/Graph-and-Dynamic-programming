`q  #include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXC 1000
string s1,s2,ans;
ll dp[MAXC][MAXC];
ll visited[MAXC][MAXC];
ll printLCS(ll i,ll j)
{
    if(i>=s1.size() || j>=s2.size())
       {
           cout<<ans<<endl;
           return 0;
       }
       if(s1[i]==s2[j])
       {
           ans=ans+s1[i];
           printLCS(i+1,j+1);
       }
       else
       {
           if(dp[i+1][j]>dp[i][j+1])
                printLCS(i+1,j);
           else
            printLCS(i,j+1);
       }
}
ll calcLCS(ll i,ll j)
{
    if(i>=s1.size() || j>=s2.size())
        return 0;
    if(visited[i][j])
        return dp[i][j];
    ll ans=0;
    if(s1[i]==s2[j])
        ans=1+calcLCS(i+1,j+1);
    else
    {
        ll val1=calcLCS(i+1,j);
        ll val2=calcLCS(i,j+1);
        ans=max(val1,val2);
    }
    visited[i][j]=1;
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
    cin>>s1>>s2;
    cout<<calcLCS(0,0)<<endl;
    printLCS(0,0);
    return 0;
}
/*
HELLOM
HMLLD
*/
