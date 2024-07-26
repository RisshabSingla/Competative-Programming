#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// ll solve(vector<ll> &arr, string &str, ll index, ll count)
// {
//     if (index == -1)
//     {
//         return 0;
//     }

//     if (str[index] == '1')
//     {
//         ll a = solve(arr, str, index - 1, count) + arr[index];
//         ll b = solve(arr, str, index - 1, count + 1);
//         return max(a, b);
//     }
//     if (count > 0)
//     {
//         ll a = solve(arr, str, index - 1, count - 1) + arr[index];
//         ll b = solve(arr, str, index - 1, count);
//         return max(a, b);
//     }
//     return solve(arr, str, index - 1, count);
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        string str;
        cin >> str;
        vector<ll> arr(n, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll curr = 0;
        for (ll i = n - 1; i >= 0;)
        {
            if (str[i] == '1')
            {
                ll minVal = arr[i];
                while (i >= 0)
                {
                    minVal = min(minVal, arr[i]);
                    if (str[i] == '1')
                    {
                        curr += arr[i];
                        i--;
                    }
                    else
                    {
                        curr += arr[i];
                        i--;
                        curr -= minVal;
                        break;
                    }
                }
            }
            else
            {
                i--;
            }
        }
        cout << curr << "\n";

        // for (ll i = 0; i < n; i++)
        // {
        //     if (str[i] == '1')
        //     {
        //         covered[i] = true;
        //     }
        // }

        // for (ll i = 1; i < n; i++)
        // {
        //     if (covered[i])
        //     {
        //         if (arr[i - 1] > arr[i])
        //         {
        //             covered[i - 1] = true;
        //             covered[i] = false;
        //         }
        //     }
        // }
        // ll count = 0;
        // for (ll i = 0; i < n; i++)
        // {
        //     if (covered[i])
        //     {
        //         count += arr[i];
        //     }
        // }
        // cout << count << "\n";
    }
    return 0;
}