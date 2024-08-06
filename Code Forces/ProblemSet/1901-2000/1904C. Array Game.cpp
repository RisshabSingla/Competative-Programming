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
        ll miniElem = LLONG_MAX;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            miniElem = min(arr[i], miniElem);
        }
        if (k > 2)
        {
            cout << 0 << "\n";
            continue;
        }
        sort(arr.begin(), arr.end());
        ll minDiff = miniElem;
        for (ll i = 1; i < n; i++)
        {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }
        if (k == 1)
        {
            cout << minDiff << "\n";
            continue;
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < i; j++)
            {
                ll diff = arr[i] - arr[j];
                ll index = lower_bound(arr.begin(), arr.end(), diff) - arr.begin();
                if (index < n)
                {
                    minDiff = min(minDiff, arr[index] - diff);
                }
                if (index > 0)
                {
                    minDiff = min(minDiff, diff - arr[index - 1]);
                }
            }
        }
        cout << minDiff << "\n";
    }
    return 0;
}