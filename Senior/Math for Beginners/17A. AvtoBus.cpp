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
        ll tires;
        cin >> tires;
        if (tires % 2 || tires == 2)
        {
            cout << -1 << "\n";
            continue;
        }
        tires /= 2;
        ll maxi = (tires / 2);
        ll mini = (tires + 3 - 1) / 3;
        cout << mini << " " << maxi << "\n";
    }
    return 0;
}