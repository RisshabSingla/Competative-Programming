#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll modexp(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if ((b % 2) == 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

ll sum_square(ll n)
{
    ll ans = (((n * (n + 1)) % mod) * (2 * n + 1) % mod) % mod;
    ans = (ans * modexp(6, mod - 2)) % mod;
    return ans;
}

ll sum_linear(ll n)
{
    ll ans = (n * (n + 1)) % mod;
    ans = (ans * modexp(2, mod - 2)) % mod;
    return ans;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;

        ll ans = 0;

        ans = (ans + sum_square(n)) % mod;
        ans = (ans + sum_square(n - 1)) % mod;
        ans = (ans + sum_linear(n - 1)) % mod;
        ans = (ans * 2022) % mod;

        cout << ans << "\n";
        // ll currX = 1;
        // ll currY = 1;
        // ll count = 1;
        // while (currX < n && currY < n)
        // {
        //     ll down = (currY + 1) * (currX);
        //     ll right = (currY) * (currX + 1);
        //     if (right < down)
        //     {
        //         currY++;
        //         count += down;
        //         count %= mod;
        //     }
        //     else
        //     {
        //         currX++;
        //         count += right;
        //         count %= mod;
        //     }
        // }

        // while (currX < n)
        // {
        //     ll amt = (currX + 1) * (currY);
        //     count += amt;
        //     count %= mod;
        //     currX++;
        // }
        // while (currY < n)
        // {
        //     ll amt = (currX) * (currY + 1);
        //     count += amt;
        //     count %= mod;
        //     currY++;
        // }
        // cout << (count * 2022) % mod << "\n";
    }
    return 0;
}