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
    ll num;
    cin >> num;
    vector<bool> numbers(num + 1, false);
    for (int i = 0; i < num - 1; i++)
    {
        int t;
        cin >> t;
        numbers[t] = true;
    }
    for (int i = 1; i <= num; i++)
    {
        if (!numbers[i])
        {
            cout << i << " ";
            return 0;
        }
    }
    return 0;
}