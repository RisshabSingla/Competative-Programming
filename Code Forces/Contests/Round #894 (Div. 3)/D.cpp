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

ll calc(ll mid)
{
    return (mid * (mid - 1)) / 2;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        ll front = 1;
        ll end = INT_MAX;
        ll max_possible = -1;
        ll num;
        while (front <= end)
        {
            // cout << "Front: " << front << endl;
            // cout << "End: " << end << endl;
            ll mid = front + (end - front) / 2;
            ll one = calc(mid);
            ll two = calc(mid + 1);
            // cout << "One: " << one << endl;
            // cout << "Two: " << two << endl;

            if (one <= n && two > n)
            {
                if (mid > max_possible)
                {
                    max_possible = mid;
                    num = one;
                }
                break;
            }
            else if (one < n)
            {
                front = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        while (num != n)
        {
            num++;
            max_possible++;
        }
        cout << max_possible << endl;
    }
    return 0;
}
