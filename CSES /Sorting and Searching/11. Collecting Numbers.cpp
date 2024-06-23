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
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    ll prev = arr[0].second;
    ll count = 1;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i].second < prev)
        {
            count++;
        }
        prev = arr[i].second;
    }
    cout << count << "\n";

    return 0;
}