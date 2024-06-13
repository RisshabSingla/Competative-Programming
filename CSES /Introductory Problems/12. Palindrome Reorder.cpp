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
    vector<int> freq(26, 0);
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i] - 'A']++;
    }
    int odd = -1;
    string front = "";
    string back = "";
    bool possible = true;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2)
        {
            if (odd == -1)
            {
                odd = i;
            }
            else
            {
                possible = false;
            }
        }
        int times = freq[i] / 2;
        for (int j = 0; j < times; j++)
        {
            front += char('A' + i);
        }
    }

    if (possible)
    {
        string back = front;
        reverse(back.begin(), back.end());
        string ans = front;
        if (odd != -1)
        {
            ans += char('A' + odd);
        }
        ans += back;
        cout << ans << "\n";
    }
    else
    {
        cout << "NO SOLUTION\n";
    }
    return 0;
}