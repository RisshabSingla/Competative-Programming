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
        ll x, y, k;
        cin >> x >> y >> k;
        if (k % 2)
        {
            cout << x << " " << y << "\n";
            k--;
        }
        for (ll i = 1; i <= k; i++)
        {
            cout << x - i << " " << y - i << "\n";
            if (i + 1 <= k)
            {
                cout << x + i << " " << y + i << "\n";
                i++;
            }
        }
        cout << "\n";
    }
    return 0;
}
