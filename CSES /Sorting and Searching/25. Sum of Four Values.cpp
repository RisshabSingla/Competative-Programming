#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<ll> findAns(vector<pair<ll, ll>> &arr, ll n, ll target)
{
    vector<ll> ans;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = n - 1; j > i; j--)
        {
            ll start = i + 1;
            ll end = j - 1;
            while (start < end)
            {
                ll sum = arr[i].first + arr[start].first + arr[end].first + arr[j].first;
                if (sum > target)
                {
                    end--;
                }
                if (sum < target)
                {
                    start++;
                }
                if (sum == target)
                {
                    ans.push_back(arr[i].second);
                    ans.push_back(arr[start].second);
                    ans.push_back(arr[end].second);
                    ans.push_back(arr[j].second);
                    return ans;
                }
            }
        }
    }
    return ans;
}

int main()
{
    ll n, target;
    cin >> n >> target;
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end());
    vector<ll> ans = findAns(arr, n, target);
    if (ans.size() == 0)
    {
        cout << "IMPOSSIBLE";
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}