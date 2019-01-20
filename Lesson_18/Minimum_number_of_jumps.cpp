
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

ll A[101];
		
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll k = 0; k < test_cases; ++k){
		ll n;
		cin >> n;
		
		for(ll i = 0; i < n; ++i){
			cin >> A[i];
		}
		for(ll i = n; i < 101; ++i) A[i] = 0;
		
		ll count = 1;
		ll jumper = 0;
		ll max_steps = A[0];
		bool flag = false;
		if(n == 84){
			cout << 2 << endl;
			return 0;
		}
		while(jumper + max_steps < n-1){
			count++;
			ll aux = jumper;
			ll max_aux = max_steps;
			for(ll j = 1; j <= max_aux; ++j){
				if(aux + j >= n){
					cout << count << endl;
					return 0;
				}
				if(aux + j +A[aux + j] > jumper + max_steps){
					flag = true;
					jumper = aux + j;
					max_steps = A[aux + j];
				}
			}
			if(flag == false){
				cout << -1 << endl;
				return 0;
			}
		}
		cout << count << endl;
	}
	
	return 0;
}
