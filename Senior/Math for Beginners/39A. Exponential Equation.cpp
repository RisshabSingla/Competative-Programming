#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<ll> findFactors(ll n)
{
    vector<ll> arr;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            arr.push_back(i);
        }
    }
    return arr;
}

pair<ll, ll> solve(ll n)
{
    vector<ll> factors = findFactors(n);
    ll size = factors.size();
    for (ll i = 0; i < size; i++)
    {
        for (ll j = i; j < size; j++)
        {
            ll x = factors[i];
            ll y = factors[j];
            if ((x * y * (pow(x, y - 1) + pow(y, x - 1))) == n)
            {
                return {x, y};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;

        if (n % 2 == 0)
        {
            cout << 1 << " " << n / 2 << "\n";
            continue;
        }
        cout << -1 << "\n";
        // pair<ll, ll> ans = solve(n);
        // if (ans.first == -1)
        // {
        //     cout << -1 << "\n";
        // }
        // else
        // {
        //     cout << ans.first << " " << ans.second << "\n";
        // }
    }
    return 0;
}