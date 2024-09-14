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
    void dfs(TreeNode* node, int currNum, int& ans) {
        if (node == nullptr) {
            return;
        }
        currNum = currNum*10 + node->val;

        // if leaf node, populate vector with number by iterating the deque
        if (node->left == nullptr && node->right == nullptr) {
            ans += currNum;
        }
        dfs(node->left, currNum, ans);
        dfs(node->right, currNum, ans);
    }

    int sumNumbers(TreeNode* root) {
        // populate nums with root-leaf nums
        int ans  = 0;
        dfs(root, 0, ans);
        return ans;
    }
};
