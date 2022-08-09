#include <bits/stdc++.h>
using namespace std;
void dfs(int s,vector<int> adj[],bool visited[])
{
    visited[s] = 1;
    cout << s;
    for(int i = 0;i < adj[s].size();i++)
    {
        if(visited[adj[s][i]] == 0)
        {
            dfs(adj[s][i],adj,visited);
        }
    }

}
int main()
{
    bool visited[100];
    for(int i = 0;i < 100;i++)
    {
        visited[i] = 0;
    }
    int i,n,e,x,y,s;
    cout << "Number of vertexes: ";
    cin >> n;
    vector <int> adj[n];
    cout << "Number of total edges: ";
    cin >> e;
    for(i = 0;i < e;i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << "Enter source vertex: ";
    cin >> s;
    dfs(s,adj,visited);
    return 0;
}
