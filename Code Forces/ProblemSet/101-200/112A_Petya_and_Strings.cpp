#include <iostream>
using namespace std;

int main()
{
    // A ->65 a->97

    string a, b;
    cin >> a >> b;

    for (int i = 0; a[i] != '\0'; i++)
    {
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
    }
    int i = 0;

    while (a[i] != '\0')
    {
        int diff = a[i] - b[i];
        if (diff > 0)
        {
            cout << 1 << endl;
            return 0;
        }
        if (diff < 0)
        {
            cout << -1 << endl;
            return 0;
        }
        i++;
    }
    cout << 0 << endl;
    return 0;
}
