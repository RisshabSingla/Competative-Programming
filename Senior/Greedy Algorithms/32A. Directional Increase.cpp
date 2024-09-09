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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll posMoves = 0;
        ll ans = true;
        ll zero = false;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            posMoves += arr[i];
            if (arr[i] && zero)
            {
                ans = false;
            }
            if (posMoves < 0)
            {
                ans = false;
            }
            if (posMoves == 0)
            {
                zero = true;
            }
        }
        if (posMoves != 0)
        {
            ans = false;
        }

        if (ans)
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