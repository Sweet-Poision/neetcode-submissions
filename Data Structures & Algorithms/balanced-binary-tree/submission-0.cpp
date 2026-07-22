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
    int solve(TreeNode * root, bool & ans) {
        if(root == nullptr) return 0;
        if(ans == false) return 0;
        int lh = 1 + solve(root->left, ans);
        int rh = 1 + solve(root->right, ans);
        if(abs(lh - rh) > 1) {
            ans = false;
            return 0;
        }
        return max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int random = solve(root, ans);
        return ans;
    }
};

