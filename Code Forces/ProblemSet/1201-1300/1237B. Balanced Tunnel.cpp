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

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> brr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> brr[i];
        brr[i]--;
    }
    vector<ll> pos(n);
    for (ll i = 0; i < n; i++)
    {
        pos[brr[i]] = i;
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; i++)
    {
        c[i] = pos[arr[i]];
    }
    ll mx = -1, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (c[i] >= mx)
        {
            mx = c[i];
        }
        else
        {
            ++ans;
        }
    }
    cout << ans << '\n';
    // ll index = 0;
    // unordered_map<ll, ll> fined;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (fined.count(arr[index]))
    //     {
    //         index++;
    //         continue;
    //     }
    //     if (arr[index] != brr[i])
    //     {
    //         fined[brr[i]]++;
    //     }
    //     else
    //     {
    //         index++;
    //     }
    // }
    // cout << fined.size() << "\n";

    return 0;
}