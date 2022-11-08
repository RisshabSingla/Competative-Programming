#include <iostream>
// #include <string>
#include <unordered_map>
// #include <ctype.h>
#include <cwctype> 

// #include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, char> mapping;
    string layout1;
    string layout2;
    cin >> layout1 >> layout2;
    string output1;
    cin >> output1;
    string output2 = "";
    for (int i = 0; i < 26; i++)
    {
        mapping[layout1[i]] = layout2[i];
    }


    for (int i = 0; i < output1.length(); i++)
    {
        char ch = output1[i];
        if (!iswdigit(ch))
        {
            if (iswupper(ch))
            {
                ch = towlower(ch);
                char a = mapping[ch];
                // a = toupper(a);
                output2 += ((char)towupper(a));
                // cout<<"Added "<<a<<endl;
            }
            else
            {
                char a = mapping[ch];
                output2 += a;
                // cout<<"Added "<<a<<endl;
            }
        }
        else
        {
            output2 += ch;
            // cout<<"Added "<<ch<<endl;
        }
    }
    cout << output2 << endl;

    return 0;
}
