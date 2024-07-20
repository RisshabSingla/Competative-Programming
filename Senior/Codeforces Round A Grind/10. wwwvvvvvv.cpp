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
    string str;
    cin >> str;
    ll count = 0;
    for (auto ch : str)
    {
        if (ch == 'v')
        {
            count++;
        }
        if (ch == 'w')
        {
            count += 2;
        }
    }
    cout << count << "\n";
    return 0;
}