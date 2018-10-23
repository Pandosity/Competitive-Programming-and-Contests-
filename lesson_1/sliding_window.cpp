#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//The asymptotic complexity of the algorith in use is, as explained in the slides, \Theta(n); the only unexplained bit is about the number of pop operations in the 
//deque, but it suffices to observe that each element gets pushed and popped at most once, resulting in 2n operations.
//As for space complexity, this implementation requires a vector for the numbers of size n, a vector for the submaximums of size n-k+1 
//and a deque of size at most k.

vector<int> linear_solver(vector<int> const& A, int k){
	deque<int> Q; //Q will store the positions of the array during the algorithm
	vector<int> max; 
	max.reserve(A.size()-k+1); //max will contain the requested maxes
	
	for (int i = 0; i < A.size(); ++i){
		
		//first we remove from the front of Q the elements no longer in the sliding window
		while ((!Q.empty()) && Q.front() < i-k+1) {
			Q.pop_front();
		}
		
		//we then remove from the back all the elements greater than the element whose position we want to add to Q
		while ((!Q.empty()) && A[i] >= A[Q.back()]) {
			Q.pop_back();
		}
		
		//we finally insert the new element at the back
		Q.push_back(i);
		
		//Now we add the front element of Q to the vector of maxima, thanks to the correctedness of the algorithm 
		//(obviously we start from the first full window)
		
		if (i >= k-1){
			max.push_back(A[Q.front()]);
		}
	}
	
	return max;
}




int main(){
	int test_cases;//we acquire the test cases
	cin >> test_cases;
	
	int length;
	int sublength;
	vector<int> line;
	vector<int> maxima;
	
	//the following cycle iterates the algorithm through the test cases
	for (int i = 0; i < test_cases ; ++i){
		cin >> length;
		cin >> sublength;
		line.reserve(length);
		
		for (int j = 0; j < length ; ++j){
			int n;
			cin >> n;
			line.push_back(n);
		}
		
		maxima = linear_solver(line, sublength);
		
		for (vector<int>::iterator it = maxima.begin() ; it != maxima.end(); ++it){
			cout << *it << " ";
		}
		line.clear();
		maxima.clear();
		cout << endl;
	}
	
	return 0;
}
