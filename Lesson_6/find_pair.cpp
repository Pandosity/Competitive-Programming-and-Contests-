#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

bool sorter(ll a, ll b){
	if(a < b) return 1;
	return 0;
}

int main(){
	ll n, k;
	cin >> n >> k;
	vector<ll> numbers(n, 0);
	
	for(ll i = 0; i < n; ++i){
		cin >> numbers[i];
	}
	
	vector<pair<ll,ll>> mult;
	mult.reserve(n);
	
	sort(numbers.begin(), numbers.end(), sorter);
	//for(int i = 0; i < n; ++i){
	//	dbg(numbers[i]);
	//}
	
	ll count = 1;
	
	for(ll i = 0; i < n; ++i){
		if((numbers[i] != numbers[i+1])  || (i == n-1)){
			mult.emplace_back(numbers[i], count);
			count = 1;
		}
		else ++count;
	}
	ll t = mult.size();
	//for(int i = 0; i < t; ++i){
	//	dbg(mult[i].first);
	//	dbg(mult[i].second);
	//}
	
	ll a = 0;
	ll b = 0;
	
	//for(ll i = 1; i < t; ++i){
	//	mult[i].second += mult[i-1].second;
	//}
	
	while(k > mult[a].second*n){
		k -= mult[a].second*n;
		++a;
	}
	//dbg(a);
	
	while(k > mult[b].second*mult[a].second){
		k -= mult[b].second*mult[a].second;
		++b;
	}
	//dbg(b);
	
	cout << mult[a].first << " " << mult[b].first;
	return 0;
}
