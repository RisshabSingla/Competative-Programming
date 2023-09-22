#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>

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
    while(cases--){
        string str;
        cin>>str;
        char f = str[0];
        bool swapped = false;
        if(f != 'a'){
            if(str[1] == 'a'){
                swap(str[0], str[1]);
                // swapped = true;
            }else{
                swap(str[2], str[0]);
                // swapped = true;
            }
        }else{
            if(str[1] != 'b'){
                swap(str[1], str[2]);
            }
        }
        if(str == "abc"){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
