#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    int parent[n], key[n], mstSet[n];
    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    for (int count = 0; count < n - 1; count++)
    {
        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u, key[v] = weight;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << "---" << i << "\n";
    }
}