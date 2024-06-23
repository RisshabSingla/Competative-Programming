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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr1(n);
    vector<ll> arr2(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    ll index1 = 0;
    ll index2 = 0;
    ll count = 0;
    while (index1 < n && index2 < m)
    {
        if (abs(arr1[index1] - arr2[index2]) <= k)
        {
            count++;
            index1++;
            index2++;
            continue;
        }
        if (arr1[index1] > arr2[index2])
        {
            index2++;
            continue;
        }
        index1++;
    }
    cout << count << "\n";
    return 0;
}