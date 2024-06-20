#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = -1;
    ll gcd = __gcd(a, b);
    for (ll i = gcd; i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            k--;
            // cout << i << " ";
            if (k == 0)
            {
                ans = i;
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}