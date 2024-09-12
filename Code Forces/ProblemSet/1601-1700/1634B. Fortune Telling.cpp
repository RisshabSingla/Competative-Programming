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

// ll solve(ll index, ll &alice, ll &bob, vector<ll> &arr, ll currNum)
// {
//     if (index == 0)
//     {
//         if (currNum == alice)
//         {
//             return 1;
//         }
//         if (currNum == bob)
//         {
//             return 2;
//         }
//         return 0;
//     }
//     ll add = currNum - arr[index];
//     if (add >= 0)
//     {
//         ll ans = solve(index - 1, alice, bob, arr, add);
//         if (ans != 0)
//         {
//             return ans;
//         }
//     }
//     return solve(index - 1, alice, bob, arr, (currNum xor arr[index]));
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        ll alice = x;
        ll bob = x + 3;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if ((sum + x + y) % 2 == 0)
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }

        // set<ll> ans;
        // ans.insert(y);
        // for (ll i = n - 1; i >= 0; i--)
        // {
        //     set<ll> curr;
        //     for (auto num : ans)
        //     {
        //         if (num - arr[i] >= 0)
        //         {
        //             curr.insert(num - arr[i]);
        //         }
        //         curr.insert(num xor arr[i]);
        //     }
        //     ans = curr;
        // }
        // if (ans.count(alice))
        // {
        //     cout << "Alice\n";
        // }
        // else
        // {
        //     cout << "Bob\n";
        // }

        // ll ans = solve(n - 1, alice, bob, arr, y);
        // if (ans == 1)
        // {
        //     cout << "Bob\n";
        // }
        // else
        // {
        //     cout << "Alice\n";
        // }
    }
    return 0;
}