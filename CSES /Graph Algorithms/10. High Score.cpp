#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;
const ll INF = 1e17;
const ll NINF = INF * (-1);

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    // vector<vector<pair<int, int>>> neighbors(n);
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a - 1, b - 1, -c});
    }

    if (n == 1)
    {
        if (m == 1 && edges[0][2] == 1)
        {
            cout << "0\n";
        }
        else
        {
            cout << "-1\n";
        }
        return 0;
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll weight = edges[j][2];
            if (dist[u] == INF)
            {
                continue;
            }
            dist[v] = min(dist[v], weight + dist[u]);
            dist[v] = max(dist[v], NINF);
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (dist[u] == INF)
            {
                continue;
            }
            dist[v] = max(dist[v], NINF);
            if (dist[u] + weight < dist[v])
            {
                dist[v] = NINF;
            }
        }
    }

    // for (auto i : dist)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    if (dist[n - 1] == NINF)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[n - 1] * (-1) << endl;

    return 0;
}