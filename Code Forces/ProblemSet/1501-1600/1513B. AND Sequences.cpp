#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
    ll m = 2e5 + 2;
    vector<ll> fact(m, 1);
    for (ll i = 2; i < m; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        map<ll, ll> freq;
        ll mini = LLONG_MAX;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mini = min(mini, arr[i]);
            freq[arr[i]]++;
        }
        bool flag = true;
        for (auto i : arr)
        {
            if ((i & mini) != mini)
            {
                flag = false;
                break;
            }
        }
        if (freq[mini] < 2)
        {
            cout << 0 << "\n";
            continue;
        }
        if (!flag)
        {
            cout << 0 << "\n";
            continue;
        }

        ll ans = (((freq[mini] * (freq[mini] - 1)) % mod) * fact[n - 2]) % mod;
        cout << ans << "\n";
    }
    return 0;
}