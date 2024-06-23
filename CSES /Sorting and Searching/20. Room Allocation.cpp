#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
    vector<vector<ll>> arr(n, vector<ll>(3, -1));
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }
    sort(arr.begin(), arr.end());
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll number = 1;
    vector<ll> ans(n, -1);
    for (ll i = 0; i < n; i++)
    {
        if (pq.empty() || pq.top().first >= arr[i][0])
        {
            pq.push({arr[i][1], number});
            ans[arr[i][2]] = number;
            number++;
        }
        else
        {
            pair<ll, ll> top = pq.top();
            pq.pop();
            pq.push({arr[i][1], top.second});
            ans[arr[i][2]] = top.second;
        }
    }
    cout << number - 1 << "\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}