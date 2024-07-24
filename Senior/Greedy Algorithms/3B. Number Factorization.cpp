#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<ll> findPrimeFactors(ll n)
{
    vector<ll> ans;
    while (n % 2 == 0)
    {
        ans.push_back(2);
        n /= 2;
    }
    for (ll i = 3; i <= sqrtl(n); i++)
    {
        while (n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
    {
        ans.push_back(n);
    }
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
        vector<ll> factors = findPrimeFactors(n);
        unordered_map<ll, ll> mp;
        ll freq = 0;
        for (auto i : factors)
        {
            mp[i]++;
            freq = max(freq, mp[i]);
        }
        ll number = 1;
        unordered_map<ll, ll> mp2;
        for (ll i = 0; i < freq; i++)
        {
            for (auto &i : mp)
            {
                if (i.second > 0)
                {
                    number *= i.first;
                    i.second--;
                }
            }
            mp2[number]++;
            number = 1;
        }

        ll ans = 0;
        for (auto i : mp2)
        {
            ans += ((i.first) * i.second);
        }
        cout << ans << "\n";
    }
    return 0;
}