#include<iostream>

using namespace std;

int main()
{
    string code;
    cin>>code;
    string ans = "";
    for(int i =0; i<code.length(); i++){
        if(code[i] == '.'){
            ans +='0';
        }else if(code[i]== '-'&& code[i+1] == '.'){
            ans+= '1';
            i++;
        }else if(code[i]== '-'&& code[i+1] == '-'){
            ans+='2';
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
