#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    if (n < 4)
    {
        cout << "NO SOLUTION"
             << "\n";
        return 0;
    }
    int odd = -1;
    int even = -1;
    if (n % 2 == 0)
    {
        even = n;
        odd = n - 1;
    }
    else
    {
        even = n - 1;
        odd = n;
    }
    for (int i = odd; i >= 1; i -= 2)
    {
        cout << i << " ";
    }
    for (int i = even; i > 1; i -= 2)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}