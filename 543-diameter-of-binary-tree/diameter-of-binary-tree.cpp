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
    int func(TreeNode* &node,int &maxno){
        if(node==nullptr) return 0;

        int l=0;
        int r=0;
        if(node->left!=nullptr){
            l=func(node->left,maxno);
        }
        if(node->right!=nullptr){
            r=func(node->right,maxno);
        }
        if(l+r>maxno) maxno=l+r;

        return max(l,r)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxno=0;
        func(root,maxno);
        return maxno;
        
    }
};