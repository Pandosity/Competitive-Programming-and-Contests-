/*This algorithm greedily checks wether the last one, two or three digits are 1, 14 or 144 respectively, and in that case deletes them.
The space used is constant, so O(1), and time is proportional to the number of digits of n, so O(log(n)).*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	
	while(n > 0){
		if(n % 10 != 1 && n % 100 != 14 && n % 1000 != 144){
			cout << "NO" << endl;
			return 0;
		}
		else if(n % 10 == 1){
			n = (n - 1)/10;
		}
		else if(n % 100 == 14){
			n = (n - 14)/100;
		}
		else if (n % 1000 == 144){
			n = (n - 144)/1000;
		}
	}
	cout << "YES" << endl;
	return 0;
}
