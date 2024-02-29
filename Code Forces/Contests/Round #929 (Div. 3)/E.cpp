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

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> pref(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + arr[i - 1];
        }
        ll q;
        cin >> q;
        while (q--)
        {
            // ll l, u;
            // cin >> l >> u;
            // // l--;
            // ll ran = u + pref[l - 1];
            // ll index = lower_bound(pref.begin(), pref.end(), ran) - pref.begin();
            // int rounds1 = pref[index] - pref[l - 1];
            // int rounds2 = 0;
            // if (index - 1 >= 0)
            // {
            //     rounds2 = pref[index - 1] - pref[l - 1];
            // }

            // int perf1 = rounds1 * u - ((rounds1) * (rounds1 + 1)) / 2;
            // int perf2 = (rounds2 - 1) * u - ((rounds2 - 1) * (rounds2)) / 2;

            // if (rounds1 <= rounds2)
            // {
            //     cout << index - 1 << " ";
            // }
            // else
            // {
            //     cout << index << " ";
            // }

            // if (rounds1 > u)
            // {
            //     cout << index - 1 << " ";
            // }
            // else
            // {
            //     cout << index << " ";
            // }
            // cout << "Rounds1: " << rounds1 << "  Rounds2: " << rounds2 << "\n";
            // cout << "Perf1: " << perf1 << "  Perf2: " << perf2 << "\n";

            // cout << index << " ";

            ll l, u;
            cin >> l >> u;

            u += pref[l - 1];
            ll index = lower_bound(pref.begin() + 1, pref.end(), u) - pref.begin();
            if (pref[index] - u > u - pref[index - 1])
            {
                index--;
            }
            index = max(index, l);
            index = min(index, n);
            cout << index << " ";
        }
        cout << "\n";
    }
    return 0;
}
