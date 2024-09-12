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

bool isPossible(vector<ll> &arr, ll val, ll n)
{
    ll currXor = 0;
    vector<bool> hasOcc(256, false);
    for (ll i = 0; i < n; i++)
    {
        currXor = currXor xor arr[i];
        if (currXor == val || hasOcc[currXor xor val])
        {
            return true;
        }
        hasOcc[currXor] = true;
    }
    return false;
}

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

        ll ans = 0;
        for (ll i = 255; i >= 0; i--)
        {
            if (isPossible(arr, i, n))
            {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}