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
        vector<ll> arr(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<ll> diff;
        for (ll i = 1; i < m; i++)
        {
            diff.push_back(arr[i] - arr[i - 1] - 1);
        }

        diff.push_back(arr[0] + n - arr[m - 1] - 1);
        sort(diff.begin(), diff.end(), greater<ll>());
        ll day = 0;
        ll safe = 0;
        for (ll i = 0; i < diff.size(); i++)
        {
            ll remaining = diff[i] - day * 2;
            if (remaining <= 0)
            {
                break;
            }
            safe += (remaining - 1);
            if (remaining == 1)
            {
                safe++;
            }
            day += 2;
        }
        cout << n - safe << "\n";
    }
    return 0;
}