/*This algorithm simply applies twice the solution to longest increasing subsequence, then sums the results -1 (remeber that LIS[i] always used char V[i]).
Complexities are thus the same as those for that problem, that is O(N*lon(N)) time and O(N) space.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll k = 0; k < test_cases; ++k){
		ll N;
    	cin >> N;
    	vector<ll> V(N,0);
    	vector<ll> LIS(N,0);
    	vector<ll> LDS(N,0);
    	vector<ll> F;
    	
    	for(ll i = 0; i < N; ++i){
        cin >> V[i];
        vector<ll>::iterator it = lower_bound(F.begin(), F.end(), V[i]);
        if(it == F.end()) {
            F.push_back(V[i]);
        	} else *it = V[i];
        LIS[i] = F.size();
    	}
    	
    	F.clear();
    	reverse(V.begin(), V.end());
    	
    	for(ll i = 0; i < N; ++i){
        vector<ll>::iterator it = lower_bound(F.begin(), F.end(), V[i]);
        if(it == F.end()) {
            F.push_back(V[i]);
        	} else *it = V[i];
        LDS[i] = F.size();
    	}
    	
    	for(ll i = 0; i < N; i++){
    		V[i] = LIS[i] + LDS[N - i -1] - 1;
		}
		
		vector<ll>::iterator x = max_element(V.begin(), V.end());
		
		cout << *x << endl;
	}
	return 0;
}
