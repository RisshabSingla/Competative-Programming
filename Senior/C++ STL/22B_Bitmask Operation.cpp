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
    ll n, q;
    cin >> q >> n;
    while (q--)
    {
        ll t, x;
        cin >> t >> x;
        if (t == 1)
        {
            if (n >> x & 1)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (t == 2)
        {
            n |= (1 << x);
            cout << n << "\n";
        }
        else if (t == 3)
        {
            n = n & ~(1 << x);
            cout << n << "\n";
        }
        else
        {
            n = n xor (1 << x);
            cout << n << "\n";
        }
    }
    return 0;
}