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
    vector<ll> freq(30, 0);
    while (cases--)
    {
        ll num1, num2;
        cin >> num1 >> num2;
        if (num1 == 1)
        {
            freq[num2]++;
        }
        else
        {
            vector<ll> temp = freq;
            bool flag = true;
            for (int position = 0; position < 30; position++)
            {
                if ((num2 >> position) & 1)
                {
                    if (temp[position])
                    {
                        temp[position]--;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                temp[position + 1] += temp[position] / 2;
            }
            if (flag)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}