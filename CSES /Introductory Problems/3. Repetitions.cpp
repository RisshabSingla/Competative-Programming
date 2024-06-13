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
    char prev = str[0];
    int max_length = 1;
    int len = 1;
    for (int i = 1; i <= str.length(); i++)
    {
        if (str[i] == prev)
        {
            len++;
        }
        else
        {
            prev = str[i];
            max_length = max(max_length, len);
            len = 1;
        }
    }
    cout << max_length << "\n";
    return 0;
}