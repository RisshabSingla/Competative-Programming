// // #include <bits/stdc++.h>

#include <iostream>
#include <vector>

// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     vector<string> arr;
//     if (t >= 0 && t <= 100)
//     {
//         for (int i = 0; i < t; i++)
//         {
//             string str;
//             cin >> str;
//             arr.push_back(str);
//             string s = "";
//             bool upperPresent = false;
//             bool numPresent = false;
//             for (int i = 0; i < str.length(); i++)
//             {
//                 if (isupper(str[i]))
//                 {
//                     upperPresent = true;
//                     break;
//                 }
//                 if(isdigit(str[i])){
//                     numPresent = true;
//                 }
//             }

//             if (!upperPresent)
//             {
//                 for (int i = 0; i < str.length(); i++)
//                 {
//                     char ch = str[i];
//                     ch = ch + i;
//                     s = s + ch;
//                 }
//                 arr.push_back(s);
//                 cout << str << endl;
//                 cout << s << endl;
//             }else{
//                 // capital present
//                 s = s+ str + ": ["; 
//                 for(int i = 0; i<str.length(); i++){
//                     if(isupper(str[i])){
//                         s = s+"-1, ";
//                     }else{
//                         s = s + "0, ";
//                     }
//                 }
//             }


//             if(numPresent){

//             }
//         }
//     }
//     else
//     {
//         cout << "Input length is out of range." << endl;
//     }
// }




// #include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<string> arr;
    if (t >= 0 && t <= 100)
    {
        for (int i = 0; i < t; i++)
        {
            string str;
            cin >> str;
            arr.push_back(str);
            string s = "";
            
            for (int i = 0; i < str.length(); i++)
            {
                char ch = str[i];
                ch = ch + i;
                if(ch > 122){
                    ch -= 26;
                }
                s = s + ch;
            }
            arr.push_back(s);
            cout << str << endl;
            cout << s << endl;
        }
    }
    else
    {
        cout << "Input length is out of range." << endl;
    }
}