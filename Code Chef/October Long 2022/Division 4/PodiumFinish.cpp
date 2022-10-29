/*
Problem
Chef got his dream seat in F1 and secured a 3rd place in his debut race. 
He now wants to know the time gap between him and the winner of the race.
You are his chief engineer and you only know the time gap between Chef and the runner up of the race, 
given as AA seconds, and the time gap between the runner up and the winner of the race, given as BB seconds.

Please calculate and inform Chef about the time gap between him and the winner of the race.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of a single line of input containing two space-separated integers AA and BB 
denoting the time gap between Chef and the runner up and the time gap between the runner up and the winner respectively.

Output Format
For each test case, output the time gap between Chef and the winner of the race.
Constraints
1≤T≤100
1≤A,B≤10
Sample 1:
Input
4
1 1
2 5
3 2
5 6
Output
2
7
5
11
Explanation:
Test case 1: The time gap between Chef and runner up is 11 second. The time gap between runner up and the winner is 11 second. Thus, the time gap between Chef and the winner is 1+1=21+1=2 seconds.

Test case 2: The time gap between Chef and runner up is 22 seconds. The time gap between runner up and the winner is 55 second. Thus, the time gap between Chef and the winner is 2+5=72+5=7 seconds.

Test case 3: The time gap between Chef and runner up is 33 seconds. The time gap between runner up and the winner is 22 second. Thus, the time gap between Chef and the winner is 3+2=53+2=5 seconds.

Test case 4: The time gap between Chef and runner up is 55 seconds. The time gap between runner up and the winner is 66 second. Thus, the time gap between Chef and the winner is 5+6=115+6=11 seconds.

*/

#include <iostream>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	while(cases--){
	    int a; 
	    int b;
	    cin>>a>>b;
	    cout<<a+b<<endl;
	}
	return 0;
}
