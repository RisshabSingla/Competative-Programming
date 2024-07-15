#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void calcMaxConsFreq(vector<ll> &arr, unordered_map<ll, ll> &mp, ll n)
{
    ll prev = arr[0];
    ll count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != prev)
        {
            if (mp.count(prev))
            {
                mp[prev] = max(mp[prev], count);
            }
            else
            {
                mp[prev] = count;
            }
            prev = arr[i];
            count = 1;
        }
        else
        {
            count++;
        }
    }
    if (mp.count(prev))
    {
        mp[prev] = max(mp[prev], count);
    }
    else
    {
        mp[prev] = count;
    }
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr1(n);
        vector<ll> arr2(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }

        unordered_map<ll, ll> mp1;
        unordered_map<ll, ll> mp2;

        calcMaxConsFreq(arr1, mp1, n);
        calcMaxConsFreq(arr2, mp2, n);

        ll maxi = 0;

        for (auto &i : mp1)
        {
            if (mp2.count(i.first))
            {
                maxi = max(maxi, (i.second + mp2[i.first]));
            }
            else
            {
                maxi = max(maxi, i.second);
            }
        }
        for (auto &i : mp2)
        {
            if (mp1.count(i.first))
            {
                maxi = max(maxi, (i.second + mp1[i.first]));
            }
            else
            {
                maxi = max(maxi, i.second);
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}