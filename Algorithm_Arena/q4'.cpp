#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;


int main(){
    int n;
    int k;
    cin>>n>>k;
    queue<int> q;
    for(int i =0; i<n; i++){
        q.push(i);
    }

    while(q.size()!= 1){

        for(int i =0;i<k-1; i++){
            int t = q.front();
            q.push(t);
            q.pop();
        }
        q.pop();
    }
    int rem = q.front();
    cout<<rem+1<<endl;


}