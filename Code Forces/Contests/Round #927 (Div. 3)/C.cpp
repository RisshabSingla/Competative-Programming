#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <deque>

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
        int n, m;
        cin >> n >> m;
        deque<int> arr;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr.push_back(a);
        }
        string str;
        cin >> str;
        vector<int> mul;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'L')
            {
                mul.push_back(arr.front());
                arr.pop_front();
            }
            else
            {
                mul.push_back(arr.back());
                arr.pop_back();
            }
        }
        reverse(mul.begin(), mul.end());

        vector<int> ans;
        long long prod = 1;
        for (int i = 0; i < n; i++)
        {
            prod *= mul[i];
            prod %= m;
            ans.push_back(prod);
        }
        reverse(ans.begin(), ans.end());
        for (auto &i : ans)
        {
            cout << i << ' ';
        }
        cout << "\n";
    }
    return 0;
}
