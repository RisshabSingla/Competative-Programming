#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
        vector<ll> arr(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> ans(n + 1, 1);
        ll maxi = 1;
        for (ll i = 2; i <= n; i++)
        {
            for (ll j = 1; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    ll num1 = i / j;
                    ll num2 = j;
                    if (arr[i] > arr[num1])
                    {
                        ans[i] = max(ans[i], ans[num1] + 1);
                        maxi = max(maxi, ans[i]);
                    }
                    if (arr[i] > arr[num2])
                    {
                        ans[i] = max(ans[i], ans[num2] + 1);
                        maxi = max(maxi, ans[i]);
                    }
                }
            }
        }
        // for (auto i : ans)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        cout << maxi << "\n";
    }
    return 0;
}