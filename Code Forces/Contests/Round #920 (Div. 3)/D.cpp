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

// bool comp(vector<ll> &a, vector<ll> &b)
// {
//     ll diff1 = abs(a[1] - b[1]);
//     ll diff2 = abs(b[1] - a[0]);
//     if (a[0] == LLONG_MAX)
//     {
//         diff1 = 0;
//     }
//     if (b[0] == LLONG_MAX)
//     {
//         diff2 = 0;
//     }
//     return diff1 > diff2;
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> arr1(n);
        vector<ll> arr2(m);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (ll i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end(), greater());
        ll count = 0;
        ll start1 = 0;
        ll start2 = 0;
        ll end1 = n - 1;
        ll end2 = m - 1;
        for (ll i = 0; i < n; i++)
        {
            if (abs(arr1[start1] - arr2[start2]) >
                abs(arr1[end1] - arr2[end2]))
            {
                count += abs(arr1[start1] - arr2[start2]);
                start1++;
                start2++;
            }
            else
            {
                count += abs(arr1[end1] - arr2[end2]);
                end1--;
                end2--;
                // arr1.pop_back();
                // arr2.pop_back();
            }
        }
        cout << count << "\n";
        // if (n == 1)
        // {
        //     cout << abs(arr1[0] - arr2[0]) << "\n";
        //     continue;
        // }
        // ll ans = 0;
        // for (ll cut = 0; cut < n; cut++)
        // {
        //     ll count = 0;
        //     for (ll i = 0; i < cut; i++)
        //     {
        //         count += abs(arr1[i] - arr2[i]);
        //     }
        //     for (ll i = 0; i < n - cut; i++)
        //     {
        //         count += abs(arr1[n - 1 - i] - arr2[m - 1 - i]);
        //     }
        //     ans = max(ans, count);
        // }
        // cout << ans << "\n";
    }

    return 0;
}
