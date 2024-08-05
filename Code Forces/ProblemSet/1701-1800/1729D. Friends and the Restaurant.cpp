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
    double r1 = (double)a.first / (double)a.second;
    double r2 = (double)b.first / (double)b.second;
    if (r1 == r2)
    {
        ll diff1 = a.first - a.second;
        ll diff2 = b.first - b.second;
        return diff1 < diff2;
    }
    return r1 < r2;
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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            arr[i] = t - arr[i];
        }
        sort(arr.begin(), arr.end());
        ll front = 0;
        ll last = n - 1;
        ll count = 0;
        while (front < last)
        {
            if (arr[front] + arr[last] >= 0)
            {
                count++;
                front++;
                last--;
            }
            else
            {
                front++;
            }
        }
        cout << count << "\n";

        // vector<pair<ll, ll>> arr(n);
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> arr[i].first;
        // }
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> arr[i].second;
        // }
        // sort(arr.begin(), arr.end(), comp);
        // for (auto i : arr)
        // {
        //     cout << i.first << " " << i.second << "\n";
        // }
        // cout << "\n";

        // ll front = 0;
        // ll last = n - 1;

        // ll count = 0;
        // while (front < last)
        // {
        //     ll spend = arr[front].first + arr[last].first;
        //     ll pocket = arr[front].second + arr[last].second;
        //     if (spend > pocket)
        //     {
        //         last--;
        //     }
        //     else
        //     {
        //         count++;
        //         last--;
        //         front++;
        //     }
        // }
        // cout << count << "\n";
    }

    return 0;
}