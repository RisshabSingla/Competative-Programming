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

        ll num1 = LLONG_MAX;
        ll num2 = LLONG_MAX;
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            if (num1 > num2)
            {
                swap(num1, num2);
            }
            if (arr[i] <= num1)
            {
                num1 = arr[i];
            }
            else if (arr[i] <= num2)
            {
                num2 = arr[i];
            }
            else
            {
                num1 = arr[i];
                count++;
            }
            // // cout << "Num1: " << num1 << " num2: " << num2 << "\n";
            // if (num1 == LLONG_MAX)
            // {
            //     num1 = arr[i];
            // }
            // else if (num2 == LLONG_MAX)
            // {
            //     num2 = arr[i];
            // }
            // else
            // {
            //     if (num1 == arr[i] || num2 == arr[i])
            //     {
            //         continue;
            //     }
            //     if (num1 >= num2)
            //     {
            //         if (num1 >= arr[i])
            //         {
            //             num1 = arr[i];
            //         }
            //         else
            //         {
            //             num1 = arr[i];
            //             count++;
            //         }
            //     }
            //     else
            //     {
            //         if (num2 >= arr[i])
            //         {
            //             num2 = arr[i];
            //         }
            //         else
            //         {
            //             num2 = arr[i];
            //             count++;
            //         }
            //     }
            // }
        }
        cout << count << "\n";

        // ll count = 0;
        // for (ll i = 1; i < n; i++)
        // {
        //     if (arr[i] > arr[i - 1])
        //     {
        //         count++;
        //     }
        // }
        // cout << max(count - 1, 0LL) << "\n";
    }
    return 0;
}