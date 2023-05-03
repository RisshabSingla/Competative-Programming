#include<iostream>
using namespace std;


int main() {
    
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
     int n;
    cin>>n;
     for(int i=0;i<(n/2)+1;i++){
     for(int j=0;j<n;j++){
            if(j>=n/2-i&&j<n/2+i+1){
                cout<<"*";
            }
            else
             cout<<" ";
         }
        cout<<endl;
    }
    for(int i=0;i<n/2;i++){
     for(int j=0;j<n;j++){
            if(j<n-i-1&&j>i){
                cout<<"*";
            }
            else
             cout<<" ";
         }
        cout<<endl;
    }
}
