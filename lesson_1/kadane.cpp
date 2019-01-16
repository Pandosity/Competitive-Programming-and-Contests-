#include <iostream>
#include <vector>
#include <algorithm>

/*The algorithm implemented here scans the array forward, at each step updating two integers, the global max and the current local 
maximum. The global maximum at the end of the algorithm is the answer to the problem. Space and time complexities are O(n).*/

int main(){
	int test_cases=0;
	std::cin >> test_cases;

	std::vector<int> line;
	
	for (int i = 0; i < test_cases; ++i) {
		int length;
		std::cin >> length;
		line.reserve(length);
		
		for (int n = 0; n < length; ++n) {
			int x=0;
			std::cin >> x;
			line.push_back(x);
		}
		
		int current_max = line.front();
		int global_max = line.front();
		for (std::vector<int>::iterator it = line.begin()+1 ; it != line.end(); ++it) {
			
		current_max = std::max(*it, *it + current_max);
		global_max  = std::max(current_max, global_max);
				
		}
		std::cout << global_max << "\n";
	line.clear();
	
	}
		
	std::cout << std::endl;	
	return 0;
}
