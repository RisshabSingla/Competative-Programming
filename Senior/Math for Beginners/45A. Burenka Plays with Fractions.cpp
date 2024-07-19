#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll GCD(ll a, ll b)
{
    return b == 0 ? a : GCD(b, a % b);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll first = a * d;
        ll second = b * c;
        if (first == second)
        {
            cout << 0 << "\n";
            continue;
        }
        if (first == 0 || second == 0)
        {
            cout << 1 << "\n";
            continue;
        }

        ll gcd = GCD(first, second);
        first /= gcd;
        second /= gcd;
        ll opr = 0;
        if (first != 1)
        {
            opr++;
        }
        if (second != 1)
        {
            opr++;
        }
        cout << opr << "\n";
    }
    return 0;
}