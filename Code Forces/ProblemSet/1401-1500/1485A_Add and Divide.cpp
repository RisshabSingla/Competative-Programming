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
        ll a, b;
        cin >> a >> b;
        if (a == 1)
        {
            if (b == 1)
            {
                cout << 2 << "\n";
                continue;
            }
            cout << 1 << "\n";
            continue;
        }
        ll ans = 1e18;
        for (ll i = 0; i * i <= a; i++)
        {
            if (b == 1 && i == 0)
            {
                continue;
            }
            ll count = i;
            ll temp = a;
            while (temp)
            {
                temp /= (b + i);
                count++;
            }
            ans = min(ans, count);
        }
        cout << ans << "\n";
    }

    return 0;
}