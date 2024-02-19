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
    ll minimum = LLONG_MAX;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        minimum = min(minimum, abs(t));
    }
    cout << minimum << "\n";

    return 0;
}