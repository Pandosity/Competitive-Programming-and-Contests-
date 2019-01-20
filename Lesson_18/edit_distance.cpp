/*This algorithm implements a classic dynamic programming approach. In the entry (i,j) of the matrix A we compute the answer to the problem using only 
the first i char of the first string and the first j of the second. At each step, A[i][j] equals to A[i-1][j-1] if s1[i-1] = s2[j-1] (no extra operations needed),
otherwise we take the answer as the minimum from the the three already computed "neighbours" of (i,j) plus 1.
Time and space complexity of this algorithm are both O(P*Q), where P and Q are the lenghts of the two strings.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

ll A[101][101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll k = 0; k < test_cases; k++){
		ll P, Q;
		string s1, s2;
		cin >> P >> Q >> s1 >> s2;
		
		for(ll i = 0; i <= P; ++i){
			A[i][0] = i;
		}
		for(ll i = 0; i <=Q ; ++i){
			A[0][i] = i;
		}
		
		for(ll i = 1; i <= P; ++i){
			for(ll j = 1; j <= Q ; ++j){
				if(s1[i-1] == s2[j-1]){
					A[i][j] = A[i-1][j-1];
				} else{
					A[i][j] = min(A[i-1][j-1]+1, min(A[i][j-1]+1, A[i-1][j]+1));
				}
			}
		}
		
		cout << A[P][Q] << endl;
	}
	
	
	return 0;
}
