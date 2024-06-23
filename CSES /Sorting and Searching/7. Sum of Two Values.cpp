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
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    ll index1 = 0;
    ll index2 = n - 1;
    while (index1 < index2)
    {
        ll sum = arr[index1].first + arr[index2].first;
        if (sum == x)
        {
            cout << arr[index1].second + 1 << " " << arr[index2].second + 1 << "\n";
            return 0;
        }
        if (sum < x)
        {
            index1++;
        }
        else
        {
            index2--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}