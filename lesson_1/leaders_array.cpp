#include <iostream>
#include <vector>

//The algorithm we present is fairly simple, scanning the array back-to-front and adding the leaders we find
//in a separate array. Time complexity is thus \Theta(n), scanning and operating on the array only once.
//Space consuption is mainly due to two vectors of size n, one for the numbers and one for the leaders,
//plus some necessary integers and (reverse) iterators.

int main(){
	//here's the acquisition part
	int test_cases;
	std::cin >> test_cases;

	std::vector<int> line;
	std::vector<int> line_leaders;	
	
	for (int i = 0; i < test_cases; ++i) {
		int length=0;
		std::cin >> length;
		line.reserve(length);
		line_leaders.reserve(length);
		
		for (int n = 0; n < length; ++n) {
			int x=0;
			std::cin >> x;
			line.push_back(x);
		}
		
		int current_leader=line.back();//we start from the back
		line_leaders.push_back(current_leader);//last element always a leader
		
		//we scan the array backwards, and once we find an element larger than our current_leader, he becomes 
		//the leader and gets pushed in the leaders'array.
		for (std::vector<int>::reverse_iterator it = line.rbegin() + 1; it != line.rend(); ++it) {
			if (*it >= current_leader){
				current_leader = *it;
				line_leaders.push_back(current_leader);
			}
		}
		//here's the output part
		for (std::vector<int>::reverse_iterator printer = line_leaders.rbegin(); printer != line_leaders.rend(); ++printer){
			std::cout << *printer << " " ;
		}
		std::cout << std::endl;	
		
	line.clear();
	line_leaders.clear();
	
	}
		
	return 0;
}
