#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while (n>0)
    {
        string s;
        cin>>s;
        string ans = "";
        int length = s.length();
        if (length > 10)
        {
            ans += s[0];
            int a = length - 2;
            ans += to_string(a);
            ans += s[length - 1];
            cout << ans << endl;
        }
        else
        {
            cout << s << endl;
        }
        n--;
    }

    return 0;
}
