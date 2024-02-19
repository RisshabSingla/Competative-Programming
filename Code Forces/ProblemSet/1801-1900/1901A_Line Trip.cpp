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
        ll n, x;
        cin >> n >> x;
        vector<ll> arr(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        ll max_dist = 0;
        for (ll i = 1; i <= n; i++)
        {
            max_dist = max(max_dist, arr[i] - arr[i - 1]);
        }
        ll last = 2 * (x - arr[n]);
        cout << max(max_dist, last) << "\n";
    }
    return 0;
}