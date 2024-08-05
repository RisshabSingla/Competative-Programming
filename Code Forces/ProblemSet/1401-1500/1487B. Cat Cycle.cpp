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
        k--;
        if (n % 2 == 0)
        {
            ll ans = k % n;
            cout << ans + 1 << "\n";
        }
        else
        {
            ll steps = n / 2;
            ll ans = (k + (k / steps)) % n;
            cout << ans + 1 << "\n";
        }

        // ll currA = n - 1;
        // ll currB = 0;
        // for (ll i = 0; i < k - 1; i++)
        // {
        //     currA--;
        //     (currA += n) %= n;
        //     currB++;
        //     (currB += n) %= n;
        //     if (currA == currB)
        //     {
        //         currB++;
        //         (currB += n) %= n;
        //     }
        // }
        // cout << currB + 1 << "\n";
    }
    return 0;
}