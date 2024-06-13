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
    ll sum = 0;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
        sum += arr[i].first;
    }
    sort(arr.begin(), arr.end());
    vector<int> ans;
    for (int i = 0; i < n - 1; i++)
    {
        ll curr_sum = sum - arr[i].first - arr[n - 1].first;
        if (curr_sum == arr[n - 1].first)
        {
            // cout << "elem: " << arr[i].first << "\n";
            ans.push_back(arr[i].second + 1);
        }
    }

    // last element
    ll curr_sum = sum - arr[n - 1].first - arr[n - 2].first;
    if (curr_sum == arr[n - 2].first)
    {
        ans.push_back(arr[n - 1].second + 1);
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}