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
    bool visit(TreeNode* cursor, int target, int sum) {
        if (!cursor) {
            return false;
        } else if ((!cursor->left && !cursor->right)) {
            return target == (sum + cursor->val);
        } 

        sum += cursor->val;

        return visit(cursor->left, target, sum) || visit(cursor->right, target, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return visit(root, targetSum, 0);
    }
};