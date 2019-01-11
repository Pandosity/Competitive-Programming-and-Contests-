#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

std::pair<int, int> tree_limits(Node* root, bool* res){
	
	bool left_check = true;
	bool right_check = true;
	int current_min = root -> data;
	int current_max = root -> data;
	
	if(root -> left){
		auto left = tree_limits(root -> left, &left_check);
		if(left.second > root->data) left_check = false;
		current_min = std::min(current_min, left.first);
		current_max = std::max(current_max, left.second);
	}
	
	if(root -> right){
		auto right = tree_limits(root -> right, &right_check);
		if(right.first < root->data) right_check = false;
		current_min = std::min(current_min, right.first);
		current_max = std::max(current_max, right.second);
	}
	
	*res = left_check && right_check;
	return std::make_pair(current_min, current_max);
	
}

bool isBST(Node* root){
	
	if(!root) return true;
	bool checker = true;
	auto limits = tree_limits(root, &checker);
	return checker;
	
}
