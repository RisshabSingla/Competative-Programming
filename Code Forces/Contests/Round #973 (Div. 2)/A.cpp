#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
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
        ll x, y;
        cin >> x >> y;
        ll each = min(x, y);
        ll ans = n / each;
        if (n % each)
        {
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
