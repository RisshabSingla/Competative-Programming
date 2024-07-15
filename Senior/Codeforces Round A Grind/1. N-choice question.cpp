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
    ll n, a, b;
    cin >> n >> a >> b;
    ll sum = a + b;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        if (t == sum)
        {
            cout << i + 1;
        }
    }
    return 0;
}