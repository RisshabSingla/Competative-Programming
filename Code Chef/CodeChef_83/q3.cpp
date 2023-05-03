// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// int main() {
// 	int n;
// 	cin>>n;
// 	for(int i=0;i<n;i++)
// 	{
// 	    int n1;
// 	    cin>>n1;
// 	    string str1,sol;
// 	    cin>>str1;
// 	    sol="";
//         for(int j= 0; j<n1; j++)
//         {
//             char chr= str1[j];
//             int cnt = 1;
//             for(int k = j+1; k<n1; k++)
//             {
//                 char ch = str1[k];
//                 if(ch!= chr)
//                 {
//                     break;
//                 }
//                 cnt++;
//             }
//             j=j+(cnt-1);
//             //acount even then this
//             if(cnt%2 == 0)
//             {
//                 sol=sol+chr;
//                 sol=sol+chr;
//             }
//             //acount odd then this
//             else
//             {
//                 sol=sol+chr;
//             }
//         }
//         cout<<sol<<endl;

// 	}
// 	return 0;
// }



// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// typedef long long ll; 
// typedef pair<int, int> ii; 
// typedef vector<ii> vii;
// typedef vector<int> vi;

// const int mod = 1000000007;

// int calc(int n){
//     if(n == 4){
//         return 3;
//     }
//     if(n == 3){
//         return 2;
//     }
//     if(n == 1 || n == 2){
//         return 0;
//     }
//     return calc(n-2) + 3;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int cases;
//     cin>>cases;
//     while(cases--){
//         int n;
//         cin>>n;
        
//         cout<<calc(n)<<endl;
//     }
//     return 0;
// }



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// int calc(int n){
//     if(n == 4){
//         return 3;
//     }
//     if(n == 3){
//         return 2;
//     }
//     if(n == 1 || n == 2){
//         return 0;
//     }
//     return calc(n-2) + 3;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        
        int val = 3*(n/2 - 1) + 2*(n%2);
        cout<<val<<endl;
        // cout<<calc(n)<<endl;
    }
    return 0;
}
