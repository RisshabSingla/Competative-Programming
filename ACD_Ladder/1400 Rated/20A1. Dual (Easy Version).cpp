#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

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
    while (cases--)
    {

        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll maxElem = LLONG_MIN;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > 0)
            {
                maxElem = max(maxElem, arr[i]);
            }
        }
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        if (maxElem == LLONG_MIN)
        {
            // no positive element
            // cout << "NOPOS\n";
            cout << n - 1 << '\n';
            for (ll i = n - 1; i > 0; i--)
            {
                cout << i << ' ' << i + 1 << "\n";
            }
            cout << "\n";
            continue;
        }

        auto maxi = max_element(arr.begin(), arr.end());

        ll val = *maxi;
        ll index = maxi - arr.begin() + 1;
        vector<pll> ans;
        while (val <= 20)
        {
            val += val;
            ans.push_back({index, index});
        }
        ans.push_back({2, index});
        ans.push_back({2, index});
        for (ll i = 3; i <= n; i++)
        {
            ans.push_back({i, i - 1});
            ans.push_back({i, i - 1});
        }

        cout << ans.size() << "\n";
        for (auto i : ans)
        {
            cout << i.first << " " << i.second << "\n";
        }
        cout << "\n";

        // ll n;
        // cin >> n;
        // vector<ll> arr(n);
        // set<pll> st;
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        //     st.insert({arr[i], i});
        // }
        // vector<pll> ans;
        // for (ll i = 1; i < n; i++)
        // {
        //     if (arr[i] < arr[i - 1])
        //     {
        //         auto itr = st.upper_bound({arr[i - 1], i - 1});
        //         if (itr == st.end())
        //         {
        //             --itr;
        //         }
        //         // if (itr != st.begin())
        //         // {
        //         //     --itr;
        //         // }
        //         ll val = itr->first;
        //         ll index = itr->second;
        //         ll div = abs(arr[i - 1] - arr[i]) / val;
        //         if ((abs(arr[i - 1] - arr[i]) % val))
        //         {
        //             div++;
        //         }
        //         ll nVal = arr[i] + (div * val);
        //         while (div--)
        //         {
        //             ans.push_back({i, index});
        //         }
        //         st.erase(st.lower_bound({arr[i], i}));
        //         st.insert({nVal, i});
        //         arr[i] = nVal;
        //     }
        // }
        // cout << ans.size() << "\n";
        // for (auto i : ans)
        // {
        //     cout << i.first + 1 << " " << i.second + 1 << "\n";
        // }
        // cout << "\n";
    }
    return 0;
}