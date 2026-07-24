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
    int func(TreeNode* &node, bool &result){
        if(node==nullptr) return 0;
        

        int l=0;
        int r=0;
        if(node->left!=nullptr){
            l=func(node->left,result);
        }
        if(node->right!=nullptr){
            r=func(node->right,result);
        }
        if(abs(l-r)>1) result=false;
        return max(l,r)+1;

    }

    bool isBalanced(TreeNode* root) {
        bool result=true;
        func(root,result);
        return result ;




        
    }
};