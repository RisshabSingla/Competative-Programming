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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i + 1;
        }
        sort(arr.begin(), arr.end());
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                if ((arr[i].first * arr[j].first) == (arr[i].second + arr[j].second))
                {
                    ans++;
                }
                if ((arr[i].first * arr[j].first) > 2 * n)
                {
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}