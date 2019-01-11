#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;

using namespace std;
typedef long long int ll;

bool rightsort(vector<ll> &a, vector<ll> &b){
	return(a[1] < b[1]);
}

struct fenwick_tree {
	vector<ll> BIT;
	fenwick_tree (ll n) : BIT(n+1,0) {}
	ll getsum(ll index) {
		ll tot=0;
		index++;
		while (index>0) {
			tot += BIT[index];
			index -= index & -index;
		}
		return tot;
	}
	void updateBIT(ll index, ll val) {
		index++;
		while (index <= BIT.size()) {
			BIT[index] += val;
			index += index & -index;
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;
	
	vector<vector<ll>> numbers(n);
		
	for(ll i = 0; i < n ; ++i){
		ll left, right;
		cin >> left >> right;
		numbers[i].reserve(5);
		numbers[i].push_back(left);
		numbers[i].push_back(right);
		numbers[i].push_back(i);
		numbers[i].push_back(0);
		numbers[i].push_back(0);
	}
	
	sort(numbers.begin(), numbers.end(), rightsort);
	for(int i = 0; i < n; ++i){
		numbers[i][3] = i;
	}
	sort(numbers.begin(), numbers.end());
	
	fenwick_tree B(2*n);
	for(ll i = n-1 ; i > -1; --i){
		numbers[numbers[i][2]][4] = B.getsum(numbers[i][3]);
		B.updateBIT(numbers[i][3], 1);	
	}
	for(ll i = 0; i < n; ++i){
		cout << numbers[i][4] << endl;
	}
	
	return 0;
}
