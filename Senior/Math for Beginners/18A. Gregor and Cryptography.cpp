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
        unordered_map<ll, ll> mp;
        ll ans1 = -1;
        ll ans2 = -1;
        for (ll i = 2; i <= n; i++)
        {
            if (mp.count(n % i))
            {
                ans1 = mp[n % i];
                ans2 = i;
                break;
            }
            mp[n % i] = i;
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}