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

vector<ll> fact;
ll N = 1e6;

ll powm(ll x, ll n)
{
    x %= mod;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    ll p = powm(x * x, n / 2);
    if (n % 2)
        return p * x % mod;
    else
        return p;
}

ll mod_div(ll p, ll q)
{
    return p % mod * powm(q, mod - 2) % mod;
}

ll findnCr(ll n, ll r)
{
    if (r > n)
        return 0;
    return mod_div(fact[n], fact[n - r] * fact[r]);
}

int main()
{
    fact.assign(N, 1);
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        ll count1 = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                count1++;
            }
        }
        ll count0 = n - count1;
        ll req = (k / 2) + 1;
        ll ans = 0;
        for (ll i = req; i <= min(count1, k); i++)
        {
            ll first = findnCr(count1, i) % mod;
            ll second = findnCr(count0, k - i) % mod;
            ll a1 = (first * second) % mod;
            ans += a1;
            ans %= mod;
        }
        cout << ans << "\n";
    }
    return 0;
}
