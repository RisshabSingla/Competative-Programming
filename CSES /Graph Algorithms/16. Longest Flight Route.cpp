#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void dfs(ll src, ll n, vector<vector<ll>> &adjList, vector<ll> &dp, vector<ll> &nextNode, vector<bool> &visited)
{
    visited[src] = true;
    for (auto node : adjList[src])
    {
        if (!visited[node])
        {
            dfs(node, n, adjList, dp, nextNode, visited);
        }
        if (dp[node] != -1 && dp[src] < 1 + dp[node])
        {
            dp[src] = 1 + dp[node];
            nextNode[src] = node;
        }
        visited[node] = true;
    }
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

    vector<ll> dp(n, -1);
    dp[n - 1] = 1;
    vector<ll> nextNode(n, 0);
    nextNode[n - 1] = n - 1;
    vector<bool> visited(n, false);

    dfs(0, n, adjList, dp, nextNode, visited);

    if (dp[0] == -1 || !visited[n - 1])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dp[0] << "\n";
    vector<ll> ans;
    ll curr = 0;
    while (curr != n - 1)
    {
        ans.push_back(curr);
        curr = nextNode[curr];
    }
    ans.push_back(n - 1);
    for (auto i : ans)
    {
        cout << i + 1 << " ";
    }
    return 0;
}