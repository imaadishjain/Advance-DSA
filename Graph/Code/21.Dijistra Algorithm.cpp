#include <bits/stdc++.h>
using namespace std;

// Using Queue
vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> dist(N, 1e9);
    dist[src] = 0;
    vector<int> adj[N];
    queue<int> q;
    q.push(src);

    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    while (!q.empty())
    {
        int u = q.front();
        int wt = dist[u];
        q.pop();

        for (auto it : adj[u])
        {
            if (dist[it] > wt + 1)
            {
                dist[it] = wt + 1;
                q.push(it);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
        {
            dist[i] = -1;
        }
    }

    return dist;
}

// Using Priority Queue

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{

    vector<int> dist(V, 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, S});
    dist[S] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        int dis = pq.top().first;

        pq.pop();

        for (auto it : adj[u])
        {
            int v = it[0];
            int wt = it[1];
            if (dist[v] > dis + wt)
            {
                dist[v] = dis + wt;
                pq.push({dis + wt, v});
            }
        }
    }

    return dist;
}

// Using Set

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{

    vector<int> dist(V, 1e9);

    set<pair<int, int>> st;

    st.insert({0, S});
    dist[S] = 0;

    while (!st.empty())
    {
        auto it = *(st.begin());
        int u = it.second;
        int dis = it.first;

        st.erase(it);

        for (auto it : adj[u])
        {
            int v = it[0];
            int wt = it[1];
            if (dist[v] > dis + wt)
            {
                if (dist[v] != 1e9)
                {
                    st.erase({dist[v], v});
                }
                dist[v] = dis + wt;
                st.insert({dis + wt, v});
            }
        }
    }

    return dist;
}