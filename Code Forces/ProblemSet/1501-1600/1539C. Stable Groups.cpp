#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<ll> req;
    ll count = 1;
    ll prev = arr[0];
    for (ll i = 1; i < n; i++)
    {
        ll diff = arr[i] - prev;
        if (diff > x)
        {
            ll c = diff / x;
            if (diff % x == 0)
            {
                c--;
            }
            count++;
            req.push_back(c);
        }
        prev = arr[i];
    }
    sort(req.begin(), req.end());
    ll sum = 0;
    for (auto i : req)
    {
        sum += i;
        if (sum <= k)
        {
            count--;
        }
        else
        {
            break;
        }
    }
    // for (auto i : req)
    // {
    //     cout << i << " ";
    // }
    cout << count << "\n";
    return 0;
}