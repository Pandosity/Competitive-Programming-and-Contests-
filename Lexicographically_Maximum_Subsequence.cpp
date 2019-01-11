/*This problem scans the string from right to left and at each step appends the new character to the local max if it is appendable: it's easy to see
that this generates the global max. Time is O(L) where L is the length of the string, same for space complexity.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin >> s;
	
	string max;
	for(ll i = s.size()-1; i >= 0; --i){
		if(max.empty() || max.back() <= s[i]) max.push_back(s[i]);
	}
	
	reverse(max.begin(), max.end());
	cout << max << endl;
	
	return 0;
}
