/*This algorithm implements the following dynamic routine: at the i-th step we compute the "optimal" LIS buildable with the first i integers,
where with optimal we mean that at each step we append the new value to the current LIS if it's greater than every value stored, and otherwise
we change the integer at position lower_bound with x, getting the sequence to which it is easiest to append new values. lower_bound has complexity log(n),
so time complexity is O(n*log(n)). Space complexity is linear in n.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

ll A[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll k = 0; k < test_cases; ++k){
		ll N;
    	cin >> N;
    	vector<ll> LIS;
    	
    	for(ll i = 0; i < N; ++i){
        int x;
        cin >> x;
        vector<ll>::iterator it = lower_bound(LIS.begin(), LIS.end(), x);
        
        if(it == LIS.end()) {
            LIS.push_back(x);
        	} else *it = x;
    	}
    cout << LIS.size() << endl;
	}
	return 0;
}
