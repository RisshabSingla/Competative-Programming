#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <set>

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
        ll a, b, l;
        cin >> a >> b >> l;
        set<ll> values;
        ll val1 = 1;
        for (ll i = 0; i < 21; i++)
        {
            long long val2 = 1;
            if (val1 > l)
            {
                break;
            }
            for (ll j = 0; j < 21; j++)
            {
                if (val2 > l)
                {
                    break;
                }
                ll prod = val1 * val2;
                if (prod > l)
                {
                    break;
                }
                if (l % prod == 0)
                {
                    values.insert(l / prod);
                }
                val2 *= b;
            }
            val1 *= a;
        }
        cout << values.size() << "\n";
    }
    return 0;
}
