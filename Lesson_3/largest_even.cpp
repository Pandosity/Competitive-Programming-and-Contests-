

//The solution we have implemented here runs in linear time and linear space. Space-wise, the only relevant amount of space used is the one for
//the vector storing the digits of each number, which then gets permutated in-place to the desired number: all the other space is constant (some integers and 
//a vector counting digits occurences). Time-wise, we sort all the digits in linear time via couting sort, and then we search the smallest even digit and
//permutate the end of the number accordingly to its position:both these operations take Theta(n) time.

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;

using namespace std;
typedef long long int ll;

void count_sort(string &N){
	
	vector<int> count(10,0)//vector storing digits occurences
	int size = N.size();

	//building count
	for(int i = 0 ; i < size ; ++i){
		++count[N[i] - 48];
	}
	
	N.clear();

	//re-building N in increasing order
	for(int i = 0; i < 10 ; ++i){
		while(count[i] > 0){
			N.push_back('0' + i);
			--count[i];
		}
	}
	
}

int main(){
	
	int test_cases;
	cin >> test_cases;
	
	for(int i = 0; i < test_cases; ++i){
		
		string current;//string is to take care of leading zeros	
		cin >> current;
		int magnitude;//the number of digits
		magnitude = current.size();
		
		//we sort it
		count_sort(current);
		//if the smallest digit is already even we stop
		if (current[0] % 2 == 1){
		//we search the smallest even digit
		for(int j = 1; j < magnitude ; ++j){
			if(current[j] % 2 == 0){
				
				//we cyclically permutate the last j+1 digits: to do so we implemented the decomposition of a cycle in swaps
				for(int i = 0; i < j; ++i){
					char swapper = current[0];
					current[0] = current[i+1];
					current[i+1] = swapper;	
					}
				//we brutally exit the cycle
				break;
				}	
			}
		}
	
	//we now finally reverse current
	string largest;

	for(ll i = 0 ; i < magnitude ; ++i) largest.push_back(current[magnitude - i -1]);
	
	//we define and calculate the final result
	cout << largest << endl;
	largest.clear();
	current.clear();
	}
	
	return 0;
}
