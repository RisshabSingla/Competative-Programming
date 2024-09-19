#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

// dfs(0, arr, ans, visited);

ll dfs(ll node, vector<vector<ll>> &arr, vector<ll> &ans, vector<ll> &respect)
{
    ll count = 0;
    for (auto child : arr[node])
    {
        count += dfs(child, arr, ans, respect);
    }

    if (respect[node] == 1 && count == arr[node].size())
    {
        ans.push_back(node);
    }

    // cout << "For node: " << node << " count: " << count << "\n";
    // count += respect[node];
    // cout << "for node: " << node << " returning: " << count << "\n";
    return respect[node];
}

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n + 1);
    vector<ll> respect(n + 1);
    ll parent = -1;
    for (ll i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a == -1)
        {
            parent = i;
            a++;
        }
        arr[a].push_back(i);
        respect[i] = b;
    }

    vector<ll> ans;
    dfs(0, arr, ans, respect);
    if (ans.size() == 0)
    {
        cout << -1 << "\n";
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}