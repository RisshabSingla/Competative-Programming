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
        // vector<vector<int>> arr;
        vector<ll> smallest;
        vector<ll> second;
        for (ll i = 0; i < n; i++)
        {
            ll m;
            cin >> m;
            vector<ll> nums(m);
            for (ll i = 0; i < m; i++)
            {
                cin >> nums[i];
            }
            sort(nums.begin(), nums.end());
            smallest.push_back(nums[0]);
            second.push_back(nums[1]);
        }
        if (n == 1)
        {
            cout << smallest[0] << "\n";
            continue;
        }
        sort(smallest.begin(), smallest.end());
        sort(second.begin(), second.end());
        ll sum = smallest[0];
        for (ll i = 1; i < second.size(); i++)
        {
            sum += second[i];
        }
        cout << sum << "\n";
    }
    return 0;
}