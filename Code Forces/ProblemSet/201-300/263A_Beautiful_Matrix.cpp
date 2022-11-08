#include <iostream>

using namespace std;

int main()
{
    int i, j;
    int num;
    for (int a = 0; a < 5; a++)
    {
        for (int b = 0; b < 5; b++)
        {
            cin >> num;
            if (num == 1)
            {
                i = a;
                j = b;
            }
        }
    }

    int idiff = abs(i - 2);
    int jdiff = abs(j - 2);

    cout << (idiff + jdiff) << endl;

    return 0;
}