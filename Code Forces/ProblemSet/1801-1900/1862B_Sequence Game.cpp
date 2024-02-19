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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> ans;
        ans.push_back(arr[0]);
        for (ll i = 1; i < n; i++)
        {
            if (arr[i - 1] <= arr[i])
            {
                ans.push_back(arr[i]);
            }
            else
            {
                ans.push_back(min(arr[i - 1], arr[i]));
                ans.push_back(arr[i]);
            }
        }
        cout << ans.size() << "\n";
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}