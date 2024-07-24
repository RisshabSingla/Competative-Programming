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
        ll n, k;
        cin >> n >> k;
        if (k == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        if (k == n * n)
        {
            cout << 2 * n - 1 << "\n";
            continue;
        }
        ll longest = n - 1;
        k -= (n);
        ll count = 1;

        for (ll i = longest; i >= 1; i--)
        {
            if (k <= 0)
            {
                break;
            }
            count++;
            k -= i;
            if (k <= 0)
            {
                break;
            }
            count++;
            k -= i;
        }
        // while (k >= 2 * longest && longest > 0 && k > 0)
        // {
        //     count += 2;
        //     k -= ((2) * (longest));
        //     longest--;
        // }
        // if (k > 0)
        // {
        //     count++;
        // }
        cout << count << "\n";
    }
    return 0;
}
