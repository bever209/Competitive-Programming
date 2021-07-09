#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

int n; // number of nodes

void search(int start,int k,vector<pii> g[]){ // start node, max size of edges, and adjacency list
    int d[n];
    bool used[n];

    queue<int> bfs[k+1];
    bfs[0].push(start);

    d[start] = 0;
    int pos = 0, num = 1; // I recommend to define a variable num - the number of vertexes that are in the queues
    while (num > 0)
    {
        while (bfs[pos % (k + 1)].empty())
        {
            ++pos;
        }
        int u = bfs[pos % (k + 1)].front();
        bfs[pos % (k + 1)].pop();
        --num;
        if (used[u]) // used vertex can be in other queues
        {
            continue;
        }
        used[u] = true;
        for (pair<int, int> edge : g[u])
        {
            int cost = edge.first, w = edge.second;
            if (d[u] + cost < d[w])
            {
                d[w] = d[u] + cost;
                bfs[d[w] % (k + 1)].push(w);
                ++num;
            }
        }
    }
}
