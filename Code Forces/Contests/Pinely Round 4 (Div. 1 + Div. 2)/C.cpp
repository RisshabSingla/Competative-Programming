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
    // vector<ll> powers;
    // for (ll i = 30; i >= 0; i--)
    // {
    //     powers.push_back(1LL << i);
    // }
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        bool isPossible = true;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] % 2 != arr[0] % 2)
            {
                isPossible = false;
                break;
            }
        }
        if (!isPossible)
        {
            cout << "-1\n";
            continue;
        }

        vector<ll> operations;
        for (ll i = 0; i < 40; i++)
        {
            if (sum == 0)
            {
                break;
            }
            ll mini = LLONG_MAX;
            ll maxi = LLONG_MIN;
            for (auto x : arr)
            {
                mini = min(mini, x);
                maxi = max(maxi, x);
            }
            ll med = (maxi + mini) / 2;
            operations.push_back(med);
            for (auto &x : arr)
            {
                sum -= x;
                x = abs(x - med);
                sum += x;
            }
        }

        if (sum == 0)
        {
            cout << operations.size() << "\n";
            for (auto i : operations)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
        // if (sum == 0)
        // {
        //     cout << 0 << "\n\n";
        //     continue;
        // }
        // vector<ll> operations;
        // ll prevMedian = -1;
        // for (ll i = 0; i < 40; i++)
        // {
        //     if (sum == 0)
        //     {
        //         break;
        //     }
        //     sort(arr.begin(), arr.end());
        //     ll median = 0;
        //     if (n % 2)
        //     {
        //         median = arr[n / 2];
        //     }
        //     else
        //     {
        //         median = (arr[n / 2] + arr[(n / 2) + 1]) / 2;
        //     }
        //     if (median == 0)
        //     {
        //         median = arr[n - 1];
        //     }
        //     if (median == prevMedian)
        //     {
        //         median /= 2;
        //     }
        //     prevMedian = median;
        //     for (auto &num : arr)
        //     {
        //         sum -= num;
        //         num = abs(num - median);
        //         sum += num;
        //     }
        //     // cout << "Median: " << median << "\n";
        //     // for (auto x : arr)
        //     // {
        //     //     cout << x << " ";
        //     // }
        //     // cout << "\n";
        //     operations.push_back(median);
        // }

        // if (sum != 0)
        // {
        //     cout << -1 << "\n";
        //     continue;
        // }
        // cout << operations.size() << "\n";
        // for (auto i : operations)
        // {
        //     cout << i << ' ';
        // }
        // cout << "\n";

        // for (auto i : arr)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";

        // ll opr = 0;

        // vector<ll> operations;
        // for (ll i = 0; i < 30; i++)
        // {
        //     if (sum == 0)
        //     {
        //         break;
        //     }
        //     operations.push_back(powers[i]);
        //     for (ll j = 0; j < n; j++)
        //     {
        //         sum -= arr[j];
        //         arr[j] = abs(arr[j] - powers[i]);
        //         sum += arr[j];
        //     }
        // }
        // if (sum == 0)
        // {
        //     cout << operations.size() << "\n";
        //     for (auto i : operations)
        //     {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // }
        // else
        // {
        //     cout << -1 << "\n";
        // }
    }
    return 0;
}
