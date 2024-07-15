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
        ll count = 0;
        if (a > b)
        {
            // divide
            while (a % 8 == 0 && a / 8 >= b)
            {
                a /= 8;
                count++;
            }
            while (a % 4 == 0 && a / 4 >= b)
            {
                a /= 4;
                count++;
            }
            while (a % 2 == 0 && a / 2 >= b)
            {
                a /= 2;
                count++;
            }
        }
        else
        {
            while ((a * 8) <= b)
            {
                a *= 8;
                count++;
            }
            while ((a * 4) <= b)
            {
                a *= 4;
                count++;
            }
            while ((a * 2) <= b)
            {
                a *= 2;
                count++;
            }
        }
        if (a == b)
        {
            cout << count << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}