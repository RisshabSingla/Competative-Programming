#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    ll diff1 = a.first - a.second;
    ll diff2 = b.first - b.second;
    return diff1 > diff2;
}

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), comp);
    // for (auto i : arr)
    // {
    //     cout << i.first << " " << i.second << "\n";
    // }
    ll count = 0;
    ll index1 = 0;
    ll index2 = n - 1;
    while (index1 <= index2)
    {
        ll diff = (arr[index1].first + arr[index2].first) - (arr[index1].second + arr[index2].second);
        // cout << "Diff is: " << diff << "\n";
        if (diff > 0)
        {
            // cout << "Adding: " << index2 - index1 << "\n";
            count += (index2 - index1);
            index1++;
        }
        else
        {
            index2--;
        }
    }
    cout << count << "\n";
    return 0;
}