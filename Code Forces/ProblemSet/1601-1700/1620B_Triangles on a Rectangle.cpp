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
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll w, h;
        cin >> w >> h;
        vector<ll> horizontal0;
        vector<ll> horizontalw;
        vector<ll> vertical0;
        vector<ll> verticalh;
        ll k;
        cin >> k;
        for (ll i = 0; i < k; i++)
        {
            ll t;
            cin >> t;
            horizontal0.push_back(t);
        }
        cin >> k;
        for (ll i = 0; i < k; i++)
        {
            ll t;
            cin >> t;
            horizontalw.push_back(t);
        }
        cin >> k;
        for (ll i = 0; i < k; i++)
        {
            ll t;
            cin >> t;
            vertical0.push_back(t);
        }
        cin >> k;
        for (ll i = 0; i < k; i++)
        {
            ll t;
            cin >> t;
            verticalh.push_back(t);
        }
        sort(horizontal0.begin(), horizontal0.end());
        sort(horizontalw.begin(), horizontalw.end());
        sort(vertical0.begin(), vertical0.end());
        sort(verticalh.begin(), verticalh.end());

        ll a1 = (horizontal0[horizontal0.size() - 1] - horizontal0[0]) * h;
        ll a2 = (horizontalw[horizontalw.size() - 1] - horizontalw[0]) * h;
        ll a3 = (vertical0[vertical0.size() - 1] - vertical0[0]) * w;
        ll a4 = (verticalh[verticalh.size() - 1] - verticalh[0]) * w;

        cout << max({a1, a2, a3, a4}) << "\n";
    }
    return 0;
}