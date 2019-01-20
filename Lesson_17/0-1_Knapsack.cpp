/*This algorithm implements the weight-based dynamic recursion of the slides. Time and space consumption are bot O(N*C), where N is the number ob objects and C
is the maximum capacity of the knapsack.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

ll K[101][101];
ll values[101];
ll weights[101];
		

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll k = 0; k < test_cases; ++k){
		ll N;
		ll W;

		cin >> N >> W;
		for(ll i = 0; i < N; ++i) cin >> values[i];
		for(ll i = 0; i < N; ++i) cin >> weights[i];
		
		for(ll i = 0; i < N+1 ; ++i){
			for(ll j = 0; j < W+1; ++j){
				if(i == 0 || j == 0){
				K[i][j] = 0;
				}else if(j < weights[i - 1]) {
					K[i][j] = K[i - 1][j];
					} else {K[i][j] = max(K[i - 1][j], K[i - 1][j - weights[i-1]]+values[i-1]);}
			}
		}
		
		cout << K[N][W] << endl;
	}
	
	return 0;
}
