#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
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
        ll n, x;
        cin >> n >> x;
        ll count = 0;
        for (ll a = 1; a < n && a < x; a++)
        {
            for (ll b = 1; a * b < n && a + b < x; b++)
            {
                ll c1 = max(0LL, x - a - b);
                ll c2 = max(0LL, (n - a * b) / (a + b));
                ll c = min(c1, c2);
                count += c;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
