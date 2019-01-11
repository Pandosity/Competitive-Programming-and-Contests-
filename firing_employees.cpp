#include<bits/stdc++.h>
#define dbg(x) cout << #x << ": " << x << endl;
using namespace std;
typedef long long int ll;

vector<bool> vector_primes(ll n) {
	
    vector<bool> primes(n, true);
    primes[0] = primes[1] = false;
    for(ll i = 2; i <= (ll) sqrt(n); ++i) {
        if (primes[i]) {
            ll isquare = i*i;   
            for(ll j = isquare; j < n; j = j + i)
                primes[j] = false;
        }      
    }
    return primes;
}

vector<ll> count_superiors(vector<ll>& N){
	
		vector<ll> results(N.size(), -2);
		results[0] = -1;
		for(ll j = 0; j < N.size(); j++){
			stack<int> sup;
			int i = j;
			//dbg(j);
			while(results[i] < -1){
				//dbg(i);
				sup.push(i);
				//dbg(sup.top());
				i = N[i];
			}
			
			int superiori = results[i];
			while(!sup.empty()){
				results[sup.top()] = ++superiori;
				sup.pop();
			}
		}
	
	return results;
}

int main(){
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll i = 0; i < test_cases ; i++){
		int size;
		cin >> size;
		vector<ll> direct_superior(size + 1);
		
		for(ll j = 1; j < size + 1 ; j++){
			cin >> direct_superior[j];
		}
		
		vector<ll> superiors = count_superiors(direct_superior);
		vector<bool> checker = vector_primes(2*size);
		ll blacklisted = 0;
		
		for(ll i = 1; i < size + 1; ++i){
			if(superiors[i] != 0 && checker[superiors[i]+i]){
				++blacklisted;
			}
		}
		
		cout << blacklisted << endl;
		
	}
	
	
	
	return 0;
}
