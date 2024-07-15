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
    ll a, b;
    cin >> a >> b;

    ll diff = b - a;

    if (diff >= 5)
    {
        cout << 0;
        return 0;
    }

    ll last = 1;
    for (ll i = a + 1; i <= b; i++)
    {
        last *= i;
        last = last % 10;
    }
    cout << last;
    return 0;
}