#include <iostream>

using namespace std;

int main()
{
    long long number;
    cin >> number;
    int fours = 0;
    int sevens = 0;
    while (number > 0)
    {
        int last = number % 10;
        if (last == 4)
            fours++;
        if (last == 7)
            sevens++;
        number = number / 10;
    }

    int total = fours + sevens;

    if(total == 4 || total == 7){
        cout << "YES" << endl;
        return 0;
    }
    if(total == 0){
        cout << "NO" << endl;
        return 0;
    }

    while (total > 0)
    {
        int last = total % 10;
        if (last != 4 || last != 7)
        {
            cout << "NO" << endl;
            return 0;
        }
        last = last / 10;
    }
    cout << "YES" << endl;
    return 0;
}
