/*Space and time complexity are both linear.*/

#include<bits/stdc++.h>
#define dbg(x) cout << #x << ": " << x << endl;
using namespace std;
typedef long long int ll;

int main(){
	
	ll n;
	cin >> n;
	vector<ll> numbers(n,0);
	ll sum = 0;
	
	for(ll i = 0; i < n; ++i){
		cin >> numbers[i];
		sum += numbers[i];
	}
	
	if(sum%3 != 0){
		cout << 0;
		return 0;
	}
	
	ll third = sum/3;
	ll suffix = 0;
	ll counter = 0;
	vector<ll> manysuf(n,0);
	
	for(ll i = n-1; i > -1; --i){
		suffix += numbers[i];
		if(suffix == third){
			++counter;
		}
		manysuf[i] = counter;
	}
		
	ll prefix = 0;
	ll ways = 0;
	
	for(ll j = 0; j < n-2; ++j){
		prefix += numbers[j];
		if(prefix == third){
			ways += manysuf[j+2];
		}
	}
	
	cout << ways <<endl;
	
	return 0;
	
}
