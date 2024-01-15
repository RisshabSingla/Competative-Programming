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
        ll lower = -1;
        ll upper = LLONG_MAX;
        vector<ll> invalid;
        for (ll i = 0; i < n; i++)
        {
            ll a, x;
            cin >> a >> x;
            if (a == 1)
            {

                lower = max(lower, x);
            }
            else if (a == 2)
            {
                upper = min(upper, x);
            }
            else
            {
                invalid.push_back(x);
            }
        }
        // for (auto i : invalid)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // cout << "invalid is: " << invalid.size() << "\n";
        ll notvalid = 0;
        for (ll i = 0; i < invalid.size(); i++)
        {
            // cout << invalid[i] << " ";
            if (invalid[i] > upper || invalid[i] < lower)
            {
                // cout << "Invalid";
                // invalid.erase(invalid.begin() + i);
            }
            else
            {
                notvalid++;
            }
            // cout << "\n";
        }
        // cout << "Upper is: " << upper << "\n";
        // cout << "lower is: " << lower << "\n";
        // cout << "invalid is: " << invalid.size() << "\n";

        ll count = upper - lower - notvalid + 1;
        count = max(count, 0LL);
        cout << count << "\n";
    }
    return 0;
}
