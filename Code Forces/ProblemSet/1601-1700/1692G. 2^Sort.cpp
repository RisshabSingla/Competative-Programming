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
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> ans;
        ll count = 0;
        for (ll i = 1; i < n; i++)
        {
            if (arr[i] * 2 - arr[i - 1] > 0)
            {
                count++;
            }
            else
            {
                ans.push_back(count);
                count = 0;
            }
        }
        if (count != 0)
        {
            ans.push_back(count);
        }
        ll fAns = 0;
        // cout << "Ans is: ";
        for (auto i : ans)
        {
            // cout << i << ' ';

            fAns += max(i - k + 1, 0LL);
        }
        // cout << "\n";
        cout << fAns << "\n";
    }
    return 0;
}