#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    // Using Brute Force
    // set<int> st;
    // int n;
    // cin >> n;
    // int t;
    // cin >> t;
    // st.insert(t);
    // for (int i = 1; i < n; i++)
    // {
    //     cin >> t;
    //     set<int> nst;
    //     for (auto num : st)
    //     {
    //         nst.insert(num);
    //         nst.insert(num + t);
    //         nst.insert(t);
    //     }
    //     st = nst;
    // }
    // cout << st.size() << "\n";
    // for (auto num : st)
    // {
    //     cout << num << " ";
    // }

    // Using 2D Vector
    // ll n;
    // cin >> n;
    // vector<ll> arr(n);
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // sort(arr.begin(), arr.end());
    // vector<vector<ll>> ans;
    // int prev = -1;
    // set<int> st;
    // for (ll i = 0; i < n; i++)
    // {
    //     vector<ll> curr;
    //     st.insert(arr[i]);
    //     if (prev == arr[i])
    //     {
    //         for (auto j : ans.back())
    //         {
    //             if (!st.count(j + arr[i]))
    //             {
    //                 curr.push_back(j + arr[i]);
    //                 st.insert(j + arr[i]);
    //             }
    //         }
    //         ans.push_back(curr);
    //     }
    //     else
    //     {
    //         curr.push_back(arr[i]);
    //         for (auto j : ans)
    //         {
    //             for (auto k : j)
    //             {
    //                 if (!st.count(k + arr[i]))
    //                 {
    //                     curr.push_back(k + arr[i]);
    //                     st.insert(k + arr[i]);
    //                 }
    //             }
    //         }
    //         ans.push_back(curr);
    //     }
    //     prev = arr[i];
    // }

    // cout << st.size() << "\n";
    // for (auto i : st)
    // {
    //     cout << i << " ";
    // }

    int n;
    cin >> n;
    vector<int> arr(n);
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxSum += arr[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(maxSum + 1, 0));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= maxSum; k++)
        {
            dp[i][k] = dp[i - 1][k];
            int prev = k - arr[i - 1];

            if (prev >= 0 && dp[i - 1][prev])
            {
                dp[i][k] = true;
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= maxSum; i++)
    {
        if (dp[n][i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}