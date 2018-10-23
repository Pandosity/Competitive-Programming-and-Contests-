#include <iostream>

//The algorithm runs in linear time, and interestingly that time is all used in scanning the numbers, which I fear we can't avoid.
//The space used is minimal, limited to that of some basic integers for each test case.

int main(){
	int test_cases;
	std::cin >> test_cases;	
	int sum = 0;
	int missing = 0;
	int length;
	
	for (int i = 0; i < test_cases; ++i) {
		std::cin >> length;
		
		for (int n = 1; n < length; ++n) {
			int x;
			std::cin >> x;
			sum += x;
		}
		
		//Here's the only meaningful idea, that of using the formula
		//for the sum of the first n consecutive integers.
		missing = (length + 1)*length/2 - sum;
		std::cout << missing << "\n";
		
	
	}
		
	std::cout << std::endl;	
	return 0;
}
