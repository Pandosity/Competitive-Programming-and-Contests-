/*This algorithm implements the dynamic recursion showed in the slides. Its space and time consumption are both O(a*b), where a and b are the lengths
of the two strings.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

ll LCS[100][100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll k = 0; k < test_cases; ++k){
		ll a, b;
		cin >> a >> b;
		++a;
		++b;
		
		string s1, s2;
		cin >> s1 >> s2;
		
		for(ll i = 0; i < a; ++i){
			for(ll j = 0; j < b; ++j){
				if(i == 0 || j == 0){
					LCS[i][j] = 0;
				}
				else if(s1[i - 1] == s2[j - 1]){
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				}
				else LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
			}
		}
		cout << LCS[a - 1][b - 1] << endl;
	}
	
	return 0;
}
