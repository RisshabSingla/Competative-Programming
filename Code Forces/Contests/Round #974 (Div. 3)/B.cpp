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
        ll n, k;
        cin >> n >> k;
        if (k == 1)
        {
            if (n % 2)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
            continue;
        }

        ll start = n - k + 1;
        ll end = n;
        ll num = (end - start) / 2;

        if (end % 2 != 0 || start % 2 != 0)
        {
            num += 1;
        }

        // for (ll i = n - k + 1; i <= n; i++)
        // {
        //     if (i % 2)
        //     {
        //         count++;
        //     }
        // }

        if (num % 2)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}
