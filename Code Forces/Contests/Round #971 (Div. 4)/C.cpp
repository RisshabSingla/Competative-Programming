#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        ll xReq = (x + k - 1) / k;
        ll yReq = (y + k - 1) / k;
        if (yReq >= xReq)
        {
            cout << 2 * yReq << "\n";
        }
        else
        {
            cout << 2 * xReq - 1 << "\n";
        }
    }
    return 0;
}
