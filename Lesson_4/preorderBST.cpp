/*This algorithm implements the standard preorder traversal of a BST. The space and time are both linear in the number of vertexes.*/
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

bool check(vector<int> a) {
    stack<int> s;
    int i;
    int root = INT_MIN;
    int n = a.size();
    
    for(i = 0; i < n; i++) {
    	
        if(a[i] < root) return false;
        
        while(!s.empty() && s.top() < a[i]) {
            root = s.top();
            s.pop();
        }
        s.push(a[i]);
    }
    return true;
}

int main(){
	
	int test_cases;
	cin >> test_cases;
	
	vector<int> numbers;
	
	for(int i = 0; i < test_cases ; ++i){
		
		int size;
		cin >> size;
		numbers.reserve(size);
		
		for(int i = 0; i < size; ++i){
			int current;
			cin >> current;
			numbers.push_back(current);
		}
		
		cout << check(numbers) << endl;
		numbers.clear();
		
	}
	
	return 0;
}
