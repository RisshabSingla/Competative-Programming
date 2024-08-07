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

ll result(ll a, ll b)
{
    if (a == b)
    {
        return 0;
    }
    if (a > b)
    {
        return 1;
    }
    return -1;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll total = 0;
        if (result(a, c) + result(b, d) > 0)
        {
            total++;
        }
        if (result(a, d) + result(b, c) > 0)
        {
            total++;
        }
        if (result(b, c) + result(a, d) > 0)
        {
            total++;
        }
        if (result(b, d) + result(a, c) > 0)
        {
            total++;
        }

        cout << total << "\n";
    }
    return 0;
}
