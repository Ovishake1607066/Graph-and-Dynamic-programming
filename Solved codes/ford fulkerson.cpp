#include<bits/stdc++.h>
using namespace std;
#define V 6
#define ll long long
vector<ll>cont;
bool bfs(ll rGraph[V][V], ll s, ll t, ll parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue <ll> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        for (ll v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}
ll fordFulkerson(ll graph[V][V], ll s, ll t)
{
    ll u, v;
    ll rGraph[V][V];

    for (ll u = 0; u < V; u++)
        for (ll v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    ll parent[V];

    ll max_flow = 0;
    while (bfs(rGraph, s, t, parent))
    {
        ll path_flow = INT_MAX;
        for (ll v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            cont.push_back(v);
            path_flow = min(path_flow, rGraph[u][v]);
        }
        cont.push_back(s);
        reverse(cont.begin(),cont.end());
        for(ll i=0; i<cont.size(); i++)
        {
            cout<<cont[i]<<" ";
        }
        cout<<endl;
        cont.clear();
        for (ll v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    ll graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
}

