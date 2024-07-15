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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll mini = max(arr[0] - k, 0LL);
        ll maxi = arr[0] + k;
        ll count = 0;
        for (ll i = 1; i < n; i++)
        {
            ll lower = max(arr[i] - k, 0LL);
            ll upper = arr[i] + k;
            if (lower > maxi || upper < mini)
            {
                count++;
                mini = lower;
                maxi = upper;
            }
            mini = max(mini, lower);
            maxi = min(maxi, upper);
        }
        cout << count << "\n";
    }
    return 0;
}