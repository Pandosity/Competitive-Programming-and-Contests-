/*This greedy algorithm exploits the fact that the operations are commutative and that, at each step, you NEED to perform operations equal to the abs
of the first number, since that is the only way you have to change it. Answer is than equal to the sum ob abs of differences of consecutive numbers,
which we can compute in O(n) time and O(1) space. */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	ll ans = 0;
	ll a = 0;
	ll b;
	
	for(ll i = 0; i < n ; ++i){
		cin >> b;
		ans += abs(b - a);
		a = b;
	}
	
	cout << ans << endl;
	
	return 0;
}
