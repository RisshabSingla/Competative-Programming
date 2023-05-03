#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

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
        int a,b,c;
        cin>>a>>b>>c;
        int upper = pow(2,c);
        map<int,int> freq;
        for(int x= 0; x<upper; x++){
            int val = (b|x) - (a&x);
            freq[val]++;
        }
        
        
        int highest = 0;
        map<int,int>::iterator i = freq.begin();
        for(; i!=freq.end(); i++){
            highest = i->second;
        }
        cout<<highest<<endl;
        
        
    }
    return 0;
}
