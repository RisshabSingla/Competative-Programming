#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<ll> dijstras(ll source, vector<vector<pair<ll, ll>>> &adjList, ll n)
{

    vector<ll> dist(n, LLONG_MAX);
    dist[source] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, source});
    while (!pq.empty())
    {
        ll node = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();
        if (dis > dist[node])
            continue;
        for (auto &i : adjList[node])
        {
            if (dist[i.first] > dist[node] + i.second)
            {
                dist[i.first] = dist[node] + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
    return dist;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adjListSrc(n);
    vector<vector<pair<ll, ll>>> adjListDest(n);

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        // edges.push_back({a - 1, b - 1, c});
        adjListSrc[a - 1].push_back({b - 1, c});
        adjListDest[b - 1].push_back({a - 1, c});
    }

    vector<ll> distanceSource = dijstras(0, adjListSrc, n);
    vector<ll> distanceDest = dijstras(n - 1, adjListDest, n);

    ll ans = LLONG_MAX;
    for (ll i = 0; i < n; i++)
    {
        if (distanceSource[i] == LLONG_MAX)
        {
            continue;
        }
        for (auto &edge : adjListSrc[i])
        {
            if (distanceDest[edge.first] == LLONG_MAX)
            {
                continue;
            }
            ans = min(ans, (distanceSource[i] + (edge.second / 2) + distanceDest[edge.first]));
        }
    }
    cout << ans << "\n";

    // ll n, m;
    // cin >> n >> m;
    // vector<vector<ll>> edges;

    // for (ll i = 0; i < m; i++)
    // {
    //     ll a, b, c;
    //     cin >> a >> b >> c;
    //     edges.push_back({a - 1, b - 1, c});
    //     // adjList[a - 1].push_back({b - 1, c});
    // }

    // vector<ll> distanceSrc(n, INT_MAX);
    // distanceSrc[0] = 0;
    // vector<ll> distanceDest(n, INT_MAX);
    // distanceDest[n - 1] = 0;
    // for (ll i = 0; i < n - 1; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         ll src = edges[j][0];
    //         ll dest = edges[j][1];
    //         ll wt = edges[j][2];
    //         if (distanceSrc[src] != INT_MAX && distanceSrc[src] + wt < distanceSrc[dest])
    //         {
    //             distanceSrc[dest] = distanceSrc[src] + wt;
    //         }

    //         if (distanceDest[src] != INT_MAX && distanceDest[src] + wt < distanceDest[dest])
    //         {
    //             distanceDest[dest] = distanceDest[src] + wt;
    //         }
    //     }
    // }

    // ll ans = distanceSrc[n - 1];
    // for (ll i = 0; i < m; i++)
    // {
    //     ll src = edges[i][0];
    //     ll dest = edges[i][1];
    //     ll wt = edges[i][2];
    // }

    // for (auto i : distance)
    // {
    //     cout << i.first << " " << i.second << "\n";
    // }
    // cout << "\n";
    // ll current = n - 1;

    // vector<ll> path;
    // while (current != 0)
    // {
    //     path.push_back(distance[current].first);
    //     current = distance[current].second;
    // }
    // path.push_back(0);
    // for (auto i : path)
    // {
    //     cout << i << " ";
    // }
    // vector<ll> costs;
    // for (ll i = 0; i < path.size() - 1; i++)
    // {
    //     costs.push_back(abs(path[i] - path[i + 1]));
    // }
    // ll maxi = 0;
    // for (auto i : costs)
    // {
    //     // cout << i << " ";
    //     maxi = max(maxi, i);
    // }

    // ll ans = distance[n - 1].first - maxi + maxi / 2;
    // cout << ans << "\n";
    // cout << "\n";

    return 0;
}