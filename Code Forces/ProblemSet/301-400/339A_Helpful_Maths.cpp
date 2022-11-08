#include <iostream>

using namespace std;

int main()
{
    int arr[3] = {0};
    string a;
    cin >> a;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '1')
            arr[0]++;
        if (a[i] == '2')
            arr[1]++;
        if (a[i] == '3')
            arr[2]++;
    }
    string ans = "";

    while (arr[0]--)
    {
        ans = ans + "1+";
    }
    while (arr[1]--)
    {
        ans = ans + "2+";
    }
    while (arr[2]--)
    {
        ans = ans + "3+";
    }
    int length = ans.length();
    ans.erase(length - 1);
    cout << ans << endl;
    return 0;
}
