/*Space and time consumption are both linear.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;

int main(){
	
	int size;
	cin >> size;
	vector<int> times(size,0);
	int sum = 0;
	
	for(int i = 0; i < size; ++i){
		cin >> times[i];
		sum += times[i];
	}
	
	int partial = 0;
	int alice = 0;
	
	while(alice < size && partial < sum){
		partial += times[alice];
		sum -= times[alice];
		++alice;
	}
	
	if(partial - times[alice-1] > sum) alice--;
	
	cout << alice << " " << size - alice <<endl;
	
	return 0;
}
