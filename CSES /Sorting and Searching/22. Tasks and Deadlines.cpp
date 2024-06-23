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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    ll prev = 0;
    ll reward = 0;
    for (ll i = 0; i < n; i++)
    {
        reward += (arr[i].second - (prev + arr[i].first));
        prev += arr[i].first;
    }
    cout << reward << "\n";
    return 0;
}