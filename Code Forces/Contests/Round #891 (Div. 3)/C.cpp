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
        ll num = (n) * (n - 1) / 2;
        vector<int> numbers(num);
        for (ll i = 0; i < num; i++)
        {
            cin >> numbers[i];
        }
        sort(numbers.begin(), numbers.end());
        vector<ll> ans;
        ll index = 0;
        ll add = n - 1;
        while (add > 0)
        {
            ans.push_back(numbers[index]);
            index += add--;
        }
        ans.push_back(1e9);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
