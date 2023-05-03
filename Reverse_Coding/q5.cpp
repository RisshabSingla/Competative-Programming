// // #include <bits/stdc++.h>
// // using namespace std;

// // int main() {
// //     // your code goes here
// //     int t;
// //     cin>>t;
// //     while (t--)
// //     {
// //         string s;
// //         cin>>s;
// //         int n=s.length();
// //         if(n<3){
// //             cout<<s<<endl;
// //         }
// //         else{
// //             for(int i=0;i<n;i++){
// //                 if(s[i]==s[i+1]){
// //                     cout<<s[i]<<s[i+1]<<endl;
// //                     break;
// //                 }
// //                 else{
// //                     cout<<s[0]<<endl;
// //                     break;
// //                 }
// //             }
// //         }

// //     }
// //     return 0;
// // }


// #include <bits/stdc++.h>
// using namespace std;

// string longestPalindrome(string s) {
//     int n = s.size();
//     if (n == 0) {
//         return "";
//     }
//     bool dp[n][n] = {false};
//     int start = 0, len = 1;
//     for (int i = 0; i < n; i++) {
//         dp[i][i] = true;
//     }
//     for (int i = n - 1; i >= 0; i--) {
//         for (int j = i + 1; j < n; j++) {
//             if (s[i] == s[j]) {
//                 if (j - i == 1 || dp[i + 1][j - 1]) {
//                     dp[i][j] = true;
//                     if (j - i + 1 > len) {
//                         len = j - i + 1;
//                         start = i;
//                     }
//                 }
//             }
//         }
//     }
//     return s.substr(start, len);
// }
// int main() {
//     int t;
//     cin>>t;
//     while (t--)
//     {
//         string s;
//         cin>>s;
//         string a=longestPalindrome(s);
//         cout<<a<<endl;


//     }
//     return 0;
// }