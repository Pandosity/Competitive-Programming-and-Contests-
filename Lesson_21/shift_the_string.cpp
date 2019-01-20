/*This algorithm implements the Knuth-Morris-Pratt algorithm to find the longest prefix of A that is a substring of B, and then the number of shits is 
the starting position of the substring found in B. Space and time are both linear, that is O(n) where n is the common length of the strings.*/

#include<bits/stdc++.h>
#define dbg(x) cout << #x  << ": " << x << endl;
using namespace std;
typedef long long ll;

const ll MAX = 1000001;
ll pref_suff[MAX];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	string A, B;
	cin >> A >> B;
	
	ll j = 0;
	ll i = 1;
	while(i < n) {
		if(A[i] == A[j]) {
			j++;
			i++;
			pref_suff[i] = j;
			continue;
		}
		if(j > 0){
			j = pref_suff[j];
		} else i++;
	}
	
	ll shift = 0;
	ll aux = 0;
	ll ans = 0;
	ll k = 0;
	while(k < n && shift < n) {
		
		if(A[k] == B[(k + shift) % n]) {
			k++;
			if(aux < k) {
				aux = k;
				ans = shift;
			}
			continue;
		}
		
		if(k > 0) {
			shift += k - pref_suff[k];
			k = pref_suff[k];
		} else shift++;
	}
	
	cout << ans << endl;
	
	return 0;
}
