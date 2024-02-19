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
        ll count = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            int t = 0;
            cin >> t;
            count += t;
            // cout << "Count is: " << count << "\n";
        }
        // cout << "Count is: " << count << "\n";
        if (count < 0)
        {
            cout << abs(count) << "\n";
        }
        else
        {
            cout << -count << "\n";
        }
    }
    return 0;
}