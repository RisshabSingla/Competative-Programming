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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr < arr[i])
            {
                curr = arr[i];
            }
            else
            {
                int mul = curr / arr[i];
                curr = arr[i] * (mul + 1);
            }
        }
        cout << curr << "\n";
    }
    return 0;
}
