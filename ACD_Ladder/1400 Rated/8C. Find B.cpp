#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
        ll n, q;
        cin >> n >> q;
        vector<ll> arr(n + 1);
        vector<ll> count(n + 1, 0);
        vector<ll> sum(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
            count[i] = count[i - 1];
            if (arr[i] == 1)
            {
                count[i]++;
            }
        }
        while (q--)
        {
            ll a, b;
            cin >> a >> b;
            ll windowSum = sum[b] - sum[a - 1];
            ll ones = count[b] - count[a - 1];
            windowSum -= (b - a + 1);
            if (ones == 0)
            {
                if (a == b)
                {
                    cout << "NO\n";
                }
                else
                {
                    cout << "YES\n";
                }
            }
            else
            {
                if (windowSum >= ones)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}