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
        vector<int> arr(k);
        int ones = 0;
        for (ll i = 0; i < k; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                ones++;
            }
        }
        sort(arr.begin(), arr.end());

        if (arr[k - 1] == 1)
        {
            // all ones
            cout << k - 1 << "\n";
            continue;
        }
        ll ans = 0;
        bool left = false;
        for (ll i = k - 1; i >= 0 && arr[i] != 1; i--)
        {
            if (arr[i] != 1)
            {
                if (left)
                {
                    ans += (arr[i] - 1);
                    ones += arr[i];
                }
                left = true;
            }
        }
        // cout << ans << " " << ones << "\n";
        ans += ones;
        cout << ans << "\n";
    }
    return 0;
}
