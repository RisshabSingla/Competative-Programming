#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
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
        vector<ll> arr(n - 1);
        for (ll i = 0; i < n - 1; i++)
        {
            cin >> arr[i];
        }
        vector<ll> ans(n, 0);
        ans[0] = arr[0];
        for (ll i = 1; i < n - 1; i++)
        {
            if (max(arr[i], ans[i - 1]) != arr[i - 1])
            {
                ans[i] = min(arr[i], arr[i - 1]);
            }
            else
            {
                ans[i] = arr[i];
            }
        }
        ans[n - 1] = arr[n - 2];
        for (auto i : ans)
        {
            cout << i << ' ';
        }
        cout << "\n";

        // vector<ll> ans(n, 0);
        // bool forward = false;
        // ll prev = INT_MAX;
        // for (ll i = n - 1; i > 0; i--)
        // {
        //     if (forward)
        //     {
        //         ans[i] = prev;
        //         forward = false;
        //         prev = arr[i - 1];
        //     }
        //     else
        //     {
        //         if (arr[i - 1] > prev)
        //         {
        //             forward = true;
        //             prev = arr[i - 1];
        //             ans[i] = 0;
        //         }
        //         else
        //         {
        //             ans[i] = arr[i - 1];
        //             prev = arr[i - 1];
        //         }
        //     }
        // }
        // ans[0] = prev;
        // for (auto i : ans)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
    }
    return 0;
}