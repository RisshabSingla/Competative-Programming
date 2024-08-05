#include <iostream>
#include <vector>
#include <algorithm>

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
        ll ans = 1;
        for (ll i = 1; i <= k; i++)
        {
            ans = ans * n;
            ans %= mod;
        }
        cout << ans << "\n";
    }
    return 0;
}