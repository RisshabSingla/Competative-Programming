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
    cin >> n >> q;
    vector<ll> arr(n + 1, 0);
    while (q--)
    {
        ll t, x;
        cin >> t >> x;
        if (t == 1)
        {
            arr[x]++;
        }
        else if (t == 2)
        {
            arr[x] += 2;
        }
        else
        {
            if (arr[x] >= 2)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}