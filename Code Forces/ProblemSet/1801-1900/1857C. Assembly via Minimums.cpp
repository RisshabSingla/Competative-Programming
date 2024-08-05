#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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
        ll m = ((n) * (n - 1)) / 2;
        map<ll, ll> mp;
        for (ll i = 0; i < m; i++)
        {
            ll t;
            cin >> t;
            mp[t]++;
        }
        vector<pair<ll, ll>> numbers;
        for (auto i : mp)
        {
            numbers.push_back({i.first, i.second});
        }

        vector<ll> ans(n, 1e9);
        ll back = numbers.size() - 1;
        ll count = 1;
        for (ll i = n - 2; i >= 0 && back >= 0; i--)
        {
            ans[i] = numbers[back].first;
            numbers[back].second -= count;
            count++;
            if (numbers[back].second <= 0)
            {
                back--;
            }
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}