#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
        map<int, int> mp;

        ll t;
        for (ll i = 0; i < n; i++)
        {
            cin >> t;
            mp[t]++;
        }
        vector<ll> traps(n + 1, 0);
        for (auto i : mp)
        {
            for (int k = i.first; k <= n; k += i.first)
            {
                traps[k] += i.second;
            }
        }

        ll maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            maxi = max(maxi, traps[i]);
        }
        cout << maxi << "\n";
    }
    return 0;
}