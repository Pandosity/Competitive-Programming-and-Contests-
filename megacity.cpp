#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;

using namespace std;
typedef long long int ll;

bool sorter(pair<double,ll> a, pair<double,ll> b){
	if(a.first < b.first) return 1;
	return 0;
}

int main(){
	int towns, tomskians;
	cin >> towns >> tomskians;
	vector<pair<double,ll>> locations;
	locations.reserve(towns);
	int x, y, population;
	
	for(int i = 0; i < towns; ++i){
		cin >> x >> y >> population;
		pair<double,ll> pair;
		pair.first = sqrt(x*x + y*y);
		pair.second = population;
		locations.push_back(pair);	
	}
	
	sort(locations.begin(), locations.end(), sorter);
	//for(int i = 0; i < towns; ++i){
	//	dbg(locations[i].first);
	//}
	int i = 0;
	double result = -1;
	
	while(tomskians < 1000000 && i < towns){
		tomskians += locations[i].second;
		++i;
	}
	
	if(tomskians >= 1000000) result = locations[i-1].first;
	
	cout.precision(8);
	cout << result << endl;
	
	return 0;
}

