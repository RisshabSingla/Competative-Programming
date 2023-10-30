#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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
    multiset<pair<int, int>> lr;
    multiset<pair<int, int>> rl;
    while (cases--)
    {
        char ch;
        cin >> ch;
        int a, b;
        cin >> a >> b;
        if (ch == '+')
        {
            lr.insert({a, b});
            rl.insert({b, a});
        }
        else
        {
            lr.erase(lr.find({a, b}));
            rl.erase(rl.find({b, a}));
        }
        if (lr.size() <= 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            int b = (*lr.begin()).first;
            int c = (*(rl.end()--)).first;
            if (b < c)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
