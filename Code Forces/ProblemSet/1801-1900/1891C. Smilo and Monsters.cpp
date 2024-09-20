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
        ll n;
        cin >> n;

        vector<ll> arr(n);
        ll totalSum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            totalSum += arr[i];
        }
        sort(arr.begin(), arr.end());
        ll ans = 0;
        if (totalSum % 2)
        {
            ans = 1;
            arr[0]--;
        }
        ll currSum = 0;
        ll index = 0;
        while (currSum + arr[index] <= (totalSum / 2))
        {
            currSum += arr[index];
            index++;
        }
        cout << ans + (totalSum / 2) + (n - index) << '\n';
    }
    return 0;
}