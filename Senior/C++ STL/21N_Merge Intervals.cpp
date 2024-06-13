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
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    int index = 0;
    vector<pair<ll, ll>> ans;
    ans.push_back(arr[0]);
    // for (auto i : arr)
    // {
    //     cout << i.first << " " << i.second << "\n";
    // }
    // cout << "\n";
    for (int i = 1; i < n; i++)
    {
        if (arr[i].first <= ans[index].second)
        {
            ans[index].second = max(ans[index].second, arr[i].second);
        }
        else
        {
            ans.push_back(arr[i]);
            index++;
        }
    }

    for (int i = 0; i <= index; i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}