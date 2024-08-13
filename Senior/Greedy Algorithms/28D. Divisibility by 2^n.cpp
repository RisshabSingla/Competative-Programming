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

int main()
{
    int cases;
    cin >> cases;
    ll maxi = 2e5 + 2;
    vector<ll> contribution(maxi, 0);
    for (ll i = 1; i < maxi; i++)
    {
        ll count = 0;
        ll index = i;
        while (index % 2 == 0)
        {
            count++;
            index /= 2;
        }
        contribution[i] = count;
    }
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            ll num = arr[i];
            while (num % 2 == 0)
            {
                count++;
                num /= 2;
            }
            ll index = i + 1;
        }
        if (count >= n)
        {
            cout << 0 << '\n';
            continue;
        }
        ll maxContri = log2(n);
        unordered_map<ll, ll> mp;
        for (ll i = 1; i <= n; i++)
        {
            mp[contribution[i]]++;
        }
        ll req = n - count;
        ll opr = 0;
        // cout << "req is: " << req << "\n";
        for (ll i = maxContri; i > 0; i--)
        {
            if (!mp.count(i))
            {
                continue;
            }
            ll need = req / i;
            ll take = min(need, mp[i]);
            req -= ((i) * (take));
            opr += take;
            if (req <= 0)
            {
                break;
            }
        }
        if (req <= 0)
        {
            cout << opr << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }

        // cout << count << "\n";
        // cout << countIndex << "\n";
    }
    return 0;
}