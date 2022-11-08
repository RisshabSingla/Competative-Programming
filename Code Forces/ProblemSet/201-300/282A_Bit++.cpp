#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 0;
    while (n--)
    {
        string a;
        cin >> a;
        if (a[0] == 'X'){
            if (a[1] == '+')
                x++;
            else
                x--;
        }else{
            if (a[0] == '+')
                x++;
            else
                x--;
        }
    }
    cout << x << endl;
    return 0;
}