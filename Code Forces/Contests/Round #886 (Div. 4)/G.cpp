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
        int n;
        cin >> n;
        vii arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        int count = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i].first == arr[j].first)
                {
                    // x is same
                    count += 2;
                }
                else if (arr[i].second == arr[j].second)
                {
                    // y is same
                    count += 2;
                }
                else
                {
                    int x = arr[i].first - arr[j].first;
                    int y = arr[i].second - arr[j].second;
                    if (x / y == 1 || x / y == -1)
                    {
                        // tangent is 1 or -1
                        count += 2;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
