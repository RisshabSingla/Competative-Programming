#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
        unordered_map<ll, ll> bits;
        vector<vector<ll>> arr(n);
        for (ll i = 0; i < n; i++)
        {
            ll k;
            cin >> k;
            while (k--)
            {
                ll bit;
                cin >> bit;
                bits[bit - 1]++;
                arr[i].push_back(bit - 1);
            }
        }
        bool ans = false;
        for (auto num : arr)
        {
            bool possible = true;
            for (auto bit : num)
            {
                if (bits[bit] == 1)
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                ans = true;
                break;
            }
        }
        if (!ans)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}