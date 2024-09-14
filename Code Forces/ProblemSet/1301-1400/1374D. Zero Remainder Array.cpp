#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
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
        vector<ll> arr;
        multiset<ll> st;
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            t = (k - t % k) % k;
            if (t != 0)
            {
                st.insert(t);
                count++;
            }
        }

        ll x = 0;
        ll opr = 0;
        for (ll i = 0; i < count; i++)
        {
            auto itr = st.lower_bound(x);
            if (itr == st.end())
            {
                ll req = k - x;
                opr += req;
                x = 0;
                i--;
                continue;
            }
            ll req = (*itr) - x;
            opr += req;
            x += req;
            opr++;
            x++;
            x %= k;
            st.erase(itr);
        }
        cout << opr << "\n";
        // sort(arr.begin(), arr.end());
        // ll x = 0;
        // ll first = 0;
        // ll second = arr.size() - 1;
        // ll opr = 0;
        // while (first <= second)
        // {
        //     cout << "X is: " << x << "\n";
        //     if (x == arr[first])
        //     {
        //         cout << "for first: " << arr[first] << "\n";
        //         opr++;
        //         first++;
        //         x++;
        //         x %= k;
        //     }
        //     else if (x == arr[second])
        //     {
        //         cout << "for second: " << arr[second] << "\n";
        //         opr++;
        //         second--;
        //         x++;
        //         x %= k;
        //     }
        //     else
        //     {
        //         ll diff1 = abs(x - arr[first]);
        //         ll diff2 = abs(arr[second] - x);
        //         if (diff1 < diff2)
        //         {
        //             cout << "for first: " << arr[first] << "\n";
        //             cout << "Adding: " << diff1 << "\n";
        //             opr += diff1;
        //             x += diff1;
        //             x++;
        //             x %= k;
        //             opr++;
        //             first++;
        //         }
        //         else
        //         {
        //             cout << "for second: " << arr[second] << "\n";
        //             cout << "Adding: " << diff2 << "\n";
        //             opr += diff2;
        //             x += diff2;
        //             x++;
        //             x %= k;
        //             opr++;
        //             second--;
        //         }
        //     }
        // }
        // cout << opr << "\n";
    }
    return 0;
}