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

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll x;
        cin >> x;
        ll a = x;
        ll b = 0;
        for (ll i = 31; i >= 0; i--)
        {
            if (!(a & (1 << i)))
            {
                // unset bit
                ll c = b | (1LL << i);
                ll d = a | (1LL << i);
                // cout << "C is: " << c << " d is: " << d << "\n";
                if (((c + d) / 2) <= x)
                {
                    b = b | (1 << i);
                    a = a | (1 << i);
                }
            }
        }
        ll mid = (a + b) / 2;
        if (mid == x)
        {
            cout << a << " " << b << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}