#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>
#include<stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;


int n,m;
int arr[1001][1001];
bool visited[1001][1001];

// int findPath(int** arr, int** visited, int i, int j){

//     for(int )
// }

int findPath(int i , int j){
    int ans = arr[i][j];
    visited[i][j] = true;
    if(i!=0 && arr[i-1][j] >0  && !visited[i-1][j]){
        ans+=findPath(i-1,j);
    }

    if(i!= n-1 && arr[i+1][j]>0 && !visited[i+1][j]){
        ans+=findPath(i+1,j);
    }

    if(j!=0 && arr[i][j-1] >0  && !visited[i][j-1]){
        ans+=findPath(i,j-1);
    }

    if(j!= m-1 && arr[i][j+1]>0 && !visited[i][j+1]){
        ans+=findPath(i,j+1);
    }
    return ans;
}



int main(){
    int cases;
    cin>>cases;
    while(cases--){
        cin>>n>>m;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>arr[i][j];
                visited[i][j]= false;
            }
        }

        int max_ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && arr[i][j]>0){
                    int ans = findPath(i,j);
                    max_ans = max(ans,max_ans);
                }
                
            }
        }
        cout<<max_ans<<endl;
    }
}



// int main()
// {
//     int cases;
//     cin>>cases;
//     while(cases--){
//         int n,m;
//         cin>>n>>m;
//         int **arr = new int*[n];
//         bool **visited = new bool*[n];
//         for(int i = 0; i<n ; i++){
//             arr[i] = new int[m];
//             visited[i] = new bool[m];
//         }

//         int first_i = -1;
//         int first_j = -1;
        
//         for(int i =0; i<n; i++){
//             for(int j = 0; j<m; j++){
//                 cin>>arr[i][j];
//                 visited[i][j] = false;
//                 if(arr[i][j] == 1){
//                     if(first_i == -1){
//                         first_i = i;
//                         first_j = j;
//                     }
//                 }
//             }
//         }
//         if(first_i == -1){
//             cout<<0<<endl;
//             continue;
//         }

//         stack<pair<int,int> > q;
//         pair<int,int> pair_one(first_i, first_j);
//         q.push(pair_one);
//         // cout<<"Here"<<endl;
//         // return 0;
//         int count = 0;
//         while(!q.empty()){
//             pair<int,int> p = q.top();
//             // cout<<"Pair is: "<<p.first<<" "<<p.second<<endl;
//             q.pop();
//             if(!visited[p.first][p.second]){
//                 visited[p.first][p.second] = true;
//                 count+=arr[p.first][p.second];
//             }
//             if(p.first + 1<n && arr[p.first+1][p.second] != 0 && 
//                 !visited[p.first+1][p.second]){
//                 pair<int,int> pa(p.first + 1, p.second);
//                 q.push(pa);
//             }
//             if(p.second +1<m && arr[p.first][p.second+1] != 0 &&
//                !visited[p.first][p.second+1]){
//                 pair<int,int> pa(p.first, p.second+1);
//                 q.push(pa);
//             }
//             if(p.second -1>=0 && arr[p.first][p.second-1] != 0 && 
//                 !visited[p.first][p.second-1]){
//                 pair<int,int> pa(p.first, p.second-1);
//                 q.push(pa);
//             }
//             if(p.first - 1>=0 && arr[p.first-1][p.second] != 0 && 
//                 !visited[p.first-1][p.second]){
//                 pair<int,int> pa(p.first - 1, p.second);
//                 q.push(pa);
//             }
            
//             // if(p.first + 1<n && p.second +1<m){
//             //     pair<int,int> pa(p.first+1, p.second+1);
//             //     q.push(pa);
//             // }
//         }
//         cout<<count<<endl;

//     }
//     return 0;
// }
