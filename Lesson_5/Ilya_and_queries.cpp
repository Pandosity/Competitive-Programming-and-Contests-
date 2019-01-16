/*We just compute a boolean vector with true if s_i = s_(i+1), and compute its prefix sums. 
Answer is then a difference of entries of this array. Space and time consumption are linear */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;

vector<int> PartialBool(string letters){
	int n = letters.size();
	vector<bool> checker(n-1, false);
	
	for(int i = 0; i < n-1 ; i++){
		if(letters[i] == letters[i+1]) checker[i] = true;
	}
	
	int partial = 0;
	vector<int> sums(n,0);
	
	for(int j = 1; j < n ; j++){
		partial += checker[j-1];
		sums[j] = partial;
	}
	
	return sums;
}

int main(){
	string address;
	cin >> address;
	
	vector<int> solver = PartialBool(address);
	int test_cases;
	cin >> test_cases;
	
	for(int i = 0; i < test_cases; ++i){
		int left, right;
		cin >> left;
		cin >> right;
		
		cout << solver[right -1] - solver[left - 1] << endl;
	}	
	
	return 0;
}
