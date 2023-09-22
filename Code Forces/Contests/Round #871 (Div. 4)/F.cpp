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
        int vertices;
        int edges;
        cin>>vertices>>edges;
        int degree[vertices+1];
        for(int i = 0; i<=vertices; i++){
            degree[i] = 0;
        }

        for(int i = 0; i<edges; i++){
            int u,v;
            cin>>u>>v;
            degree[u]++;
            degree[v]++;
        }
        // cout<<"Degrees are: ";
        // for(int i = 0; i<=vertices; i++){
        //     cout<<degree[i]<<" ";
        // }
        // cout<<endl;
        map<int,int> count;
        for(int i = 1; i<=vertices; i++){
            count[degree[i]]++;
        }
        vector<int> ans(3);
        int index = 0;
        cout<<"Map is: "<<endl;
        for(auto i: count){
            ans[index] = i.second;
            index++;
            cout<<i.first<<" "<<i.second<<endl;
        }
        int x = ans[1];
        int y = ans[0]/ ans[1];
        cout<<"Ans is"<<x<<" "<<y<<endl;
        // int degreeOne = count.begin()->second;
        // int degreeTwo = (count.begin()++)->second;
        // int degreeThree = ((count.begin()++)++)->second;
        // cout<<"One is: "<<degreeOne<<endl;
        // cout<<"Two is: "<<degreeTwo<<endl;
        // cout<<"Three is: "<<degreeThree<<endl;

    }
    return 0;
}
