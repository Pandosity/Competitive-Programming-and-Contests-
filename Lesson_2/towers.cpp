#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	//Here's the acquisition part

		vector<int> line;

		int length;
		cin >> length;
		line.reserve(length);
		
		for (int n = 0; n < length; ++n) {
			int x=0;
			cin >> x;
			line.push_back(x);
		}
		//here we sort line using the std library function
		
		sort(line.begin(), line.end());
		
		
		//here's the integers we'll use to check the requests of the problem.
		int largest = 1;
		int current_size = 1;
		int towers = 1;
		
		for (int i = 0; i < length - 1 ; ++i){
			if (line[i] == line[i+1]){
				++current_size;
				largest = max(largest, current_size);
			} else {
				++towers;
				largest = max(largest, current_size);
				current_size = 1;
			}
		line.clear();
		}
		
		cout << largest << " " ;
		cout << towers;	
		return 0;
}
	

