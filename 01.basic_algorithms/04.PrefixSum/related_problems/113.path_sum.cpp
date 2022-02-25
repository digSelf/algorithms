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
    void visit(TreeNode* cursor, int target, int sum, vector<int>& path, vector<vector<int>>& ans) {
        if (cursor == nullptr) return;

        sum += cursor->val;
        path.push_back(cursor->val);
        visit(cursor->left, target, sum, path, ans);
        visit(cursor->right, target, sum, path, ans);

        if (!cursor->left && !cursor->right && sum == target) {
            ans.push_back(vector<int>(path));
        }
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        visit(root, targetSum, 0, path, ans);

        return ans;
    }
};