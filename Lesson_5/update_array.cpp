/*This algorithm implements the standard fenwick tree data structure. Space consumption is linear. Time consumption
is O(nlog(n)) to build the initial array, O(updates*log(n)) to perform the updates and O(queries*log(n)) to get the results.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;

using namespace std;
typedef long long int ll;

int getsum(vector<int> BITree, int index){ 
    int sum = 0; 
    index = index + 1; 
  
    while (index>0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void updateBIT(vector<int> &BITree, int n, int index, int val){ 
    index = index + 1; 
  
    while (index <= n){ 
    BITree[index] += val; 
    index += index & (-index); 
    } 
} 
  
vector<int> constructBITree(vector<int> arr, int n){ 
    vector<int> BITree(n+1,0); 
        
    for (int i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 

    //for (int i=1; i<=n; i++) 
    //     cout << BITree[i] << " "; 
  
    return BITree; 
} 

int main(){
	
	int test_cases;
	cin >> test_cases;
	
	for(int j = 0; j < test_cases; ++j){
		
	int size, updates;
	cin >> size >> updates;
	
	vector<int> array(size,0);
	vector<int> BIT = constructBITree(array, size);
	
	int left, right, val;
	for(int i = 0; i < updates; ++i){
		cin >> left >> right >> val;
		updateBIT(BIT, size, left, val);
		updateBIT(BIT, size, right+1, -val);
	}
	
	int queries;
	cin >> queries;
	int k;
	
	for(int i = 0; i < queries; ++i){
		cin >> k;
		cout << getsum(BIT, k) << endl;
	}
	
  }	
	return 0;
}
