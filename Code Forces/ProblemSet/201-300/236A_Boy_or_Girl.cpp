#include <iostream>

using namespace std;

int main()
{
    string c;
    cin >> c;

    int arr[26] = {0};
    for (int i = 0; c[i] != '\0'; i++)
    {
        int index = int(c[i]) - 97;
        // cout<<"Index is: "<<index<<endl;
        // cout<<"Char is: "<<c[i]<<endl;
        arr[index]++;
    }
    int count = 0;

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
            count++;
    }

    if (count % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
    return 0;
}
