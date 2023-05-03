#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        string str;
        cin>>n>>str;
        string ans = "";
        for(int i = 0; i<n; i++){
            char ch = str[i];
            int count = 1;
            int index = i+1;
            char occ = str[index];
            while(occ == ch){
                index++;
                occ = str[index];
                count++;
                i++;
            }
            if(count>=3){
                ans+=ch;
            }else{
                while(count!=1){
                    ans+=ch;
                }
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
