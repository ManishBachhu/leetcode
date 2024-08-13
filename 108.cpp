/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper (vector<int>& nums, int start, int end) {
        if (start >= end)
            return nullptr;
        
        int rootIndex = (start + end)/2;
        TreeNode* left = helper(nums, start, rootIndex);
        TreeNode* right = helper(nums, rootIndex + 1, end);
        TreeNode *rootNode = new TreeNode(nums[rootIndex]);
        rootNode->left = left;
        rootNode->right = right;
        return rootNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());;
    }
};
