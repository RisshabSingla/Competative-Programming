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
        int n,m;
        cin>>n>>m;
        vector<vector<char>> arr(n, vector<char>(m));
        for(int i = 0; i<n; i++){
            string s;
            cin>>s;
            for(int j = 0;j<m; j++){
                arr[i][j] = s[j];
            }
        }

        // for(auto i: arr){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        string str = "vika";
        int index = 0;
        for(int j = 0; j<m; j++){
            for(int i = 0;i<n; i++){
                if(arr[i][j] == str[index]){
                    index++;
                    break;
                }
            }
        }
        if(index == 4){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
