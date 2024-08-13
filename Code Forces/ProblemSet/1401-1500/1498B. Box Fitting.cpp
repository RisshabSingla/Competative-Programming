#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(vector<ll> count, ll height, ll w)
{
    for (ll i = 0; i < height; i++)
    {
        ll currW = w;
        for (ll j = 31; j >= 0; j--)
        {
            if (count[j] == 0)
            {
                continue;
            }
            ll canFit = currW / (1LL << j);
            ll put = min(canFit, count[j]);
            currW -= ((1LL << j) * put);
            count[j] -= put;
            // cout << "Putting: " << put << " : " << (1LL << j) << "\n";
        }
    }
    for (auto i : count)
    {
        if (i != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, w;
        cin >> n >> w;
        vector<ll> arr(n);
        vector<ll> count(32, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            count[log2(arr[i])]++;
        }
        // for (auto i : count)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";

        ll low = 1;
        ll high = n;
        ll ans = 0;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (isPossible(count, mid, w))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << ans << "\n";

        // sort(arr.begin(), arr.end());
        // for (auto i : arr)
        // {
        //     cout << i << " ";
        // }

        // cout << "\n";
        // ll left = 0;
        // ll right = n - 1;
        // ll count = 0;
        // while (left <= right)
        // {
        //     ll sum = 0;
        //     while (right >= left && sum + arr[right] <= w)
        //     {
        //         sum += arr[right];
        //         // cout << "adding: " << arr[right];
        //         right--;
        //     }
        //     while (left <= right && sum + arr[left] <= w)
        //     {
        //         sum += arr[left];
        //         // cout << " adding: " << arr[left];
        //         left++;
        //     }
        //     // cout << " Done\n";
        //     count++;
        // }
        // cout << count << "\n";
    }
    return 0;
}