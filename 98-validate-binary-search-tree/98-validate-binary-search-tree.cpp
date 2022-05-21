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
    bool check(TreeNode* root,TreeNode* lower,TreeNode *upper){
   if(!root) return true;
   if(lower and root->val<=lower->val) return false;
   if(upper and root->val>=upper->val) return false;
   return check(root->left,lower,root) and check(root->right,root,upper);

 }
 bool isValidBST(TreeNode* root) {

        return check (root,NULL,NULL);
    
    
    }
};