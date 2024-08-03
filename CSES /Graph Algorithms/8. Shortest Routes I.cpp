#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> neighbors(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        neighbors[a - 1].push_back({b - 1, c});
    }

    vector<ll> dist(n, LLONG_MAX);

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        const auto [cdist, node] = pq.top();
        pq.pop();
        if (cdist != dist[node])
        {
            continue;
        }
        for (const pair<int, int> &i : neighbors[node])
        {
            if (cdist + i.second < dist[i.first])
            {
                pq.push({dist[i.first] = cdist + i.second, i.first});
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << dist[i] << ' ';
    }
    cout << dist[n - 1] << endl;

    // ll n, m;
    // cin >> n >> m;
    // vector<vector<pair<int, int>>> adjList(n);
    // // vector<vector<int>> edges;
    // for (int i = 0; i < m; i++)
    // {
    //     int a, b, c;
    //     cin >> a >> b >> c;
    //     // edges.push_back({a - 1, b - 1, c});
    //     adjList[a - 1].push_back({b - 1, c});
    // }
    // vector<ll> dist(n, LLONG_MAX);
    // dist[0] = 0;

    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // pq.push({0, 0});
    // while (!pq.empty())
    // {
    //     int node = pq.top().second;
    //     int dis = pq.top().first;
    //     pq.pop();
    //     if (dis > dist[node])
    //         continue;
    //     for (auto &i : adjList[node])
    //     {
    //         if (dist[i.first] > dist[node] + i.second)
    //         {
    //             dist[i.first] = dist[node] + i.second;
    //             pq.push({dist[i.first], i.first});
    //         }
    //     }
    // }

    // for (auto &i : dist)
    // {
    //     cout << i << " ";
    // }

    // set<pair<int, int>> st;
    // st.insert({0, 0});

    // while (!st.empty())
    // {
    //     int src = st.begin()->second;
    //     st.erase(st.begin());
    //     for (auto i : adjList[src])
    //     {
    //         int dest = i.first;
    //         int wt = i.second;
    //         if (dist[dest] > dist[src] + wt)
    //         {
    //             if (dist[dest] != LLONG_MAX)
    //             {
    //                 st.erase({dist[dest], dest});
    //             }
    //             dist[dest] = dist[src] + wt;
    //             st.insert({dist[dest], dest});
    //         }
    //     }
    // }

    // priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    // pq.push({0, 0});
    // while (!pq.empty())
    // {
    //     int src = pq.top().second;
    //     pq.pop();
    //     for (auto i : adjList[src])
    //     {
    //         int dest = i.first;
    //         int wt = i.second;
    //         if (dist[dest] > dist[src] + wt)
    //         {
    //             dist[dest] = dist[src] + wt;
    //             pq.push({dist[dest], dest});
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (auto edge : edges)
    //     {
    //         int src = edge[0];
    //         int dest = edge[1];
    //         int wt = edge[2];
    //         if (distances[src] != LLONG_MAX && distances[src] + wt < distances[dest])
    //         {
    //             distances[dest] = distances[src] + wt;
    //         }
    //     }
    // }

    // for (auto &i : dist)
    // {
    //     cout << i << " ";
    // }

    // return 0;
}