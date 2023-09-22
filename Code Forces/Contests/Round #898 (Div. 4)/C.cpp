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
        vector< vector <char> > board(10, vector<char>(10));
        for(int i =0; i<10; i++){
            for(int j = 0; j<10; j++){
                cin>>board[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i<5; i++){
            for(int j = i; j<10-i; j++){
                if(board[i][j] == 'X'){
                    ans+=(i+1);
                }
                if(board[9-i][j] == 'X'){
                    ans+=(i+1);
                }
            }
            for(int x = i+1; x<10-i-1; x++){
                if(board[x][i] == 'X'){
                    ans+= (i+1);
                }
                if(board[x][9-i] == 'X'){
                    ans+= (i+1);
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
