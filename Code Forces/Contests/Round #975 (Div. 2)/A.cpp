#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll count1 = 0;
        ll maxi1 = 0;
        for (ll i = 0; i < n; i += 2)
        {
            count1++;
            maxi1 = max(maxi1, arr[i]);
        }
        ll count2 = 0;
        ll maxi2 = 0;
        for (ll i = 1; i < n; i += 2)
        {
            count2++;
            maxi2 = max(maxi2, arr[i]);
        }
        cout << max(maxi1 + count1, maxi2 + count2) << "\n";
    }
    return 0;
}
