#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(ll plus, ll minus, ll a, ll b, ll n)
{
    if (a == b)
    {
        return false;
    }
    ll x = min(a, b);
    ll y = max(a, b);
    ll numerator = (plus - minus) * y;
    ll deno = (y - x);
    if (numerator % deno != 0)
    {
        return false;
    }
    ll k = numerator / deno;
    if (-minus <= k && k <= plus)
    {
        return true;
    }
    return false;
}

int main()
{
    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll countPlus = 0;
    ll countNeg = 0;
    for (char ch : str)
    {
        if (ch == '+')
        {
            countPlus++;
        }
        else
        {
            countNeg++;
        }
    }
    ll q;
    cin >> q;
    if (countNeg == countPlus)
    {
        // equal plus and minus
        while (q--)
        {
            ll a, b;
            cin >> a >> b;
            cout << "YES\n";
        }
        return 0;
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        if (isPossible(countPlus, countNeg, a, b, n))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}