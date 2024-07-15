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
        vector<ll> arr(n);
        bool present = false;
        ll odd = 0;
        ll even = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % k == 0)
            {
                present = true;
            }
            // prod *= arr[i];
            if (arr[i] % 2)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        if (present)
        {
            cout << "0\n";
            continue;
        }
        if (k == 2)
        {
            if (even)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << 1 << "\n";
            }
            continue;
        }

        ll diff = k;
        for (ll i = 0; i < n; i++)
        {
            diff = min(diff, k - arr[i] % k);
        }
        if (k == 4)
        {
            cout << min(diff, max(0LL, 2LL - even)) << "\n";
            continue;
        }
        cout << diff << "\n";
    }
    return 0;
}