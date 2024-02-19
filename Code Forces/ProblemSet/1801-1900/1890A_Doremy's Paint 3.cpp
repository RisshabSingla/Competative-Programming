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
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        unordered_map<int, int> freq;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        if (freq.size() == 1)
        {
            cout << "YES\n";
            continue;
        }
        if (freq.size() > 2)
        {
            cout << "NO\n";
            continue;
        }
        vector<ll> ans;
        for (auto i : freq)
        {
            ans.push_back(i.second);
        }
        if (abs(ans[0] - ans[1]) < 2)
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