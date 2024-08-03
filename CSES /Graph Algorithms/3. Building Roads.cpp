#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void dfs(int node, vector<vector<ll>> &adjList, vector<bool> &visited)
{
    visited[node] = true;
    for (auto city : adjList[node])
    {
        if (!visited[city])
        {
            dfs(city, adjList, visited);
        }
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
        a--;
        b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    ll count = 0;
    vector<bool> visited(n, false);
    vector<int> clusterHeads;
    for (ll i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            clusterHeads.push_back(i);
            dfs(i, adjList, visited);
            count++;
        }
    }

    if (count == 1)
    {
        cout << count - 1;
        return 0;
    }

    cout << count - 1 << "\n";
    for (ll i = 1; i < count; i++)
    {
        cout << clusterHeads[0] + 1 << " " << clusterHeads[i] + 1 << "\n";
    }

    return 0;
}