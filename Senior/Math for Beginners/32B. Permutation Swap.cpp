#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll diff = abs(arr[i - 1] - i);
            ans = __gcd(ans, diff);
        }

        cout << ans << "\n";
    }
    return 0;
}