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

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, x;
        cin >> n >> x;
        vector<pll> arr(n);
        vector<ll> brr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> brr[i];
        }

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        vector<ll> ans(n);
        ll index = n - x;
        index = index % n;
        for (ll i = 0; i < n; i++)
        {
            ans[index] = brr[i];
            index++;
            index %= n;
        }
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            brr[arr[i].second] = ans[i];
            if (brr[arr[i].second] < arr[i].first)
            {
                count++;
            }
        }
        if (count == x)
        {
            cout << "YES\n";
            for (auto i : brr)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }

        // ll index = (n - x) % n;
        // vector<ll> ans(n, 0);
        // for (ll i = 0; i < n; i++)
        // {
        //     ans[index] = brr[index];
        //     index++;
        //     index %= n;
        // }

        // for (auto i : arr)
        // {
        //     cout << i << ' ';
        // }
        // cout << "\n";
        // for (auto i : ans)
        // {
        //     cout << i << ' ';
        // }
        // cout << "\n";
        // cout << "\n";

        // ll count = 0;
        // for (ll i = 0; i < n; i++)
        // {
        //     if (arr[i] > ans[i])
        //     {
        //         count++;
        //     }
        // }
        // if (count == x)
        // {
        //     cout << "YES\n";
        //     for (auto i : ans)
        //     {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        // }
        // cout << count << "\n";
    }
    return 0;
}