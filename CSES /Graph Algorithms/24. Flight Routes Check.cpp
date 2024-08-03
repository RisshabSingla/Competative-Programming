#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void dfs(vector<vector<ll>> &adjList, vector<bool> &visited, ll node)
{
    visited[node] = true;
    for (auto neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfs(adjList, visited, neighbor);
        }
    }
}

vector<ll> checkPossible(ll n, vector<vector<ll>> &adjList)
{
    for (ll i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        dfs(adjList, visited, i);
        for (ll j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                return {i, j};
            }
        }
    }
    return {};
}

void dfs(ll node, vector<bool> &visited, vector<ll> &topo, vector<vector<ll>> &adjList)
{
    visited[node] = true;
    for (auto neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, topo, adjList);
        }
    }
    topo.push_back(node);
}

void dfs(ll node, vector<vector<ll>> &adjList, vector<bool> &visited)
{
    visited[node] = true;
    for (auto neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adjList(n);
    vector<vector<ll>> revAdjList(n);

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);
        revAdjList[b].push_back(a);
    }

    vector<bool> visited(n, false);
    vector<ll> topo;
    for (ll i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, topo, adjList);
        }
    }
    reverse(topo.begin(), topo.end());

    for (ll i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<ll> scc;
    for (auto node : topo)
    {
        if (!visited[node])
        {
            scc.push_back(node);
            dfs(node, revAdjList, visited);
        }
    }

    if (scc.size() > 1)
    {
        cout << "NO\n";
        cout << scc[1] + 1 << " " << scc[0] + 1 << endl;
    }
    else
    {
        cout << "YES\n";
    }

    // vector<ll> ans = checkPossible(n, adjList);
    // if (ans.size() == 0)
    // {
    //     cout << "YES\n";
    // }
    // else
    // {
    //     cout << "NO\n";
    //     for (auto i : ans)
    //     {
    //         cout << i + 1 << " ";
    //     }
    // }

    return 0;
}