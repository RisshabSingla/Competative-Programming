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
        ll n;
        cin >> n;
        string str;
        cin >> str;
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        vector<ll> arr(n, 0);
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == '*')
            {
                arr[i] = 1;
            }
        }
        // cout << "Arr is: ";
        // for (auto i : arr)
        // {
        //     cout << i << ' ';
        // }
        // cout << '\n';
        vector<ll> pref(n, 0);
        vector<ll> suff(n, 0);
        ll curr = 0;
        if (arr[0] == 1)
        {
            curr++;
        }
        for (ll i = 1; i < n; i++)
        {
            if (arr[i] == 1)
            {
                pref[i] = pref[i - 1];
                curr++;
            }
            else
            {
                pref[i] = pref[i - 1] + curr;
            }
        }
        curr = 0;
        if (arr[n - 1] == 1)
        {
            curr++;
        }
        for (ll i = n - 2; i >= 0; i--)
        {
            if (arr[i] == 1)
            {
                suff[i] = suff[i + 1];
                curr++;
            }
            else
            {
                suff[i] = suff[i + 1] + curr;
            }
        }

        // cout << "Pref is: ";
        // for (auto i : pref)
        // {
        //     cout << i << ' ';
        // }
        // cout << '\n';
        // cout << "Suff is: ";
        // for (auto i : suff)
        // {
        //     cout << i << ' ';
        // }
        // cout << '\n';
        ll ans = LLONG_MAX;
        for (ll i = 0; i < n - 1; i++)
        {
            ans = min(ans, pref[i] + suff[i + 1]);
        }
        cout << ans << "\n";
    }
    return 0;
}