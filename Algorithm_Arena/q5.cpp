#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;


int main(){
    string str;
    cin>>str;
    int length = str.length();
    // for(int i =0; i<length/2; i++){
    //     char ch = str[i];
    //     str[i] = str[length-1-i] ;
    //     str[length-1-i] = ch;
    // }
    reverse(str.begin(), str.end());

    cout<<str<<endl;
    str = str+'.';
    int index = 0;
    for(int i =0; i<length; i++){
        if(str[i] == '.'){
            reverse(str.begin()+index, str.begin()+i);
            index = i+1;
        }
    }
    cout<<str.substr(0,length)<<endl;
}