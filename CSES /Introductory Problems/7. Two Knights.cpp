#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll countWays(ll n)
{
    if (n == 1)
    {
        return 0;
    }
    ll a = (n) * (n);
    ll b = a - 1;
    ll total = (a * b) / 2;
    ll threeXtwo = (n - 2) * (n - 1);
    ll twoXthree = (n - 1) * (n - 2);
    ll ans = total - 2 * threeXtwo - 2 * twoXthree;

    return ans;
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cout << countWays(i) << "\n";
    }
    return 0;
}