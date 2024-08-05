#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll calculate(ll n, ll x, ll y)
{
    ll divisibleByX = n / x;
    ll divisibleByY = n / y;
    ll lcm = (x * y) / __gcd(x, y);
    ll divisibleByLCM = n / lcm;

    ll divisibleByBoth = divisibleByX + divisibleByY - divisibleByLCM;
    ll divisibleByXNotY = divisibleByBoth - divisibleByY;
    return divisibleByXNotY;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, x, y;
        cin >> n >> x >> y;

        ll nX = calculate(n, x, y);
        ll nY = calculate(n, y, x);

        ll a = ((n) * (n + 1)) / 2;
        ll b = ((n - nX) * (n - nX + 1)) / 2;
        ll sum1 = a - b;

        // for (ll i = 0; i < nX; i++)
        // {
        //     sum1 += (n - i);
        // }

        // ll sum2 = 0;
        // for (ll i = 1; i <= nY; i++)
        // {
        //     sum2 += i;
        // }

        ll sum2 = ((nY) * (nY + 1)) / 2;
        cout << sum1 - sum2 << "\n";
    }
    return 0;
}