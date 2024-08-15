#include <iostream>
#include <vector>
#include <cmath>
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
        if (n % 2 == 0)
        {
            cout << n / 2 << " " << n / 2 << "\n";
            continue;
        }
        ll a = 1;
        ll b = n - 1;
        for (ll i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                a = n / i;
                b = n - a;
                break;
            }
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}