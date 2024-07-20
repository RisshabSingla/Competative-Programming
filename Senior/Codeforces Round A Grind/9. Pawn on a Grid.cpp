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
    ll n, m;
    cin >> n >> m;
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '#')
            {
                count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}