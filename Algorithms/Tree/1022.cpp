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
    void Preorder(TreeNode *root, int path, int &sum)
    {
        path = (path << 1) + root->val;
        if (root->left != nullptr)
            Preorder(root->left, path, sum);
        if (root->right != nullptr)
            Preorder(root->right, path, sum);
        if (root->left == nullptr && root->right == nullptr)
            sum += path;
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        if (root != nullptr)
            Preorder(root, 0, sum);
        
        return sum;
    }
};