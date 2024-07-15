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
    // double c1 = double(a.second) / double(a.first);
    // double c2 = double(b.second) / double(b.first);
    // return c1 < c2;
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, p;
        cin >> n >> p;
        vector<pair<ll, ll>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].second;
            arr[i].second = min(arr[i].second, p);
        }

        sort(arr.begin(), arr.end(), comp);
        if (p <= arr[0].second)
        {
            cout << p * n << "\n";
            continue;
        }
        ll know = 1;
        ll cost = p;
        for (int i = 0; i < n; i++)
        {
            ll canTell = arr[i].first;
            if (canTell + know >= n)
            {
                cost += (n - know) * arr[i].second;
                break;
            }
            know += arr[i].first;
            cost += arr[i].first * arr[i].second;
        }
        cout << cost << "\n";
    }
    return 0;
}