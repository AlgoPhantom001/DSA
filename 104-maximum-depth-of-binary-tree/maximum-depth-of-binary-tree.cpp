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
    int func(TreeNode* node){
        if(node==nullptr) return 0;

        int l=0;
        int r=0;
        if(node->left!=nullptr){
            l=func(node->left);
        }
        if(node->right!=nullptr){
            r=func(node->right);
        }
        return max(l,r)+1;

    }
    int maxDepth(TreeNode* root) {
        return func(root);
        
    }
};