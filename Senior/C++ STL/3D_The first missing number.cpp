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
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        mp[t]++;
    }
    ll number = -m;
    for (; number <= m; number++)
    {
        if (!mp.count(number))
        {
            break;
        }
    }
    cout << number << "\n";
    return 0;
}