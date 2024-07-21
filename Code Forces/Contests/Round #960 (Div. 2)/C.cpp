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

pair<ll, vector<ll>> calcMad(vector<ll> &arr, ll n)
{
    ll maxi = 0;
    unordered_map<ll, ll> mp;
    bool found = false;
    vector<ll> ans;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        sum += arr[i];
        if (arr[i] > maxi && mp[arr[i]] > 1)
        {
            maxi = arr[i];
        }
        if (maxi != 0)
        {
            ans.push_back(maxi);
        }
    }
    return {sum, ans};
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        pair<ll, vector<ll>> a1 = calcMad(arr, n);
        sum += a1.first;

        ll prev = 0;
        map<ll, ll> freq;
        for (auto i : a1.second)
        {
            freq[i]++;
        }
        ll size = a1.second.size();
        for (ll i = 0; i < size; i++)
        {
            sum += a1.second[i];
            if (freq[a1.second[i]] > 1)
            {
                sum += (size - i - 1) * a1.second[i];
                prev = a1.second[i];
            }
            else
            {
                sum += (size - i - 1) * prev;
            }
        }

        cout << sum << "\n";
        // ll start = 0;
        // ll index = 0;
        // while (index < n)
        // {
        //     ll maxi = 0;
        //     unordered_map<ll, ll> mp;
        //     bool found = false;
        //     for (ll i = start; i < n; i++)
        //     {
        //         sum += arr[i];
        //         mp[arr[i]]++;
        //         if (arr[i] > maxi && mp[arr[i]] > 1)
        //         {
        //             maxi = arr[i];
        //         }
        //         if (maxi != 0 && !found)
        //         {
        //             found = true;
        //             index = i;
        //         }
        //         arr[i] = maxi;
        //     }
        //     if (!found)
        //     {
        //         break;
        //     }
        //     start = index;
        //     // index++;
        //     // cout << "Index is: " << index << "\n";
        //     // for (auto i : arr)
        //     // {
        //     //     cout << i << ' ';
        //     // }
        //     // cout << "\n";
        // }

        // cout << sum << "\n";
    }
    return 0;
}
