/*Space complexity of this algorithm is O(n + queries). Time complexity is O(nlog(n)+queries).*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;

using namespace std;
typedef long long int ll;


void count_sort(vector<ll> &N, ll &max){
	
	vector<int> count(max,0);//vector storing digits occurences
	ll size = N.size();

	//building count
	for(ll i = 0 ; i < size ; ++i){
		++count[N[i] - 1];
	}
	
	N.clear();

	//re-building N in increasing order
	for(ll i = 0; i < max ; ++i){
		while(count[i] > 0){
			N.push_back(i + 1);
			--count[i];
		}
	}
	
}

int main(){
	
	ll n, queries;
	cin >> n >> queries;
	vector<ll> numbers(n,0);
	
	for(ll i = 0; i < n; ++i){
		cin >> numbers[i];		
	}
	
	vector<ll> F(n,0);
	ll left, right;
	
	for(ll i = 0; i < queries; ++i){
		cin >> left >> right;
		F[left - 1]++;
		if(right < n) F[right]--;
	}
	
	ll prefix = 0;
	
	for(ll i = 0; i < n; ++i){
		prefix += F[i];
		F[i] = prefix;		
	}
	
	sort(F.begin(), F.end());
	sort(numbers.begin(), numbers.end());
	
	ll result = 0;
	
	for(ll i = 0; i < n; ++i){
		result += numbers[i]*F[i];
	}
	
	cout << result << endl;
	
	return 0;
}
