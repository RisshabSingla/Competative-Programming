#include <iostream>
#include <vector>
#include <cmath>
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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> bits(32, 0);
        for (ll i = 0; i < n; i++)
        {
            ll bit = log2(arr[i]);
            bits[bit]++;
        }
        ll ans = 0;
        for (ll i = 0; i < 32; i++)
        {
            ans += ((bits[i] * (bits[i] - 1))) / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}