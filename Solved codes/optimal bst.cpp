#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m[100][100];
ll co;
ll f(ll x,ll y)
{
    if(co<3)
        cout<<m[x][y]<<endl;
     co++;
     if(co>=3)
        return 0;
     if(m[x][y]>=1)
        f(0,m[x][y]-1);
     if(m[x][y]<3)
        f(m[x][y],y);
}
int sum(int freq[], int i, int j);

int optimalSearchTree(int keys[], int freq[], int n)
{
    int cost[n][n];

    for (int i = 0; i < n; i++)
    {
        cost[i][i] = freq[i];
        m[i][i]=i;
    }

    for (int L=2; L<=n; L++)
    {

        for (int i=0; i<=n-L+1; i++)
        {

            int j = i+L-1;
            cost[i][j] = INT_MAX;


            for (int r=i; r<=j; r++)
            {
                int c = ((r > i)? cost[i][r-1]:0) +
                        ((r < j)? cost[r+1][j]:0) +
                        sum(freq, i, j);
                if (c < cost[i][j])
                {
                    cost[i][j] = c;
                    m[i][j]=r;
                }
            }
        }
    }
    return cost[0][n-1];
}

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
        s += freq[k];
    return s;
}

int main()
{
    memset(m, -1, sizeof m);
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<("Cost of Optimal BST is %d ",
           optimalSearchTree(keys, freq, n))<<endl;
    for(ll i=0; i<3; i++)
    {
        for(ll j=0; j<3; j++)
            cout<<m[i][j];
        cout<<endl;
    }
    ll x=0;
    ll y=n-1;
    f(x,y);
}
