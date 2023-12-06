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

bool isValid(vii &points, int k)
{
    int left = 0;
    int right = 0;
    for (auto &i : points)
    {
        int posLeft = left - k;
        int posRight = right + k;
        if (i.second < posLeft && i.second < posRight)
        {
            return false;
        }
        else if (i.first > posLeft && i.first > posRight)
        {
            return false;
        }
        left = max(posLeft, i.first);
        right = min(posRight, i.second);
    }
    return true;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        vii points(n);
        for (int i = 0; i < n; i++)
        {
            cin >> points[i].first >> points[i].second;
        }
        int left = 0;
        int right = INT_MAX;
        int ans = INT_MAX;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isValid(points, mid))
            {
                right = mid - 1;
                ans = min(ans, mid);
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
