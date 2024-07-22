#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(vector<ll> &arr, ll n)
{
    if (arr[0] > arr[1] && arr[0] <= arr[n - 1])
    {
        return false;
    }
    if (arr[0] < arr[1] && arr[0] >= arr[n - 1])
    {
        return false;
    }

    if (arr[n - 1] > arr[n - 2] && arr[n - 1] <= arr[0])
    {
        return false;
    }
    if (arr[n - 1] < arr[n - 2] && arr[n - 1] >= arr[0])
    {
        return false;
    }

    for (ll i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            continue;
        }
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
        {
            continue;
        }
        return false;
    }
    return true;
}

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
        vector<ll> ans(n);
        ll index = 0;
        for (ll i = 0; i < n; i += 2)
        {
            ans[i] = arr[index];
            index++;
        }
        // index = n - 1;
        for (ll i = 1; i < n; i += 2)
        {
            ans[i] = arr[index];
            index++;
        }

        if (isPossible(ans, n))
        {
            cout << "YES\n";
            for (auto i : ans)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
        // for (auto i : ans)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
    }
    return 0;
}