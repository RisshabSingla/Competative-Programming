#include <iostream>
using namespace std;
int day_of_week(int y, int m, int d)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}
int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int y, m, d;
        // cout<<"Enter the date(1-31): ";
        cin >> d;
        // cout<<"Enter the month(1-12): ";
        cin >> m;
        // cout<<"Enter the year(yyyy): ";
        cin >> y;
        if (d > 31 || m > 12 || y>9999)
        {
            cout << "Invalid input. Please check the question description." << endl;
        }
        else
        {
            switch (day_of_week(y, m, d))
            {
            case 0:
                cout << "\nFriday";
                break;
            case 1:
                cout << "\nSaturday";
                break;
            case 2:
                cout << "\nSunday";
                break;
            case 3:
                cout << "\nMonday";
                break;
            case 4:
                cout << "\nTuesday";
                break;
            case 5:
                cout << "\nWednesday";
                break;
            case 6:
                cout << "\nThursday";
                break;
            }
        }
    }

    return 0;
}