#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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
        ll n, f, a, b;
        cin >> n >> f >> a >> b;
        vector<ll> times(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> times[i];
        }
        ll req = 0;
        ll curr = 0;
        for (ll i = 0; i < n; i++)
        {
            ll onOff = b;
            ll on = (times[i] - curr) * a;
            ll add = min(onOff, on);
            // cout << "Add is: " << add << "\n";
            req += add;
            curr = times[i];
        }
        // cout << "Req is: " << req << "\n";
        if (req < f)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
