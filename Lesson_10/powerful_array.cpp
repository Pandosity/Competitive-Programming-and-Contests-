#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

constexpr ll MAX_A = 1000000;
constexpr ll MAX = 200000;
ll m;

vector<ll> A(MAX);
vector<ll> occurrences(MAX_A+1,0);
ll ans;

struct query{
	ll start, end;
	ll index;
	ll bucket;
	ll result;
};

struct compStart{
	bool operator()(const query& a, const query& b){
		return a.start > b.start;
	}
};

struct compEnd{
	bool operator()(const query& a, const query& b){
		return a.end > b.end;
	}
};

struct compIndex{
	bool operator()(const query& a, const query& b){
		return a.index < b.index;
	}
};

struct compMOs{
	bool operator()(const query& a, const query& b){
		ll blockA = (ll) a.start/m;
		ll blockB = (ll) b.start/m;
		if (blockA<blockB) return true;
		else if (blockA>blockB) return false;
		else return a.end < b.end;
	}
};

void add(ll a){
	++occurrences[A[a]];
	ans += (2*occurrences[A[a]]-1)*A[a];
}

void remove(ll b){
	--occurrences[A[b]];
	ans -= (2*occurrences[A[b]]+1)*A[b];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n, q;
	cin >> n >> q;
	m = sqrt(n);
	for(ll i = 1; i < n+1; ++i) cin >> A[i];
	vector<query> queries(q);
	for(ll i=0;i<q;++i){
		cin >> queries[i].start >> queries[i].end;
		queries[i].bucket = queries[i].start/m;
		queries[i].index = i;
	}

	sort(queries.begin(), queries.end(), compMOs())
	
	ans = 0;
	add(1);
	ll curr_l = 1;
	ll curr_r = 1;
	
	for(ll i=0;i<q;++i){
		while(curr_l < queries[i].start){
			//dbg(1);
			remove(curr_l);
			++curr_l;
		}
		while(curr_l > queries[i].start){
			//dbg(2);
			--curr_l;
			add(curr_l);
		}
		while(curr_r < queries[i].end){
			//dbg(3);
			++curr_r;
			add(curr_r);
		}
		while(curr_r > queries[i].end){
			//dbg(4);
			remove(curr_r);
			--curr_r;  
		}
		queries[i].result = ans;
	}
	sort(queries.begin(),queries.end(),compIndex());
	
	for(ll i = 0; i < q; ++i) cout << queries[i].result << endl;
	
	
	return 0;
}
