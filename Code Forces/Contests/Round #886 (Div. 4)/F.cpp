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
        int n;
        cin >> n;
        // vector<int> arr(n);
        map<int, int> arr;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            arr[t]++;
        }
        vector<ll> traps(n + 1, 0);

        for (auto i : arr)
        {
            for (int j = i.first; j <= n; j += i.first)
            {
                traps[j] += i.second;
            }
        }
        int ans = *max_element(traps.begin(), traps.end());
        cout << ans << endl;

        // for (int i = 0; i < n; i++)
        // {
        //     int num = arr[i];
        //     while (num <= n)
        //     {
        //         possible[num]++;
        //         num += arr[i];
        //     }
        // }
        // int ans = 0;
        // for (int i = 0; i <= n; i++)
        // {
        //     if (possible[i] > ans)
        //     {
        //         ans = possible[i];
        //     }
        // }
        // cout<< ans << endl;
    }
    return 0;
}
