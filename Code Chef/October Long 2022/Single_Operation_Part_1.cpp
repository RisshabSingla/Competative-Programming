#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int cases;
	cin>>cases;

	while(cases--){
	    // int length;
	    // cin>>length;
	    string bin;
	    cin>>bin;
	    long long num = 0;
			int length = bin.length();
	    for(int i = 0; i<length; i++){
	        num+= (bin[length-i-1] - '0')*(pow(2,i));
	    }
			cout<<"Num is: "<<num<<endl;
			// int num;
			// cin>>num;
			// long long input ;
			// cin>>input;
			// for(int i = 1; i<input+1; i++){
				// long long num = input;
				long long val;
		    long long high = 0;
		    for(int i = 0; i<8; i++){
		        int a = pow(2,i);
						cout<<"Value of a is: "<<a<<endl;
		        long long b = floor(num/a);
						cout<<"Value of b is: "<<b<<endl;
		        long long ans = num ^ b;
						cout<<"ans is: "<<ans<<endl;
		        if(ans>high){
		            high = ans;
		            val = i;
		        }
						cout<<endl;
		    }
		    cout<<val<<endl;
				cout<<"*********"<<endl;

	    // int val;
	    // int high = 0;
	    // int power = sqrt(num);
	    // for(int i = 0; i<power+2; i++){
	    //     int a = pow(2,i);
	    //     int b = floor(num/a);
	    //     int ans = num ^ b;
			// 		cout<<"ans is: "<<ans<<endl;
	    //     if(ans>high){
	    //         high = ans;
	    //         val = i;
	    //     }
	    // }
	    // cout<<val<<endl;

	}
	return 0;
}




// #include <iostream>
// #include <cmath>
// using namespace std;
//
// int main() {
// 	int cases;
// 	cin>>cases;
// 	while(cases--){
// 	    long long length;
// 	    cin>>length;
// 	    string bin;
// 	    cin>>bin;
// 	    long long num = 0;
// 	    for(int i = 0; i<length; i++){
// 	        num+= (bin[length-i-1] - '0')*(pow(2,i));
// 	    }
//
// 	    long long val;
// 	    long long high = 0;
// 	    for(int i = 1; i<8; i++){
// 	        int a = pow(2,i);
// 	        long long b = floor(num/a);
// 	        long long ans = num ^ b;
// 	        if(ans>high){
// 	            high = ans;
// 	            val = i;
// 	        }
// 	    }
// 	    cout<<val<<endl;
// 	}
// 	return 0;
// }
