#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll firstMin = LLONG_MAX;
        ll secondMin = LLONG_MAX;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] < firstMin)
            {
                firstMin = arr[i];
            }
            else if (arr[i] < secondMin)
            {
                secondMin = arr[i];
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}