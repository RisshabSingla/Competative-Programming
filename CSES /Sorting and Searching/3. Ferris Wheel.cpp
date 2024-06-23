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
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if (arr[0] >= x)
    {
        cout << n << "\n";
        return 0;
    }
    ll front = 0;
    ll back = n - 1;
    ll count = 0;
    while (front <= back)
    {
        if (arr[front] + arr[back] <= x)
        {
            count++;
            front++;
            back--;
        }
        else
        {
            back--;
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}