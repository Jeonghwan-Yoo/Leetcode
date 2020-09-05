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
// O(N)
class Solution {
public:
    void Inorder(TreeNode *root, vector<int> &path)
    {
        if (root->left != nullptr)
            Inorder(root->left, path);
        path.emplace_back(root->val);
        if (root->right != nullptr)
            Inorder(root->right, path);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        vector<int> ret;
        if (root1 != nullptr)
            Inorder(root1, v1);
        if (root2 != nullptr)
            Inorder(root2, v2);
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(ret));
        
        return ret;
    }
};