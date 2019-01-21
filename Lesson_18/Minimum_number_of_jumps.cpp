/*This algorithm implements the greedy strategy of maximizing each time the reachable range one can get to by landing
into a given tile. Time and space are both O(n). This code returns an error on Geeks4Geeks for an high test case (n = 84) 
which works perfectly in my local environment. Iwas guessing this was some sort of initialization problem, but that does
not seem to be the case since I think I initialized all that I could.*/

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
