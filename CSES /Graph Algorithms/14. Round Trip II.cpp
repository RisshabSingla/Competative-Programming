#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// bool dfs(vector<vector<ll>> &adjList, ll n, ll src, vector<bool> &visited, vector<ll> &ans)
// {
//     visited[src] = true;
//     for (auto &node : adjList[src])
//     {
//         ans.push_back(node);
//         if (visited[node])
//         {
//             return true;
//         }

//         if (dfs(adjList, n, node, visited, ans))
//         {
//             return true;
//         }
//         ans.pop_back();
//     }
//     visited[src] = false;
//     return false;
// }

bool dfs(ll src, ll n, vector<bool> &visited, vector<ll> &path, vector<vector<ll>> &adjList, vector<bool> &inPath)
{
    visited[src] = true;
    path.push_back(src);
    inPath[src] = true;
    for (auto node : adjList[src])
    {
        if (!visited[node])
        {
            if (dfs(node, n, visited, path, adjList, inPath))
            {
                return true;
            }
        }
        if (inPath[node])
        {
            path.push_back(node);
            return true;
        }
    }

    path.pop_back();
    inPath[src] = false;
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
        adjList[a - 1].push_back(b - 1);
        // edges.push_back({a - 1, b - 1, c});
    }

    vector<bool> visited(n, false);
    vector<bool> inPath(n, false);

    vector<ll> path;

    for (ll i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, n, visited, path, adjList, inPath))
            {
                break;
            }
        }
    }

    if (path.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<ll> ans;
    ll temp = path.back();
    ans.push_back(temp);
    for (ll i = path.size() - 2; i >= 0; i--)
    {
        ans.push_back(path[i]);
        if (ans.back() == temp)
        {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto node : ans)
    {
        cout << node + 1 << " ";
    }

    // vector<ll> ans;
    // vector<bool> visited(n, false);
    // visited[0] = true;

    // dfs(adjList, n, 0, visited, ans);

    // ll last = ans.back();
    // vector<ll> fAns;
    // fAns.push_back(last);

    // for (ll i = ans.size() - 2; i >= 0; i--)
    // {
    //     fAns.push_back(ans[i]);
    //     if (ans[i] == last)
    //     {
    //         break;
    //     }
    // }
    // reverse(fAns.begin(), fAns.end());
    // for (auto i : fAns)
    // {
    //     cout << i << ' ';
    // }
    return 0;
}