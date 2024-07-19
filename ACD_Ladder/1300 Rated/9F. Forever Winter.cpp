#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> adjList(n);
        vector<ll> inDegrees(n, 0);
        for (ll i = 0; i < m; i++)
        {
            ll a, b;
            cin >> a >> b;
            inDegrees[a - 1]++;
            inDegrees[b - 1]++;
            adjList[a - 1].push_back(b - 1);
            adjList[b - 1].push_back(a - 1);
        }
        map<ll, ll> first;
        ll maxi = 0;
        for (ll i = 0; i < n; i++)
        {
            if (inDegrees[i] == 1)
            {
                first[adjList[i][0]]++;
                maxi = max(maxi, first[adjList[i][0]]);
            }
        }
        ll x = first.size();
        ll y = maxi;
        cout << x << " " << y << "\n";
    }
    return 0;
}