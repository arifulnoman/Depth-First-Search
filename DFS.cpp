#include <bits/stdc++.h>
using namespace std;
int dis[100],fin[100],colour[100],parent[100],tim = 0;
vector<int> adj[100];
void dfs(int u)
{
    tim = tim + 1;
    colour[u] = 1;
    dis[u] = tim;
    for(int i = 0;i < adj[u].size();i++)
    {
        int v = adj[u][i];
        if(colour[v] == 0)
        {
            parent[v] = u;
            cout << u << " -> " << v << endl;
            dfs(v);
        }
        tim = tim + 1;
        fin[v] = tim;
        colour[v] = 2;
    }
}
void initialize(int vertex)
{
    int i;
    for(i = 0;i < vertex;i++)
    {
        colour[i] = 0;
        dis[i] = 99999;
        fin[i] = 99999;
        parent[i] = -1;
    }
}
int main()
{
    int vertex,edge,u,v,i,source;
    cin >> vertex >>edge;
    for(i = 0;i < edge;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    initialize(vertex);
    cout << "Source node: ";
    cin >> source;
    dfs(source);
    return 0;
}