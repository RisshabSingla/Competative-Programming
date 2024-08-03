#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

        if (k > 2)
        {
            cout << 0 << "\n";
            continue;
        }
        if (k == 1)
        {
            sort(arr.begin(), arr.end());
            ll minDiff = LLONG_MAX;
            ll minElem = arr[0];
            for (ll i = 1; i < n; i++)
            {
                minDiff = min(minDiff, arr[i] - arr[i - 1]);
                minElem = min(minElem, arr[i]);
            }
            cout << min(minDiff, minElem) << "\n";
            continue;
        }

        sort(arr.begin(), arr.end());
        ll minElem = arr[0];
        ll minDiff = arr[0];
        for (ll i = 1; i < n; i++)
        {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < i; j++)
            {
                ll diff = abs(arr[i] - arr[j]);
                int index = lower_bound(arr.begin(), arr.end(), diff) - arr.begin();
                if (index < n)
                {
                    minDiff = min(minDiff, arr[index] - diff);
                }
                if (index > 0)
                    minDiff = min(minDiff, diff - arr[index - 1]);
            }
        }
        cout << minDiff << "\n";
    }

    return 0;
}