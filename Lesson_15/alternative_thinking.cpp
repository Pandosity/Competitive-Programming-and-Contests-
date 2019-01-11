/*This greedy algorithm searches for the longest increasing subsequence, and as shown in the slides to be correct returns the minimun between
this length + 2 and n. Space is O(1) and time is O(n).*/

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
	char a, b;
	cin >> a;
	ll subs = 1;
	for(ll i = 1; i < n; ++i){
		cin >> b;
		if(a != b){
			subs++;
			a = b;
		}
	}
	
	cout << min(n, subs + 2) << endl;
	return 0;
}
