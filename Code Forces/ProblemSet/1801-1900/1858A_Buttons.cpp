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
        ll a, b, c;
        cin >> a >> b >> c;
        // Anna first turn
        if (c % 2 == 0)
        {
            // after finishes -> Anna
            if (a > b)
            {
                cout << "First\n";
            }
            else
            {
                cout << "Second\n";
            }
        }
        else
        {
            // after finishes -> Katie
            if (a >= b)
            {
                cout << "First\n";
            }
            else
            {
                cout << "Second\n";
            }
        }
    }
    return 0;
}