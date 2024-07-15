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
        ll n, k, q;
        cin >> n >> k >> q;
        vector<ll> arr(n);
        ll prev = INT_MIN;
        ll index = 0;
        vector<vector<ll>> times;
        vector<ll> curr;
        ll max_cons = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] <= q)
            {
                curr.push_back(arr[i]);
            }
            else
            {
                max_cons = max(max_cons, (ll)curr.size());
                times.push_back(curr);
                curr.clear();
            }
        }
        if (curr.size() > 0)
        {
            max_cons = max(max_cons, (ll)curr.size());
            times.push_back(curr);
        }

        if (max_cons < k)
        {
            cout << 0 << "\n";
            continue;
        }
        ll count = 0;
        ll sumK = ((k) * (k + 1)) / 2;
        for (int i = 0; i < times.size(); i++)
        {
            int size = times[i].size();
            // for (auto &j : times[i])
            // {
            //     cout << j << " ";
            // }
            // cout << ": ";
            if (size < k)
            {
                continue;
            }
            ll add = 0;
            for (int a = k; a <= size; a++)
            {
                add += (size - a + 1);
            }

            // int num = size - k + 1;
            // int sumN = ((size) * (size + 1)) / 2;
            // int add = ((size + 1) * num - (sumN - sumK));
            // cout << add << "\n";
            count += add;
        }
        cout << count << "\n";
    }
    return 0;
}