#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

constexpr ll MAX = 1000000000000;
constexpr ll MAXL = 200001;

void LazyUpdate(ll root, ll val, ll s, ll e, ll us, ll ue, vector<ll> &tree, vector<ll> &lazy){

	if(lazy[root] != 0){
		tree[root] += lazy[root];
		if(s != e){
			lazy[2*root + 1] += lazy[root];
			lazy[2*root + 2] += lazy[root];
		}
		lazy[root] = 0;
	}
	
	//no overlap
	if(us > e || ue < s){
	return;	
	}
	
	//total overlap
	if(us <= s && ue >= e){
		tree[root] += val;
		if(s != e){
			lazy[2*root + 1] += val;
			lazy[2*root + 2] += val;
		}
		return;
	}
	
	//partial overlap
	ll mid = (s + e)/2;
	LazyUpdate(2*root+1, val, s, mid, us, ue, tree, lazy);
	LazyUpdate(2*root+2, val, mid+1, e, us, ue, tree, lazy);
	tree[root] = min(tree[2*root+1], tree[2*root+2]);

}

ll LazyRmQ(ll root, ll s, ll e, ll qs, ll qe, vector<ll> &tree, vector<ll> &lazy){
	
	if(lazy[root] != 0){
		tree[root] += lazy[root];
		if(s != e){
			lazy[2*root + 1] += lazy[root];
			lazy[2*root + 2] += lazy[root];
		}
		lazy[root] = 0;
	}
	
	//no overlap
	if(qs > e || s > qe){
	 return MAX;}
	
	//total overlap
	if(qs <= s && qe >= e) {
	return tree[root];}
	
	//partial overlap
	ll mid = (s + e)/2;
	return min(LazyRmQ(2*root+1, s, mid, qs, qe, tree, lazy), LazyRmQ(2*root+2, mid+1, e, qs, qe, tree, lazy));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	
	vector<ll> tree(MAXL*4);
	vector<ll> lazy(MAXL*4);	
	
	for(ll i = 0; i < n ; ++i){
			ll v;
			cin >> v;
			LazyUpdate(0, v, 0, MAXL-1, i, i, tree, lazy);
	}
	
	char line[100];
	ll queries;
	cin >> queries;
	cin.ignore();
	
	for(ll j = 0; j < queries; ++j){
		
		cin.getline(line, 100);
		ll left, right, val;
		
		if(istringstream(line) >> left >> right >> val){
			
			if(left > right){
				LazyUpdate(0, val, 0, MAXL-1, left, n-1, tree, lazy);
				LazyUpdate(0, val, 0, MAXL-1, 0, right, tree, lazy);
			} else LazyUpdate(0, val, 0, MAXL-1, left, right, tree, lazy);		
		} 
		
		else{
			if(left > right){
				cout << min(LazyRmQ(0, 0, MAXL-1, left, n-1, tree, lazy), LazyRmQ(0, 0, MAXL-1, 0, right, tree, lazy)) << endl;
			} else cout << LazyRmQ(0, 0, MAXL-1, left, right, tree, lazy) << endl;
		}
		
	}
	
	return 0;
}
