#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

struct fenwick_tree {
	vector<ll> BIT;
	fenwick_tree (ll n) : BIT(n+1,0) {}
	ll getsum(ll index) {
		ll tot=0;
		index++;
		while (index>0) {
			tot+=BIT[index];
			index -= index & -index;
		}
		return tot;
	}
	void updateBIT(ll index, ll val) {
		index++;
		while (index<=BIT.size()) {
			BIT[index]+=val;
			index += index & -index;
		}
	}
};

ll remap(vector<ll>& vet) {
	ll n=vet.size();
	vector<ll> tmp(n);
	copy(vet.begin(),vet.end(),tmp.begin());
	sort(tmp.begin(),tmp.end());
	map<ll,ll> rank;
	ll r=0,i=0;
	while (i<n) {
		rank.insert(make_pair(tmp[i],r++));
		while (tmp[i]==tmp[++i] && i<n) {};
	}
	for (ll i=0;i<n;i++) vet[i] = rank[vet[i]];
	return r;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	vector<ll> A(n,0);
	for(ll i = 0; i < n; ++i)cin >> A[i];
	ll rank = remap(A);
	vector<ll> occ(rank,0);
	vector<ll> SuffixCounter(n,0);
	
	for(ll i = n-1; i >=0; --i) SuffixCounter[i] = ++occ[A[i]];
	fenwick_tree B(n);
	for(ll i=0;i<n;++i) B.updateBIT(SuffixCounter[i],1);
	
	for(ll i = 0; i<rank; ++i) occ[i] = 0;
	ll res = 0;
	for(ll i = 0; i<n;++i){
		++occ[A[i]];
		B.updateBIT(SuffixCounter[i],-1);
		res += B.getsum(occ[A[i]]-1);	
	}
	
	cout << res << endl;

	return 0;
}
