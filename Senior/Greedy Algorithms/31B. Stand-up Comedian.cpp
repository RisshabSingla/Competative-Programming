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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == 0)
        {
            cout << 1 << "\n";
            continue;
        }
        cout << a + 2 * min(b, c) + min(a + 1, abs(b - c) + d) << "\n";

        // ll alice = a;
        // ll bob = a;
        // ll count = a;
        // while (alice >= 0 && bob >= 0)
        // {
        //     if (alice == 0)
        //     {
        //         ll pos = min(b, bob);
        //         if (pos == 0)
        //         {
        //             break;
        //         }
        //         alice += pos;
        //         b -= pos;
        //         count += pos;
        //     }
        //     else
        //     {
        //         ll pos = min(c, alice);
        //         if (pos == 0)
        //         {
        //             break;
        //         }
        //         bob += pos;
        //         c -= pos;
        //         count += pos;
        //     }
        // }
        // count += (min({alice, bob, d - 1}) + 1);
        // cout << count << "\n";
    }
    return 0;
}