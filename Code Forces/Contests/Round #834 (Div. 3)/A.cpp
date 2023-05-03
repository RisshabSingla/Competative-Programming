#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;


int main()
{
    int cases;
    cin>>cases;
    unordered_map<string, int> substrings;
    string yes = "Yes";
    // for(int i =0; i<yes.length(); i++){
    //     for(int j =i; )
    // }
    while(cases--){
        string str;
        cin>>str;
        // if(str.length() <3){
        //     cout<<"NO"<<endl;
        //     continue;
        // }

        bool found = false;
        for(int i =0; i<str.length()-2;i++){
            if(str[i] == 'Y' && str[i+1] == 'e' && str[i+2] == 's'){
                cout<<"YES"<<endl;
                found = true;
                break;
            }
        }

        for(int i =0; i<str.length(); i++){
            for(int j = i+1; j<str.length(); i++){
                string a = str.substr(i,j-i);
                  
                
            }
        }

        if(!found){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
