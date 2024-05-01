#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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
        unordered_map<int, int> bs;
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            bs[i] = t;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (i == bs[bs[i]])
            {
                ans = 2;
                break;
            }
        }
        cout << min(ans, 3) << "\n";

        // int ans = INT_MAX;
        // for (int i = 1; i <= n; i++)
        // {
        //     vector<bool> invited(n, false);
        //     invited[i - 1] = true;
        //     int best = bs[i];
        //     int count = 1;
        //     cout << "best: " << best << " ";
        //     while (!invited[best - 1])
        //     {
        //         invited[best - 1] = true;
        //         count++;
        //         best = bs[best];
        //         cout << best << " ";
        //     }
        //     cout << "\n";
        //     cout << "i: " << i << " count: " << count << "\n";
        //     ans = min(ans, count);
        // }
        // cout << ans << "\n";
    }
    return 0;
}
