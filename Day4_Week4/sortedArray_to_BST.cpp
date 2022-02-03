#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* constructBST(vector<int>& nums,int start,int end) {
        if(start > end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left = constructBST(nums,start,mid-1);
        root->right = constructBST(nums,mid+1,end);
        return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
   if(!nums.size()) return NULL;
   return constructBST(nums,0,nums.size()-1);
}

int main () {
	
	return 0;
}