/*This algorithm uses a vector of vectors representing a graph whose nodes represent
 both employees and languages, in which an employee is connected to a language if he knows it.
 We then count the connected components of this graph which contain at least one employee (i.e.
 which are not an unknown language) and report the answer, which is this number -1 except
 for the case in which nobody knows no language where it is that number. Space consuption in
 the worst case is O(n*m), and time complexity is that of DFS connected components algorithm
 which is O(V+E)=O(n*m).*/

#include<bits/stdc++.h>
#define dbg(x) cout << #x << ": " << x << endl;
using namespace std;
typedef long long ll;

vector<ll> Emp_Lang[500];
bool visited[500];

void DFS(ll a){
	visited[a] = true;
	for(ll i = 0 ; i < Emp_Lang[a].size() ; ++i){
		if( !visited[Emp_Lang[a][i]] ){
			DFS(Emp_Lang[a][i]);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	ll analphabet = 0;
	
	for(ll i = 0; i < n; ++i){
		ll lang;
		cin >> lang;
		for(ll j = 0; j < lang; ++j){
			analphabet = 1;
			ll id;
			cin >> id;
			Emp_Lang[i].push_back(id + 200);
			Emp_Lang[id + 200].push_back(i);
		}
	}
	
	ll components = 0;
	for(ll a = 0; a < n; ++a){
		if(!visited[a]){
			components++;
			DFS(a);
		}
	}
	
	cout << components-analphabet << endl;
	
	return 0;
}
