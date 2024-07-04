#include <iostream>
#include <vector>

/**
 * @brief https://leetcode.com/problems/binary-tree-inorder-traversal
 * 
 */

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}   
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    void step_into(TreeNode* root, vector<int>& vec) {
        if (root) {
            step_into(root->left, vec);
            vec.push_back(root->val);
            step_into(root->right, vec);
        }
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return {};
        }
        step_into(root, res);
        return res;
    }
};
