#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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
        ll n;
        cin >> n;
        vector<ll> arr(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (arr[0] != arr[1])
        {
            cout << "YES\n";
            continue;
        }
        bool present = false;
        for (int i = 1; i < n; i++)
        {
            int mod = arr[i] % arr[0];
            if (mod != 0 && mod < arr[0])
            {
                present = true;
                break;
            }
        }
        if (present)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
