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

bool isPossible(vector<ll> &arr, ll index, ll height)
{
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < index; i++)
    {
        mp[arr[i]]++;
    }
    vector<pair<ll, ll>> vc;
    for (auto i : mp)
    {
        vc.push_back({i.first, i.second});
    }
    sort(vc.begin(), vc.end());
    bool extra = false;
    // cout << "Index is: " << index << "\n";
    for (ll i = vc.size() - 1; i >= 0; i--)
    {
        if (vc[i].second % 2 && extra)
        {
            extra = false;
            vc[i].second--;
        }
        if (vc[i].second % 2)
        {
            extra = true;
        }
        ll req = (vc[i].second + 1) / 2;
        ll hReq = req * vc[i].first;
        if (hReq <= height)
        {
            height -= hReq;
        }
        else
        {
            // cout << "returning false for: " << vc[i].first << " ReqH: " << hReq << " height: " << height << "\n";
            return false;
        }
    }
    return true;
}

int main()
{
    ll n, h;
    cin >> n >> h;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        if (arr[0] <= h)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
        return 0;
    }
    ll low = 0;
    ll high = n;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (isPossible(arr, mid, h))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << "\n";

    return 0;
}
