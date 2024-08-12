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

ll findDistance(vector<ll> &a, vector<ll> &b)
{
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> arr(n);
        for (ll i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            arr[i] = {a, b};
        }
        ll sX, sY, eX, eY;
        cin >> sX >> sY >> eX >> eY;
        vector<ll> distancesStart(n, 0);
        vector<ll> distancesEnd(n, 0);
        vector<ll> start{sX, sY};
        vector<ll> end{eX, eY};
        for (ll i = 0; i < n; i++)
        {
            distancesStart[i] = findDistance(arr[i], start);
            distancesEnd[i] = findDistance(arr[i], end);
        }

        ll distance = findDistance(start, end);
        ll totalTime = distance;
        bool possible = true;
        for (ll i = 0; i < n; i++)
        {
            if (distancesEnd[i] <= totalTime)
            {
                possible = false;
                break;
            }
        }
        if (possible)
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
