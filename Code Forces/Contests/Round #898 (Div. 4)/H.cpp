// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <map>
// #include <unordered_map>
// #include <cmath>
// #include<queue>

// using namespace std;
// typedef long long ll;
// typedef pair<int, int> ii;
// typedef vector<ii> vii;
// typedef vector<int> vi;

// const int mod = 1000000007;

// bool dfs(int start, int node, vector<vector<int>> &adj_list, vector<bool> &visited){
//     visited[start] = true;
//     if(start == node){
//         return true;
//     }
//     for(int i = 0; i<adj_list[start].size(); i++){
//         int n = adj_list[start][i];
//         if(!visited[n] && dfs(n, node, adj_list, visited)){
//             return true;
//         }
//     }
//     return false;
// }

// bool isPart(int node, vector<vector<int>> &adj_list){
//     vector<bool> visited(adj_list.size(), false);
//     // visited[node] = true;
//     for(int i = 0; i<adj_list[node].size(); i++){
//         int n = adj_list[node][i];
//         if(!visited[n] && dfs(n, node, adj_list, visited)){
//             return true;
//         }
//     }
//     return false;
// }


// int calcDistance(vector<vector<int>> &adj_list, int start, int end){
//     int cost = INT_MAX;
//     queue<pair<int,int>> q;
//     vector<bool> visited(adj_list.size(), false);
//     for(int i = 0; i<adj_list[start].size(); i++){
//         int node = adj_list[start][i];
//         q.push({node, 1});
//         visited[node] = true;
//         if(node == end){
//             cost = 1;
//             return 1;
//         }
//     }
//     while(!q.empty()){
//         pair<int,int> p = q.front();
//         q.pop();
//         for(int i = 0; i<adj_list[p.first].size(); i++){
//             int n = adj_list[p.first][i];
//             if(n == end){
//                 cost = min(cost, p.second+1);
//             }
//             if(!visited[n]){
//                 visited[n] = true;
//                 q.push({n, p.second+1});
//             }
//         }
//     }
//     return cost;
// }

// int findClosestNode(vector<int> &cycle,  vector<vector<int>> &adj_list, int node){
//     int distance = INT_MAX;
//     int closestNode;
//     for(int i = 0; i<cycle.size(); i++){
//         if(node == cycle[i]){
//             return cycle[i];
//         }
//         int d = calcDistance(adj_list, cycle[i], node);
//         // cout<<d<<" ";
//         if(d < distance){
//             distance = d;
//             closestNode = cycle[i]; 
//         }
//         // distance = min(distance, d);
//     }
//     return closestNode;
// }


// int main()
// {
//     int cases;
//     cin >> cases;
//     while (cases--)
//     {
//         // After contest code
//         int nodes;
//         int marcel;
//         int valeriu;
//         cin >> nodes >> marcel >> valeriu;
//         vector<vector<int>> adj_list(nodes);
//         for(int i = 0; i<nodes; i++){
//             int a,b;
//             cin>>a>>b;
//             adj_list[a-1].push_back(b-1);
//             adj_list[b-1].push_back(a-1);
//         }

//         if(marcel == valeriu){
//             cout<<"NO"<<endl;
//             continue;
//         }

//         // cout<<"Adj list"<<endl;
//         // for(int i = 0; i<nodes; i++){
//         //     cout<<i<<" : ";
//         //     for(auto j: adj_list[i]){
//         //         cout<<j<<" ";
//         //     }
//         //     cout<<endl;
//         // }

//         vector<int> cycle;
//         for(int i = 0; i<nodes; i++){
//             if(adj_list[i].size() > 1 && isPart(i, adj_list)){
//                 cycle.push_back(i);
//             }
//         }

//         // cout<<"Cycle: ";
//         // for(auto i: cycle){
//         //     cout<<(i)<<" ";
//         // }
//         // cout<<endl;
//         // cout<<endl;

        
//         if(find(cycle.begin(), cycle.end(), marcel-1) != cycle.end() && find(cycle.begin(), cycle.end(), valeriu-1) !=cycle.end()){
//             // both are inside the cycle
//             cout<<"YES"<<endl;
//         }else{
//             // cout<<"Distance: ";
//             // int distMarcel = findDistance(cycle, adj_list, marcel-1);
//             // cout<<endl;
//             // cout<<"Distance Marcel: "<<distMarcel<<endl;
//             // cout<<"Distance: ";
//             int nodeClosestToValeriu = findClosestNode(cycle, adj_list, valeriu-1);

//             int distValeriu  = calcDistance(adj_list, valeriu-1, nodeClosestToValeriu);
//             int distMarcel  = calcDistance(adj_list, marcel-1, nodeClosestToValeriu);

//             // cout<<endl;
//             // cout<<"Distance Valeriu: "<<distValeriu<<endl;
//             if(distMarcel <= distValeriu ){
//                 cout<<"YES"<<endl;
//             }else{
//                 cout<<"NO"<<endl;
//             }
//         }

//     }
//     return 0;
// }
