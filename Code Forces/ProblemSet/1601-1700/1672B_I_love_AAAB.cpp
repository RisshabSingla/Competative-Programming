#include<iostream>

using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        string str;
        cin>>str;
        if(str[str.length()-1] == 'A'){
            cout<<"NO"<<endl;
            continue;
        }
        if(str[0] == 'B'){
          cout<<"NO"<<endl;
          continue;
        }
        bool ans = true;
        int sum = 0;
        for(int i = 0; i<str.length(); i++){
            char ch = str[i];
            if(ch == 'A'){
                sum++;
                
            }else{
                sum--;
            }
            if(sum <0){
                ans = false;
            }
        }
        if(ans){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
