#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

void change_value(ll &n){
	if(n == 1) ++n;
	else if(n == 2) --n;
}

int main(){
	ll m;
	cin >> m;
	ll n = 2*m;
	
	vector<pair<ll,ll>> numbers(n);
	
	for(ll i = 0; i < n; ++i){
		cin >> numbers[i].first;
		numbers[i].second = i;
	}
	
	sort(numbers.begin(), numbers.end());
	
	ll singleton = 1;
	ll multi = 1;
	vector<ll> heaps(n,0);
	ll i = 0;
	vector<ll> counter(2,0);
	
	while(i < n){
		if(i == 0 || numbers[i].first != numbers[i-1].first){
			
			if(numbers[i].first != numbers[i+1].first || i == n-1){
				heaps[i] = singleton;
				counter[singleton-1]++;
				change_value(singleton);
			}
			
			else if(numbers[i].first == numbers[i+1].first){
				heaps[i] = multi;
				counter[multi-1]++;
				change_value(multi);
				++i;
				heaps[i] = multi;
				counter[multi-1]++;
				change_value(multi);
			}
		}
		++i;
	}
	
	//for(ll y = 0; y < n; ++y){
	//	dbg(heaps[y]);
	//}
	
	ll max = counter[0]*counter[1];
	
	for(ll j = 0; j < n; ++j){
		if(heaps[j] == 0 && counter[0] != m){
			heaps[j] = 1;
			counter[0]++;
		}
		else if(heaps[j] == 0 && counter[0] == m){
			heaps[j] = 2;
		}
	}
	
	ll temp;
	
	for(ll j = 0; j < n; ++j){
		temp = numbers[j].second;
		numbers[j].second = heaps[j];
		numbers[j].first = temp;		
	}
	
	sort(numbers.begin(), numbers.end());
	
	cout << max << endl;
	for(ll j = 0; j < n; ++j){
		cout << numbers[j].second << " ";
	}
	cout << endl;
	
	return 0;
}
