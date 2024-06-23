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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    if (sum - arr[n - 1] < arr[n - 1])
    {
        cout << (2 * arr[n - 1]) << "\n";
    }
    else
    {
        cout << sum << "\n";
    }
    return 0;
}