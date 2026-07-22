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
private: 

    int solve(TreeNode* root, int & ans) {
        if(root == nullptr) return 0;
        int lh = 1 + solve(root->left, ans);
        int rh = 1 + solve(root->right, ans);
        ans = max(ans, lh + rh -1);
        return max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int h = solve(root, ans);
        return ans - 1;
    }
};
