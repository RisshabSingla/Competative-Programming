#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll dfs(ll src, ll dest, vector<ll> &possible, vector<vector<ll>> &adjList, vector<bool> &visited)
{
    if (src == dest)
    {
        return 1LL;
    }
    if (visited[src])
    {
        return possible[src];
    }
    visited[src] = true;
    ll paths = 0;
    for (auto node : adjList[src])
    {
        ll count = dfs(node, dest, possible, adjList, visited);
        paths += count;
        paths %= mod;
    }

    possible[src] += paths;
    possible[src] %= mod;

    return paths;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adjList(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
    }
    vector<ll> possible(n, 0);
    vector<bool> visited(n, false);

    cout << dfs(0, n - 1, possible, adjList, visited);
    // cout << possible[0] << "\n";
    return 0;
}