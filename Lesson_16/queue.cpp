/*This algorithm sorts people in line by increasing a[i], then checks if in the sorted vector some people has a[i]>i, in which case prints -1.
Otherwise, we use emplace to construct a new vector in which what was the people in position i in the sorted vector goes to position a[i] with
height n-i+1 (in this way people with the same a[i] end up in increasing height). It's easy to see that this generates a valid set of height, but
causes time to rise to O(n^2) from the proposed solution because of emplace inside a for, where space stays linear. It got accepted nonetheless so yay!*/
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

struct person{
	string name;
	ll taller;
};

struct compTaller{
	bool operator()(const person& a, const person& b){
		return a.taller < b.taller;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    ll n;
    cin >> n;
    vector<person> v(n);
    for(ll i = 0; i < n; ++i){
    	cin >> v[i].name >> v[i].taller;
	}
	
    sort(v.begin(), v.end(), compTaller());
    
    vector<person> final;
    
    for(ll i = 0; i < n; ++i) {
    	
        if(v[i].taller > i) {
            cout << -1 << endl;
            return 0;
        }
        person aux;
        aux.name = v[i].name;
        aux.taller = n + 1 - i;
        final.emplace(final.begin() + v[i].taller, aux);
    }
    
    for(ll i = 0; i < n; ++i) {
        cout << final[i].name << " "  << final[i].taller << "\n";
    }
    
    cout << endl;
    return 0;
}
