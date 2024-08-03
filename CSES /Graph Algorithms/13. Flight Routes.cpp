#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> adjList(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adjList[a - 1].push_back({b - 1, c});
        // edges.push_back({a - 1, b - 1, c});
    }

    vector<vector<ll>> dist(n, vector<ll>(k, LLONG_MAX));

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[0][0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        ll cost = pq.top().first;
        ll src = pq.top().second;
        pq.pop();

        if (dist[src][k - 1] < cost)
        {
            continue;
        }
        for (auto &edge : adjList[src])
        {
            ll dest = edge.first;
            ll wt = edge.second;

            if (dist[dest][k - 1] > cost + wt)
            {
                dist[dest][k - 1] = cost + wt;
                pq.push({dist[dest][k - 1], dest});
                sort(dist[dest].begin(), dist[dest].end());
            }
        }
    }

    for (auto &i : dist[n - 1])
    {
        cout << i << " ";
    }

    // vector<multiset<pair<ll, ll>>> dist(n, {{INT_MAX, 0}});
    // dist[0].insert({0, 0});
    // for (ll i = 0; i < n - 1; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         ll src = edges[j][0];
    //         ll dest = edges[j][1];
    //         ll wt = edges[j][2];
    //         for (auto i : dist[src])
    //         {
    //             if (i.first == INT_MAX)
    //             {
    //                 continue;
    //             }
    //             dist[dest].insert({i.first + wt, src});
    //         }

    //         while (dist[src].size() > k)
    //         {
    //             dist[src].erase(*(dist[src].rbegin()));
    //         }
    //     }
    // }

    // for (auto i : dist)
    // {

    //     for (auto j : i)
    //     {
    //         cout << j.first << " " << j.second << "\n";
    //     }
    //     cout << "\n";
    // }

    // vector<ll> ans;
    // for (auto i : dist[n - 1])
    // {
    //     ans.push_back(i.first);
    // }
    // for (int i = 0; i < ans.size() && i < k; i++)
    // {
    //     cout << ans[i] << " ";
    // }
    return 0;
}