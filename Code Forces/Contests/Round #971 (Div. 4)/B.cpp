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
        ll n;
        cin >> n;
        vector<ll> indexes;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < 4; j++)
            {
                char ch;
                cin >> ch;
                if (ch == '#')
                {
                    indexes.push_back(j + 1);
                }
            }
        }
        for (ll i = n - 1; i >= 0; i--)
        {
            cout << indexes[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
