#include <iostream>
#include <vector>
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
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        unordered_map<ll, ll> mp;
        bool ans = false;
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            mp[t]++;
            if (mp[t] > 1)
            {
                ans = true;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}