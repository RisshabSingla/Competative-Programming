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

    ll n, x;
    cin >> n >> x;
    ll i;
    for (i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        if (t == x)
        {
            break;
        }
    }
    cout << i + 1 << "\n";
    return 0;
}