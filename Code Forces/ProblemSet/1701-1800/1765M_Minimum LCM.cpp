#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll __gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return __gcd(b, a % b);
}

ll __lcm(ll a, ll b)
{
    return ((a * b) / (__gcd(a, b)));
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;

        vector<ll> divisors;
        for (ll i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                divisors.push_back(i);
                if (n / i != i)
                {
                    divisors.push_back(n / i);
                }
            }
        }

        ll a = 1;
        ll b = n - 1;
        ll ans = n - 1;

        for (auto &i : divisors)
        {
            ll sec = n / i;
            ll temp1 = i;
            ll temp2 = i * (sec - 1);
            ll tempans = __lcm(temp1, temp2);
            if (tempans < ans)
            {
                ans = tempans;
                a = temp1;
                b = temp2;
            }
        }

        cout << a << " " << b << "\n";

        // ll lcm = n - 1;
        // int ans = 1;
        // for (ll i = 1; i <= n / 2; i++)
        // {
        //     ll g = __gcd(i, n - i);
        //     // cout << "i: " << i << " gcd: " << g << "\n";
        //     if (g != 1)
        //     {
        //         int l = (i * (n - i)) / g;
        //         // cout << "lcm is: " << l << "\n";
        //         if (l < lcm)
        //         {
        //             lcm = l;
        //             ans = i;
        //         }
        //     }
        // }
        // cout << ans << " " << n - ans << "\n";
    }
    return 0;
}