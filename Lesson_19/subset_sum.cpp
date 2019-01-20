/*We use a dymanic approach. At each step, we set the entry K[i][j] at true if a sum of j is buildable with the first i integers, false otherwise.
At the end it's enough to check K[N][sum/2] (if sum = 2t+1 the task is obviously impossible).
Space and time complexity are O(N*sum).*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

bool K[101][100001];
ll A[100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll k = 0; k < test_cases; ++k){
		ll N;
		cin >> N;
		ll sum = 0;
		for(ll i = 0; i < N; ++i){
			cin >> A[i];
			sum += A[i];
		}
		
		if(sum % 2 == 1){
			cout << "NO" << endl;
			continue;
		}
		
		for(ll i = 0; i <= N; ++i){
			K[i][0] = true;
		}
		for(ll i = 1; i <= sum; ++i){
			K[0][i] = false;
		}
		
		for(ll j = 1; j <= N; ++j){
			for(ll i = 1; i <= sum; ++i){
				if(i >= A[j-1]){
					K[j][i] = K[j-1][i] || K[j-1][i-A[j-1]];
				} else K[j][i] = K[j-1][i];
			}
		}
		
		if(K[N][sum/2] == true){
			cout << "YES" << endl;
		} else{
			cout << "NO" << endl;
		}
		
	}
	return 0;
}
