#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll dfs(ll node, vector<vector<ll>> &tree, vector<bool> &visited, vector<ll> &children)
{
    if (tree[node].size() == 0)
    {
        return 1;
    }
    ll count = 0;
    for (auto neighbor : tree[node])
    {
        visited[neighbor] = true;
        count += dfs(neighbor, tree, visited, children);
    }
    children[node] = count;
    return count + 1;
}

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> tree(n);
    for (ll i = 1; i < n; i++)
    {
        ll t;
        cin >> t;
        tree[t - 1].push_back(i);
    }

    vector<ll> children(n, 0);
    vector<bool> visited(n, false);
    for (ll i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, tree, visited, children);
        }
    }
    for (auto i : children)
    {
        cout << i << " ";
    }
    cout << "\n";

    // ll n;
    // cin >> n;
    // vector<ll> arr(n);
    // for (ll i = 1; i < n; i++)
    // {
    //     cin >> arr[i];
    //     arr[i]--;
    // }
    // vector<ll> children(n, 0);
    // for (ll i = 0; i < n; i++)
    // {
    //     ll node = i;
    //     while (node != 0)
    //     {
    //         children[arr[node]]++;
    //         node = arr[node];
    //     }
    // }
    // for (auto i : children)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    return 0;
}