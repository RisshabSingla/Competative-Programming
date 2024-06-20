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
    ll odd = 0;
    ll even = 0;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        if (t % 2)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    if (odd % 2)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    return 0;
}