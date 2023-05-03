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
        int number;
        cin>>number;
        if(number%2 == 1){
            for(int i =0; i<number; i++){
                cout<<"1 ";
            }
            cout<<endl;
        }else{
            
        }
    }
    return 0;
}
