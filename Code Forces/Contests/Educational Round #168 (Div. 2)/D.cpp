#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(vector<ll> &arr, vector<vector<ll>> &adjList, ll val, ll carry, ll node)
{
    ll additional = 0;
    if (node == 0)
    {
        additional = max(val - arr[node], 0LL);
    }
    else
    {
        additional = max(carry - arr[node], 0LL);
    }
    carry += additional;
    if (carry > INT_MAX)
    {
        return false;
    }
    if (adjList[node].size() == 0)
    {
        return arr[node] >= carry;
    }
    for (auto neighbor : adjList[node])
    {
        if (!isPossible(arr, adjList, val, carry, neighbor))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll maxi = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }
        vector<vector<ll>> adjList(n);
        for (ll i = 1; i < n; i++)
        {
            ll t;
            cin >> t;
            adjList[t - 1].push_back(i);
        }
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << i << " : ";
        //     for (auto j : adjList[i])
        //     {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        ll ans = arr[0];
        ll low = 0;
        ll high = INT_MAX;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (isPossible(arr, adjList, mid, 0, 0))
            {
                low = mid + 1;
                ans = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
