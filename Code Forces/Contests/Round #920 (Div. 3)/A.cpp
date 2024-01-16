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
        vector<vector<ll>> points(4, vector<ll>(2, 0));
        for (ll i = 0; i < 4; i++)
        {
            cin >> points[i][0] >> points[i][1];
        }
        ll dis = LLONG_MAX;
        for (ll i = 0; i < 4; i++)
        {
            for (ll j = i + 1; j < 4; j++)
            {
                ll d = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                dis = min(d, dis);
            }
        }
        cout << dis << "\n";
    }
    return 0;
}
