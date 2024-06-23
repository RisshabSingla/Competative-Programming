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
    vector<int> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int count = 1;
    int prev = arr[0];
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] != prev)
        {
            count++;
            prev = arr[i];
        }
    }
    cout << count << "\n";
    return 0;
}