/*Solution is a standard segment tree (non-lazy for simplicity). Space is O(n+m), and time is O((n+m)*log(n)).*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

void Update(ll root, ll val, ll s, ll e, ll us, ll ue, vector<ll> &tree){
	
	//no overlap
	if(us > e || ue < s){
	return;	
	}
	
	//total overlap
	if(us <= s && ue >= e){
		tree[root] = val;
		return;
	}
	
	//partial overlap
	ll mid = (s + e)/2;
	Update(2*root+1, val, s, mid, us, ue, tree);
	Update(2*root+2, val, mid+1, e, us, ue, tree);

}

ll get(ll root, ll s, ll e, ll pos, vector<ll> &tree){
	
	//no overlap
	if(pos > e || s > pos){
	 return -1;}
	
	//total overlap
	if(pos == s && pos == e) {
	dbg(tree[root]);
	return tree[root];}
	
	//partial overlap
	ll mid = (s + e)/2;
	ll a = get(2*root+1, s, mid, pos, tree);
	ll b = get(2*root+2, mid+1, e, pos, tree);
	return max(max(a,b),tree[root]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	vector<ll> A(n);
	vector<ll> B(n);
	for(ll i=0;i<n;++i) cin >> A[i];
	for(ll i=0;i<n;++i) cin >> B[i];
	
	ll k = 0;
	while(pow(2,k)<n) ++k;
	vector<ll> segment(pow(2,k+1)-1,0);
	vector<vector<ll>> queries;
	queries.reserve(m);
	for(ll i=0; i<m;++i){
		
	ll q_id;
	cin >> q_id;
	if(q_id == 1){
		vector<ll> query(3);
		cin >> query[0] >> query[1] >> query[2];
		queries.push_back(query);
		Update(0, queries.size(), 0, n-1, query[1], query[1]+query[2], segment);
	}
	if(q_id == 2){
		ll index;
		cin >> index;
		ll q = get(0, 0, n-1, index, segment);
		dbg(q);
		if(q == 0) cout << B[index] << endl;
		else {cout << A[queries[q-1][0] + index - queries[q-1][1]] << endl;}
	}
	}
	
	
	return 0;
}
