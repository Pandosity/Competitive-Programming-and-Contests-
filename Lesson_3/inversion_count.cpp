/*The cool trick of this solution is to implement a merge sort, and sort the array via it. Each time the integers get their position with 
respect to the merging halves swapped during the merging, we add 1 to our inversion count. Algorithm runs in O(n*log(n)) time and linear space.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

struct counted_vector{
	vector<ll> numbers;
	ll inversions;
	
	counted_vector(vector<ll> a, ll b)
  	: numbers(a), inversions(b) {}
  	
};

counted_vector merge_sort( vector<ll>& N){

	ll mid = N.size()/2;
	vector<ll> firsthalf;
	vector<ll> secondhalf;
	firsthalf.reserve(mid);
	secondhalf.reserve(N.size() - mid);
	
	for (ll i = 0; i < mid ; ++i){
		firsthalf.push_back(N[i]);	
	}
	
	for (ll i = mid; i < N.size() ; ++i){
		secondhalf.push_back(N[i]);	
	}
	
	counted_vector left = {firsthalf, 0};
	counted_vector right = {secondhalf, 0};
	
	if(firsthalf.size() > 1){
		left = merge_sort(firsthalf);
		}
	if(secondhalf.size() > 1){
		right = merge_sort(secondhalf);
		} 
		
	counted_vector merged = {N, 0};
	ll counter = 0;
	
	ll i = 0;
	ll j = 0;
	
	while(i < mid && j < N.size() - mid){
		if(left.numbers[i] <= right.numbers[j]){
			merged.numbers[i+j] = left.numbers[i];
			i++;
		}
		if(left.numbers[i] > right.numbers[j]){
			merged.numbers[i+j] = right.numbers[j];
			counter += mid - i;
			j++;
		}
	}

	while(i < mid){
		merged.numbers[i+j] = left.numbers[i];
		i++;	
	}
	while(j < N.size() - mid){
		merged.numbers[i+j] = right.numbers[j];
		j++;	
	}

	merged.inversions = left.inversions + right.inversions + counter;

	return merged;
}

int main(){
	
	ll test_cases;
	cin >> test_cases;
	vector<ll> A;
	vector<ll> result;
	result.reserve(test_cases);
	
	for(ll i = 0; i < test_cases; ++i){
		
		ll size;
		cin >> size;
		A.reserve(size);
		ll current;
		
		for(ll i = 0; i < size; ++i){
			cin >> current;
			A.push_back(current);
		}
		
		counted_vector sorted = merge_sort(A);

		result.push_back(sorted.inversions);
		A.clear();
	}
	
	cout << endl;
	for(ll i = 0; i < test_cases; ++i){
	cout << result[i] << endl;	
	}
	
	return 0;
}
