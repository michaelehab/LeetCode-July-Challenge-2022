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
    TreeNode* solve(int first_preorder, int first_inorder, int last_inorder, vector<int>& preorder, vector<int>& inorder) {
        if(first_inorder > last_inorder || first_preorder > preorder.size() - 1) return NULL;
        TreeNode* root = new TreeNode(preorder[first_preorder]);
        int idx = 0;
        for(int i = first_inorder; i <= last_inorder; i++) if(root->val == inorder[i]) idx = i;
        root->left = solve(first_preorder + 1, first_inorder, idx - 1, preorder, inorder);
        root->right = solve(first_preorder + idx - first_inorder + 1, idx + 1, last_inorder, preorder, inorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return solve(0, 0, inorder.size() - 1, preorder, inorder);
    }
};