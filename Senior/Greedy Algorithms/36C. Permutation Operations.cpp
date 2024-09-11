#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<pll> diff;
        for (ll i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                diff.push_back({arr[i - 1] - arr[i], i});
            }
        }
        sort(diff.begin(), diff.end());
        reverse(diff.begin(), diff.end());
        vector<ll> ans(n, 0);
        ll index = n - 1;
        for (auto i : diff)
        {
            ans[index] = i.second + 1;
            index--;
        }
        for (ll i = 0; i < n; i++)
        {
            if (ans[i] == 0)
            {
                ans[i] = 1;
            }
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";

        // ll n;
        // cin >> n;
        // vector<ll> arr(n);
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        // }
        // ll maxi = 0;
        // ll add = 0;
        // vector<ll> ans(n, 1);
        // set<ll> used;
        // for (ll i = 0; i < n; i++)
        // {
        //     if (arr[i] + add < maxi)
        //     {
        //         ll diff = maxi - (arr[i] + add);
        //         while (used.count(diff))
        //         {
        //             diff++;
        //         }
        //         // cout << "index: " << i << " diff: " << diff << "\n";
        //         ans[diff - 1] = i + 1;
        //         add += diff;
        //         used.insert(diff);
        //     }
        //     else
        //     {
        //         maxi = max(maxi, arr[i] + add);
        //     }
        // }
        // for (auto i : ans)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
    }
    return 0;
}