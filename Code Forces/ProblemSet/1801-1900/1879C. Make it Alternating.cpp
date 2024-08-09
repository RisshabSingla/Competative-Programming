#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 998244353;

int main()
{
    int cases;
    cin >> cases;
    int num = 2e5 + 2;
    vector<ll> fact(num);
    fact[0] = 1;
    for (ll i = 1; i <= num; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }

    while (cases--)
    {
        string str;
        cin >> str;
        vector<ll> arr;
        char prev = str[0];
        ll count = 1;
        ll n = str.length();
        for (ll i = 1; i <= n; i++)
        {
            if (str[i] != prev)
            {
                prev = str[i];
                arr.push_back(count);
                count = 0;
            }
            count++;
        }

        ll sections = arr.size();
        ll ways = n - sections;
        ll ans = 1;
        for (auto i : arr)
        {
            ans *= i;
            ans %= mod;
        }
        ans = ans * fact[ways];
        ans %= mod;
        cout << ways << " " << ans << "\n";
    }
    return 0;
}