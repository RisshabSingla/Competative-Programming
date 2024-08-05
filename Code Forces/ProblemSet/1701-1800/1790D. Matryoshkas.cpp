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

void takeInputVector(vector<ll> &arr, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void takeInputVector(vector<vector<ll>> &arr, ll n, ll m)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
}

// bool isPossible(vector<ll> &arr, ll mid, ll n){

// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        takeInputVector(arr, n);
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());

        vector<pair<ll, ll>> freq;
        for (ll i = 0; i < n;)
        {
            ll j = i;
            while (i < n && arr[i] == arr[j])
            {
                i++;
            }
            freq.push_back({arr[j], i - j});
        }

        ll elem = freq[0].first;
        ll ans = freq[0].second;
        // for (auto i : freq)
        // {
        //     cout << i.first << " " << i.second << "\n";
        // }
        for (ll i = 1; i < freq.size(); i++)
        {
            if ((freq[i].first + 1) == freq[i - 1].first)
            {
                ans += max((freq[i].second - freq[i - 1].second), 0LL);
            }
            else
            {
                ans += freq[i].second;
            }
            // cout << "Ans is: " << ans << "\n";
        }
        cout << ans << "\n";

        // set<pair<ll, ll>> st;
        // st.insert({arr[0], 0});
        // ll count = 1;
        // for (ll i = 0; i < n; i++)
        // {
        //     auto itr = st.upper_bound({arr[i], -1});
        //     // if (itr == st.end())
        //     // {
        //     //     cout << "index: " << i << " end\n";
        //     //     itr--;
        //     //     st.erase(itr);
        //     //     // count++;
        //     //     st.insert({arr[i], i});
        //     //     continue;
        //     // }
        //     itr--;
        //     if (itr->first >= arr[i])
        //     {
        //         cout << "index: " << i << " greater :" << itr->first << "\n";
        //         if (itr->first == arr[i])
        //         {
        //             count++;
        //             st.insert({arr[i], i});
        //         }
        //         else
        //         {
        //             st.erase(itr);
        //             st.insert({arr[i], i});
        //         }
        //     }
        //     else
        //     {
        //         cout << "index: " << i << " less :" << itr->first << "\n";
        //         st.erase(itr);

        //         st.insert({arr[i], i});
        //     }
        // }
        // cout << count << "\n";

        // ll low = 1;
        // ll high = n;
        // ll ans = 0;
        // while (low <= high)
        // {
        //     ll mid = low + (high - low) / 2;
        //     if (isPossible(arr, mid, n))
        //     {
        //         ans = mid;
        //         high = mid - 1;
        //     }
        //     else
        //     {
        //         low = mid + 1;
        //     }
        // }
    }
    return 0;
}