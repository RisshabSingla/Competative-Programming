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

bool check(int n, int target){
    if(n == target){
        return true;
    }

    if(n%3 != 0){
        return false;
    }

    return (check(n/3, target) || check(2*n/3, target));
}


int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        int target;
        cin>>target;
        if(n == target){
            cout<<"YES"<<endl;
            continue;
        }
        if(n%3 != 0){
            cout<<"NO"<<endl;
            continue;
        }

        if(check(n, target)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}



// bool func(int first, int target){
//     if(first == target){
//         return true;
//     }
//     if(first == 1 || first == 2 || first == 4){
//         return false;
//     }

//     while(first%3 == 0){
//         int first_half = 2*(first/3);
//         int second_half = (first/3);
//         first = first/3;
//         bool one = func(first_half, target);
//         if(one){
//             return true;
//         }
//         bool two = func(second_half, target);
//         if(one || two){
//             return true;
//         }
//     }
//     return false;
// }

// int main()
// {
//     int cases;
//     cin>>cases;
//     while(cases--){
//         int initial;
//         int target;
//         cin>>initial>>target;
//         if(initial == target){
//             cout<<"YES"<<endl;
//             continue;
//         }

//         if(target>=initial){
//             cout<<"NO"<<endl;
//             continue;
//         }
//         if(initial%3 != 0){
//             cout<<"NO"<<endl;
//             continue;
//         }
        
//         int first_half = -1;
//         int second_half = -1;

//         bool first;
//         bool second;
//         bool found = false;
//         while(initial%3 == 0){
//             first_half = 2*(initial/3);
//             second_half = (initial/3);
//             initial = initial/3;
//             first = func(first_half, target);
//             if(first){
//                 found = true;
//                 break;
//             }
//             second = func(second_half, target);
//             if(first|| second){
//                 found = true;
//                 break;
//             }
//         }
//         if(found){
//             cout<<"YES"<<endl;
//             continue;
//         }
//         cout<<"NO"<<endl;

//         // for(int i = 1; i<initial; i++){
//         //     if(3*i == initial){
//         //         first_half = 2*i;
//         //         second_half = i;
//         //     }
//         //     if(3*i > initial){
//         //         break;
//         //     }
//         // }

//         // if(first_half == -1 && second_half == -1){
//         //     cout<<"NO"<<endl;
//         //     continue;
//         // }

//         // bool first = func(first_half, target);
//         // bool second = func(second_half, target);
//         // if(first || second){
//         //     cout<<"YES"<<endl;
//         // }else{
//         //     cout<<"NO"<<endl;
//         // }
        

        
//     }
//     return 0;
// }
