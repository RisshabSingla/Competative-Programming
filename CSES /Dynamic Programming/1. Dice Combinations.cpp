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
    vector<ll> arr(n + 1, 0);
    arr[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        (arr[i] += (arr[i - 1])) %= mod;
        if (i > 1)
        {
            (arr[i] += (arr[i - 2])) %= mod;
        }
        if (i > 2)
        {
            (arr[i] += (arr[i - 3])) %= mod;
        }
        if (i > 3)
        {
            (arr[i] += (arr[i - 4])) %= mod;
        }
        if (i > 4)
        {
            (arr[i] += (arr[i - 5])) %= mod;
        }
        if (i > 5)
        {
            (arr[i] += (arr[i - 6])) %= mod;
        }
    }
    // for (ll i = 0; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    cout << arr[n];

    return 0;
}