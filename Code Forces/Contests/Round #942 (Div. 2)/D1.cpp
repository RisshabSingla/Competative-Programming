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

int findGCD(ll a, ll b)
{
    return b == 0 ? a : findGCD(b, a % b);
}
int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m;
        cin >> n >> m;
        ll count = 0;
        for (ll b = 1; b <= m; b++)
        {
            for (ll a = b; a <= n; a += b)
            {
                int gcd = findGCD(a, b);
                if ((a + b) % (gcd * b) == 0)
                {
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}
