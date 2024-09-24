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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> brr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> brr[i];
        }
        vector<ll> ans(n + 1, 0);
        vector<ll> pref(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + brr[i - 1];
        }
        vector<ll> diffArray(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            ll index = (upper_bound(pref.begin(), pref.end(), arr[i] + pref[i]) - pref.begin()) - 1;
            // cout << "index: " << index << "\n";
            diffArray[i]++;
            diffArray[index]--;
            ans[index] += (arr[i] - (pref[index] - pref[i]));
        }
        for (ll i = 1; i <= n; i++)
        {
            diffArray[i] += diffArray[i - 1];
        }
        for (ll i = 0; i < n; i++)
        {
            cout << diffArray[i] * brr[i] + ans[i] << " ";
        }
        cout << '\n';

        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = n - 1; j >= i; j--)
        //     {
        //         ans[j] += min(brr[j], arr[j - i]);
        //         arr[j - i] -= min(brr[j], arr[j - i]);
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