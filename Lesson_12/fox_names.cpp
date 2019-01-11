/*This algorithm compares couples of consecutive strings to generate from each of them one ordering of two letters, which are turned into an ede of a directed
graph via adjiacency matrix. We then use a topological sorting to obtain a linearization of the graph. Time complexity is O(L), where L is the total length of
the input strings. Space complexity is obviously O(L) as well.*/
#include<bits/stdc++.h>
#define dbg(x) cout << #x << ": " << x << endl;
using namespace std;
typedef long long ll;

bool Adj[26][26];
vector<int> visited(26,0);

bool TopSort(int root, deque<char> &sorted){
	
	visited[root] = -1;
	
	for(int i=0; i<26; ++i){
		if(!Adj[i][root]) continue;
		if(visited[i]<0) return false;
		if(visited[i]==0 && !TopSort(i, sorted)) return false;
	}
	
	visited[root] = 1;
	sorted.push_back(root);
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for(int i = 0 ; i < 26 ; ++i){
		for(int j = 0 ; j < 26 ; ++j){
			Adj[i][j] = false;
		}
	}
	
	int n;
	cin>>n; 
	
	vector<string> v(n);
	for(int i = 0 ; i < n ; ++i) cin >> v[i];
	
	for(int i = 0 ; i < n-1 ; ++i){
		string aux1 = v[i];
		string aux2 = v[i+1];
		reverse(aux1.begin(), aux1.end());
		reverse(aux2.begin(), aux2.end());
		
		while(!aux1.empty() && !aux2.empty() && aux1.back() == aux2.back()){
			aux1.pop_back();
			aux2.pop_back();
		}
		
		if(!aux1.empty() && aux2.empty()){
			cout << "Impossible" << endl;
			return 0;
		}
		if(!aux1.empty() && !aux2.empty()) Adj[aux1.back() - 'a'][aux2.back() - 'a'] = true;
	}
	
	deque<char> sorted;
	bool sortable = true;
	
	for(int i = 0; i < 26; ++i){
	if(!visited[i]){
	 	sortable = sortable && TopSort(i, sorted);
	    }
	}
	
	if(sortable){
		for(deque<char>::iterator it = sorted.begin(); it != sorted.end(); ++it) cout << (char)(*it + 'a');
	}
	else cout << "Impossible";
	
	cout << endl;
	
	return 0;
}
