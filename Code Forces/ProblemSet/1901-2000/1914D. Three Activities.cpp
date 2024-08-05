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
        ll n;
        cin >> n;
        vector<pair<ll, ll>> arr(n);
        vector<pair<ll, ll>> brr(n);
        vector<pair<ll, ll>> crr(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> brr[i].first;
            brr[i].second = i;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> crr[i].first;
            crr[i].second = i;
        }
        sort(arr.begin(), arr.end(), greater<pair<ll, ll>>());
        sort(brr.begin(), brr.end(), greater<pair<ll, ll>>());
        sort(crr.begin(), crr.end(), greater<pair<ll, ll>>());
        ll ans = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i].second == brr[j].second)
                {
                    continue;
                }
                for (int k = 0; k < 3; k++)
                {
                    if (arr[i].second == crr[k].second || brr[j].second == crr[k].second)
                    {
                        continue;
                    }
                    ans = max(ans, arr[i].first + brr[j].first + crr[k].first);
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}