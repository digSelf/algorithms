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
    unordered_map<int, int> sum_to_count;

    void visit(TreeNode* root, int target, int sum, int& ans) {
        // exit
        if (!root) 
            return;
        
        sum += root->val;
        if (sum_to_count.find(sum - target) != sum_to_count.end()) {
            ans += sum_to_count[sum - target];
        }
        sum_to_count[sum] ++;

        visit(root->left, target, sum, ans);
        visit(root->right, target, sum, ans);
        // 当当前节点已经做完当前的任务马上返回上一层节点时
        // 由于当前节点的相关信息不需要了，因此需要回撤到刚进入当前节点时的状态
        sum_to_count[sum] --;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        sum_to_count[0] = 1;

        int ans = 0;
        visit(root, targetSum, 0, ans);
        return ans;
    }
};