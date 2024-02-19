#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
        map<int, int> freq;
        int n;
        cin >> n;
        vector<int> ans1;
        vector<int> ans2;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            freq[t]++;
        }
        if (freq.size() == 1)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (auto &i : freq)
        {
            ans1.push_back(i.first);
            for (int j = 0; j < i.second - 1; j++)
            {
                ans2.push_back(i.first);
            }
        }
        reverse(ans1.begin(), ans1.end());
        for (auto &i : ans1)
        {
            cout << i << " ";
        }
        for (auto &i : ans2)
        {
            cout << i << " ";
        }
        cout << '\n';
    }

    return 0;
}