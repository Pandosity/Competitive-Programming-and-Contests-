/*The algorithm here, which implements the solution showed in the slide. Time and space consumption are both O(n)*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<long> linear_solver(vector<long> A){
	stack<int> S;//it will store positions
	vector<long> next_greater;//this will store the values of the "successors"
	next_greater.reserve(A.size());
	
	//here we set initial values for next_greater, since we will
	//require access to every slot in the array at random order.
	for (int i=0; i < A.size(); ++i){
		next_greater.push_back(0);
	}
	
	for (long i = 0; i < A.size(); ++i){
		//we compare the i-th element of A wits S'top. If the top is smaller
		//we set the next greater element in position S.top to be A[i].
		while ((!S.empty()) && A[S.top()] < A[i]){
			next_greater[S.top()] = A[i];
			S.pop();
		}
		//we now add i at the top of the stack
		S.push(i);
	}
	
	//here we put -1 as next greater of remaining elements,
	//which are our right leaders.
	while (!S.empty()){
		next_greater[S.top()] = -1;
		S.pop();
	}
	
	return next_greater;
}

int main(){
	int test_cases;//we acquire the test cases
	cin >> test_cases;
	
	int length;
	vector<long> line;
	vector<long> successors;
	
	//the following cycle iterates the algorithm through the test cases
	for (int i = 0; i < test_cases ; ++i){
		cin >> length;
		line.reserve(length);
		
		for (int j = 0; j < length ; ++j){
			long n;
			cin >> n;
			line.push_back(n);
		}
		
		successors = linear_solver(line);
		
		for (vector<long>::iterator it = successors.begin() ; it != successors.end(); ++it){
			cout << *it << " ";
		}
		
		line.clear();
		successors.clear();
		cout << endl;
	}
	
	return 0;
}
