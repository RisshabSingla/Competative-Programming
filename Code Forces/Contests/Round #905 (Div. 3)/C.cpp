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
        ll n, k;
        cin >> n >> k;
        vector<int> arr(n);
        bool check = false;
        ll prod = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (k == 2 || k == 3 || k == 5)
        {
            int ans = 20;
            for (int i = 0; i < n; i++)
            {
                int diff = ((arr[i] + k - 1) / k) * k - arr[i];
                ans = min(ans, diff);
            }
            cout << ans << endl;
            continue;
        }
        int ans = 20;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int diff = ((arr[i] + k - 1) / k) * k - arr[i];
            ans = min(ans, diff);
            count += (arr[i] % 2 == 0);
        }
        count = min(2, count);
        ans = min(2 - count, ans);
        cout << ans << endl;
    }
    return 0;
}
