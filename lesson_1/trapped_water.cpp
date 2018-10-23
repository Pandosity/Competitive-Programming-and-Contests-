#include <iostream>
#include <vector>
#include <algorithm>

//The algorithm presented here uses two interators to scan the array front to back and back to front,
//doing so with a while cycle that at each step advances the iterator at the position with the smaller
//water level (so that the we are ensured that there is no "waterfall" ahead of us and we can add safely)
//until the whole array has been scanned. The asymptotic complexity is thus \Theta(n), since each number in the array
//gets processed (with a constant number of operations) only once.
//The space used by this algorithm is, apart from that required by the integers and interators at each test case,
//only that of one vector of size n.

int main(){
	//Here's just acquisition of data
	int test_cases;
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
		
		//we now introduce two iterator that will scan the array front to back and back to front,
		//and two integers that will record the current level of water at the back and at the front
		//of the unscanned part.
		std::vector<int>::iterator begin = line.begin();
		std::vector<int>::iterator end = line.end()-1;
		int left_level = *begin;
		int right_level = *end;
		int trapped_water=0;
		
		//the cycle stops when begin and end coincide, i.e. the whole array has been scanned.
		while (begin != end){
			//At each step we can advance only the indicator with the smaller level, 
			//so we separate two cases
			if(*begin <= *end){
				left_level = std::max(left_level, *begin);//set new level if a taller wall is found
				trapped_water += left_level - *begin;
				++begin;
			} else {
				right_level = std::max(right_level, *end);
				trapped_water += right_level - *end;
				--end;
			}
		}
		
		std::cout << trapped_water << "\n" ;
		line.clear();
	
	}
		
	std::cout << std::endl;	
	return 0;
}
