#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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
        sort(arr.begin(), arr.end(), greater<ll>());
        ll prev = 0;
        ll alice = 0;
        ll bob = 0;
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                prev = arr[i];
                alice += arr[i];
            }
            else
            {
                ll add = prev - arr[i];
                if (add <= k)
                {
                    k -= add;
                    bob += prev;
                }
                else
                {
                    bob += (arr[i] + k);
                    k = 0;
                }
            }
        }
        cout << alice - bob << "\n";
    }
    return 0;
}
