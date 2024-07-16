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
        ll n, m;
        cin >> n >> m;
        ll k = n * m;
        vector<ll> arr(k);
        for (ll i = 0; i < k; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        ll maxi = arr[k - 1];
        ll max1 = arr[k - 1];
        ll max2 = arr[k - 2];

        ll mini = arr[0];
        ll min1 = arr[0];
        ll min2 = arr[1];

        ll ans1 = (maxi - min1) * (n - 1) + (maxi - min2) * (m - 1) + (maxi - min1) * (n * m - (n - 1) - (m - 1) - 1);
        ll ans2 = (maxi - min2) * (n - 1) + (maxi - min1) * (m - 1) + (maxi - min1) * (n * m - (n - 1) - (m - 1) - 1);

        ll ans3 = (max1 - mini) * (n - 1) + (max2 - mini) * (m - 1) + (maxi - min1) * (n * m - (n - 1) - (m - 1) - 1);
        ll ans4 = (max2 - mini) * (n - 1) + (max1 - mini) * (m - 1) + (maxi - min1) * (n * m - (n - 1) - (m - 1) - 1);

        cout << max({ans1, ans2, ans3, ans4}) << "\n";
        // ll a = arr[0];
        // ll b = arr[k - 1];
        // ll c = arr[k - 2];

        // ll ans1 = ((b - a) * n * (m - 1) + (c - a) * (n - 1));

        // a = arr[k - 1];
        // b = arr[0];
        // c = arr[1];

        // ll ans2 = ((a - b) * n * (m - 1) + (a - c) * (n - 1));
        // cout << max(ans1, ans2) << "\n";
        // if (n == 1)
        // {
        //     ll num = arr.back() - arr[0];
        //     cout << num * (m - 1) << "\n";
        //     continue;
        // }

        // if (m == 1)
        // {
        //     ll num = arr.back() - arr[0];
        //     cout << num * (n - 1) << "\n";
        //     continue;
        // }
    }
    return 0;
}