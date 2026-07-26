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

    bool isSameTree(TreeNode* p, TreeNode* q) {
       
        stack<pair<TreeNode*,int>> st1,st2;
        if(p==NULL && q==NULL) return true  ;
        if(!p || !q) return false ;
        st1.push({p,0});
        st2.push({q,0});
        while(!st1.empty() && !st2.empty()){

            
            auto node1=st1.top().first;
            auto node2=st2.top().first;


            int dir1=st1.top().second;
            int dir2=st2.top().second;
            st1.pop();
            st2.pop();
            if(!node1 && !node2)continue;
            if(!node1 || !node2) return false;
            
            if(node1->val!=node2->val ||dir1!=dir2 ) return false;
            
            
            st1.push({node1->right,2});
            st1.push({node1->left,1});

            st2.push({node2->right,2});
            st2.push({node2->left,1});
            

        }
        return true;
        
        
        
        



        
    }
};