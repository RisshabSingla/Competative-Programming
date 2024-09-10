#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    // vector<set<ll>> possibleNums(10);
    // for (ll i = 0; i < 10; i++)
    // {
    //     ll num = i;
    //     while (!possibleNums[i].count(num))
    //     {
    //         possibleNums[i].insert(num);
    //         num += num % 10;
    //         num = num % 10;
    //     }
    // }

    // for (auto i : possibleNums)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    while (cases--)
    {
        ll n;
        cin >> n;

        vector<ll> arr(n);
        vector<ll> count(2, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 10 == 0)
            {
                count[0]++;
            }
            else if (arr[i] % 10 == 5)
            {
                count[0]++;
                arr[i] += 5;
            }
            else
            {
                count[1]++;
                while (arr[i] % 10 != 2)
                {
                    arr[i] += arr[i] % 10;
                }
            }
        }

        if (count[0] == n)
        {
            sort(arr.begin(), arr.end());
            if (arr[0] == arr.back())
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            sort(arr.begin(), arr.end());
            bool flag = false;
            for (ll i = 1; i < n; i++)
            {
                if ((arr[i] - arr[i - 1]) % 20 != 0)
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }

        // vector<set<ll>> possible(n);
        // for (ll i = 0; i < n; i++)
        // {
        //     ll t;
        //     cin >> t;
        //     t = t % 10;
        //     possible[i] = possibleNums[t];
        // }
        // bool ansPossible = false;
        // for (ll i = 0; i < 10; i++)
        // {
        //     ll j = 0;
        //     for (j = 0; j < n; j++)
        //     {
        //         if (!possible[j].count(i))
        //         {
        //             break;
        //         }
        //     }
        //     if (j == n)
        //     {
        //         ansPossible = true;
        //         break;
        //     }
        // }
        // if (ansPossible)
        // {
        //     cout << "YES\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        // }
    }
    return 0;
}