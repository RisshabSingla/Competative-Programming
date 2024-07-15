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
        ll n;
        cin >> n;
        ll c = 1;
        ll a, b;
        for (ll i = 2;; i++)
        {
            a = i;
            b = n - 1 - a;
            if (__gcd(a, b) == c)
            {
                if (a != b && b != c && a != c)
                {
                    cout << a << " " << b << " " << c << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}