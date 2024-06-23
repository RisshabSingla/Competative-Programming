#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool comp(vector<ll> &a, vector<ll> &b)
{
    if (a[0] == b[0])
    {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(3, 0));
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }
    sort(arr.begin(), arr.end(), comp);
    // for (auto i : arr)
    // {
    //     cout << i[0] << " " << i[1] << "\n";
    // }

    vector<bool> contained(n);
    vector<bool> contains(n);
    ll maxi = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i][1] <= maxi)
        {
            contained[arr[i][2]] = true;
        }
        maxi = max(maxi, arr[i][1]);
    }

    ll mini = LLONG_MAX;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (arr[i][1] >= mini)
        {
            contains[arr[i][2]] = true;
        }
        mini = min(mini, arr[i][1]);
    }

    for (auto i : contains)
    {
        if (i)
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
    cout << '\n';

    for (auto i : contained)
    {
        if (i)
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
    cout << '\n';

    return 0;
}