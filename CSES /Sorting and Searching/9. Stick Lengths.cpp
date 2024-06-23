#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll findCost(vector<ll> &arr, ll middle, ll n)
{

    ll cost = 0;
    for (auto i : arr)
    {
        cost += abs(i - middle);
    }
    return cost;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if (n % 2)
    {
        ll middle = arr[n / 2];
        ll cost = findCost(arr, middle, n);
        cout << cost << "\n";
    }
    else
    {
        ll mid1 = arr[n / 2];
        ll mid2 = arr[(n / 2) - 1];
        ll cost = min(findCost(arr, mid1, n), findCost(arr, mid2, n));
        cout << cost << "\n";
    }
    return 0;
}