#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void towerOfHanoi(int n, int from, int to, int aux)
{
    if (n == 0)
    {
        return;
    }

    towerOfHanoi(n - 1, from, aux, to);
    cout << from << " " << to << "\n";
    towerOfHanoi(n - 1, aux, to, from);
}
int main()
{
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    towerOfHanoi(n, 1, 3, 2);
    return 0;
}