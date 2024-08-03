#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

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

void dfs(ll node, vector<vector<ll>> &adjList, vector<bool> &visited, vector<ll> &number, ll parent)
{
    visited[node] = true;
    number[node] = parent;
    for (auto neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adjList, visited, number, parent);
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

    vector<ll> number(n, -1);
    int count = 0;
    for (auto node : topo)
    {
        if (!visited[node])
        {
            dfs(node, revAdjList, visited, number, count);
            count++;
        }
    }
    cout << count << "\n";
    for (auto i : number)
    {
        cout << i + 1 << " ";
    }
    return 0;
}
