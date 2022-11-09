#include<iostream>

using namespace std;

int main()
{
    int numbers;
    cin>>numbers;
    string str;
    cin>>str;
    string phone = str;
    for(int i  = 0; i<numbers-1; i++){
        cin>>str;
        int j;
        for(j = 0; j<str.length() && j<phone.length(); j++){
            if(phone[j]!= str[j]){
                break;
            }
        }
        phone = str.substr(0,j);
    }
    cout<<phone.length()<<endl;

    return 0;
}
