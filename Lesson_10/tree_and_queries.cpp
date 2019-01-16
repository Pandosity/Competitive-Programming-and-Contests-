/*We linearize the tree by using a DFS, and once we have a linear vector we can just use Mo's algorithm to complete the task in O(sqrt(n)*(n+m)).
Space complexity is linear, that is O(n+m).*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

constexpr ll MAX = 100001;
vector<ll> occurrences(MAX,0);
vector<ll> AtLeast(MAX,0);
ll rad;

struct query {
	ll start,end,k;
	ll index;
	ll result;
};

struct compIndex{
	bool operator()(const query& a, const query& b){
		return a.index < b.index;
	}
};

struct compMOs{
	bool operator()(const query& a, const query& b){
		ll blockA = (ll) a.start/rad;
		ll blockB = (ll) b.start/rad;
		if (blockA<blockB) return true;
		else if (blockA>blockB) return false;
		else return a.end < b.end;
	}
};

void add(ll i, vector<ll>& colori) {
	occurrences[colori[i]]++;
	AtLeast[occurrences[colori[i]]]++;
}

void remove(ll i, vector<ll>& colori) {
	AtLeast[occurrences[colori[i]]]--;
	occurrences[colori[i]]--;
}

//returns colors in the order in which a dfs traverses them
ll temp = 1;
void DFS(vector<ll> &color, vector<vector<ll>> &amigos, ll node, ll dad, vector<pair<ll,ll>> &subtree, vector<ll> &trav){
	trav[temp] = color[node];
	subtree[node].first = temp;
	++temp;
	for(vector<ll>::iterator a = amigos[node].begin(); a != amigos[node].end(); ++a){
		if(*a != dad) DFS(color, amigos, *a, node, subtree, trav);
	}
	subtree[node].second = temp-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	rad = sqrt(n);
	vector<ll> colors(n+1);
	for(ll i=1; i<=n; ++i) cin >> colors[i];
	vector<vector<ll>> relatives(n+1);
	for(ll i=1;i<n;++i){
		ll node, relative;
		cin >> node >> relative;
		relatives[node].push_back(relative);
		relatives[relative].push_back(node);
	}
	vector<pair<ll,ll>> boundaries(n+1);
	vector<ll> traversed(n+1,0);
	DFS(colors, relatives, 1, -1, boundaries, traversed);
	vector<query> queries(m);
	for(ll i=0;i<m;++i){
		ll k, node;
		cin >> node >> k;
		queries[i].start = boundaries[node].first;
		queries[i].end = boundaries[node].second;
		queries[i].k = k;
		queries[i].index = i;
	}
	sort(queries.begin(), queries.end(), compMOs());

	ll currLeft=0,currRight=0;
	for (vector<query>::iterator q = queries.begin(); q!=queries.end(); q++) {
		while (currLeft < q->start) {
			remove(currLeft,traversed);
			currLeft++;
		}
		while (currLeft > q->start) {
			currLeft--;
			add(currLeft,traversed);
		}
		while (currRight < q->end) {
			currRight++;
			add(currRight,traversed);
		}
		while (currRight > q->end) {
			remove(currRight,traversed);
			currRight--;
		}
		q->result = AtLeast[q->k];
	}
	sort(queries.begin(), queries.end(), compIndex());
	for(ll i = 0; i<m ; ++i) cout << queries[i].result << endl; 
	return 0;
}
