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
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if (k == 0)
    {
        ll number = arr[0] - 1;
        if (number < 1)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << number << "\n";
        }
        return 0;
        // cout <<  << "\n";
    }
    if (k < n && arr[k - 1] != arr[k])
    {
        cout << arr[k - 1] << "\n";
    }
    else if (k < n && arr[k - 1] == arr[k])
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << arr[k - 1] << "\n";
    }

    return 0;
}