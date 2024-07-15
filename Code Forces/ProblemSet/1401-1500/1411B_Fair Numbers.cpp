#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isFair(ll n)
{
    ll num = n;
    while (n > 0)
    {
        ll last = n % 10;
        if (last != 0 && num % last != 0)
        {
            return false;
        }
        n = n / 10;
    }
    return true;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        while (!isFair(n))
        {
            n++;
        }
        cout << n << "\n";
    }
    return 0;
}