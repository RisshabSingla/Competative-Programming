#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll findAns(vector<ll> &arr, ll n)
{

    vector<ll> zeros(n, 0);
    if (arr[n - 1] == 0)
    {
        zeros[n - 1] = 1;
    }
    for (ll i = n - 2; i >= 0; i--)
    {
        zeros[i] = zeros[i + 1];
        if (arr[i] == 0)
        {
            zeros[i]++;
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            ans += zeros[i];
        }
    }
    return ans;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        ll first = -1;
        ll last = -1;
        vector<ll> arr(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                last = i;
            }
            if (arr[i] == 0)
            {
                if (first == -1)
                {
                    first = i;
                }
            }
        }
        ll ans = findAns(arr, n);
        arr[first] = 1;
        ll a = findAns(arr, n);
        ans = max(ans, a);
        arr[first] = 0;
        arr[last] = 0;
        a = findAns(arr, n);
        ans = max(ans, a);
        cout << ans << "\n";
    }
    return 0;
}