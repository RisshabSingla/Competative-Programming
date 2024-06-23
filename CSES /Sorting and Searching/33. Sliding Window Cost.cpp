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

ll findCost(vector<ll> &arr, ll start, ll end, ll median)
{
    ll cost = 0;
    for (ll i = start; i < end; i++)
    {
        cost += abs(arr[i] - median);
    }
    return cost;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (k == 1)
    {
        for (ll i = 0; i < n; i++)
        {
            cout << 0 << " ";
        }
        return 0;
    }

    if (k == 2)
    {
        ll sum = arr[0];
        for (ll i = 1; i < n; i++)
        {
            sum += arr[i];
            cout << abs(sum - 2 * min(arr[i], arr[i - 1])) << " ";
            sum -= arr[i - 1];
        }
        return 0;
    }

    set<pair<ll, ll>> ls;
    set<pair<ll, ll>> rs;
    ll leftSizeReq = (k / 2) + (k % 2);

    ll currLeftSum = 0;
    ll currRightSum = 0;
    for (ll i = 0; i < k; i++)
    {
        currLeftSum += arr[i];
        ls.insert({arr[i], i});
    }
    while (ls.size() > leftSizeReq)
    {
        currRightSum += (*ls.rbegin()).first;
        currLeftSum -= (*ls.rbegin()).first;
        rs.insert(*ls.rbegin());
        ls.erase(*ls.rbegin());
    }

    ll median = (*ls.rbegin()).first;
    cout << ls.size() * median - currLeftSum + currRightSum - rs.size() * median << " ";

    for (ll i = k; i < n; i++)
    {
        if (ls.count({arr[i - k], i - k}))
        {
            currLeftSum -= arr[i - k];
            ls.erase({arr[i - k], i - k});
        }
        else
        {
            currRightSum -= arr[i - k];
            rs.erase({arr[i - k], i - k});
        }

        if ((*ls.rbegin()).first < arr[i])
        {
            currRightSum += arr[i];
            rs.insert({arr[i], i});
        }
        else
        {
            currLeftSum += arr[i];
            ls.insert({arr[i], i});
        }

        while (ls.size() < leftSizeReq)
        {
            currRightSum -= (*rs.begin()).first;
            currLeftSum += (*rs.begin()).first;
            ls.insert(*rs.begin());
            rs.erase(*rs.begin());
        }

        while (ls.size() > leftSizeReq)
        {
            currRightSum += (*ls.rbegin()).first;
            currLeftSum -= (*ls.rbegin()).first;
            rs.insert(*ls.rbegin());
            ls.erase(*ls.rbegin());
        }

        median = (*ls.rbegin()).first;
        cout << ls.size() * median - currLeftSum + currRightSum - rs.size() * median << " ";
        // cout << (*ls.rbegin()).first << " ";
    }
    return 0;
}