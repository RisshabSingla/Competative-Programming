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
        ll k, x, a;
        cin >> k >> x >> a;
        ll total = 0;
        ll last = 1;
        vector<ll> arr;
        arr.push_back(1);
        bool possible = true;
        for (ll i = 1; i < x + 2; i++)
        {
            ll neededToOfset = total / (k - 1);
            arr.push_back(neededToOfset + 1);
            total += arr.back();
            if (total > a)
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}