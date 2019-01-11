/*This algorithm implements the greedy strategy of considering sequentially trees from left to right, and make each one fall on the left if possible,
otherwise on the right, otherwise not making it fall. Space and time are both linear in the number of trees.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

struct tree{
	ll x;
	ll h;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	vector<tree> trees(n);
	for(ll i = 0; i < n; ++i){
		cin >> trees[i].x;
		cin >> trees[i].h;
	}
	
	ll ans = 0;
	ll comp = -1000000001;
	for(ll i = 0; i < n; ++i){
		if(trees[i].x - trees[i].h > comp){
			++ans;
			comp = trees[i].x;
		} else if(i == n-1 || trees[i].x + trees[i].h < trees[i+1].x){
			++ans;
			comp = trees[i].x + trees[i].h;
		} else comp = trees[i].x;
	}
	
	cout << ans << endl;
	
	return 0;
}
