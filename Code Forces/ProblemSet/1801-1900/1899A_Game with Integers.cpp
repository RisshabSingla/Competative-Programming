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
        ll curr;
        cin >> curr;
        if (curr % 3 == 0)
        {
            cout << "Second\n";
        }
        else
        {
            cout << "First\n";
        }
    }
    return 0;
}