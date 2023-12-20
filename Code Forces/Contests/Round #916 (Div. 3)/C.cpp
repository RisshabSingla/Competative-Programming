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
        ll quests, max_q;
        cin >> quests >> max_q;
        vector<ll> first(quests, 0);
        vector<ll> second(quests, 0);
        for (int i = 0; i < quests; i++)
        {
            cin >> first[i];
        }
        for (int i = 0; i < quests; i++)
        {
            cin >> second[i];
        }
        ll first_possible = 0;
        ll max_possible = 0;
        ll second_max = 0;
        for (ll index = 0; index < quests; index++)
        {
            if (max_q == index)
            {
                break;
            }
            first_possible += first[index];
            second_max = max(second_max, second[index]);
            max_possible = max(first_possible + (max_q - index - 1) * second_max, max_possible);
        }
        cout << max_possible << "\n";
    }
    return 0;
}
