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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> count(32, 0);
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < 32; j++)
            {
                if (arr[i] & (1LL << j))
                {
                    count[j]++;
                }
            }
        }
        // for (auto i : count)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        for (ll i = 30; i >= 0; i--)
        {
            ll req = n - count[i];
            if (req <= k)
            {
                count[i] = n;
                k -= req;
            }
        }
        // for (auto i : count)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        ll number = 0;
        for (ll i = 31; i >= 0; i--)
        {
            if (count[i] == n)
            {
                // cout << "Or with: " << (1LL << i) << "\n";
                number = number | (1LL << i);
            }
        }
        cout << number << "\n";
    }
    return 0;
}