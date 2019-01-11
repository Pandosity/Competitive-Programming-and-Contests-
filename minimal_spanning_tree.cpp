/*We implement here Kruskal's algorithm for the minimum spanning tree. We know that its time complexity is O(M*logN). Its space
consuption is that of the vector Edges, which is O(m). */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
constexpr int N=10001;

struct edge{
	ll start;
	ll finish;
	ll weight;
};

bool Comp_Edge(const edge &e1, const edge &e2){
		return e1.weight < e2.weight;
}

ll ft[N];
ll find(ll x){
	if(ft[x] != x) ft[x] = find(ft[x]);
	return ft[x];
}

void unite(ll x, ll y){
	x = find(x);
	y = find(y);
	ft[x] = y;
}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	vector<edge> Edges(m);
	for(ll i=0; i<m; i++) {
	cin >> Edges[i].start >> Edges[i].finish >> Edges[i].weight;
	}
	
	sort(Edges.begin(), Edges.end(), Comp_Edge);
	for(ll i = 0 ; i < n; i++) ft[i] = i;
	
	ll sum=0;
	for(vector<edge>::iterator it = Edges.begin() ; it != Edges.end(); it++){
		if(find(it->start) == find(it->finish)) continue;
		unite(it->start, it->finish);
		sum += it->weight;
	}
	cout << sum << endl;	
	
	return 0;
}
