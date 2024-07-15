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
        string str;
        cin >> str;
        vector<ll> arr(n + 1, 0);
        for (ll i = n - 1; i >= 0; i--)
        {
            arr[i] = arr[i + 1];
            if (str[i] == 'W')
            {
                arr[i]++;
            }
        }

        ll ans = INT_MAX;
        for (ll i = n - k; i >= 0; i--)
        {
            ll opr = arr[i] - arr[i + k];
            ans = min(ans, opr);
        }
        cout << ans << "\n";
    }
    return 0;
}