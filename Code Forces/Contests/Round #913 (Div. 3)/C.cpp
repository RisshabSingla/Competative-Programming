#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>

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
        int len;
        cin >> len;
        string str;
        cin >> str;
        int max_freq = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < len; i++)
        {
            freq[str[i] - 'a']++;
            max_freq = max(max_freq, freq[str[i] - 'a']);
        }
        int ans = max(len % 2, (max_freq - (len - max_freq)));
        cout << ans << "\n";
    }
    return 0;
}
