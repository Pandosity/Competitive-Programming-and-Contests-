/*This algorithm implements the strategy of greedily selecting earliest finish time that fits with last one selected. Space consumption is clearly 
O(n), and time consumption is O(n*log(n)) because we need to sort the activities with respect to their finish time.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

struct activity{
	ll start, end;
	ll index;
};

struct compEnd{
	bool operator()(const activity& a, const activity& b){
		return a.end < b.end;
	}
};

struct compIndex{
	bool operator()(const activity& a, const activity& b){
		return a.index < b.index;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll i = 0; i < test_cases; ++i){
		ll n;
		cin >> n;
		
		vector<activity> A(n);
		for(ll j = 0; j < n; ++j){
			cin >> A[j].start;
			A[j].index = j;
		}
		for(ll j = 0; j < n; ++j){
			cin >> A[j].end;
		}
		
		deque<activity> schedule;
		sort(A.begin(), A.end(), compEnd());
		for(ll j = 0; j < n; ++j){
			if(schedule.empty() || schedule.back().end <= A[j].start) schedule.push_back(A[j]);
		}
		
		while(!schedule.empty()){
			cout << schedule.front().index + 1 << " ";
			schedule.pop_front();
		}
		cout << endl;
	}
	
	return 0;
}
