#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
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
        ll bits = log2(n - 1);
        ll start = 1 << bits;
        for (ll i = n - 1; i >= start; i--)
        {
            cout << i << " ";
        }
        for (ll i = 0; i < start; i++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}