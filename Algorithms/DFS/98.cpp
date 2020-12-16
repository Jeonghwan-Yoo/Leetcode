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
    bool Dfs(TreeNode *root, long long minVal, long long maxVal)
    {
        if (!root)
            return true;
        
        int cur = root->val;
        if (cur <= minVal || cur >= maxVal)
            return false;
        
        return Dfs(root->left, minVal, cur) && Dfs(root->right, cur, maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        return Dfs(root, LLONG_MIN, LLONG_MAX);
    }
};

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
    void Inorder(TreeNode *root, vector<int> &path)
    {
        if (!root)
            return;
        
        Inorder(root->left, path);
        path.emplace_back(root->val);
        Inorder(root->right, path);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> path;
        Inorder(root, path);
        int sz = (int)path.size();
        for (int i = 1; i < sz; ++i)
            if (path[i] <= path[i - 1])
                return false;
        
        return true;
    }
};