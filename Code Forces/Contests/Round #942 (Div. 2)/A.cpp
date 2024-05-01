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
        vector<ll> arr1(n);
        vector<ll> arr2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr1[i] > arr2[i])
            {
                arr1.insert(lower_bound(arr1.begin(), arr1.end(), arr2[i]), arr2[i]);
                arr1.pop_back();
                ans++;
            }
        }
        cout << ans << "\n";
        // cout << "Here\n";
        // int ans = 0;
        // while (count != 0)
        // {
        //     cout << "count is: " << count << "\n";
        //     int i;
        //     for (i = 0; i < n; i++)
        //     {
        //         if (arr1[i] > arr2[i])
        //         {
        //             arr1.push_back(arr2[i]);
        //             ans++;
        //             break;
        //         }
        //     }
        //     sort(arr1.begin(), arr1.end());

        //     arr1.erase(arr1.begin() + n - 1);

        //     count = 0;
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (arr1[i] > arr2[i])
        //         {
        //             count++;
        //         }
        //     }
        // }
        // cout << ans << "\n";
    }
    return 0;
}
