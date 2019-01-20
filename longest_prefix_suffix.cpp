/*This algorithm dynamically computes a vector pref_suff storing at position i the length of the longest prefix suffix of S[0,...,i].
The recurrrence is the following: supposing we have calculated pref_suff[0...i], pref_suff[i+1] is the length of pref_suff[i-1]+1 if the inserted char
match. Otherwise, the viable prefixes that could be suffixes shall be searched in S[0,...,pref_suff[i-1]-1], and this goes on until we reach a pref_suff 
or the viable length reaches 0, at which point pref_suff[i]=0. Space and time complexity of this algorithm are clearly both linear.*/

#include<bits/stdc++.h>
#define dbg(x) cout << #x  << ": " << x << endl;
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll k = 0; k < test_cases; ++k){
		
		string S;
		cin >> S;
		ll n = S.size();
	
		vector<ll> pref_suff(n,0);
		
		ll curr_max = 0;
		ll i = 1;
		
		while(i < n){
			if(S[curr_max] == S[i]){
				curr_max++;
				pref_suff[i] = curr_max;
				i++;
				continue;
			}			
			if(curr_max == 0){
				i++;
				pref_suff[i] = 0;
			}
			else{
			curr_max = pref_suff[curr_max-1];
			}
		}
		
		cout << pref_suff[n-1] << endl;
		
	}
	
	return 0;
}
