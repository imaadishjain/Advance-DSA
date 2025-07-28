
#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<bool> visi(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    int ans = 0;

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int v = pq.top().second;

        pq.pop();

        if (visi[v] == 1)
        {
            continue;
        }
        visi[v] = true;
        ans += distance;

        for (auto it : adj[v])
        {
            if (!visi[it[0]])
            {
                pq.push({it[1], it[0]});
            }
        }
    }

    return ans;
}