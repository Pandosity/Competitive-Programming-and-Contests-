/*This algorithm implements the basic idea to sort numbers, and then subtract to k the cardinality of sets of equal pairs, sorted in 
lexicographical order (first row by row, then cell by cell). Space and time are both linear.*/

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
	
	ll count = 1;
	
	for(ll i = 0; i < n; ++i){
		if((numbers[i] != numbers[i+1])  || (i == n-1)){
			mult.emplace_back(numbers[i], count);
			count = 1;
		}
		else ++count;
	}
	ll t = mult.size();
	
	ll a = 0;
	ll b = 0;
	
	while(k > mult[a].second*n){
		k -= mult[a].second*n;
		++a;
	}
	
	while(k > mult[b].second*mult[a].second){
		k -= mult[b].second*mult[a].second;
		++b;
	}
	
	cout << mult[a].first << " " << mult[b].first;
	return 0;
}
