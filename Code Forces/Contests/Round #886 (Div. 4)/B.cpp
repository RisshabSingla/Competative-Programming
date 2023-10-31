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
        int res;
        cin >> res;
        int ans = 0;
        int index = 0;
        for (int i = 0; i < res; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a > 10)
            {
                continue;
            }
            if (b > ans)
            {
                ans = b;
                index = i + 1;
            }
        }
        cout << index << endl;
    }
    return 0;
}
