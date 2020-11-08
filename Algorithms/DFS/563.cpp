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
    int GetSubSum(TreeNode *root)
    {
        if (!root)
            return 0;
        
        int left = GetSubSum(root->left);
        int right = GetSubSum(root->right);
        tiltSum += abs(left - right);
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        GetSubSum(root);
        return tiltSum;
    }
private:
    int tiltSum;
};