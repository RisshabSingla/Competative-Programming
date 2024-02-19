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
        int len;
        cin >> len;
        string str;
        cin >> str;
        vector<bool> reach(len + 2, false);
        reach[0] = true;
        int count = 0;
        for (int i = 0; i < len; i++)
        {
            if (!reach[i])
            {
                break;
            }
            if (str[i] == '@')
            {
                count++;
            }
            if (str[i] == '*')
            {
                continue;
            }
            reach[i + 1] = true;
            reach[i + 2] = true;
        }
        cout << count << "\n";
    }
    return 0;
}
