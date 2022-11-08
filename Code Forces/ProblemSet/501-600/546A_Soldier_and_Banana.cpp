#include <iostream>

using namespace std;

int main()
{
    int cost;
    int total;
    int bananas;

    cin >> cost >> total >> bananas;

    int total_cost = (cost * (bananas) * (bananas + 1)) / 2;
    if (total_cost < total)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (total_cost - total) << endl;
    }

    return 0;
}
