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
    int cases;
    cin>>cases;
    while(cases--){
        int length;
        cin>>length;
        string str;
        cin>>str;
        int maxChar = -1;
        for(int i =0; i<length; i++){
            int ch = str[i] -'a'+1;
            maxChar = max(ch,maxChar);
        }
        cout<<maxChar<<endl;
    }
    return 0;
}
