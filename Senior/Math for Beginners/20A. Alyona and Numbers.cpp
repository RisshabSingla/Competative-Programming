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
    ll n, m;
    cin >> n >> m;
    vector<ll> arr1(5, 0);
    vector<ll> arr2(5, 0);
    for (ll i = 0; i < 5; i++)
    {
        arr1[i] = n / 5;
    }
    for (ll i = 0; i < 5; i++)
    {
        arr2[i] = m / 5;
    }
    n = n % 5;
    m = m % 5;
    for (ll i = 1; i <= n; i++)
    {
        arr1[i]++;
    }
    for (ll i = 1; i <= m; i++)
    {
        arr2[i]++;
    }
    ll count = arr1[0] * arr2[0];
    for (ll i = 1; i < 5; i++)
    {
        count += arr1[i] * arr2[5 - i];
    }
    cout << count << "\n";

    return 0;
}