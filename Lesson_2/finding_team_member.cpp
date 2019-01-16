/*We sort the partecipants by strength, and then select the teams greedily. Space and time consumption are
both O(N^2) where N is the number of teams to be formed.*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct team {
  int member1;
  int member2;
  long strength;
  
  team(int a, int b, long s)
  	: member1(a), member2(b), strength(s) {}
	  
};


bool comparer(const team &A, const team &B){
	return (A.strength > B.strength);
}

int main(){
	
	int teams;
	cin >> teams;
	vector<team> mydata;
	mydata.reserve(teams*(2*teams - 1));
	
	for (int i = 1; i < 2*teams; ++i){
		for (int j = 0; j < i ; ++j){
			long strength;
			cin >> strength;
			mydata.emplace_back(i, j, strength);
		}
	}
	
	sort(mydata.begin(), mydata.end(), comparer);
		
	vector<int> couples;
	couples.reserve(2*teams);
	for (int i = 0; i < 2*teams ; ++i){
		couples.push_back(0);
	}
	
	for (vector<team>::iterator it = mydata.begin(); it != mydata.end(); ++it){
		if (couples[(*it).member1] == 0 && couples[(*it).member2] == 0){
			couples[(*it).member1] = (*it).member2 + 1;
			couples[(*it).member2] = (*it).member1 + 1;
		}
	}
	
	for(int i = 0; i < 2*teams ; ++i){
		cout << couples[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}
