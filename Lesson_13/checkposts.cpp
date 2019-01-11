/*The algorithm shown here implements the one we've seen in class to find SCCs of a directed graph, and thus runs in linear time (i.e. O(n+m) ). 
Space wise we've used a vector for the graph, one for the transponed graph, two boolean vectors, a vector for the costs and one for SCCs, plus a stack.
The relevant part are the two graph vectors, which take O(n+m) as well.*/

#include<bits/stdc++.h>
#define dbg(x) cout << #x << ": " << x << endl;
using namespace std;
typedef long long ll;

vector<ll> Graph[200000];
vector<ll> Trasp_graph[200000];
vector<ll> Conn_Comp[200000];
bool visited[200000];
bool trasp_visited[200000];
stack<ll> endtime;
ll MOD = 1000000007;

void DFS(ll a){
	visited[a] = true;
	for(ll k = 0; k < Graph[a].size(); ++k){
		if(!visited[Graph[a][k]]){
			DFS(Graph[a][k]);
		}
	}
	endtime.push(a); 
}

void Trasp_DFS(ll a, ll cc){
	trasp_visited[a] = true;
	for(ll i = 0; i < Trasp_graph[a].size(); ++i){
		if(!trasp_visited[Trasp_graph[a][i]]){
			Trasp_DFS(Trasp_graph[a][i], cc);
		}
	}
	Conn_Comp[cc].push_back(a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> cost(n);
	for(ll i = 0; i < n; ++i) cin >> cost[i];
	
	ll m;
	cin >> m;
	for(ll i = 0; i < m ; ++i){
		ll a, b;
		cin >> a >> b;
		Graph[a-1].push_back(b-1);
		Trasp_graph[b-1].push_back(a-1);
	}
	
	for(ll i = 0; i < n; ++i){
		if(!visited[i]){
			DFS(i);
		}
	}
	
	ll comp = 0;
	
	while(!endtime.empty()){
		Trasp_DFS(endtime.top(), comp);
		comp++;
		while((!endtime.empty()) && trasp_visited[endtime.top()]){
		endtime.pop();
		}
	}
	
	ll money = 0;
	ll ways = 1;
	for(ll i = 0; i < comp; ++i){
		ll loc = MOD;
		ll t = 0;
		for(ll j = 0 ; j < Conn_Comp[i].size(); ++j){
			loc = min(loc, cost[Conn_Comp[i][j]]);
		}
		for(ll j = 0 ; j < Conn_Comp[i].size(); ++j){
			if(loc == cost[Conn_Comp[i][j]]) ++t;
		}
		money += loc;
		ways *= t;
		ways %= MOD;
	}
	
	cout << money << " " << ways << endl;
	
	return 0;
}
