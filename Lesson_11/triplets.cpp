#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;

using namespace std;
typedef long long int ll;

bool rightsort(vector<ll> &a, vector<ll> &b){
	return(a[1] < b[1]);
}

ll getsum(vector<ll> BITree, ll index){ 
    ll sum = 0; 
    index = index + 1; 
  
    while (index>0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void updateBIT(vector<ll> &BITree, ll n, ll index, ll val){ 
    index = index + 1; 
  
    while (index <= n){ 
    BITree[index] += val; 
    index += index & (-index); 
    } 
} 


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	vector<ll> data(n,0);
	
	for(int i = 0; i < n; ++i){
		cin >> data[i];
		data[i]++;
	}

	vector<ll> fenwick(n + 1, 0);
	vector<ll> doubles(n);
	
	for(ll i = 0; i < n; ++i){
		doubles[i] = getsum(fenwick, data[i]-1);
		updateBIT(fenwick, n, data[i], 1);
	}
	fill(fenwick.begin(), fenwick.end(), 0); 
	ll res = 0;
	
	for(ll i = n - 1 ; i >= 0; --i){
		doubles[i] *= getsum(fenwick, n - 1 - data[i]);
		res += doubles[i];
		updateBIT(fenwick, n, n - data[i], 1);	
	}
	cout << res << endl;
	
	return 0;
}
