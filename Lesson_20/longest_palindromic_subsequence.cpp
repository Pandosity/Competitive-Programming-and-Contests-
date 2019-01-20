/*This algorithm simply uses longest common subsequence on the string S and on its reverse string. Time and space complexity are both O(N^2)*/
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

ll LCS[1001][1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll k = 0; k < test_cases; ++k){
		
		string s1;
		cin >> s1;
		ll N = s1.size();
		
		string s2 = s1;
		reverse(s2.begin(), s2.end());
		
		for(ll i = 0; i <= N; ++i){
			for(ll j = 0; j <= N; ++j){
				if(i == 0 || j == 0){
					LCS[i][j] = 0;
				}
				else if(s1[i - 1] == s2[j - 1]){
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				}
				else LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
			}
		}
		cout << LCS[N][N] << endl;
	}
	
	return 0;
}
