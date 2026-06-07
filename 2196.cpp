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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> noParent;

        for(auto node: descriptions) {
            TreeNode* parent;
            TreeNode* child;
            if(nodeMap.find(node[0]) == nodeMap.end()) {
                parent = new TreeNode(node[0]);
                nodeMap[node[0]] = parent;
                noParent.insert(node[0]);
            } else {
                parent = nodeMap[node[0]];
            }

            if(nodeMap.find(node[1]) == nodeMap.end()) {
                child = new TreeNode(node[1]);
                nodeMap[node[1]] = child;
            } else {
                child = nodeMap[node[1]];
            }

            if(node[2]) {
                // child is left child of parent
                parent->left = child;
            } else {
                parent->right = child;
            }
            noParent.erase(child->val);
        }

        // Only one node will be left in noParent
        return nodeMap[ *(noParent.begin())];
    }
};
