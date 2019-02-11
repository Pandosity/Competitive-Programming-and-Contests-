/*This algorithm implements the dynamic routine in which the i-th subproblem is the length of the longest possible LIS that strictly uses
the i-th entry of the array. This is achieved by using lower_bound to examine the currently stored LIS, and substituting the current value
to it unless the new value is appendable at the end. This will destroy the correct subsequences for the subproblems (for example, correct
solution to the i-th subproblem appears only after substituiting it to the i-th lower bound as the values up to the substituted one, and
possibly gets changed afterwards) as we process the remaining values, but in the end we just care about the length of the final LIS. Using the
of the lower_bound saves us some time compared to the naive implementation of the dynamic routine described, making so that time is O(n*log(n))
and space is O(n).*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

ll A[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll test_cases;
	cin >> test_cases;
	
	for(ll k = 0; k < test_cases; ++k){
		ll N;
    	cin >> N;
    	vector<ll> LIS;
    	
    	for(ll i = 0; i < N; ++i){
        int x;
        cin >> x;
        vector<ll>::iterator it = lower_bound(LIS.begin(), LIS.end(), x);
        
        if(it == LIS.end()) {
            LIS.push_back(x);
        	} else *it = x;
    	}
    cout << LIS.size() << endl;
	}
	return 0;
}
