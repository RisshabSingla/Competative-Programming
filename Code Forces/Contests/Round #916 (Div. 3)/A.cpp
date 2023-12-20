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
        ll dur;
        cin >> dur;
        vector<ll> alpha(26, 0);
        string str;
        cin >> str;
        for (int i = 0; i < dur; i++)
        {
            alpha[str[i] - 'A']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] >= i + 1)
            {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
