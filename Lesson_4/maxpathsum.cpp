/*This algorithm searches recursively for the maximum sum by examining left and right subtree in the MaxSubPath function. Time and
space consumption are linear in the number of vertexes.*/

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

int MaxSubPath(struct Node *root, int *max){
	if(root == NULL) return INT_MIN;
	int leftmax = MaxSubPath(root->left, max);
	int rightmax = MaxSubPath(root->right, max);
	
	if(leftmax == INT_MIN && rightmax == INT_MIN) return root->data;
	
	int bestpath = root->data;
	if(leftmax > rightmax) bestpath += leftmax;
	else bestpath += rightmax;
	
	if(leftmax != INT_MIN && rightmax != INT_MIN){
		int newmax = root->data + leftmax + rightmax;
		*max = std::max(newmax, *max);
	}
	
	return bestpath;
	
}

int maxPathSum(struct Node *root){
	int max = INT_MIN;
	int maxpath = MaxSubPath(root, &max);
	return max;
}


