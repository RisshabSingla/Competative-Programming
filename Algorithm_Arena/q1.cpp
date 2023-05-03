#include <iostream>
#include<algorithm>

using namespace std;


int __gcd(int n1, int n2){

}

int main() {
	int n1,n2;
    cin>>n1>>n2;
	// cin >> num;    //Reading input from STDIN
	// cout << "Input number is " << num << endl;	// Writing output to STDOUT

    int gcd =  __gcd(n1, n2);
    if(gcd == 1){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;

}