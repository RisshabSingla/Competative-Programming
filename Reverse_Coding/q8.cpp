#include <iostream>
#include <vector>
#include <cstring>  

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        char *str;
        cin >> str;
        char *arr = strtok(str, ",");
        while (arr != NULL)
        {
            cout << arr << endl; // print the string token
            arr ++;
        }
    }
}


