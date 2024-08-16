#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
        ll n, k;
        cin >> n >> k;
        if (k == 1)
        {
            cout << n << "\n";
            continue;
        }
        if (n <= k)
        {
            cout << 1 << "\n";
            continue;
        }
        ll ans = n;
        for (ll i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i <= k)
                {
                    ans = min(ans, n / i);
                }
                if (n / i <= k)
                {
                    ans = min(ans, i);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}