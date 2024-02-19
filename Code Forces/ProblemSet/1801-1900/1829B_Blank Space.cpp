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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll max_count = 0;
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                count++;
                max_count = max(max_count, count);
            }
            else
            {
                max_count = max(max_count, count);
                count = 0;
            }
        }
        cout << max_count << "\n";
    }
    return 0;
}