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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum % 3 == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        int rem = 3 - (sum % 3);
        if (rem == 1)
        {
            cout << 1 << "\n";
        }
        else
        {
            bool present = false;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 3 == 1)
                {
                    present = true;
                    break;
                }
            }
            if (present)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 2 << "\n";
            }
        }
    }
    return 0;
}
