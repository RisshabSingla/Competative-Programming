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
        ll n, k;
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            cout << i << " ";
        }
        for (int i = 0; i < (n - k); i++)
        {
            cout << (n - i) << " ";
        }
        cout << "\n";
    }
    return 0;
}
