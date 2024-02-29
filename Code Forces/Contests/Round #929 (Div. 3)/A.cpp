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
        ll n;
        cin >> n;
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            t = abs(t);
            sum += t;
        }
        cout << sum << "\n";
    }
    return 0;
}
