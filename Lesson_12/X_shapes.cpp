/* The algorithm here implements a flood function which literally floods the Xs in the matrix with O's, incrementing a counter every time a connected
component is fully covered. Space wise we used a global matrix of size 50*50 and some negligible integers. Time wise, apart from the linear in the
product n*m input part, the flood function gets called once for every X in the original matrix(including recursions) and each O gets checked by an if
statement at most 5 times (itself and its neighbours), so the complexity is O(n*m). */
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;
constexpr ll MAX = 50;
char XO[MAX][MAX];

void flood(ll x, ll y, ll max_x, ll max_y){
	if(XO[x][y] == 'X'){
		XO[x][y] = 'O';
		if(x > 0 && XO[x-1][y]=='X'){
			flood(x-1, y, max_x, max_y);
		}
		if(x < max_x-1 && XO[x+1][y]=='X'){
			flood(x+1, y, max_x, max_y);
		}
		if(y > 0 && XO[x][y-1]=='X'){
			flood(x, y-1, max_x, max_y);
		}
		if(y < max_y-1 && XO[x][y+1]=='X'){
			flood(x, y+1, max_x, max_y);
		}
	}
    
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll i = 0; i<test_cases;++i){

		ll n, m;
		cin >> n >> m;
		
		for(ll i = 0; i<n;++i){
			for(ll j=0;j<m;++j){
				cin >> XO[i][j];
			}
		}
		
		ll components = 0;
		for(ll i = 0; i<n;++i){
			for(ll j=0;j<m;++j){
				if(XO[i][j] == 'X'){
				flood(i, j, n, m);
				++components;
				}
			}
		}
		cout << components << endl;
	}
	
	return 0;
}
