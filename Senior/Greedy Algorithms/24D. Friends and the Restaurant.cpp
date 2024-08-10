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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            arr[i] = t - arr[i];
        }
        sort(arr.begin(), arr.end());
        ll left = 0;
        ll right = n - 1;
        ll count = 0;
        while (left < right)
        {
            ll sum = arr[left] + arr[right];
            if (sum < 0)
            {
                left++;
            }
            else
            {
                count++;
                left++;
                right--;
            }
        }
        cout << count << "\n";
    }
    return 0;
}