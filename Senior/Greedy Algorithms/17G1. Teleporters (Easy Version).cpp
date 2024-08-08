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
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i - 1];
            arr[i - 1] += i;
        }
        sort(arr.begin(), arr.end());
        ll sum = 0;
        ll index = 0;
        if (arr[0] > k)
        {
            cout << 0 << "\n";
            continue;
        }
        while (index < n && sum < k)
        {
            sum += arr[index];
            index++;
        }
        if (sum > k)
        {
            index--;
        }
        cout << index << "\n";
    }
    return 0;
}