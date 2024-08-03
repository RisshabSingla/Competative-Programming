#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// bool dfs(int node, vector<int> &currentPath, vector<bool> &visited, vector<vector<ll>> &adjList, int initial, int parent)
// {
//     for (auto neighbor : adjList[node])
//     {
//         if (neighbor == parent && visited[neighbor])
//         {
//             continue;
//         }
//         if (visited[neighbor])
//         {
//             currentPath.push_back(neighbor);
//             return true;
//         }
//         if (!visited[neighbor])
//         {
//             visited[neighbor] = true;
//             currentPath.push_back(neighbor);
//             bool a = dfs(neighbor, currentPath, visited, adjList, initial, node);
//             if (a)
//             {
//                 return true;
//             }
//             // visited[neighbor] = false;
//             currentPath.pop_back();
//         }
//     }
//     return false;
// }

bool dfs(int node, int par, vector<vector<ll>> &adjList, vector<int> &parent, vector<bool> &visited, int &startVertex, int &endVertex)
{
    visited[node] = true;
    parent[node] = par;
    for (auto neighbor : adjList[node])
    {
        if (neighbor == par)
        {
            continue;
        }
        if (visited[neighbor])
        {
            startVertex = neighbor;
            endVertex = node;
            return true;
        }
        if (!visited[neighbor])
        {
            if (dfs(neighbor, node, adjList, parent, visited, startVertex, endVertex))
            {
                return true;
            }
        }
    }
    return false;
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

    vector<bool> visited(n, false);
    int startVertex = -1;
    int endVertex = -1;
    vector<int> parents(n, -1);
    bool possible = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adjList, parents, visited, startVertex, endVertex))
            {
                possible = true;
                break;
            }
        }
    }

    if (possible)
    {
        vector<int> ans;
        int vert = endVertex;
        ans.push_back(vert);
        while (vert != startVertex)
        {
            ans.push_back(parents[vert]);
            vert = parents[vert];
        }
        ans.push_back(endVertex);
        cout << ans.size() << "\n";
        for (auto i : ans)
        {
            cout << i + 1 << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}