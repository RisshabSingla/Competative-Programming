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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        // vector<ll> closed(102, false);
        ll open = max(a, c);
        ll close = min(b, d);
        if (close < open)
        {
            cout << 1 << "\n";
            continue;
        }
        ll ans = close - open + 1;
        if (min(a, c) < open)
        {
            ans++;
        }
        if (max(b, d) > close)
        {
            ans++;
        }
        cout << ans - 1 << "\n";
    }
    return 0;
}
