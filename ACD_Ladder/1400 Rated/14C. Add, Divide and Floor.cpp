#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll mini = LLONG_MAX;
        ll maxi = LLONG_MIN;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        ll operations = 0;
        vector<ll> ans;

        while (mini != maxi)
        {
            ll add = mini % 2;
            mini = (mini + add) / 2;
            maxi = (maxi + add) / 2;
            ans.push_back(add);
        }
        cout << ans.size() << "\n";
        if (ans.size() <= n)
        {
            for (auto i : ans)
            {
                cout << i << " ";
            }
            cout << "\n";
        }

        // ll diff = maxi - mini;
        // ll operations = log2(diff) + 1;
        // cout << operations << "\n";
        // if (operations <= n)
        // {
        //     while (diff != 0)
        //     {
        //         cout << diff << " ";
        //         diff /= 2;
        //     }
        //     cout << "\n";
        // }

        // ll operations = 0;
        // vector<ll> ans;
        // while (diff != 0)
        // {
        //     if (operations < n)
        //     {
        //         ans.push_back(diff);
        //     }
        //     operations++;
        //     maxi = (maxi + diff) / 2;
        //     mini = (mini + diff) / 2;
        //     diff = maxi - mini;
        // }

        // cout << operations << "\n";
        // if (operations <= n)
        // {
        //     for (auto i : ans)
        //     {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // }

        // ll n;
        // cin >> n;
        // vector<ll> arr(n);
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        // }
        // if (n == 1)
        // {
        //     cout << 0 << "\n";
        //     continue;
        // }
        // sort(arr.begin(), arr.end());
        // ll diff = arr.back() - arr[0];
        // vector<ll> ans;
        // ll opr = 0;
        // while (diff != 0)
        // {
        //     opr++;
        //     if (opr <= n)
        //     {
        //         ans.push_back(diff);
        //     }
        //     arr[n - 1] = (arr[n - 1] + diff) / 2;
        //     arr[0] = (arr[0] + diff) / 2;
        //     // for (auto &i : arr)
        //     // {
        //     //     i = (i + diff) / 2;
        //     // }
        //     diff = arr[n - 1] - arr[0];
        // }
        // cout << opr << "\n";
        // if (opr <= n)
        // {
        //     for (auto i : ans)
        //     {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // }
    }
    return 0;
}