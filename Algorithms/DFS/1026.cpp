// O(N)
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
    int Dfs(TreeNode *root, int maxVal, int minVal)
    {
        if (!root)
            return maxVal - minVal;
        
        maxVal = max(maxVal, root->val);
        minVal = min(minVal, root->val);
        int left = Dfs(root->left, maxVal, minVal);
        int right = Dfs(root->right, maxVal, minVal);
        return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
        return Dfs(root, root->val, root->val);
    }
};