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

    TreeNode* subtree(int startpre,int endpre,int startin,int endin,unordered_map<int,int>&mp,vector<int>& preorder,vector<int>&inorder ){

        if(startpre>endpre||startin>endin)return nullptr ;

        TreeNode* root= new TreeNode(preorder[startpre]);
        int rootind=mp[root->val];

        int tnums=rootind-startin;
        root->left=subtree(startpre+1,startpre+tnums,startin,rootind-1,mp,preorder,inorder);
        root->right=subtree(startpre+1+tnums,endpre,rootind+1,endin,mp,preorder,inorder);

        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        return subtree(0,preorder.size()-1,0,inorder.size()-1,mp,preorder,inorder);
        
    }
};