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
        ll n, x, m;
        cin >> n >> x >> m;
        vector<pair<ll, ll>> arr;
        arr.push_back({x - 1, x - 1});
        while (m--)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            if (b < arr[0].first)
            {
                continue;
            }
            if (a > arr[0].second)
            {
                continue;
            }
            arr[0].first = min(arr[0].first, a);
            arr[0].second = max(arr[0].second, b);
        }
        cout << arr[0].second - arr[0].first + 1 << "\n";
    }
    return 0;
}