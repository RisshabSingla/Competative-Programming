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
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i < 5; i++)
        {
            if (a <= b && a <= c)
            {
                a++;
            }
            else if (b <= a && b <= c)
            {
                b++;
            }
            else
            {
                c++;
            }
        }
        cout << a * b * c << "\n";
    }
    return 0;
}
