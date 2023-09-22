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
        int slen;
        int k;
        cin>>slen>>k;
        string str;
        cin>>str;
        vector<int> indexes;
        int count = 0;
        for(int i = 0; i<slen; i++){
            if(str[i] == 'B'){
                count++;
                i+= k-1;
            }
        }
        cout<<count<<endl;  
    }
    return 0;
}
