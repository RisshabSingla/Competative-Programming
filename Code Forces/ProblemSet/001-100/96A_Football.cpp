#include<iostream>

using namespace std;

int main()
{
    string str;
    cin>>str;
    int count = 0;
    char ch = '0';
    int maxCount = -1;
    for(int i =0; i<str.length(); i++){
        if(str[i] == ch){
            count++;
            maxCount = max(maxCount, count);
        }else{
            ch =  str[i];
            count = 1;
        }
    }
    // cout<<"Max Count is "<<maxCount<<endl;
    if(maxCount >6){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}