#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int recursive(vector<vector<ll>> &arr, int current, int index, int n)
{
    if (index == n)
    {
        return 0;
    }
    if (arr[index][0] > current)
    {
        ll a = recursive(arr, arr[index][1], index + 1, n) + arr[index][2];
        ll b = recursive(arr, current, index + 1, n);
        return max(a, b);
    }
    return recursive(arr, current, index + 1, n);
}

map<pair<ll, ll>, ll> dp;

int memo(vector<vector<ll>> &arr, int current, int index, int n)
{
    if (index == n)
    {
        return 0;
    }

    if (dp.count({current, index}))
    {
        return dp[{current, index}];
    }
    if (arr[index][0] > current)
    {
        ll a = memo(arr, arr[index][1], index + 1, n) + arr[index][2];
        ll b = memo(arr, current, index + 1, n);
        return dp[{current, index}] = max(a, b);
    }
    return dp[{current, index}] = memo(arr, current, index + 1, n);
}

bool comp(vector<ll> &a, vector<ll> &b)
{
    return a[1] < b[1];
}

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(3, 0));
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    // cout << recursive(arr, 0, 0, n);

    // cout << memo(arr, 0, 0, n);

    sort(arr.begin(), arr.end(), comp);

    // for (auto i : arr)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    // vector<pair<ll, ll>> ans;
    // ll maxi = 0;
    // for (ll i = 0; i < n; i++)
    // {
    //     pair<ll, ll> p = {arr[i][0], -1};
    //     auto itr = lower_bound(ans.begin(), ans.end(), p);

    //     if (itr == ans.end())
    //     {
    //         maxi = max(maxi, maxi + arr[i][2]);
    //         ans.push_back({arr[i][1], maxi});
    //     }
    //     else
    //     {
    //         int index = itr - ans.begin();
    //         if (index == 0)
    //         {
    //             if (ans[index].second < arr[i][0])
    //             {
    //                 maxi = max(maxi, ans[index - 1].second + arr[i][2]);
    //                 ans.push_back({arr[i][1], maxi});
    //             }
    //             else
    //             {
    //                 maxi = max(maxi, arr[i][2]);
    //                 ans.push_back({arr[i][1], maxi});
    //             }
    //         }
    //         else
    //         {
    //             if (ans[index].second < arr[i][0])
    //             {
    //                 maxi = max(maxi, ans[index - 1].second + arr[i][2]);
    //                 ans.push_back({arr[i][1], maxi});
    //             }
    //             else
    //             {
    //                 maxi = max(maxi, ans[index - 1].second + arr[i][2]);
    //                 ans.push_back({arr[i][1], maxi});
    //             }
    //         }
    //     }
    //     // for (auto x : ans)
    //     // {
    //     //     cout << x.first << " " << x.second << "\n";
    //     // }
    //     // cout << "\n";
    // }
    // cout << maxi;

    set<pair<ll, ll>> st;
    ll maxi = 0;
    st.insert({0, 0});
    for (ll i = 0; i < n; i++)
    {
        auto itr = st.lower_bound({arr[i][0], -1});
        itr--;
        maxi = max(maxi, arr[i][2] + itr->second);
        st.insert({arr[i][1], maxi});
    }
    cout << maxi;
    return 0;
}