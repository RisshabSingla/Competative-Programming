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

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    vector<ll> ans;

    // vector<vector<pair<ll, ll>>> adjList(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        // if (a == b && ans.size() == 0)
        // {
        //     ans.push_back(a);
        //     ans.push_back(b);
        // }
        edges.push_back({a - 1, b - 1, c});
        // adjList[a - 1].push_back({b - 1, c});
    }
    // if (ans.size() > 0)
    // {
    //     cout << "YES\n";
    //     for (auto i : ans)
    //     {
    //         cout << i << " ";
    //     }
    //     return 0;
    // }

    vector<ll> distanceSrc(n, INT_MAX);
    vector<ll> parents(n, 0);

    distanceSrc[0] = 0;
    parents[0] = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll src = edges[j][0];
            ll dest = edges[j][1];
            ll wt = edges[j][2];
            if (distanceSrc[src] + wt < distanceSrc[dest])
            {
                distanceSrc[dest] = distanceSrc[src] + wt;
                parents[dest] = src;
            }
        }
    }
    ll changed = -1;
    for (ll j = 0; j < m; j++)
    {
        ll src = edges[j][0];
        ll dest = edges[j][1];
        ll wt = edges[j][2];
        if (distanceSrc[src] + wt < distanceSrc[dest])
        {
            changed = dest;
            distanceSrc[dest] = distanceSrc[src] + wt;
            parents[dest] = src;
        }
    }

    // for (auto i : distanceSrc)
    // {
    //     cout << i.first << " ";
    // }
    // cout << "\n";

    if (changed == -1)
    {
        cout << "NO\n";
        return 0;
    }

    // cout << "Changed: " << changed << "\n";

    // for (auto i : parents)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    cout << "YES\n";
    vector<ll> cycle;
    ll par = changed;
    for (ll i = 0; i < n; i++)
    {
        par = parents[par];
    }

    // cout << "Par: " << par << "\n";
    // return 0;

    for (ll x = par;; x = parents[x])
    {
        cycle.push_back(x);
        if (x == par && cycle.size() > 1)
        {
            break;
        }
    }
    reverse(cycle.begin(), cycle.end());
    for (auto i : cycle)
    {
        cout << i + 1 << " ";
    }
    // for (auto i : distanceSrc)
    // {
    //     cout << i.first << " " << i.second << "\n";
    // }
    // cout << "\nnode: " << node << "\n";
    // vector<bool> visited(n, false);

    // while (!visited[node])
    // {
    //     ans.push_back(node);
    //     visited[node] = true;
    //     node = distanceSrc[node].second;
    // }
    // ans.push_back(node);
    // reverse(ans.begin(), ans.end());
    // ll front = 0;
    // ll back = ans.size() - 1;

    // while (back >= 0 && ans[front] != ans[back])
    // {
    //     back--;
    // }

    // for (ll i = 0; i <= back; i++)
    // {
    //     cout << ans[i] + 1 << " ";
    // }
    // cout << "\n";
    // for (auto i : ans)
    // {
    //     cout << i + 1 << " ";
    // }
    // cout << "\n";

    return 0;
}