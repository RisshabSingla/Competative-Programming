#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void dijkstra(vector<vector<pair<ll, ll>>> &adjList, vector<ll> &dist, vector<ll> &minFlights, vector<ll> &maxFlights, vector<ll> &possible)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    possible[0] = 1;
    while (!pq.empty())
    {
        ll wt = pq.top().first;
        ll src = pq.top().second;
        pq.pop();
        if (wt > dist[src])
        {
            continue;
        }
        for (auto edge : adjList[src])
        {
            ll dest = edge.first;
            ll cost = edge.second;
            if (cost + wt > dist[dest])
            {
                continue;
            }
            if (cost + wt == dist[dest])
            {
                possible[dest] += possible[src];
                possible[dest] %= mod;
                minFlights[dest] = min(minFlights[src] + 1, minFlights[dest]);
                maxFlights[dest] = max(maxFlights[src] + 1, maxFlights[dest]);
            }
            if (cost + wt < dist[dest])
            {
                dist[dest] = cost + wt;
                possible[dest] = possible[src];
                minFlights[dest] = minFlights[src] + 1;
                maxFlights[dest] = maxFlights[src] + 1;
                pq.push({dist[dest], dest});
            }
        }
    }
}

// pair<ll, ll> dfs(ll src, ll dest, vector<vector<ll>> &adjList, vector<pair<ll, ll>> &dist, vector<bool> &visited)
// {
//     if (src == dest)
//     {
//         return {1, 1};
//     }

// }

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adjList(n);
    // vector<vector<ll>> edges;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        // edges.push_back({a - 1, b - 1, c});
        adjList[a - 1].push_back({b - 1, c});
    }

    vector<ll> possible(n, 0);
    vector<ll> dist(n, LLONG_MAX);
    vector<bool> visited(n, false);
    vector<ll> maxFlights(n, 0);
    vector<ll> minFlights(n, 0);
    dist[0] = 0;
    dijkstra(adjList, dist, minFlights, maxFlights, possible);

    cout << dist[n - 1] << " " << possible[n - 1] << " " << minFlights[n - 1] << " " << maxFlights[n - 1];

    return 0;
}