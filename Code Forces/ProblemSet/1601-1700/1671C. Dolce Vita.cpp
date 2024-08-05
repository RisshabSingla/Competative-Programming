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
        ll n, x;
        cin >> n >> x;
        vector<ll> arr(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr.begin(), arr.end());
        ll day = 0;
        ll count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (sum > x)
            {
                sum -= (arr[i] + day);
                continue;
            }
            ll rem = x - sum;
            ll canBuy = (rem / (i + 1)) + 1;
            count += (canBuy) * (i + 1);
            day += (canBuy);
            sum += (canBuy) * (i + 1);
            sum -= (arr[i] + day);
        }
        cout << count << "\n";
    }
    return 0;
}