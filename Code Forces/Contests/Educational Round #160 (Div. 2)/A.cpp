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
        string str;
        cin >> str;
        bool found = false;
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] == '0')
            {
                continue;
            }
            int num1 = stoi(str.substr(0, i));
            int num2 = stoi(str.substr(i));
            if (num1 < num2)
            {
                cout << num1 << " " << num2 << "\n";
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}
