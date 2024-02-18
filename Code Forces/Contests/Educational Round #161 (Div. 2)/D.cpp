#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
    while (cases--)
    {
        int n;
        cin >> n;
        vector<int> attack(n);
        vector<int> defence(n);
        for (int i = 0; i < n; i++)
        {
            cin >> attack[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> defence[i];
        }
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 0; i < n; i++)
        {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        vector<int> monsters(n);
        for (int i = 0; i < n; i++)
        {
            monsters[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> died;
            for (auto &i : monsters)
            {
                int takenDamage = 0;
                if (left[i] != -1)
                {
                    takenDamage += attack[left[i]];
                }
                if (right[i] != n)
                {
                    takenDamage += attack[right[i]];
                }
                if (takenDamage > defence[i])
                {
                    died[i]++;
                }
            }
            monsters.clear();
            cout << died.size() << " ";
            for (auto &i : died)
            {
                if (left[i.first] != -1)
                {
                    right[left[i.first]] = right[i.first];
                    if (!died.count(left[i.first]))
                    {
                        monsters.push_back(left[i.first]);
                    }
                }
                if (right[i.first] != n)
                {
                    left[right[i.first]] = left[i.first];
                    if (!died.count(right[i.first]))
                    {
                        monsters.push_back(right[i.first]);
                    }
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
