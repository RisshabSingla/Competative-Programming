#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll checkNumbers(vector<vector<ll>> &arr, map<ll, ll> count, vector<ll> &positions)
{
    for (auto index : positions)
    {
        for (auto num : arr[index])
        {
            count[num]--;
        }
    }
    ll numbers = 0;
    for (auto i : count)
    {
        if (i.second != 0)
        {
            numbers++;
        }
    }
    return numbers;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        set<ll> allElems;
        map<ll, vector<ll>> mp;
        map<ll, ll> count;
        vector<vector<ll>> arr;

        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            vector<ll> nums(t);
            for (ll j = 0; j < t; j++)
            {
                cin >> nums[j];
                allElems.insert(nums[j]);
                mp[nums[j]].push_back(i);
                count[nums[j]]++;
            }
            arr.push_back(nums);
        }
        ll maxi = 0;
        for (auto i : allElems)
        {
            ll numbers = checkNumbers(arr, count, mp[i]);
            maxi = max(numbers, maxi);
        }
        cout << maxi << "\n";
    }
    return 0;
}