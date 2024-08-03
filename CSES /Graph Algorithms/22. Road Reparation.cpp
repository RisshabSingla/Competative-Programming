#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, m;
    cin >> n >> m;
    // vector<vector<ll>> edges(m);
    vector<vector<pair<ll, ll>>> adjList(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        // edges[i] = {a, b, c};
        adjList[a - 1].push_back({b - 1, c});
        adjList[b - 1].push_back({a - 1, c});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    vector<bool> visited(n, false);

    pq.push({0, 0});
    ll ans = 0;
    while (!pq.empty())
    {
        pair<ll, ll> top = pq.top();
        pq.pop();
        if (visited[top.second])
        {
            continue;
        }
        visited[top.second] = true;
        ans += top.first;
        for (auto &edge : adjList[top.second])
        {
            if (!visited[edge.first])
            {
                pq.push({edge.second, edge.first});
            }
        }
    }
    bool possible = true;
    for (auto i : visited)
    {
        if (!i)
        {
            possible = false;
            break;
        }
        // cout << i << " ";
    }

    if (!possible)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    // cout << "\n";

    cout << ans << "\n";

    return 0;
}