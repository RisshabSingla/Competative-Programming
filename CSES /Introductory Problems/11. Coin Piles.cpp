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
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll a, b;
        cin >> a >> b;
        if (b > a)
        {
            swap(a, b);
        }
        if ((a + b) % 3 == 0 && b * 2 >= a)
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}