/*This algorithm implements a DFS to exploit a dynamic approach to the problem. SubCover of a vertex v returns the cardinality of the maximum vertex cover of the 
subtree rooted by v, together with a bool indicating wether root goes into the cover or not. To prove the exactness of this algorithm we need to prove
that there exists a minimal vertex cover in which no leaf is included, which is not hard at all. Time and space complexity are both O(n).*/

#include<bits/stdc++.h>
#define dbg(x) cout << #x << ": " << x << endl;
using namespace std;
typedef long long ll;

vector<ll> G[200000];
bool visited[200000];

pair<ll, bool> SubCover(ll root){
	visited[root] = true;
	ll cover = 0;
	bool rootCovered = true;
	for(vector<ll>::iterator it = G[root].begin(); it != G[root].end(); ++it){
		if(visited[*it]) continue;
		pair<ll, bool> aux = SubCover(*it);
		rootCovered = rootCovered && aux.second;
		cover += aux.first;
	}
	rootCovered = !rootCovered;
	if(rootCovered) cover++;
	return make_pair(cover, rootCovered);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	
	for(ll i = 1; i < n; ++i){
		ll a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	cout << SubCover(1).first << endl;
	
	return 0;
}
