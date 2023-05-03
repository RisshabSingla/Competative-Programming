#include <iostream>

using namespace std;

int main()
{
    int sectors;
    int jump;
    cin >> sectors >> jump;
    string str;
    cin >> str;
    // int index = 0;
    // int next;
    // while(str[index] != '\0' && str[index] != '#' ){
    //     for(int i = jump; i>0; i--){
    //         if(index +i < str.length() && str[index+i] =='.'){
    //             next = index+i;
    //             break;
    //         }
    //     }
    //     if(next == index){
    //         break;
    //     }
    //     index = next;
    // }
    // if(next == sectors-1){
    //     cout<<"YES"<<endl;
    // }else{
    //     cout<<"NO"<<endl;
    // }

    for (int i = 0; i < sectors; i++)
    {
        int count;
        if (str[i] == '#'){
            count++;
        }else
            count = 0;
        if (count >= jump)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}