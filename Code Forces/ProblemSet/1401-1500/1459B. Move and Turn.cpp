#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{

    ll n;
    cin >> n;

    if (n == 1)
    {
        cout << 4 << "\n";
        return 0;
    }
    if (n % 2 == 0)
    {
        cout << (n / 2 + 1) * (n / 2 + 1) << "\n";
    }
    else
    {
        cout << 2 * (n / 2 + 1) * (n / 2 + 2) << "\n";
    }
    // set<vector<ll>> st;
    // n--;
    // st.insert({1, 0, 0});
    // st.insert({-1, 0, 0});
    // st.insert({0, 1, 1});
    // st.insert({0, -1, 1});
    // if (n == 0)
    // {
    //     cout << st.size() << "\n";
    //     return 0;
    // }
    // for (ll i = 0; i < n; i++)
    // {
    //     set<vector<ll>> nst;
    //     for (auto i : st)
    //     {
    //         if (i[2] == 0)
    //         {
    //             // move in y dir
    //             nst.insert({i[0], i[1] - 1, 1});
    //             nst.insert({i[0], i[1] + 1, 1});
    //         }
    //         else
    //         {
    //             // mode in x dir
    //             nst.insert({i[0] + 1, i[1], 0});
    //             nst.insert({i[0] - 1, i[1], 0});
    //         }
    //     }
    //     st = nst;
    // }
    // set<pair<ll, ll>> ans;
    // for (auto i : st)
    // {
    //     ans.insert({i[0], i[1]});
    // }
    // // for (auto i : st)
    // // {
    // //     cout << i[0] << ' ' << i[1] << "\n";
    // // }
    // cout << ans.size() << "\n";
    return 0;
}