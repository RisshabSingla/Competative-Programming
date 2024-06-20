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
    ll sum = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        ll t;
        cin >> t;
        sum += t;
    }
    cout << ((n) * (n + 1)) / 2 - sum << "\n";

    return 0;
}