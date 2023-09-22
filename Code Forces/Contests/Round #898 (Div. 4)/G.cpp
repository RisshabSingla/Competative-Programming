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


        // Contest Code
        // string str;
        // cin>>str;
        // int slen = str.length();
        // int coins = 0;

        // for(int i = 1; i<slen; i++){
        //     if(str[i-1] == 'A' && str[i] == 'B'){
        //         str[i-1] = 'B';
        //         str[i] = 'C';
        //         coins++;
        //     }
        //     if(str[i-1] == 'B' && str[i] == 'A'){
        //         str[i-1] = 'C';
        //         str[i] = 'B';
        //         coins++;
        //         i--;
        //     }
        // }

        // for(int i = slen-1; i>0; i--){
        //     if(str[i-1] == 'A' && str[i] == 'B'){
        //         str[i-1] = 'B';
        //         str[i] = 'C';
        //         coins++;
        //     }
        //     if(str[i-1] == 'B' && str[i] == 'A'){
        //         str[i-1] = 'C';
        //         str[i] = 'B';
        //         coins++;
        //         i--;
        //     }
        // }
        // cout<<coins<<endl; 



        // After Contest Code
        string str;
        cin>>str;
        int slen = str.length();
        int coins = 0; 

        vector<pair<char,int>> encoding;
        int index = 0;
        encoding.push_back({str[0],1});
        for(int i = 1; i<slen; i++){
            if(str[i] == encoding[index].first){
                encoding[index].second++;
            }else{
                encoding.push_back({str[i], 1});
                index++;
            }
        }
        bool can_take_all = encoding.front().first == 'B' || encoding.back().first == 'B' ;
        int a_sum = 0;
        int a_min = INT_MAX;
        for(auto &i: encoding){
            if(i.first == 'B' && i.second>1){
                can_take_all = true;
            }
            if(i.first == 'A'){
                a_sum+= i.second;
                a_min = min(a_min, i.second);
            }
        }


        if(can_take_all){
            cout<<a_sum<<endl;
        }else{
            cout<<max(a_sum-a_min,0)<<endl;
        }
    }
    return 0;
}
